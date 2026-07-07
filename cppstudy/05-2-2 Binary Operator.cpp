/* 이항 연산자 */
/* 
지난 강좌에서 다음 문제점이 있었다.
a = a + "-1.1 + i3.923"; // 1. 컴파일이 잘 되어서 실행된다.

a = "-1.1 + i3.923" + a; // 2. 컴파일 되지 않는다.

1. 의 경우 a.operator(i3.923"); 으로 변환될 수 있지만,
2. 는 그렇지 못한다ㅏ.

이항 연산자: 피연산자를 두 개 취하는 연산자 (ex. +, -, *, /, ->, = 등) 를 다음과 같은
두 개 방식으로 해석한다

어떤 임의의 연산자 @ 에 대해서 a@b 는 (C++에 @연산자는 없지만, '임의의 연산자'를 의미)

*a.operator@(b);
*operator@(a,b);

컴파일러는 둘 중 가능한 선택하여 처리한다.

a.operator@(b) 에서의 operator@ 는 a 의 클래스의 멤버 함수로써 사용되는 것이고,
operator@(a,b) 에서의 operator@ 는 클래스 외부에 정의되어 있는 일반적인 함수를 의미한다.

따라서 이를 처리하기 위해 함수를 정의하자.

참고로, 이는 일부 연산자들에 대해서는 해당되지 않는다.
대표적으로 []연산자(첨자), ->연산자(멤버 접근), 대입 연산자(=), () 함수 호출 연산자들의 경우,
멤버 함수로만 존재할 수 있다.
즉, 멤버 함수가 아닌 따로 전역 함수로 뺄 수 없다는 의미이다. 
따라서 위의 예시 함수를 오버로딩할 때 주의해야 한다.

Complex operator+(const Complex& a, const Complex* b) {
	// ...
}

우리의 또 다른 oeprator+ 는 두 개의 const Complex& 타입의 a, b 를 받게 된다.
컴파일러는 정확히 일치하지 않는 경우, 가장 가까운 가능한 오버로딩되는 함수를 찾는다.
마침 우리에게 Complex(const char *) 타입의 생성자가 있으므로

"-1.1 + i3.923" + a;

는

operator+(Complex("-1.1 + i3.923"), a);

가 되어 잘 실행된다.

그런데 문제는 Complex operator+(const Complex& a, const Complex& b) 가 제대로 작동하기 위해서
이 함수가 a 와 b 의 real 과 img 에 접근해야 하는데,
해당 멤버 변수들은 모두 private 이다.

따라서 이를 해결하기 위해 이 함수는 Complex 의 friend 로 지정하면 된다.
*/

#include <iostream>
#include <cstring>

class Complex {
private:
	double real, img;

	double get_number(const char* str, int from, int to) const;
public:
	Complex(double real, double img) : real(real), img(img) {}
	Complex(const Complex& c) { real = c.real, img = c.img; }
	Complex(const char* str);

	// Complex operator+(const Complex& c) const;
	// 자기 자신을 리턴하는 이항 연산자는 멤버 함수로 정의
	Complex& operator=(const Complex& c);

	// 나머지 연산자 함수들은 생략 :)

	void println() {
		std::cout << "( " << real << " , " << img << " ) " << std::endl;
	}

	// 이제 이 함수는 Complex 클래스의 private 멤버 변수들에 접근할 수 있다.
	friend Complex operator+(const Complex& a, const Complex& b);
};

// 자기 자신을 리턴하지 않는 이항 연산자는 외부 함수로 정의
Complex operator+(const Complex& a, const Complex& b) {
	Complex temp(a.real + b.real, a.img + b.img);
	return temp;
}

