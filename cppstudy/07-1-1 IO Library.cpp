/* C++ 입출력 라이브러리 
1. ios_bsee 클래스: 스트림의 입출력 형식 관련 데이터 처리. 예를 들어 실수형을 출력할 때 정밀도를 어떻게 할지, 정수형을 출력할 떄, 10진수로 할지 16진수로 할 지 등을 처리
2. ios 클래스: 스트림 버퍼 초기화, 스트림 버퍼란, 데이터를 내보내거나 받아들이기 전에 임시로 저장하는 곳
=> 클래스들이 입출력 작업을 위해 바탕을 깔아주는 클래스
*/
/* istream 클래스  => 실제로 입력을 수행하는 클래스 

*/

#include<iostream>
#include<string>

int main() {
	int t;
	while (true) {
		std::cin >> t;
		std::cout << "입력 :: " << t << std::endl;
		if (std::cin.fail()) {
			std::cout << "제대로 입력해주세요" << std::endl;
			std::cin.clear();			// 플래그들을 초기화 하고
			std::cin.ignore(100, '\n');	// 개행문자가 나올 때까지 무시한다.
		}
	}
}


/*
	std::string s;
	while (true) {
		std::cin >> s;
		std::cout << "word : " << s << std::endl;

		this is a long sentence
			word : this
			word : is
			word : a
			word : long
			word : sentence
			ABCD EFGH IJKL
			word : ABCD
			word : EFGH
			word : IJKL
*/
/*
	int t;
	while (true) {
		std::cin >> t;
		std::cout << "입력 :: " << t << std::endl;
		if (t == 0) break;
	}
*/

/*
	int t;
		while (std::cin >> t) {
			std::cout << "입력 :: " << std::endl;
			if (t == 0) break;
		}
*/