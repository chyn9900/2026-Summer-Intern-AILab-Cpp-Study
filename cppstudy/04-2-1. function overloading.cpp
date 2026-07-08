/* Chapter 4-2 함수의 오버로딩, 생성자*/

// function overloading (함수의 오버로딩)
//	- constructor (생성자)
//	- default constructor (디폴트 생성자)

/* 함수의 오버로딩(Overloading) 

overload
1. 과적하다
2. sb (with sth) 너무 많이 주다[부과핟]
3. (컴퓨터, 전기 시스템 등에) 과부하가 걸리게 하다.

함수의 오버로딩 = '함수에 과부하를 주는 것'
C 언어에서는 하나의 이름을 가지는 함수는 딱 1개만 존재할 수밖에 없어서,
과부하라는 말 자체가 성립이 안 되었다.

예를 들어, prinf, scanf는 C 라이브러리에 단 한 개 존재한다.
하지만 C++에서는 같은 이름을 가진 함수가 여러개 존재할 수 있다.
즉, 함수의 이름에 과부하가 걸려도 상관이 없다는 뜻이다.

그렇다면 C++에서 같은 이름의 함수를 호출했을 때 구분을 어떻게 할까?
함수를 호출하였을 때 사용하는 인자를 보고 같은 이름의 함수 중 어떨 걸 사용할 지 결정한다

*/

#include <iostream>

// C와 달리, C++에선 함수 이름이 같더라도 인자가 다르면 다른 함수로 인식한다.
void print(int x) { std::cout << "int : " << x << std::endl; }

// char의 경우 자기와 정확히 일치하는 인자를 가지는 함수가 없기 때문에 '자신과 최대한 근접한 함수'를 찾게 된다.
// void print(char x) { std::cout << "char : " << x << std::endl; }


void print(double x) { std::cout << "double : " << x << std::endl; }

int main() {
	int a = 1;
	char b = 'c';
	double c = 3.2f;

	print(a); // int : 1
	print(b); // char : c, // int : 99
	print(c); // double : 3.2

	return 0;
}


/* C++ 컴파일러에서 함수를 오버로딩하는 과정

1단계
자신과 타입이 정확히 일치하는 함수를 찾는다.

2단계
정확히 일치하는 타입이 없는 경우 아래와 같은 형변환을 통해서 일치하는 함수를 찾아본다.
	- char, unsigned char, short 는 int 로 변환된다.
	- unsigned short 는 int 의 크기에 따라 int 혹은 unsigned int 로 변환된다.
	- float 는 double 로 변환된다.
	- enum 은 int 로 변환된다.

3단계
위와 같이 변환해도 일치하는 것이 없다면 아래의 좀 더 포괄적인 형변환을 통해 일치하는 함수를 찾는다.
	- 임의의 숫자(numeric) 타입은 다른 숫자 타입으로 변환된다. (예를 들어, float -> int)
	- enum 도 임의의 숫자 타입으로 변환된다 (예를 들어, enum -> double)
	- 0 은 포인터 타입이나 숫자 타입으로 변환된 0 은 포인터 타입이나 숫자 타입으로 변환된다
	- 포인터는 void 포인터로 변환된다.

4단계
유저 정의된 타입 변환으로 일치하는 것을 찾는다.
만약에 컴파일러가 위 과정을 통하더라도 일치하는 함수를 찾을 수 없거나 같은 단계에서 두 개 이상이 일치하는 경우에
모호하다 (ambiguous) 라고 판단해서 오류를 발생하게 된다.

*/