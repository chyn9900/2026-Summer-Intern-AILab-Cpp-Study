#include <iostream>

int main() {

	/*
	// 변수의 정의
	int i;
	char c;
	double d;
	float f;

	int number_of_people; // OK, 인원수
	int NumberOfPeople;   // OK
	int NumberOf_People; // BAD

	double interest_rate; // OK, 이자율

	// C-style
	int arr[10]; // 원소가 10개인 정적배열
	int *parr = arr; // arr의 첫 번째 주소를 parr 포인터에 저장한다.

	int i;
	int *pi = &i; // i의 주소를 pi라는 포인터에 저장하겠다. 포인터는 주소의 변수이다.

	// Cpp-style ( same as c-style)
	int arr[10];
	int *parr = arr;

	int i;
	int *pi = &i;
	*/


	// C++의 for 문
	/*
	int i;

	for (i = 0; i < 10; i++) {
		std::cout << i << std::endl;
	}
	*/


	/* 1부터 10까지의 합*/

	/*
	int i, sum = 0;

	for (i = 1; i <= 10; i++)
	{
		sum += i;
	}
	std::cout << sum << std::endl;
	*/

	/* 변수는 변수 사용 직전에 선언해도 된다. */
	/*
	int sum = 0;

	for (int i = 0; i <= 10; i++)
	{
		sum += i;
	}

	std::cout << sum << std::endl;
	*/

	/* while 문 이용하기 */
	/*
	int i = 1, sum = 0;

	while (i <= 10) {
		sum += i;
		i++;
	}

	std::cout << sum << std::endl;
	*/

	/* 행운의 숫자 맞추기 */
	/*
	int lucky_number = 3;
	std::cout << "내 비밀 수를 맞추어 보세요~" << std::endl;

	int user_input; // 사용자 입력

	while (1) {
		std::cout << "입력 : ";
		std::cin >> user_input;
		if (lucky_number == user_input) {
			std::cout << "맞추셨습니다~~" << std::endl;
			break;
		}
		else
		{
			std::cout << "다시 생각해보세요~" << std::endl;
		}
	}
	*/

	// switch 문 이용하기

	using std::cout;
	using std::cin;
	using std::endl;

	int user_input;
	cout << "저의 정보를 표시해줍니다" << endl;
	cout << "1. 이름" << endl;
	cout << "2. 나이" << endl;
	cout << "3. 성별" << endl;
	cin >> user_input;

	switch (user_input) {
	case 1:
		cout << "Psi !" << endl;
		break;

	case 2:
		cout << "99 살" << endl;

	case 3:
		cout << "남자" << endl;
		break;

	default:
		cout << "궁금한게 없군요~" << endl;
		break;
	}

	return 0;
}