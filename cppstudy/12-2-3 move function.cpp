#include <iostream>
#include <cstring>

class MyString {
	char* string_content;
	int string_length;

	int memory_capacity;

public:
	MyString();

	MyString(const char* str);

	MyString(const MyString& str);

	MyString(MyString&& str);

	MyString& operator=(const MyString& s);

	MyString& operator=(MyString&& s);

	~MyString();

	int length() const;

	void println();
};

MyString::MyString() {
	std::cout << "생성자 호출 ! " << std::endl;
	string_length = 0;
	memory_capacity = 0;
	string_content = NULL;
}

MyString::MyString(const char* str) {
	std::cout << "생성자 호출 ! " << std::endl;
	string_length = strlen(str);
	memory_capacity = string_length;
	string_content = new char[string_length];

	for (int i = 0; i != string_length; i++) string_content[i] = str[i];
}
MyString::MyString(const MyString& str) {
	std::cout << "복사 생성자 호출 ! " << std::endl;
	string_length = str.string_length;
	string_content = new char[string_length];

	for (int i = 0; i != string_length; i++)
		string_content[i] = str.string_content[i];
}
MyString::MyString(MyString&& str) {
	std::cout << "이동 생성자 호출 ! " << std::endl;
	string_length = str.string_length;
	string_content = str.string_content;
	memory_capacity = str.memory_capacity;

	// 임시 객체 소멸 시에 메모리를 해제하지 못하게 한다.
	str.string_content = nullptr;
	str.string_length = 0;
	str.memory_capacity = 0;
}
MyString::~MyString() {
	if (string_content) delete[] string_content;
}
MyString& MyString::operator=(const MyString& s) {
	std::cout << "복사!" << std::endl;
	if (s.string_length > memory_capacity) {
		delete[] string_content;
		string_content = new char[s.string_length];
		memory_capacity = s.string_length;
	}
	string_length = s.string_length;
	for (int i = 0; i != string_length; i++) {
		string_content[i] = s.string_content[i];
	}

	return *this;
}
MyString& MyString::operator=(MyString&& s) {
	std::cout << "이동!" << std::endl;
	string_content = s.string_content;
	memory_capacity = s.memory_capacity;
	string_length = s.string_length;

	s.string_content = nullptr;
	s.memory_capacity = 0;
	s.string_length = 0;
	return *this;
}
int MyString::length() const { return string_length; }
void MyString::println() {
	for (int i = 0; i != string_length; i++) std::cout << string_content[i];

	std::cout << std::endl;
}

template <typename T>
void my_swap(T& a, T& b) {
	T tmp(std::move(a));
	a = std::move(b);
	b = std::move(tmp);
}

int main() {
	MyString str1("abc");
	MyString str2("def");
	std::cout << "Swap 전 ----" << std::endl;
	std::cout << "str1 : ";
	str1.println();
	std::cout << "str2 : ";
	str2.println();

	std::cout << "Swap 후 ----" << std::endl;
	my_swap(str1, str2);
	std::cout << "str1 : ";
	str1.println();
	std::cout << "str2 : ";
	str2.println();
}

/*
생성자 호출 !
생성자 호출 !
Swap 전 ----
str1 : abc
str2 : def
Swap 후 ----
이동 생성자 호출 !
이동!
이동!
str1 : def
str2 : abc
*/