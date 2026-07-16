#include <algorithm>
#include <iostream>
#include <vector>

template <typename Iter>
void print(Iter begin, Iter end) {
	while (begin != end) {
		std::cout << *begin << " ";
		begin++;
	}
	std::cout << std::endl;
}

int main() {
	std::vector<int> vec;
	vec.push_back(5);
	vec.push_back(3);
	vec.push_back(1);
	vec.push_back(6);
	vec.push_back(4);
	vec.push_back(7);
	vec.push_back(2);

	std::cout << "정렬 전 ----" << std::endl;
	print(vec.begin(), vec.end());

	// sort 함수는 정렬한 원소의 시작 위치와, 마지막 위치 바로 뒤를 반복자로 받는다.
	std::sort(vec.begin(), vec.end()); 

	std::cout << "정렬 후 ----" << std::endl;
	print(vec.begin(), vec.end());
}