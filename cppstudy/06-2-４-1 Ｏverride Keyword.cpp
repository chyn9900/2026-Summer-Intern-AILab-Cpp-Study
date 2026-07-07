#include <iostream>
#include <string>

class Base {
	std::string s;
public:
	Base() : s("기반") { std::cout << "기반 클래스" << std::endl; }

	virtual void incorrect() { std::cout << "기반 클래스" << std::endl; }
};

class Derived : public Base {
	std::string s;
public:
	Derived() : Base(), s("파생") { std::cout << "파생 클래스" << std::endl; }

	void incorrect() const { std::cout << "파생 클래스" << std::endl; }
};
int main() {
	Base p;
	Derived c;

	Base* p_c = &c;
	Base* p_p = &p;

	std::cout << " == 실제 객체는 Base == " << std::endl;
	p_p->incorrect();

	std::cout << " == 실제 객체는 Derived == " << std::endl;
	p_c->incorrect();
	return 0;
}
/*
기반 클래스
기반 클래스
파생 클래스
 == 실제 객체는 Base ==
기반 클래스
 == 실제 객체는 Derived ==
기반 클래스

Derived 의 incorrect() 함수가 오버라이드 되지 않았다.
Derived 의 incorrect() 함수는 const(상수) 함수이고,
Base 의 incorrect() 함수는 아니기 때문에, 함수 이름만 같지 상수함수 여부는 다르기 때문이다.

따라서 컴파일러 입장에서 두 함수는 다른 함수로 감주되므로 p_c->inccorec()를 했을 때,
Derived 의 inccorect 함수가 Base 의 incorrect 함수를 오버라이드하는 것이 아니라,
그냥 Base 의 incorrect 함수를 호출하게 된다.

만약 의도가 Derived 의 incorrect 함수가 기반 클래스를 오버라이드 하는 것이었다면
컴파일러가 잡을 수 없기 때문에 큰 문제가 된다.

하지만, 실제로 Derived 의 incorrect 함수를 
Base (기반) 클래스의 incorrect 를 오버라이드 하기 위해 만들었다면 override 키워드를 써야 한다.
*/