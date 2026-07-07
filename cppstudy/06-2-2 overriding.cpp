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
	std::cout << " === 기반 클래스 생성 ===" << std::endl;
	Base p;

	p.what(); // Base 에서 what 을 호출하면 당연히 Base 의 what 이 실행되어 '기반'라고 나오고,

	std::cout << " === 파생 클래스 생성 === " << std::endl;
	Derived c; // Base를 상속받는 Derived 클래스에서 what을 호출하면, Derived 의 what 이 Base 의 what 을 오버라이드해서 Derived 의 what 을 호출하게 된다.

	c.what();

	return 0;
}
/*
 === 기반 클래스 생성 ===
기반 클래스
기반
 === 파생 클래스 생성 ===
기반 클래스
파생 클래스
파생
*/