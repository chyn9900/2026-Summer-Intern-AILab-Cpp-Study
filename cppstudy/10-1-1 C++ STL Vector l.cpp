#include <iostream>
#include <vector>

template <typename T>
void print_vector(const std::vector<T>& vec) {
    std::cout << "[ ";
    for (const auto& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << "]\n";
}

int main() {

    std::cout << "===== 1. vector 기본 사용 =====\n";
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);

    print_vector(vec);

    std::cout << "\n===== 2. iterator 기본 사용 =====\n";
    for (std::vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
        std::cout << *itr << "\n";
    }

    std::vector<int>::iterator itr = vec.begin() + 2;
    std::cout << "vec[2] = " << *itr << "\n";

    std::cout << "\n===== 3. insert / erase =====\n";
    vec.insert(vec.begin() + 2, 15);   // 30 앞에 15 삽입
    print_vector(vec);

    vec.erase(vec.begin() + 3);        // 30 제거
    print_vector(vec);

    std::cout << "\n===== 4. erase 반복 시 주의점 =====\n";
    std::vector<int> vec2 = { 10, 20, 30, 20, 40 };
    print_vector(vec2);

    for (std::vector<int>::size_type i = 0; i < vec2.size(); ++i) {
        if (vec2[i] == 20) {
            vec2.erase(vec2.begin() + i);
            i--; // erase 후 인덱스 조정
        }
    }
    print_vector(vec2);

    std::cout << "\n===== 5. const_iterator =====\n";
    std::vector<int>::const_iterator citr = vec.begin();
    std::cout << "첫 원소(읽기 전용) = " << *citr << "\n";
    // *citr = 50;  // 컴파일 오류: const_iterator는 수정 불가

    std::cout << "\n===== 6. reverse_iterator =====\n";
    for (std::vector<int>::reverse_iterator ritr = vec.rbegin();
        ritr != vec.rend(); ++ritr) {
        std::cout << *ritr << "\n";
    }

    std::cout << "\n===== 7. range-based for =====\n";
    for (const auto& elem : vec) {
        std::cout << elem << "\n";
    }

    std::cout << "\n===== 복습 완료 =====\n";
    return 0;
}
