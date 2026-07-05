#include <iostream>

class Date {
	int year_;
	int month_;		// 1 부터 12 까지.
	int day_;		// 1 부터 31 까지.

public:
	void SetDate(int year, int month, int date);
	void AddDay(int inc);
	void AddMonth(int inc);
	void AddYear(int inc);

	// 해당 월의 총 일 수를 구한다.
	// class 내부에 함수를 정의하면 보기 어려워, class 밖에서 함수를 정의한다.
	int GetCurrentmonthTotalDays(int year, int month);

	void ShowDate();

	// 생성자: 객체 생성시 자동으로 호출되는 함수 -> 자동 호출되면서 객체를 초기화해주는 역할.
	/* 객체를 초기화하는 역할을 하기 때문에 리턴값이 없다.*/
	// /*class이름*/ ( /*인자*/ ) {} 와 같이 생성자를 정의한다.
	Date(int year, int month, int day) {
		year_ = year;
		month_ = month;
		day_ = day;
	}
};

void Date::SetDate(int year, int month, int day) {
	year_ = year;
	month_ = month;
	day_ = day;
}

int Date::GetCurrentmonthTotalDays(int year, int month) {
	static int month_day[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month != 2) {
		return month_day[month - 1];
	}
	else if (year % 4 == 0 && year % 100 != 0) {
		return 29; // 윤년
	}
	else {
		return 28;
	}
}

void Date::AddDay(int inc) {
	while (true) {
		// 현재 달의 총 일 수
		int current_month_total_days = GetCurrentmonthTotalDays(year_, month_);

		// 같은 달 안에 들어온다면;
		if (day_ + inc <= current_month_total_days) {
			day_ += inc;
			return;
		}
		else {
			// 다음달로 넘어가야 한다.
			inc -= (current_month_total_days - day_ + 1);
			day_ = 1;
			AddMonth(1);
		}
	}
}

void Date::AddMonth(int inc) {
	AddYear((inc + month_ - 1) / 12);
	month_ = month_ + inc % 12;
	month_ = (month_ == 12 ? 12 : month_ % 12);
}

void Date::AddYear(int inc) { year_ += inc; }

void Date::ShowDate() {
	std::cout << "오늘은 " << year_ << " 년 " << month_ << " 월 " << day_
			  << " 일 입니다 " << std::endl;
}

int main() {
	// Date day; // day 인스턴스를 생성 // 이  방법으로도 Default constructor(디폴트 생성자)를 사용하면, 처음 생성자를 정의하지 않은 채 생성자 호출 가능.
	// Default Constructor: 인자를 하나도 가지지 않는 생성자인데, 클래스에서 사용자가 어떠한 생성자도 명시적으로 정의하지 않았을 경우에 컴파일러가 자동으로 추가해주는 생성자.
	// day.SetDate(2011, 3, 1); // SetDate로 초기화

	Date day(2011, 3, 1); // 생성자를 만든 후에 인스턴스를 초기화, 암시적(implict) 방법: 마치 함수를 호출하듯이 생성자 호출
	// Date 클래스의 day 객체를 만들면서 생성자 Date(int year, int month, int day)를 호출한다.
	// Date 의 객체를 생성할 때 생성자의 인자 year, month, day 에 각각 2011, 3, 1 을 전달하여 객체를 생성한다.
	// Date day = Date(2012, 3, 1); // 생성자 Date(2012, 3, 1)을 호출해서 이를 토대로 객체를 생성하라. // 명시적(explicit) 방법.
	day.ShowDate(); // 오늘은 2011 년 3 월 1 일 입니다

	day.AddDay(30);
	day.ShowDate(); // 오늘은 2011 년 3 월 31 일 입니다

	day.AddDay(2000);
	day.ShowDate(); // 오늘은 2016 년 9 월 20 일 입니다

	day.SetDate(2012, 1, 31); // 윤년
	day.AddDay(29);
	day.ShowDate(); // 오늘은 2012 년 2 월 29 일 입니다

	day.SetDate(2012, 8, 4);
	day.AddDay(2500);
	day.ShowDate(); // 오늘은 2019 년 6 월 9 일 입니다
	
		
		
		
		
	return 0;
}