#include <iostream>
#include <map>
#include <string>

template <typename K, typename V>
void print_map(const std::multimap<K, V>& m) {
	// 맵의 모든 원소들을 출력하기
	for (const auto& kv : m) {
		std::cout << kv.first << " " << kv.second << std::endl;
	}
}

int main() {
	std::multimap<int, std::string> m;
	m.insert(std::make_pair(1, "hello"));
	m.insert(std::make_pair(1, "hi"));
	m.insert(std::make_pair(1, "ahihi"));
	m.insert(std::make_pair(2, "bye"));
	m.insert(std::make_pair(2, "baba"));

	print_map(m);


	// map 과 다르게, multimap 은 한 개의 키에 여러 개의 값이 대응될 수 있다.
	// 하지만 이 때문에[] 연산자를 multimap 은 사용할 수 없다.
	std::cout << "--------------------------------" << std::endl;
	std::cout << m.find(1)->second << std::endl; // 정해진 표준이 없다. 라이브러리에 따라 다르다.

	// 1 을 키로 가지는 반복자들의 시작과 끝을
	// std::pair 로 만들어서 리턴한다.
	auto range = m.equal_range(1); // 즉, begin() 과 end() 를 std::pair 로 만들어서 세트로 리턴한다.
	// 다만, first 로 시작점을 second 로 끝점 바로 뒤를 알 수 있다. 
	// 끝점 바로 뒤를 가리키는 반복자를 리턴하는 건 비어 있는 것과 처음부터 끝까지 조회할 수 있고,
	// 무한 루프에 빠지지 않기 위한 종료지점을 알 수 있기 때문이다.
	for (auto itr = range.first; itr != range.second; ++itr) {
		std::cout << itr->first << " : " << itr->second << " " << std::endl;
	// 1에 대응하는 모든 원소들을 볼 수 있다.

	}
}

/*
1 hello
1 hi
1 ahihi
2 bye
2 baba
--------------------------------
hello
1 : hello
1 : hi
1 : ahihi
*/