/* 상속(Inheritance): 다른 클래스의 내용을 그대로 포함할 수 있는 작업을 가능하게 해줌
C++에서 상속을 통해 다른 클래스의 정보를 물려 받아 사용할 수 있다.
*/
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
	// Derived 클래스의 생성자 호출 부분
	Derived() : Base(), s("파생") { // Derived 의 생성자는 초기화 리스트에서 기반의 생성자를 호출해서 기반의 생성을 먼저 처리한 다음에, Derived의 생성자가 실행되어야 한다.
		std::cout << "파생 클래스 " << std::endl;

		// Base 에서 what() 을 물려 받았으므로
		// Derived 에서 당연히 호출 가능하다.
		what();
	}
	void what() { std::cout << s << std::endl; }
};
int main() {
	std::cout << " === 기반 클래스 생성 ===" << std::endl;
	Base p; 

	std::cout << " === 파생 클래스 생성 ===" << std::endl;
	Derived c; 
}
/* Derived 클래스에 what() 함수가 정의되어 있지 않은 경우
 === 기반 클래스 생성 ===
기반 클래스
 === 파생 클래스 생성 ===
기반 클래스
파생 클래스
기반

Derived 클래스에 what() 함수가 정의되어 있는 경우
 === 기반 클래스 생성 ===
기반 클래스
 === 파생 클래스 생성 ===
기반 클래스
파생 클래스
파생

what() 함수는 같은 이름의 함수이지만, 다른 클래스에서 정의되어 있기 때문에 class Base 의 what() 함수와 class Derived 의 what() 함수는 다른 함수로 취급된다.

위 경우에는 Derived 에 what 함수가 정의되어 있기 때문에 Derived의 생성자에서 what 을 호출할 때 (굳이) 멀리 Base 의 함수들까지 뒤지지 않고,
바로 앞에 있는 Derived 의 what 함수를 호출한다.

이런 것을 가리켜 오버라이딩(overriding)이라고 한다. 즉, Derived 의 what 함수가 Base 의 what 함수를 오버라이딩한 것이다.

간혹 함수의 오버로딩(overloading)과 혼동하기 쉬운데, 오버로딩은 같은 이름의 함수를 인자를 달리 하여 정의하는 것을 의미한다.
상속에서의 오버라이딩과 전혀 다른 이야기이다.

기반 클래스와 파생 클래스 각각 클래스에서 함수 이름이 같을 떄,
함수를 호출할 때 함수를 호출한 그 클래스에 함수를 호출하는 걸 오버라이딩이라고 한다.

*/