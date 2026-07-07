#include <iostream>

class Base {

public:
	Base() { std::cout << "기반 클래스" << std::endl; }

	virtual void what() { std::cout << "기반 클래스의 what()" << std::endl; }
};
class Derived : public Base {

public:
	Derived() : Base() { std::cout << "파생 클래스" << std::endl; }

	void what() { std::cout << "파생 클래스의 what()" << std::endl; }
};
int main() {
	Base p;
	Derived c;

	// p_c, p_p 모두 Base 객체를 가리키는 포인터이다.
	// 따라서 p_p->what(), p_p->what() 모두 Base 객체의 what() 함수가 실행되어서 둘 다 '기반'이라고 출력되어야 한다.


	Base* p_p = &p; // p_p 는 Base 포인터이므로 Base 객체를 가리키고, Base 객체인 p 를 가리키고 있다.

	Base* p_c = &c; // p_c 도 Base 포인터이므로 Base 객체를 가리켜야 한다. 하지만 Derived c를 가리키고 있다.


	std::cout << " == 실제 객체는 Derived == " << std::endl;
	p_c->what(); // 파생 클래스의 what() // virtual 키워드 효과
	/*
	p_c->what(); 코드 실행시 (런타임), 컴퓨터 입장에서;
	"흠, p_c 는 Base 포인터니까 Base 의 what() 을 실행해야지"
	"어 근데 what 이 virtual 이네?"

	"잠깐. 이거 실제 Base 객체 맞어? 아니네 Derived 객체네:
	"그럼 Derived 의 what 을 실행해야지"
	*/

	std::cout << " == 실제 객체는 Base == " << std::endl;
	p_p->what(); // 기반 클래스의 what()
	/*
	"흠, p_p 는 Base 포인터니까 Base 의 what() 을 실행해야지"
	"어 근데 what 이 virtual 이네?"

	"잠깐. 이거 실제 Base 객체 맞어? 어 맞네."
	"Base 의 what 을 실행하자."
	*/

	// 이렇게 컴파일 시에 어떤 함수가 실행될 지 정해지지 않고 런타임 시에 정해지는 일을 가리켜서 동적바인딩(dynamic binding)이라고 부른다.

	/* 즉, p_c->what(); 에서 Derived 의 what 을 실행할 지, Base 의 what 을 실행할 지 결정은 런타임에서 이루어지게 된다.
	물론 위 코드에서 컴파일 시 무조건 p_c->what() 이 Derived 의 what 이 실행되도록 정해진 거 아니냐고 물을 수 있지만 다음과 같은 상황을 생각해보자.
	*/

/*
	// i 는 사용자로부터 입력받는 변수
	if (i == 1) {
		p_p = &c; // Derived c
	}
	else {
		p_p = &p; // Base p
	}
	p_p->what();
	
	이렇게 된다면 p_p->what() 이 어떤 what 일지 런타임에 정해진다. 물론 동적 바인딩의 반대 말로 정적 바인딩(static binding) 이라는 말도 있다.
	컴파일 타임에 어떤 함수가 호출될 지 정해지는 것이다.

	덧붙여서, virtual 키워드가 붙은 함수를 가상함수(virtual function)라고 부른다. 이렇게 파생 클래스의 함수가
	기반 클래스의 함수를 오버라이드하기 위해서는 두 함수의 꼴이 정확히 같아야 한다. what() 처럼.

	// 오버라이딩이란?
	자식 클래스가, 부모 클래스에 이미 있는 함수와 똑같은 이름, 똑같은 매개변수를 가진 함수를 다시 정의해서,
	그 함수의 내용을 자식 클래스만의 것으로 바꿔치기 하는 것.
*/

	return 0;
}

/*
기반 클래스
기반 클래스
파생 클래스
 == 실제 객체는 Base ==
기반 클래스의 what()
 == 실제 객체는 Derived ==
파생 클래스의 what()
*/