Complex::Complex(const char* str) {
	// 입력받은 문자열을 분석하여 real 부분과 img 부분을 찾아야 한다.
	// 문자열의 꼴은 다음과 같습니다 "[부호](실수부)(부호)i(허수부)"
	// 이때 맨 앞의 부호는 생략 가능합니다. (생략시 + 라 가정)

	int begin = 0, end = strlen(str);
	real = 0.0;
	img = 0.0;

	// 먼저 가장 기준이 되는 'i' 의 위치를 찾는다.
	int pos_i = -1;
	for (int i = 0; i != end; i++) {
		if (str[i] == 'i') {
			pos_i = i;
			break;
		}
	}

	// 만일 'i' 가 없다면 이 수는 실수 뿐이다.
	if (pos_i == -1)
	{
		real = get_number(str, begin, end - 1);
		return;
	}

	// 만일 'i' 가 있다면, 실수부와 허수부를 나누어서 처리하면 된다.
	real = get_number(str, begin, pos_i - 1);
	img = get_number(str, pos_i + 1, end - 1);

	if (pos_i >= 1 && str[pos_i - 1] == '-') img *= -1.0;
}
double Complex::get_number(const char* str, int from, int to) const {
	bool minus = false;
	if (from > to) return 0;

	if (str[from] == '-') minus = true;
	if (str[from] == '-' || str[from] == '+') from++;

	double num = 0.0;
	double decimal = 1.0;

	bool integer_part = true;
	for (int i = from; i <= to; i++) {
		if (isdigit(str[i]) && integer_part) {
			num *= 10.0;
			num += (str[i] - '0');
		}
		else if (str[i] == '.')
			integer_part = false;
		else if (isdigit(str[i]) && !integer_part) {
			decimal /= 10.0;
			num += ((str[i] - '0') * decimal);
		}
		else
			break; // 그 이외의 이상한 문자들이 올 경우
	}

	if (minus) num *= -1.0;

	return num;
}
/*
Complex Complex::operator+(const Complex& c) const {
	Complex temp(real + c.real, img + c.img);
	return temp;
}
*/

// 자기 자신을 리턴하는 이항 연산자는 멤버 함수로 정의
Complex& Complex::operator=(const Complex& c) {
	real = c.real;
	img = c.img;
	return *this;
}

int main() {
	Complex a(0, 0);
	a = "-1.1 + i3.923" + a;
	a.println(); // ( -1.1 , 3.923 )

	a = a + a;

	Complex b(1, 2);
	b = a + b;

	b.println(); // ( -1.2 , 9.846 )

	/*
	! 주의 사항 !
	자기 자신을 리턴하는 이항 연산자는 멤버 함수로,
	자기 자신을 리턴하지 않는 이항 연산자는 외부 함수로 정의하자!

	*/
	

	/* C2593: 'operator+'이(가) 모호합니다.
	a = a + a;
	a.println();

	컴파일러는 a + a 를 해석할 때,
	a.operator+(a);
	operator+(a, a);
	위 두 가지 형태 중에서 하나를 고른다.

	그런데 위 두 가지 경우가 모두 가능하기 때문에, 어떤 걸 골라야 할지 모르겠다고 한다.

	통상적으로 자기 자신을 리턴하지 않는 이항 연산자들, 예를 들어 +, -, *, / 들은 모두
	외부 함수로 선언하는 것이 원칙이다.

	반대로, 자기 자신을 리턴하는 이항 연산자들,예를 들어 +=, -= 는 모두
	멤버 함수로 선언하는 것이 원칙이다.
	*/

}

