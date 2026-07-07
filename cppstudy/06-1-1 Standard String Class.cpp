#include <iostream>
#include <string>

int main() {
	// 표준이므로 std 안에 string 이 정의되어 있다.
	std::string s = "abc"; // string 클래스의 인자를 const char * 로 받는 생성자를 호출
	std::string t = "def";
	std::string s2 = s;

	std::cout << s << " 의 길이 : " << s.length() << std::endl;
	std::cout << s << " 뒤에 " << t << " 를 붙이면 : " << s + t << std::endl; // 연산자 오버로딩을 사용해서 + 연산자가 실제로 문자열을 결합시키는 함수로 사용되고 있다.

	if (s == s2) { // == 연산자 오버로딩
		std::cout << s << " 와 " << s2 << " 는 같다 " << std::endl;
	}
	if (s != t) { // != 연산자 오버로딩 , >=, <= 등 크기비교도 가능
		std::cout << s << " 와 " << t << " 는 다르다 " << std::endl;
	}
	// 표준 문자열 std::string 에는 length 함수 말고도, 문자열 사이에 문자열을 삽입하는 insert 함수나,
	// 특정 위치를 지우는 erase 나 문자열을 치환하는 replace 등등 수많은 유용한 함수들이 많다.

	return 0;
}