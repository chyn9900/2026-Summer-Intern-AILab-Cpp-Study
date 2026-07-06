/* mutable: 변이가능한 */
#include <iostream>

class A {
	// int data_;
	mutable int data_;

public:
	A(int data) : data_(data) {}
	void DoSomething(int x) const {
		// data_ = x; // 불가능!, const 함수 안에 멤버 변수에 값을 대입하기 때문에 오류
		data_ = x; // 가능
	}

	void PrintData() const { std::cout << "data: " << data_ << std::endl; }
};

int main() {
	A a(10);
	a.DoSomething(3);
	a.PrintData();
}