#include <iostream>

class Animal {
private: // 접근 지시자, private: 자기 객체 안에서만 접근할 수 있을 뿐 객체 외부에서 접근할 수 없다
	// 명시하지 않으면 기본 private으로 지정된다.
	// 멤버 변수 (member variable)
	int food;
	int weight;

public:
	// 멤버 함수 (member function)
	void set_animal(int _food, int _weight) {
	// food, weight 명시하지 않아도 객체 자신의 멤버 변수. 
		food = _food;
		weight = _weight;
	}
	void increase_food(int inc) {
		food += inc;
		weight += (inc / 3);
	}
	void view_stat() {
		std::cout << "이 동물의 food	: " << food << std::endl;
		std::cout << "이 동물의 weight  : " << weight << std::endl;
	}
}; //세미콜론을 잊지 말자!

int main() {
	Animal animal; // Animal 클래스의 인스턴스 animal을 만든 것.
	// animal.food = 100; // 객체 밖에서 인위적으로 food로 접근 불가능.

	// public: 접근 지시자로서 객체 밖에서 마음껏 접근 가능.
	animal.set_animal(100, 50);
	animal.increase_food(30);

	animal.view_stat();
	return 0;
}

/*
문제 1
여러분은 아래와 같은 Date 클래스를 디자인 하려고 합니다. SetDate 는 말그대로 Date 함수 내부를 초기화 하는 것이고 AddDay, AddMonth, AddYear 는 일, 월, 년을 원하는 만큼 더하게 됩니다. 한 가지 주의할 점은 만일 2012 년 2 월 28 일에 3 일을 더하면 2012 년 2 월 31 일이 되는 것이 아니라 2012 년 3 월 2 일이 되겠지요? (난이도 : 上)

class Date {
  int year_;
  int month_;  // 1 부터 12 까지.
  int day_;    // 1 부터 31 까지.

 public:
  void SetDate(int year, int month, int date);
  void AddDay(int inc);
  void AddMonth(int inc);
  void AddYear(int inc);

  void ShowDate();
};
*/

/*#include <iostream>

class Date {
private:
    int year_;
    int month_;  // 1부터 12까지
    int day_;    // 1부터 31까지

    bool IsLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    int GetDaysInMonth(int year, int month) {
        int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        if (month == 2 && IsLeapYear(year)) {
            return 29;
        }
        return days_in_month[month - 1];
    }

public:
    void SetDate(int year, int month, int day) {
        year_ = year;
        month_ = month;
        day_ = day;
    }

    void AddDay(int inc) {
        day_ += inc;

        while (day_ > GetDaysInMonth(year_, month_)) {
            day_ -= GetDaysInMonth(year_, month_);
            month_++;

            if (month_ > 12) {
                month_ = 1;
                year_++;
            }
        }
    }

    void AddMonth(int inc) {
        month_ += inc;

        while (month_ > 12) {
            month_ -= 12;
            year_++;
        }
    }

    void AddYear(int inc) {
        year_ += inc;
    }

    void ShowDate() {
        std::cout << year_ << "년 " << month_ << "월 " << day_ << "일" << std::endl;
    }
};

int main() {
    Date date;
    date.SetDate(2012, 2, 28);
    date.AddDay(3);
    date.ShowDate();  // 2012년 3월 2일 출력되어야 함

    return 0;
}*/