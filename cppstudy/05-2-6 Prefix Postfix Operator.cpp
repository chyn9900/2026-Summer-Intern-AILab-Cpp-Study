/* 전위/후위 증감 (Prefix,Postfix Increment: ++/Decrement: --) 연산자 */

#include <iostream>

class Test {
	int x;

public:
	Test(int x) : x(x) {}
	Test(const Test& t) : x(t.x) {}

	Test& operator++() {
		x++;
		std::cout << "전위 증감 연산자" << std::endl;
		return *this;
	}

	// 전위 증감과 후위 증감에 차이를 두기 위해 후위 증감의 경우 인자로 int 를 받지만
	// 실제로는 아무것도 전달되지 않는다.
	Test operator++(int) {
		Test temp(*this);
		x++;
		std::cout << "후위 증감 연산자" << std::endl;
		return temp;
	}

	int get_x() const {
		return x;
	}
};

void func(const Test& t) {
	std::cout << "x : " << t.get_x() << std::endl;
}

int main() {
	Test t(3);

	func(++t); // 4
	func(t++); // 4 가 출력됨
	std::cout << "x : " << t.get_x() << std::endl; // x : 5
}

/* 정리
연산자 오버로딩에 대해 

1. 두 개의 동등한 객체 사이에서의 이항 연산자는 멤버 함수가 아닌 외부 함수로 오버로딩하는 것이 좋다.

예를 들어, Complex 의 oeprator+(const Complex&, const Complex&) const 


=> 자기 자신을 리턴하지 않는 함수는 외부함수로 오버로딩

2. 두 개의 객체 사이의 이항 연산자이지만 한 객체만 값이 바뀐다든지 등의 동등하지 않은 이항 연사자는
멤버 함수로 오버로딩 하는 것이 좋다 

예를 들어, operator+= 는 이항 연산자이지만 oeprator+=(const Complex&) 가 낫다.

=> 자기 자신을 리턴하는 함수는 멤버함수로 오버로딩

3. 단항 연산자는 멤버 함수로 오버로딩하는 것이 좋다

예를 들어, operator++의 경우 멤버함수로 오버로딩한다.

4. 일부 연산자들은 반드시 멤버 함수로만 오버로딩 해야 한다.

=, 

*/