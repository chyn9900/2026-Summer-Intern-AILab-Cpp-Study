#include <iostream>

int change_val(int *p) { // change_val 함수의 인자(매개변수) 포인터 *p에 number의 주소값을 전달하여, 
	*p = 3; // *p를 (de-referencing) 통해 number를 참조(변경)하여 number의 값을 3으로 바꾸었다.

	return 0;
}

int change_val_ref(int &p) {
	p = 3; // 함수의 인자가 포인터일 때와 다르게 & 연산자를 붙일 필요가 없다.

	return 0;
}

int function() {
	int a = 2;
	return a;
}

// 지역 변수의 레퍼런스를 리턴할 수 있는가? => 없다.
int& function_ref() {
	int a = 2;
	return a;
}// function_ref의 리턴 타입은 int& 이다. 따라서 참조자를 리턴하게 된다.
// 그런데 문제는 리턴하는 function 안에 정의되어 있는 a 는 함수의 리턴과 함께 사라진다는 점이다.


// 외부 변수의 레퍼런스를 리턴
int& function_ref_external(int& a) {
	a = 5;
	return a;
} // 인자로 받은 레퍼런스를 그대로 리턴

/* 참조자가 아닌 값을 리턴하는 함수를 참조자로 받기 */
int function_reference() {
	int a = 6;
	return a;
}


/* 함수의 리턴값을 참조자로 받아도 컴파일이 되는 예외 경우 */
int function_final() {
	int a = 5;
	return a;
}

