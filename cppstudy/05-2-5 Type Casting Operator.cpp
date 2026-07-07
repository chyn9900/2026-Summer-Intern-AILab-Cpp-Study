/* int Wrapper 클래스 - 타입 변환 연산자 (Type Casting operator) 
* Wrapper 는 흔히 음식을 포장할 때 '랩(Wrap)으로 싼다' 라고 하는 것처럼
* '포장지' 라는 의미의 단어이다.
* 즉 Wrapper 클래스는 무언가를 포장하는 클래스라는 의미이다.
* C++ 프로그래밍을 할 때 어떤 경우에 기본 자료형들을 객체로써 다루어야 할 때가 있다.
* 이럴 때, 기본 자료형들 (int, float 등등)을 클래스로 포장해서 각각의 자료형을 객체로 사용하는 것을 Wrapper 클래스를 이용한다고 한다.
*/

// 즉, int 자료형을 감싸는 int Wrapper 클래스 Int 는 다음과 같이 구성할 수 있다.

/*
class Int {
	int data;
	// some other data;

public:
	Int(int data) : data(data) {}
	Int(const Int& i) : data(i.data) {}
};
*/

/* 위 Int 클래스에 int 형 자료형을 보관하는 data 라는 변수를 정의해 놓았는데,
* 이렇게 한다면 int 형 데이터를 저장하는 객체로 Int 클래스를 사용할 수 있을 것이다.
* 우리는 이 Int 객체가 int 의 Wrapper 클래스의 객체인 만큼, int 와 정확히 똑같이 작동하도록 만들고 싶다.
* 다시 말해 다음과 같은 명령을 내려도 아무 하자 없이 잘 실행되도록 말이다.

Int x = 3;		// Wrapper 객체
int a = x + 4; // 그냥 평범함 int 형 변수 a

이를 잘 수행하기 위해서라면, 연산자 오버로딩을 열심히 배워온 우리 생각이라면,
int 변수에 사용되는 모든 연산자 함수들을 만들어주면 되겠군!

이라고 생각이 들것이다. 물론 이렇게 해도 잘 작동하는 Wrapper 클래스를 만들 수 있을 것이다.
하지만, 그 수많은 연산자들을 일일히 오버로딩하는 것은 정말로 고통스러운 일이다.

Complex 클래스를 만들 때, Complex 객체에서 + 나 - 연산자가 하는 일 자체가 int 변수끼리 하는 일과 완전히 달라서
operator+, operator- 등을 만들어줘야 했다.

하지만 이 int Wrapper 클래스 객체끼리 하는 일은 그냥 단순히 int 형 변수끼리 하는 일과 정확히 똑같기 때문에
굳이 이미 제공하는 기능을 다시 만들어야 하는 비효율이 있다.

그렇다면, 그냥 이 Wrapper 클래스의 객체를 마치 'int 형 변수'라고 컴파일러가 생각하게 할 순 없을까?
가능하다. 왜냐하면 우리에게는 타입 변환 연산자가 있기 때문이다.
만약 컴파일러가 이 Wrapper 클래스의 객체를 int 형 변수로 변환할 수 있다면, 비록 operator+ 등을 정의하지 않더라도
컴파일러가 이 객체를 int 형 변수로 변환한 다음에 +를 수행할 수 있기 대문이다.

타입 변환 연산자는 다음과 같이 정의한다
operator (변환하고자 하는 타입) ()

예를 들어, 우리의 int Wrapper 클래스의 경우 다음과 같은 타입 변환 연산자를 정의할 수 있다.

operator int()

한 가지 주의할 점은, 생성자처럼 함수의 리턴 타입을 써주면 안된다.
그렇게 되면, int 변환 연산자는 다음과 같이 같단하게 구성할 수 있다.

operator int() {return data;}

그냥 단순히 data를 리턴해주면 된다. 그러면 Wrapper 클래스의 객체를 '읽는' 데에는 아무런 문제가 없다.
왜냐하면 컴파일러 입장에서 적절한 변환 연산자로 operator int 를 찾아서 결국 int 로 변환해서 처리하기 때문이다.

다만 문제는 '대입'시에 발생하는데, 다행이도 디폴트 대입 연산자가 이 역시 알아서 잘 처리한다.
*/

#include<iostream>

class Int {
	int data;
	// some other data;

public:
	Int(int data) : data(data) {}
	Int(const Int& i) : data(i.data) {}

	operator int() { return data; } // 문법상 생성자처럼, 리턴 타입을 써주지 않는다
};
int main() {
	Int x = 3;
	int a = x + 4;

	x = a * 2 + x + 4;
	std::cout << x << std::endl; // Int 객체가 int 변수처럼 정확히 동일하게 작동되고 있다.

	return 0;
}