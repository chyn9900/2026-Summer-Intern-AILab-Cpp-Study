/*복사 생성자 (copy constructor)
생성자: C 프로그래밍 시 변수 초기화를 하지 않아서 생겼던 수많은 오류들을 없앴다.
뿐만 아니라, C++에서 새로 도입된 함수 오버로딩 덕분에 함수 이름을 일일히 따로 지정하지 않더라도
인자들의 타입을 다르게 하여 원하는 함수들만 호출 할 수 있게 되었다.
실제로 C 언어 였다면 인자의 타입에 따른 함수의 이름들을 모두 외워야 했지만,
C++ 에서는 그럴 필요가 없어서 편해졌다.
*/


#include<iostream>

class Marine {
	int hp;					// 마린 체력
	int coord_x, coord_y;	// 마린 위치
	int damage;				// 공격력
	bool is_dead;

public:
	Marine();				// 기본 생성자
	Marine(int x, int y);	// x, y 좌표에 마린 생성

	int attack();						// 데미지를 리턴한다.
	void be_attacked(int damage_earn);	// 입는 데미지
	void move(int x, int y);			// 새로운 위치

	void show_status();		// 상태를 보여준다.
};
Marine::Marine() {
	hp = 50;
	coord_x = coord_y = 0;
	damage = 5;
	is_dead = false;
}
Marine::Marine(int x, int y) {
	coord_x = x;
	coord_y = y;
	hp = 50;
	damage = 5;
	is_dead = false;
}
void Marine::move(int x, int y) {
	coord_x = x;
	coord_y = y;
}
int Marine::attack() { return damage; }
void Marine::be_attacked(int damage_earn) {
	hp -= damage_earn;
	if (hp <= 0) is_dead = true;
}
void Marine::show_status() {
	std::cout << " *** Marine ***" << std::endl;
	std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
			  << std::endl;
	std::cout << " HP : " << hp << std::endl;
}

int main() {
	/*	
	Marine marine1(2, 3); // marine1 라는 이름의 Marine 객체 생성
	Marine marine2(3, 5); // marine2 라는 이름의 Marine 객체 생성

	marine1.show_status();
	marine2.show_status();

	std::cout << std::endl << "마린 1 이 마린 2 를 공격" << std::endl;
	marine2.be_attacked(marine1.attack());

	marine1.show_status();
	marine2.show_status();
	*/

	/* *** Marine ***
	 Location : ( 2 , 3 )
	 HP : 50
	 *** Marine ***
	 Location : ( 3 , 5 )
	 HP : 50

	마린 1 이 마린 2 를 공격
	 *** Marine ***
	 Location : ( 2 , 3 )
	 HP : 50
	 *** Marine ***
	 Location : ( 3 , 5 )
	 HP : 45 */

	// marine1, marine2, ... 마린 수십마리를 생성한다면? marine 배열을 생성

	Marine* marines[100];

	// new 는 객체를 동적으로 필요할 때 그때 그때 생성하면서, 동시에 생성자도 자동으로 호출해준다.
	marines[0] = new Marine(2, 3);
	marines[1] = new Marine(2, 3);

	marines[0]->show_status();
	marines[1]->show_status();

	std::cout << std::endl << "마린 1 이 마린 2 를 공격" << std::endl;

	marines[0]->be_attacked(marines[1]->attack());

	marines[0]->show_status();
	marines[1]->show_status();

	delete marines[0];
	delete marines[1];

/* 
 *** Marine ***
 Location : ( 2 , 3 )
 HP : 50
 *** Marine ***
 Location : ( 2 , 3 )
 HP : 50

마린 1 이 마린 2 를 공격
 *** Marine ***
 Location : ( 2 , 3 )
 HP : 45
 *** Marine ***
 Location : ( 2 , 3 )
 HP : 50
 */
}