int main() {

	/*
	int number = 5;

	std::cout << number << std::endl; // 5
	change_val(&number);
	std::cout << number << std::endl; // 3
	*/

	// C 언어에서는 어떠한 변수를 가리키고 싶을 땐 포인터를 사용해야 했다.
	// 그런데 C++에서는 다른 변수나 상수를 가리키는 참조자(레퍼런스-reference)가 있다.
	
	/*
	int a = 3;
	int& another_a = a; // another_a는 a의 참조자다!, another_a 는 a의 또 다른 이름이라고 컴파일러에게 알려주는 것.
	// 따라서 another_a 에서 어떠한 작업을 수행하던 사실상 a에 그 작업을 하는 것과 마찬가지이다.

	another_a = 5;
	std::cout << "a : " << a << std::endl;
	std::cout << "another_a : " << another_a << std::endl;
	*/

	// 참조자(레퍼런스)와 포인터는 상당히 유사한 개념이다. 
	// 포인터 역시 다른 어떤 변수의 주소값을 보관함으로써 해당 변수에 간접적인 연산을 수행할 수 있기 때문이다.
	// 하지만 포인터와 레퍼런스는 몇 가지 중요한 차이점이 있다.

	/*
	레퍼런스는 int& another_a = a와 같이 반드시 처음에 누구의 별명이 될 것인지 지정해야 한다. 따라서
	int& another_a;
	와 같은 문장은 불가능하다. 
	
	반면에 포인터의 경우
	int* p
	는 전혀 문제가 없는 코드이다. 포인터는 레퍼런스와 달리, 
	누구의 포인터인지 지정해주지 않아도 되고, 포인터 타입을 선언해주면 된다.
	*/

	/*
	또한, 레퍼런스가 한 번 별명이 되면 절대로 다른 이의 별명이 될 수 없다.
	레퍼런스의 또 한 가지 중요한 특징으로 한 번 어떤 변수의 참조자가 되버린다면, 더이상 다른 변수를 참조할 수 없게 된다.
	*/

	/*
	int a = 10;
	int &another_a = a; // another_a는 a의 참조자인데,

	int b = 3;
	another_a = b; // ??
	*/

	// another_a 는 a의 또다른 이름이므로, a = b 와 동일한 표현이다.

	// 참고로 &another_a = b; 는 &a = b; 이므로 말이 안되는 코드이다.

	// 반면 포인터를 보자.
	
	/*
	
	int a = 10;
	int* p = &a; // p는 a를 가리킨다.

	int b = 3;
	p = &b; // 이제 p 는 a 를 버리고 b 를 가리킨다.

	// 위와 같이, 포인터는 누구를 가리키는지 자유롭게 바꿀 수 있다.

	// 레퍼런스는 메모리 상에 존재하지 않을 수도 있다.

	// 포인터의 경우, 아래와 같이 포인터 p를 정의한다면,

	int a = 10;
	int* p = &a; // 포인터 p 는 메모리 상에서 8 바이트를 차지하게 된다. (32 bit 시스템에선 4 byte)

	*/

	int a = 10;
	int &another_a = a; // another_a 가 자리를 차지할 필요가 있을까?

	// 만약 내가 컴파일러라면 another_a 를 위해서 메모리 상에 공간을 할당할 필요가 있을까?
	// 아니다. 왜냐하면 another_a 가 쓰이는 자리 모두 a로 바꿔치기 하면 되기 때문이다.
	// 따라서 이 경우 레퍼런스는 메모리 상에 존재하지 않게 된다.
	// 물론, 항상 존재하지 않는 것은 아니다.

	// 함수 인자로 레퍼런스 받기

	int number = 5;

	std::cout << number << std::endl; // 5
	change_val_ref(number); // 함수 안에서 &p = number로 p가 number의 또 다른 이름이 된다.
	std::cout << number << std::endl; // 3

	int x;
	int& y = x; // y의 또 다른 이름이 x야.
	int& z = y; // z의 또 다른 이름이 y야.


	// 여러가지 참조자 예시들
	x = 1;
	std::cout << "x : " << x << " y : " << y << " z : " << z << std::endl; //x : 1 y : 1 z : 1
	
	y = 2;
	std::cout << "x : " << x << " y : " << y << " z : " << z << std::endl; //x : 2 y : 2 z : 2

	z = 3;
	std::cout << "x : " << x << " y : " << y << " z : " << z << std::endl; //x : 3 y : 3 z : 3

	// 상수에 대한 참조자
	/*
	int &ref = 4; 

	std::cout << ref << std::endl;

	error C2440: 'initializing' : cannot convert from 'int' to 'int &'
	
	'4'라는 상수값은 literal이기 때문. 리터럴(literal)이란, 소스 코드 상에서 고정된 값을 가지는 것.

	특히 C 언어의 경우 큰 따옴표 (")로 묶인 것들을 문자열 리터럴(string literal) 이라 부릅니다.

	char *pstr = "goodbye";
	printf("why so serious?");
	scanf("%c", str[0]);

	위 문장에서 goodbye, why so serious?, %c는 모두 리터럴이 된다.

	*/

	// 상수 참조자로 선언한다면 리터럴도 참조할 수 있다.
	
	/*
	const int &ref = 4;

	int a = ref; // int a = 4;
	*/

	// 레퍼런스의 배열과 배열의 레퍼런스

	// 먼저 레퍼런스의 배열이 과연 가능할까?
	// 레퍼런스는 반드시 정의와 함께 초기화를 해주어야 한다고 했다.

	/*
	* 레퍼런스의 배열
	int a, b;
	int& arr[2] = { a, b }; -> arr[0] = a , arr[1] = b ??
	
	error C2234: 'arr' : arrays of reference are illegal
				 'arr': 참조 배열이 잘못되었습니다.

	C++ 8.3.2/4
	There shall be no references to references, no arrays of references, and no pointers to references
	레퍼런스의 레퍼런스, 레퍼런스의 배열, 레퍼런스의 포인터는 존재할 수 없다.

	C++ 상 배열이 처리 되는 방식
	문법 상 배열의 이름은 (arr) 첫 번째 원소의 주소값으로 변환이 될 수 있어야 한다.
	이 때문에 arr[1] 과 같은 문장이 *(arr + 1)로 바뀌어서 처리될 수 있다. (arr가 &arr[0]을 의미하기 때문)

	그런데 주소값이 존재한다는 의미는 해당 원소가 메모리 상에서 존재한다는 의미와 같다.
	하지만 레퍼런스는 특별한 경우가 아닌 메모리 상에서 공간을 차지하지 않는다.
	따라서 이러한 모순 때문에 레퍼런스들의 배열을 정의하는 것은 언어 차원에서 금지가 되어 있다.

	그렇다고 해서 그와 반대인 배열들의 레퍼런스가 불가능한 것은 아니다.
	*/

	// 배열들의 레퍼런스
	// 포인터와 다르게 배열의 레퍼런스의 경우 참조하기 위해선 반드시 배열의 크기를 명시해야 한다.
	/*
	int arr[3] = { 1,2,3 };
	int(&ref)[3] = arr;

	ref[0] = 2; // ref[0] = arr[0]
	ref[1] = 3; // ref[1] = arr[1]
	ref[2] = 1; // ref[2] = arr[2]

	std::cout << arr[0] << arr[1] << arr[2] << std::endl; // 231
	*/

	// ex)
	// int (&ref)[3] 이라면 반드시 크기가 3인 int 배열의 별명이 되어야 하고,
	// int (&ref)[5] 이라면 반드시 크기가 5인 int 배열의 별명이 되어야 한다.

	/*
	// 이차원 배열도 일차원 배열과 동일.
	int arr[3][2] = { 1,2,3,4,5,6 };
	int(&ref)[3][2] = arr;

	std::cout << ref[0][0] << std::endl; // 1
	std::cout << ref[0][1] << std::endl; // 2
	std::cout << ref[0][2] << std::endl; // 3
	*/

	/*
	// 레퍼런스를 리턴하는 함수
	int b = function(); // b = a  (function() 함수 안에서 int a = 2  )

	std::cout << b << std::endl; // 2

	// function 안에 정의된 a 라는 변수의 값이 b에 "복사"되었다.
	// function이 종료되고 나면 a 는 메모리에서 삭제된다.
	// 따라서 main 안에서는 a를 불러올 수 없다.
	// main에서 쓸 수 없는 변수 a의 값을 함수를 호출하여 main 안에서 사용했다.
	*/
	
	/*
	// 지역변수의 레퍼런스를 리턴?
	int b = function_ref(); // int& ref = a; 근데 a가 사라짐.
	// int b = ref; 와 같은 의미인데, function_ref() 이 레퍼런스를 리턴하면서 원래 참조하고 있던 변수가 이미 사라져버렸으므로 오류가 발생.
	// 쉽게 말해 본체는 이미 사라졌지만, 별명만 남아 있는 상황이다.

	// 이와 같이 레퍼런스는 있는데 원래 참조하던 것이 사라진 레퍼런스를 댕글링 레퍼런스 (Dangling reference)라고 부른다.
	// Dangling이란 단어의 원래 뜻은 약하게 결합되어서 달랑달랑 거리는 것을 뜻하는데,
	// 레퍼런스가 참조해야 할 변수가 사라져서 혼자만 덩그러이 남아 있는 상황과 유사하다고 보면 된다.

	// 따라서 위 처럼 "레퍼런스를 리턴하는 함수에서 지역 변수의 레퍼런스를 리턴"하지 않도록 조심해야 한다.
	b = 3;

	std::cout << b << std::endl;
	*/


	/* 외부 변수의 레퍼런스를 리턴 */
	// int b = 2;
	// int c = function_ref_external(b); // function_ref_external의 a는 main의 b를 참조하고 있게 된다
	// function이 리턴한 참조자는 아직 살아있는 변수인 b를 계속 참조한다.

	// std::cout << c << std::endl; // 5
	// 참조자를 리턴하는 경우 장점은 C 언어에서 엄청나게 큰 구조체가 있을 때
	// 해당 구조체 변수를 그냥 리턴하면 전체 복사가 발생해야 해서 시간이 오래걸리지만, 
	// 해당 구조체를 가리키는 포인터를 리턴한다면 그냥 포인터 주소 한번 복사로 매우 빠르게 끝난다.

	// 마찬가지로 레퍼런스를 리턴하게 된다면 레퍼런스가 참조하는 타입의 크기와 상관없이 딱 한 번의 주소값 복사로
	// 전달이 끝나게 되어 매우 효율적이다.


	/* 참조자가 아닌 값을 리턴하는 함수를 참조자로 받기 */
	// int& c = function_reference(); // Compile Error

	// E0451 비const 참조에 대한 초기값은 lvalue여야 합니다.
	// C2040 'c': 'int &'의 간접 참조 수준이 'int'과(와) 다릅니다.
	// 상수가 아닌 레퍼런스가 function_reference 함수의 리턴값을 참조할 수 없다는 의미.

	// 함수의 리턴값은 해당 문장이 끝난 후 바로 사라지는 값이기 때문에, 
	// 참조자를 만들게 되면 바로 다음에 댕글링 레퍼런스가 되어 안된다.


	/* 함수의 리턴값을 참조자로 받아도 컴파일이 되는 예외 경우 */
	const int& c = function_final();
	std::cout << "c : " << c << std::endl; // 5

	// function_final() 의 리턴값을 참조자로 받았다.
	// const 참조자로 받았더니 문제없이 컴파일 되었다.
	// 심지어 리턴값도 제대로 출력된다.

	// 원칙상 함수의 리턴값은 해당 문장이 끝나면 소멸되는 것이 정상이다. 
	// 따라서 기존에 int& 로 받았을 때에는 컴파일 자체가 안 되었다.
	// 하지만 예외적으로 상수 레퍼런스로 리턴값을 받게 되면 해당 리턴값의 생명이 연장된다.
	// 그리고 그 연장되는 기간은 레퍼런스가 사라질 때까지이다.

	/*							함수에서 값 리턴 (int f())				함수에서 참조자 리턴(int& f())
	
	값 타입으로 받음					 값 복사됨						값 복사됨, 다만 지역 변수의 레퍼런스를
	(int a = f())														리턴하지 않도록 주의
	
	
	참조자 타입으로 받음				컴파일 오류						가능, 다만 마찬가지로 지역 변수의 레퍼런스를
	(int& a = f())														리턴하지 않도록 주의


	상수 참조자 타입으로 받음			    가능						가능, 다만 마찬가지로 지역 변수의 레퍼런스를
	(const int& a = f())												리턴하지 않도록 주의
	
	
	*/
	
	return 0;

}