/* 첨자 연산자 (Subscript Operator): operator[]
* 
* 배열에서 원소를 지정할 때 사용
* 배열의 원소를 지정할 때 [] (대괄호) 안에 넣는 수를 첨자 (subscript)라고 부른다.
* MyString 클래스에 개개의 문자에 접근하기 위해 []를 지원해야 했다.
* 이때 []를 이용해서 str[10] 과 같이 10 번째 문자에 정확하게 접근할 수 있다.
* MyString 클래스의 operator[]를 추가해보자.
* operator[] 함수는 자명하게도 인자로 몇 번째 문자인지, int 형 변수를 인덱스로 받는다.

char& operator[](const int index);

* index 로 [] 안에 들어가는 값을 받게 된다. 그리고 char& 를 인자로 리턴하는 이유ㅡㄴ
* 
* str[10] = 'c';
* 
* 와 같은 명령을 수행하기 때문에, 그 원소의 레퍼런스를 리턴하게 되는 것이다.
* 실제로 operator[] 의 구현은 아래와 같이 매우 단순하다

char& MyString::operator[](const int index) {return string_content[index];}

* 위와 같이 index 번째의 string_content 를 리턴해서, operator[]를 사용하는 사용자가,
* 이의 레퍼런스를 가질 수 있게 된다.

*/

#include <iostream>
#include <cstring>

class MyString {
	char* string_content; // 문자열 데이터를 가리키는 포인터
	int string_length;	  // 문자열 길이

	int memory_capacity;  // 현재 할당된 용량

public:
	// 문자 하나로 생성
	MyString(char c);

	// 문자열로 부터 생성
	MyString(const char* str);

	// 복사 생성자
	MyString(const MyString& str);

	~MyString();

	int length();

	void print() const;
	void println() const;

	char& operator[](const int index);
};
MyString::MyString(char c) {
	string_content = new char[1];
	string_content[0] = c;
	memory_capacity = 1;
	string_length = 1;
}

MyString::MyString(const char* str) {
	string_length = strlen(str);
	memory_capacity = string_length;
	string_content = new char[string_length];

	for (int i = 0; i != string_length; i++) string_content[i] = str[i];
}
MyString::MyString(const MyString& str) {
	string_length = str.string_length;
	string_content = new char[string_length];

	for (int i = 0; i != string_length; i++)
		string_content[i] = str.string_content[i];
}
MyString::~MyString() { delete[] string_content; }
int MyString::length() { return string_length; }
void MyString::print() const {
	for (int i = 0; i != string_length; i++) {
		std::cout << string_content[i];
	}
}
void MyString::println() const {
	for (int i = 0; i != string_length; i++) {
		std::cout << string_content[i];
	}
	std::cout << std::endl;
}

char& MyString::operator[](const int index) { return string_content[index]; }

int main() {
	MyString str("abcdef");
	str[3] = 'c';

	str.println(); // abccef
}