/*
1번. a + b 는 사실 함수 호출이다.
a + b
C++ 내부적으로 덧셈이 아니라 "operator+() 함수 호출"이다.

2번. operator+ 를 만든 방법이 두 가지 있다.

방법 A) 클래스 안에다가 만드는 방법 (멤버 함수)
방법 B) 클래스 밖에다가 따로 만드는 방법 (외부 함수)

이 둘 중 뭘 골라도 a + b 라고 쓰면 똑같이 동작하는 것처럼 보인다.
하지만, 차이가 생기는 상황이 있다.

3번. 방법 A (멤버 함수)로 만들면, 이렇게 바뀐다.

a + b

는 컴퓨터 속으로 이렇게 바뀐다.
a.operator+(b)

a 뒤에 점(.)이 붙는다. a.무언가() 라는 건, "a야, 네 안에 있는 함수를 실행해줘"라는 뜻이다.

4번. 그럼 "hello" + a 는 어떻게 될까?
"hello" + a

멤버 함수 방식이면 이렇게 바뀐다.

"hello".operator+(a)

여기서 문제가 생긴다. "hello"는 그냥 문자열이지, Complex 클래스가 아니다.
그러니까 "hello".operator(a)라는 건 "문자열아, 네 안에 있는 operator+ 함수를 실행해줘" 라는 건데,
문자열 안에는 그런 함수가 아예 없다.

그래서 컴파일 에러가 난다.
error: no match for 'operator+' (operand types are 'const char [6]' and 'Complex')

5번. 방법B (외부 함수)로 만들면 이렇게 바뀐다.

a + b
는 외부 함수 방식이면 이렇게 바뀐다.

operator+(a, b)

이번엔 점(.)이 없다. 그냥 평범한 함수 호출이다. 더하기(a, b)라고 부르는 거랑 똑같다.

6번. 그럼 "hello" + a 는 외부 함수 방식이면?
"hello" + a
는 다음과 같이 바뀐다.

operator+("hello", a)
이건 그냥 함수 두 개를 넣어서 부르는 것 뿐이다. .이 없으니까 "hello"가 Complex 클래스일 필요가
전혀 없다. 그냥 함수의 첫 번째 자리에 뭘 넣어도 상관없다.
(물론 함수가 원하는 타입으로 자동 변환이 가능하다면)
마침 Complex(const char* str)이라는 생성자가 있으니까, 컴퓨터가 알아서:
operator+(Complex("hello"), a)
이렇게 "hello"를 Complex 로 슬쩍 바꿔서 넣어준다. 그래서 성공적으로 실행된다.

7번. 그래서 결론: + 는 외부 함수로 만드는가?
" 덧셈 기호 왼쪽에 문자열처럼 다른 게 올 수도 있으니까 " 외부 함수로 만든다.

- 멤버 함수 a.operator+(b) -> 왼쪽(a)이 무조건 Complex여야 한다. 문자열은 안된다.
- 외부 함수 operator+(a,b) -> 왼쪽이든 오른쪽이든 그냥 함수 인자일 뿐, 문자열도 됨(자동 변환되니까)

8번. 그럼 = 는 왜 다른가?

a = b;

이건 + 랑 완전히 다른 이야기이다. = 는 "a 자기 자신의 내용을 바꾼다" 라는 뜻이다.
a 가 b 처럼 되도록 a 안의 값을 직접 고치는 것이다.

이 연산은  C++ 언어 규칙 자체가 " 무조건 멤버 함수로만 만들어야 한다" 라고 못박아두었다
(외부 함수로 만드는 것 자체가 금지되어 있다.)

9번. += 는 왜 멤버 함수인가?

a += b;

이것도 "a 자신을 바꾼다" 는 점에서 = 랑 비슷하다. 그리고 "hello" += a 처럼 왼쪽에
문자열이 오는 경우는 애초에 말이 안된다. (문자열 자체를 바꿔서 대입하겠다는 게 이상하다.)
그러나 + 처럼 굳이 외부 함수로 만들어서 "왼쪽에도 다른 것도 올 수 있게" 신경 쓸 이유가 없다.


Summary)
- a + b (멤버 함수) -> a.더하기(b) 로 바뀜 -> a 는 무조건 그 클래스여 한다.
- a + b (외부 함수) -> 더하기(a, b) 로 바뀜 -> a도 b도 자유롭게 다른 타입에서 변환될 수 있다.
- +, -, *, / 는 왼쪽에 문자열 같은 게올 수도 있으니까 외부 함수로 만든다.
- =, += 는 "자기 자신을 직접 바꾸는" 연산이고, 왼쪽에 다른 게 올 일이 없으니까 그냥 편하게 멤버 함수로 만든다 (= 는 아예 규익상 멤버 함수만 가능)
*/