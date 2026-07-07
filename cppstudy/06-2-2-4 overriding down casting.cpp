#include <iostream>
#include <string>

class Base {
	std::string s;

public:
	Base() : s("기반") { std::cout << "기반 클래스" << std::endl; }

	void what() { std::cout << s << std::endl; }
};

class Derived : public Base {
	std::string s;

public:
	Derived() : s("파생"), Base() { std::cout << "파생 클래스" << std::endl; }

	void what() { std::cout << s << std::endl; }
};
int main() {
	Base p;
	Derived c;

	std::cout << " === 포인터 버전 === " << std::endl;
	//Base* p_p = &c; // Base 객체인 p_p 포인터에 Derived 의 주소를 담아서는 안된다 (다운 캐스팅 금지)
	Base* p_p = &p;
	// Derived* p_c = p_p; 
	Derived* p_c = static_cast<Derived*>(p_p);
	p_c->what();

	// dynamic_cast: 강제적으로 다운 캐스팅하는 오류를 미연에 방지하기 위해서 C++에서는 상속 관계에 있는
	// 두 포인터들 간에 캐스팅을 해주는 dynamic_cast 를 지원한다.

	// Derived* p_c = dynamic_cast<Derived*>(p_p);

	// 업캐스팅은 기반(부모) 타입 포인터가 파생(자식) 객체를 가리키는 것이다.
	/*
	Employee 들은 Employee * 가 가리켜야 하고, 
	Manager 들은 Manager * 가 가리켜야 하는데, ...

	Employee * 가 Manger 객체를 가리키는 걸 왜 업캐스팅이라고 하냐?

	Manger * 가 Employee * 처럼 취급하는 것이니, 파생 타입을 기반 타입으로 취급한다고 해서 업 캐스팅이라고 한다.
	
	*/

	return 0;
}