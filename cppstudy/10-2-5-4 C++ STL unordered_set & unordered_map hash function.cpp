#include <iostream>
#include <string>
#include <unordered_set>

template <typename K>
void print_unordered_set(const std::unordered_set<K>& m) {
	// 셋의 모든 원소들을 출력하기
	for (const auto& elem : m) {
		std::cout << elem << std::endl;
	}
}
// find 함수는 해당하는 원소가 존재하면 이를 카리키는 반복자를, 없다면 end 를 리턴한다.
template <typename K>
void is_exist(std::unordered_set<K>& s, K key) {
	auto itr = s.find(key);
	if (itr != s.end()) {
		std::cout << key << " 가 존재!" << std::endl;
	}
	else {
		std::cout << key << " 가 없다" << std::endl;
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
	s.insert("c++");

	print_unordered_set(s);
	std::cout << "-------------------" << std::endl;	
	is_exist(s, std::string("c++"));
	is_exist(s, std::string("c"));

	std::cout << "-------------------" << std::endl;
	std::cout << "'hi' 를 삭제" << std::endl;
	s.erase(s.find("hi")); // unordered_set 과 unordered_map 모두 find 함수를 지원한다.
	// 또한, 원소를 제거하고 싶다면 find 함수로 원소를 가리키는 반복자를 찾은 뒤에, 이를 전달한다.
	is_exist(s, std::string("hi"));
}

/* unordered_set 으로 순서가 랜덤이다.
hi
welcome
my
name
is
psi
to
c++
-------------------
c++ 가 존재!
c 가 없다
-------------------
'hi' 를 삭제
hi 가 없다
*/