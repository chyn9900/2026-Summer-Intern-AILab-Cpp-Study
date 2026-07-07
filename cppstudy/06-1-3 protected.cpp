/*
* protected: public과 private 중간 위치에 있는 접근 지시자
* 상속받는 클래스에서는 접근 가능하고 그 외의 기타 정보는 접근 불가능.
*
private: (부모님들한테 안가르쳐 주는) 자신만의 비밀번호
protected: 집 현관문 비밀번호 (가족들은 알지만 그 외의 사람들은 접근 불가)
public: 집 주소 (가족 뿐만 아니라 다른 사람들도 알 수 있다)

*/
#include<iostream>
#include<string>

class Base {
protected:
	std::string parent_string;

public:
	Base() : parent_string("기반") { std::cout << "기반 클래스" << std::endl; }

	void what() { std::cout << parent_string << std::endl; }
};
class Derived : public Base {
	std::string child_string;

public:
	Derived() : Base(), child_string("파생") {
		std::cout << "파생 클래스" << std::endl;

		// 그렇다면 현재 private 인 Base 의
		// parent_string 에 접근할 수 있을까?
		parent_string = "바꾸기";
	}

	void what() { std::cout << child_string << std::endl; }
};

int main() {
	
	return 0;
}