/* 다중 상속 (multiple inheritance) 

C++ 에서의 상속의 또 다른 특징인 다중 상속에 대해 알아보자.
C++ 에서는 한 클래스가 다른 여러 개의 클래스들을 상속 받는 것을 허용한다. 

이를 다중상속이라 한다.

*/
#include <iostream>

class A {
public:
	int a;

	A() { std::cout << "A 생성자 호출" << std::endl; }
};
class B {
public:
	int b;

	B() { std::cout << "B 생성자 호출" << std::endl; }
};
// 클래스 C 가 클래스 A 와 클래스 B 로부터 동시에 상속 받고 있다

//class C : public A, public B {
class C : public B, public A {
public:
	int c;

	C() :A(), B() { std::cout << "C 생성자 호출" << std::endl; }
};
int main() { C c; }

/*
A 생성자 호출
B 생성자 호출
C 생성자 호출

// 상속하는 순서에 따라 생성자 호출 순서도 바뀐다.
B 생성자 호출
A 생성자 호출
C 생성자 호출
*/