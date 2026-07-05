#include<iostream>
#include "header1.h"
#include "header2.h"

namespace header1 {
	int func() {
		foo(); // 알아서 header1::foo() 가 실행된다. 
		header2::foo(); // header2::foo() 가 실행된다.
	}
} // namespace header1

int func() {
	header1::foo(); // header1 이란 이름 공간에 있는 foo 를 호출
}

using namespace header1;
int main() {
	foo(); // header1 에 있는 함수를 호출
	bar(); // header1 에 있는 함수를 호출
	header2::foo(); // header2에 있는 함수를 호출
}

// 이름없는 이름공간
namespace {
// 이 함수는 이 파일 안에서만 사용할 수 있습니다.
// 이는 마치 static int OnlyInThisFile() 과 동일합니다.
	int OnlyInThisFile() {}

// 이 변수 역시 static int x 와 동일합니다.
	int only_in_this_fiel = 0;
} // namespace


int main() 
{
	// std::cout << "Hello, World!!" << std::endl;

	std::cout << "hi" << std::endl
		<< "my name is "
		<< "Psi" << std::endl;

	return 0;
}

/*
주의사항

using namespace std; 와 같이 어떠한 이름 공간을 사용하겠다고 선언하는 것은 권장하지 않는다.
왜냐하면 std에 이름이 겹치는 함수를 만들게 된다면, 오류가 발생하기 때문이다.

std이라는 이름 공간에 같은 이름의 함수가 쓰이면 어떤 이름공간의 함수인지 식별하기가 어렵다.
그래서 어떤 이름 공간에 있는 함수인지 알기 위해 명시적으로 이름공간을 써주는게 좋다.

ex) std::cout, std::endl, ...

std라는 이름공간에 있는 cout이라는 함수를 호출해줘.
std라는 이름공간에 있는 endl이라는 함수를 호출해줘.

게다가 C++ 표준 라이브러리는 매우 매우 거대하므로, 정말 수많은 함수들이 존재하고 있다.
함수 이름을 겹치게 사용하면 시간을 매우 허비하게 된다. 게다가 std 이름 공간에는 매번 수많은 함수들이 추가되고 있기 때문에
C++ 버전이 바뀔 때마다 기존에 잘 작동하던 코드가 이름공간에 같은 이름의 함수로 인해 충돌하여 동작하지 않게 되는 경우가 있다.

따라서 권장하는 방식은 using namespace std; 같은 것은 사용하지 않고,
std::를 직접 앞에 붙여 std의 이름공간의 함수이다 라고 명시해주는 것이 좋다.
또한, 우리가 작성하는 코드는 우리만의 이름 공간에 넣어서 혹시 모를 이름 충돌로부터 보호하는 것이 중요하다.

*/