/* 입출력 연산자 오버로딩하기 */

/*
std::cout << a; 

는 사실

std::cout.operator<<(a) 

를 하는 것과 동일한 명령이다.

즉, 어떤 std::cout 이라는 객체에 멤버함수 operator<< 가 정의되어 있어서 a를 호출하게 되는 것이다.
그런데, std::cout 이 int 나 double 변수, 심지어 문자열까지 자유 자재로 operator<< 하나로 출력할 수 있었던 이유는
그 많은 수의 operator<< 함수들이 오버로딩 되어 있다는 뜻이다.

실제로 우리가 include 하던 iostream 의 헤더파일의 내용을 살펴보면
(실제로는 ostream 에 정의 되어 있습니다. 다만 iostream 이 ostream 을 include 하고 있음)
ostream 클래스에
ostream& operator<<(bool val);
ostream& operator<<(short val);
ostream& operator<<(unsigned short val);
ostream& operator<<(int val);
ostream& operator<<(unsigned int val);
ostream& operator<<(long val);
ostream& operator<<(unsigned long val);
ostream& operator<<(float val);
ostream& operator<<(double val);
ostream& operator<<(long double val);
ostream& operator<<(void* val);
와 같이 엄청난 수의 operator<< 가 정의되어 있다. 이들 덕분에 우리가 편하게
인자의 타입에 관계없이 손쉽게 출력을 사용할 수 있다.

그렇다면 Complex 클래스에서 ostream 클래스의 연산자 operator<< 를 자유롭게 사용하려면 어떻게 해야할까?

예를 들어서

Complex c;
std::cout << c;

를 하게 되면 마치

Complex c;
c.println();
을 한 것과 같은 효과를 낸다.

당연하게도, ostream 클래스에 operator<< 멤버 함수를 새롭게 추가하는 것은 불가능하다.
이를 위해서 표준 헤더파일의 내용을 수정해야 하기 때문이다.

따라서, 우리는 ostream 클래스에 Complex 객체를 오버로딩하는 operator<< 연산자 함수를 추가할 수는 없다.

하지만 우리는 클래스의 연산자 함수를 추가하는 방법으로, 멤버 함수를 사용하는 것 말고도 한 가지 더 있다.
바로 ostream 클래스 객체와 Complex 객체 두 개를 인자로 받는 전역 operator<< 함수를 정의하면 된다.

std::ostream& operator<<(std::ostream& os, const Complex& c) {
	os << "( " << c.real << " , " << c.img << " ) ";
	return os;
}
참고로 operator<< 에서 ostream& 타입을 리턴하는 이유는 다음과 같은 문장을 처리할 수 있기 위해서이다.

std::cout << "a 의 값은 : " << a << " 이다. " << std::endl;

하지만 위 operator<< 의 경우 한 가지 문제가 있는데 바로 이 operator<< 에서 c.real 과 c.img 에 접근할 수 없다는 점이다.

이를 해결하기 위해 세 가지 방법을 고려할 수 있다.

1. 그냥 real 과 img 를 public으로 바꾼다.
2. Complex 에 print(std::ostream& os)와 같은 멤버 함수를 추가한 뒤, 이를 oeprator<< 에서 호출한다.
3. 위 operator<< 를 friend로 지정한다.

3 번째,
friend ostream& operator<<(ostream& os, const Complex& c);

위와 같이 friend 선언을 해준다. 비슷한 방법으로 Complex 객체 c 에 대해 cin>>c; 와 같은 작업을 할 수 있다.
다만, 이번에는 cin 은 istream 객체이고, operator>> 를 오버로딩해야 된다는 점이 다르다.
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

	Complex& operator+=(const Complex& c);
	Complex& operator=(const Complex& c);

	// 나머지 연산자 함수들은 생략 :)

	friend std::ostream& operator<<(std::ostream& os, const Complex& c);
	friend Complex operator+(const Complex& a, const Complex& b);
};

std::ostream& operator<<(std::ostream& os, const Complex& c) {
	os << "( " << c.real << " , " << c.img << " ) ";
	return os;
}

Complex operator+(const Complex& a, const Complex& b) {
	Complex temp(a.real + b.real, a.img + b.img);
	return temp;
}

Complex::Complex(const char* str) {
	// 입력 받은 문자열을 분석하여 real 부분과 img 부분을 찾아야 한다.
	// 문자열의 꼴은 다음과 같다. "[부호](실수부)(부호)i(허수부)"
	// 이때 맨 앞의 부호는 생략 가능하다 (생략시 + 라 가정)

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

	// 만일 'i'가 없다면 이 수는 실수이다.
	if (pos_i == -1) {
		real = get_number(str, begin, end - 1);
		return;
	}

	// 만일 'i'가 있다면, 실수부와 허수부를 나누어서 처리한다.
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

Complex& Complex::operator+=(const Complex& c) {
	(*this) = *this + c;
	return *this;
}
Complex& Complex::operator=(const Complex& c) {
	real = c.real;
	img = c.img;
	return *this;
}

int main() {
	Complex a(0, 0);
	a = "-1.1 + i3.923" + a;
	std::cout << "a 의 값은 : " << a << " 이다. " << std::endl; // a 의 값은 : ( -1.1 , 3.923 )  이다.
}

