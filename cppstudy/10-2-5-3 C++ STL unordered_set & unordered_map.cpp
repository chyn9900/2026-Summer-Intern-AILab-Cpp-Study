#include <iostream>
#include <string>
#include <unordered_set>

template <typename K>
void print_unorderd_set(const std::unordered_set<K>& m) {
	// 셋의 모든 원소들을 출력하기
	for (const auto& elem : m) {
		std::cout << elem << std::endl;
	}
}

int main() {
	std::unordered_set<std::string> s;

	s.insert("hi");
	s.insert("my");
	s.insert("name");
	s.insert("is");
	s.insert("psi");
	s.insert("welcome");
	s.insert("to");
	s.insert("C++");

	print_unorderd_set(s);
}

/*
hi
welcome
my
name
is
psi
to
C++
*/