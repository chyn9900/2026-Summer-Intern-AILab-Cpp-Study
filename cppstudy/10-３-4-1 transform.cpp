#include<algorithm>
#include<functional>
#include<vector>
#include<string>
#include<iostream>

template<typename Iter>
void print(Iter begin, Iter end) {
	while (begin != end) {
		std::cout << "[" << *begin << "] ";
		begin++;
	}
	std::cout << std::endl;
}

int main() {
	std::vector<int> vec;
	vec.push_back(5);
	vec.push_back(3);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);

	std::cout << "처음 vec 상태 ------" << std::endl;
	print(vec.begin(), vec.end());

	std::cout << "벡터 전체에 1 을 더한다" << std::endl;
	std::transform(vec.begin(), vec.end(), vec.begin(),
		[](int i) {return i + 1; });
	print(vec.begin(), vec.end());
}
/*
처음 vec 상태 ------
[5] [3] [1] [2] [3] [4]
벡터 전체에 1 을 더한다
[6] [4] [2] [3] [4] [5]
*/