/* 형식 플래그 (format flage) 와 조작자(Manipulator) */

#include <iostream>
#include <string>

/*

int main() {
	int t;
	while (true) {
		std::cin.setf(std::ios_base::hex, std::ios_base::basefield); // 형식 플래그 hex: ios_base 에 선언되어 있는 단순한 상수 '값' 이다
		std::cin >> t;
		std::cout << "입력 :: " << t << std::endl;
		if (std::cin.fail()) {
			std::cout << "제대로 입력해주세요" << std::endl;
			std::cin.clear();  // 플래그를 초기화하고
							   // std::cin.ignor(100, 'n'); // 개행 문자가 나올 때까지
							   // 무시한다.
		}
		if (t == 0) break;
	}
}*/

int main() {
	int t;
	while (true) {
		std::cin >> std::hex >> t; // hex 가 cin 에서 수를 받는 방식을 바꿔버렸다.
		// hex 와 같이, 스트림을 조작하여 입력 혹은 출력 방식을 바꿔주는 함수를 조작자라고 한다.
		std::cout << "입력 :: " << t << std::endl;
		if (std::cin.fail()) {
			std::cout << "제대로 입력해주세요" << std::endl;
			std::cin.clear();			// 플래그들을 초기화하고
			std::cin.ignore(100, 'n');	// 개행문자가 나올 때까지 무시한다.
		}
		if (t == 0) break;
	}
}

/*
		형식 플래그 hex: ios_base 에 선언되어 있는 단순한 상수 '값' 이다
반면에, 조작자		hex: ios 에 정의되어 있는 '함수'이다.

*/



