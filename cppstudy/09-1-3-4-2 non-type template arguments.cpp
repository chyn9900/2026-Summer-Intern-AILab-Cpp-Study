#include <iostream>
#include <array>

/*
* array 크기 별로 함수를 만들어줘야 한다는 문제가 있다.
void print_array(const std::array<int, 5>& arr) {
	for (int i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}
*/

template<typename T>
void print_array(const T& arr) {
	for (int i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

int main() {
	/*
	// 마치 C 에서의 배열 처럼 {} 을 통해 배열을 정의할 수 있다.
	// {} 문법은 16 - 1 강에서 자세히 다루므로 여기서는 그냥 이렇게
	// 쓰면 되는구나 하고 이해하고 넘어가면 된다.
	std::array<int, 5> arr = { 1,2,3,4,5 }; // arr 은 런타임에서 동적으로 크기가 할당되는 것이 아니라, 배열처럼 컴파일 시 int 5개를 가지는 메모리를 가지고 스택에 할당된다.
	// int arr[5] = {1, 2, 3, 4, 5}; 와 동일

	// 이 배열을 함수에 전달하기 위해서 그냥 std::array 를 받는 함수를 만들면 안된다.
	// std:;array<int, 5> 자체가 하나의 타입이기 때문에

	for (int i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;


	std::array<int, 5> arr2 = { 1,2,3,4,5 };

	print_array(arr2);
	*/


	std::array<int, 5> arr = { 1, 2, 3, 4, 5 };
	std::array<int, 7> arr2 = { 1,2,3,4,5,6,7 };
	std::array<int, 3> arr3 = { 1,2,3 };

	print_array(arr);
	print_array(arr2);
	print_array(arr3);
}