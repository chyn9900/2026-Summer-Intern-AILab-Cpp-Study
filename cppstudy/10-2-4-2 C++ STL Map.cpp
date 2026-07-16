// Map 은 중복을 허용하지 않는다. 
#include <iostream>
#include <map>
#include <string>

template <typename K, typename V>
void print_map(const std::map<K, V>& m) {
	// kv 에는 맵의 key 와 value 가 std::pair 로 들어간다.
	for (const auto& kv : m) {
		std::cout << kv.first << " " << kv.second << std::endl;
	}
}

int main() {
	std::map < std::string, double> pitcher_list;

	// 맵의 insert 함수는 std::pair 객체를 인자로 받습니다.
	pitcher_list.insert(std::pair<std::string, double>("박세웅", 2.23));
	pitcher_list.insert(std::pair<std::string, double>("박세웅", 2.93));

	print_map(pitcher_list);

	// 2.23 이 나올까 2.93 이 나올까?
	std::cout << "박세웅의 방어율은? :: " << pitcher_list["박세웅"] << std::endl;
}

/*
박세웅 2.23
박세웅의 방어율은? :: 2.23

먼저 insert 된 원소가 나온다. 즉, 이미 같은 키를 가지는 원소가 있다면 그 insert 작업은 무시된다.
만약에, 원소에 대응되는 값을 바꾸고 싶다면 insert 를 하지 말고, [] 연산자로 대응되는 값을 바꿔준다.
*/