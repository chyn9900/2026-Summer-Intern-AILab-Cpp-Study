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
	Base* p_c = &c; // Derived 의 객체 c 를 Base 객체를 가리키는 포인터에 넣었다. 
	// Base 와 Derived 다른 클래스인데 가능한건가?
	// Derived 가 Base를 상속받고 있으니까 Derived is a Base 관계니까 가능하다.
	// 즉, Derived 객체 c 도 Base 객체이기 때문에 Base 객체를 가리키는 포인터가 c를 가리켜도 무방하다는 뜻이다.
	p_c->what(); // 기반 // 포인터 p 는 Base 를 가리키는 포인터이므로 Derived 객체의 Base 에 해당하는 부분에 대한 정보 밖에 없다.
	// p 는 엄연한 Base 객체를 가리키는 포인터이다. 따라서, p 의 what 을 실행한다면 p 는 당연히 Base 의 what 을 실행한다
	// 이렇게 파생 클래스에서 기반 클래스로 캐스팅하는 것을 업 캐스팅이라고 한다.
	return 0;
}
/*
기반 클래스
기반 클래스
파생 클래스
 === 포인터 버전 ===
기반


*/