#include <iostream>

/* 메모리 관리
	프로그램이 정확하게 실행되기 위해서는 컴파일 시에 모든 변수의 주소값이 확정되어야만 한다.
	이를 위해서는 프로그램에 많은 제약이 따르기 때문에
	프로그램 실행 시 자유롭게 할당하고 해제할 수 있는 힙(heap)이라는 공간이 따로 생겼다.

	하지만 이전에 컴파일러에 의해 어느정도 안정성이 보장되는 스택(stack)과는 다르게,
	힙은 사용자가 스스로 제어해야 하는 부분인 만큼 책임이 따른다.

	new: 힙 상에서 메모리 할당 (malloc)
	delete: 메모리를 해제한다. (free)
*/

typedef struct Animal {
	char name[30];  // 이름
	int age;		// 나이

	int health;		// 체력
	int food;		// 배부른 정도
	int clean;		// 깨끗한 정도
} Animal;

typedef struct Bird {
	char name[30];  // 이름
	int age;        // 나이

	int health;  // 체력
	int food;    // 배부른 정도
	int clean;   // 깨끗한 정도

	// 여기까지는 Animal 과 동일하다.
	int height;  // 나는 고도

} Bird;

typedef struct Fish {
	char name[30];  // 이름
	int age;        // 나이

	int health;  // 체력
	int food;    // 배부른 정도
	int clean;   // 깨끗한 정도

	// 여기까지는 Animal 과 동일하다.
	int deep;  // 현재 깊이

} Fish;

void create_animal(Animal *animal) {
	std::cout << "동물의 이름? ";
	std::cin >> animal->name;

	std::cout << "동물의 나이? ";
	std::cin >> animal->age;

	animal->health = 100;
	animal->food = 100;
	animal->clean = 100;
}

void play(Animal *animal) {
	animal->health += 10;
	animal->food -= 20;
	animal->clean -= 30;
}

void one_day_pass(Animal *animal) {
	// 하루가 지나면
	animal->health -= 10;
	animal->food -= 30;
	animal->clean -= 20;
}

void show_stat(Animal *animal) {
	std::cout << animal->name << "의 상태" << std::endl;
	std::cout << "체력		: " << animal->health << std::endl;
	std::cout << "배부름	: " << animal->food << std::endl;
	std::cout << "청결		: " << animal->clean << std::endl;
}


int main()
{
	///* new 사용 방법
	//T* pointer = new T; // T: 임의의 Type
	//*/

	///*
	//int* p = new int; // int 크기의 공간을 할당하여 그 주소값을 포인터 p에 집어 넣었다.

	//*p = 10; // 포인터 p 에 할당된 메모리 주소에 값 10을 저장한다.

	//std::cout << *p << std::endl; // 10

	//delete p; // p에 할당된 공간을 해제한다.
	//// delete로 해제할 수 있는 메모리 공간은 사용자가 new 를 통해서 할당한 공간만 가능하다.
	//*/


	///* 지역 변수 delete 하기 */
	//// int a = 5;
	//// delete &a; // Heap이 아닌 공간을 해제하려고 한다는 경고 메시지가 팝업된다.


	///* new 로 배열 할당하기 */

	///*
	//int arr_size;

	//std::cout << "array size : ";

	//std::cin >> arr_size;

	//int *list = new int[arr_size]; // list 에 new 를 이용하여 크기가 arr_size인 int 배열을 생성.

	//// T* pointer = new T[size];

	//for (int i = 0; i < arr_size; i++)
	//{
	//std::cin >> list[i];
	//}

	//for (int i = 0; i < arr_size; i++)
	//{
	//std::cout << i << "th element of list : " << list[i] << std::endl;
	//}
	//delete[] list;
	//*/

	Animal *list[10];
	int animal_num = 0;

	for (;;) {
		std::cout << "1. 동물 추가하기" << std::endl;
		std::cout << "2. 놀기 " << std::endl;
		std::cout << "3. 상태 보기 " << std::endl;

		int input;
		std::cin >> input;

		switch (input) {
			int play_with;
			case 1:
				list[animal_num] = new Animal;
				create_animal(list[animal_num]);

				animal_num++;
				break;
			case 2:
				std::cout << "누구랑 놀게? : ";
				std::cin >> play_with;

				if (play_with < animal_num) play(list[play_with]);

				break;

			case 3:
				std::cout << "누구껄 보게? : ";
				std::cin >> play_with;
				if (play_with < animal_num) show_stat(list[play_with]);
				break;
		}

		for (int i = 0; i != animal_num; i++) {
			one_day_pass(list[i]);
		}
	}

	for (int i = 0; i != animal_num; i++) {
		delete list[i];
	}

}
