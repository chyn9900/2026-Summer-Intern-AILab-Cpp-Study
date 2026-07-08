/* 타입이 아닌 템플릿 인자 (non-type template arguments) */

// 템플릿 인자로 타입만 받을 수 있는 게 아니다.

#include <iostream>

template <typename T, int num>
T add_num(T t) {
	return t + num;
}

int main() {
	int x = 3;
	std::cout << "x: " << add_num<int, 5>(x) << std::endl;
}