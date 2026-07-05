/* Copy Constructor (복사 생성자): 포토캐논 예제(하나에 여러 개 겹처서 복사) */
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <iostream>

class Photon_Cannon {
	int hp, shield;
	int coord_x, coord_y;
	int damage;

	char *name;

public:
	Photon_Cannon(int x, int y);
	Photon_Cannon(int x, int y, const char *cannon_name);
	Photon_Cannon(const Photon_Cannon& pc);
	~Photon_Cannon();


	void show_status();
};
Photon_Cannon::Photon_Cannon(int x, int y) {
	std::cout << "생성자 호출 !" << std::endl;
	hp = shield = 100;
	coord_x = x;
	coord_y = y;
	damage = 20;

	name = NULL;
	
}
// 복사 생성자 (copy constructor), 어떤 클래스 T 가 있을 떄,
// T(const T& a); 라고 정의한다.
// 다른 T 의 객체 a 를 상수 레퍼런스로 받는다.
// a 는 const 이기 때문에 복사 생성자 내부에서 a 의 데이터를 변경할 수 없고, 오직 새롭게 초기화 되는 인수턴스 변수들에게 '복사'만 할 수 있다.


Photon_Cannon::Photon_Cannon(const Photon_Cannon& pc) {
// 함수 내부에서 받은 인자의 값을 변화시키는 일이 없다면 꼭 const 를 붙여주는 게 좋다.
// 즉, 인자로 받는 변수의 내용을 함수 내부에서 바꾸지 않는다면 앞에 const 를 붙여 주는 게 좋다.
	std::cout << "복사 생성자 호출 !" << std::endl;
	// 복사 생성자 내부에서 pc 의 "인스턴스 변수들에 접근"해서 객체의 shield, coord_x, coord_y 등을 초기화 할 수는 있지만,
	hp = pc.hp;
	shield = pc.shield;
	coord_x = pc.coord_x;
	coord_y = pc.coord_y;
	damage = pc.damage;

	// pc.coord_x = 3; 처럼 pc 의 값 자체 변경은 할 수 없다. 왜냐하면 const 레퍼런스로 인자를 받았기 때문이다.

	name = new char[strlen(pc.name) + 1];
	strcpy(name, pc.name);
}

Photon_Cannon::Photon_Cannon(int x, int y, const char *cannon_name) {
	std::cout << "생성자 호출 !" << std::endl;
	hp = shield = 100;
	coord_x = x;
	coord_y = y;
	damage = 20;

	name = new char[strlen(cannon_name) + 1];
	strcpy(name, cannon_name);
}
Photon_Cannon::~Photon_Cannon() {
	// 0 이 아닌 값은 if 문에서 true 로 처리되므로
	// 0 인가 아닌가를 비교할 때 그냥 if(name) 하면
	// if (name != 0) 과 동일한 의미를 가질 수 있다.

	// 참고로 if 문 다음에 문장이 1개만 온다면, 중괄호를 생략 가능하다.

	if (name) delete[] name;
}
void Photon_Cannon::show_status() {
	std::cout << "Photon Cannon	" << std::endl;
	std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
			  << std::endl;
	std::cout << " HP : " << hp << std::endl;
}

int main() {
	// Photon_Cannon pc1(3, 3); // pc1 은 int x, int y 를 인자로 가지는 생성자가 오버로딩 되었고,
	Photon_Cannon pc1(3, 3, "Cannon");
	// Photon_Cannon pc2(pc1);  // pc2 은 pc1 을 넘겼으므로 복사 생성자가 호출되었다.
	// Photon_Cannon pc3 = pc2; // 이 경우에도 복사 생성자가 호출된다. // 코드를 컴파일러는 Photon_Cannon pc3(pc2); 로 해석한다. 
	Photon_Cannon pc2 = pc1;

	pc1.show_status();
	pc2.show_status();
}
/*
생성자 호출 !
복사 생성자 호출 !
Photon Cannon
 Location : ( 3 , 3 )
 HP : 100
Photon Cannon
 Location : ( 3 , 3 )
 HP : 100
*/