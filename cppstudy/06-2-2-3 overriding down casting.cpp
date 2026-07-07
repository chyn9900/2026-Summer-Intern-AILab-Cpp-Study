#include<iostream>
#include<string>

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

	std::cout << "=== 포인터 버전 ===" << std::endl;
	Derived* p_p = &p; // Derived *c 는 가리키는 객체가 Derived 라고 생각하는데 Base 를 가리키고 있다.
	p_p->what(); // 따라서 Derived의 what() 함수를 실행하려고 하지만, 이는 정의되어 있지 않다.
	// p_p 가 가리키는 객체는 Base 객체이므로 Derived 에 대한 정보가 없다. 이와 같은 문제를 막기 위해 컴파일러 상에서 함부로 다운 캐스팅하는 것을 금지하고 있다.
}