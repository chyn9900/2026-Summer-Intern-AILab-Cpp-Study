/* Default Constructor 디폴트 생성자*/

#include<iostream>

class Date {
	int year_;
	int month_; // 1 부터 12 까지.
	int day_;   // 1 부터 31 까지.

public:
	void ShowDate();

	// Default Constructor
	Date() {
		year_ = 2012;
		month_ = 7;
		day_ = 12;
	}
};

class Test {
public:
	Test() = default; // 디폴트 생성자를 정의해라.
	// 생성자 선언 바로 뒤에 = default 를 붙여준다면, 
	// Test 의 디폴트 생성자를 정의하라고 컴파일러에게 명시적으로 알려줄 수 있다.
};

void Date::ShowDate() {
	std::cout << "오늘은 " << year_ << " 년 " << month_ << " 월 " << day_
			  << " 일 입니다 " << std::endl;
}


int main() {
	Date day = Date();
	Date day2;
	
	day.ShowDate();	// 오늘은 2012 년 7 월 12 일 입니다
	day2.ShowDate();// 오늘은 2012 년 7 월 12 일 입니다



	Date day3();  
	// day3.ShowDate(); // error

	/*
	- E0153: 식에 클래스 형식이 있어야 하는데 "Date (*)()" 형식이 있음
	- '.ShowDate' 왼쪽에는 클래스/구조체/공용 구조체가 있어야 합니다.
	*/

	// 인자가 있는 생성자에 적용했던 것처럼 하면, dya3 객체를 디폴트 생성자를 이용해 초기화하는 것이 아니다.
	// 리턴값이 Date 이고 인자가 없는 함수 day3을 정의하게 된 것으로 인식한다.
	// 이는 암시적 표현으로 객체를 선언할 때 반드시 주의해 두어야 할 사항이다.
	


	// Most Vexing Parse(가장 성가신 파싱)
	// Date 라는 클래스의 day3 라는 객체를 만드는 데, 생성자에 아무 인자도 안 넣고 만드는구나 (디폴트 생성자 호출) (X)
	
	// Date day3(); C++ 컴파일러는 day3라는 이름의 “함수를 선언”한 것으로 해석한다.
	// 즉, day3 라는 이름을 가진 함수가 있는데, 이 함수는 인자를 아무것도 받지 않고 ( () ), 리턴 타입은 Date 다. 라고 해석한다.
	
	// 즉, 객체가 아니라 “함수 선언”으로 인식한다.

	
	

	return 0;
}