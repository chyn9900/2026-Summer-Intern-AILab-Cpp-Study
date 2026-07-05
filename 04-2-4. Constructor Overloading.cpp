/*생성자 오버로딩*/
// 오버로딩: 함수 이름이 같은데, 함수로 들어가는 매개변수인 인자가 다른 것,
#include<iostream>

class Date {
	int year_;
	int month_;		// 1 부터 32 까지.
	int day_;		// 1 부터 31 까지.

public:
	void ShowDate();

	Date() {
		std::cout << "기본 생성자 호출!" << std::endl;
		year_ = 2012;
		month_ = 7;
		day_ = 12;
	}

	// 생성자 역시 함수이기 때문에, 함수 오버로딩과 마찬가지로,
	// 오버로딩이 가능하다.
	Date(int year, int month, int day) {
		std::cout << "인자 3 개인 생성자 호출!" << std::endl;
		year_ = year;
		month_ = month;
		day_ = day;
	}
};

void Date::ShowDate() {
	std::cout << "오늘은 " << year_ << " 년 " << month_ << " 월 " << day_
			  << " 일 입니다 " << std::endl;
}

int main() {
	Date day = Date();			// 기본 생성자 호출!
	Date day2(2012, 10, 31);	// 인자 3 개인 생성자 호출!

	day.ShowDate();				// 오늘은 2012 년 7 월 12 일 입니다
	day2.ShowDate();			// 오늘은 2012 년 10 월 31 일 입니다

	return 0;
}