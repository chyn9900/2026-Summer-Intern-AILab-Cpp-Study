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

컴파일러는 둘 중 가능한 선택하여 처리하ㅏㄴ다ㅏ.

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

	Complex operator+(const Complex& c) const;
	Complex& operator=(const Complex& c);

	// 나머지 연산자 함수들은 생략 :)

	void println() {
		std::cout << "( " << real << " , " << img << " ) " << std::endl;
	}

	// 이제 이 함수는 Complex 클래스의 private 멤버 변수들에 접근할 수 있다.
	friend Complex operator+(const Complex& a, const Complex& b);
};

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
}