#pragma once

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
