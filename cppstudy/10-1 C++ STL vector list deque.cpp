// 클로드로 한 번에 cpp 파일에서 실행하면서 코드 복습할 수 있는 코드 짜주세요.

#include <iostream>
#include <vector>

template <typename T> // 암기
void print_vector(std::vector<T>& vec) {
	// 전체 벡터를 출력하기
	for (typename std::vector<T>::iterator itr = vec.begin(); itr != vec.end();
		++itr) {
		std::cout << *itr << std::endl;
	}
}

int main() {
	std::vector<int> vec;
	vec.push_back(10);	// 맨 뒤에 10 추가
	vec.push_back(20);	// 맨 뒤에 20 추가
	vec.push_back(30);	// 맨 뒤에 30 추가
	vec.push_back(40);	// 맨 뒤에 40 추가

	
	for (std::vector<int>::size_type i = 0; i < vec.size(); i++) {
		std::cout << "vec 의" << i + 1 << " 번째 원소 :: " << vec[i] << std::endl;
	}

	// 전체 벡터를 출력하기 
	for (std::vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
		std::cout << *itr << std::endl;
	}

	// int arr[4] = {10, 20, 30, 40}
	// *(arr + 2) == arr[2] == 30;
	// *(itr + 2) == vec[2] == 30;

	std::vector<int>::iterator itr = vec.begin() + 2;
	std::cout << "3 번째 원소 :: " << *itr << std::endl;

	std::cout << "처음 벡터 상태" << std::endl;
	print_vector(vec);
	std::cout << "-----------------------------------" << std::endl;

	// insert, erase : O(n)
	// vec[2] 앞에 15 추가
	vec.insert(vec.begin() + 2, 15);
	print_vector(vec);

	std::cout << "-----------------------------------" << std::endl;
	// vec[3] 제거
	vec.erase(vec.begin() + 3);
	print_vector(vec);


	// 범위 기반 for 문 (range based for loop)
	for (int elem : vec) {
		std::cout << "원소 : " << elem << std::endl;
	}
}