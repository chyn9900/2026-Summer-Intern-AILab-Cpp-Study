/* friend keyword */
/*
friend 키워드는 클래스 내부에서 다른 클래스나 함수들을 friend 로 정의할 수 있는데,
friend 로 정의된 클래스나 함수들은 원래 클래스의 private 로 정의된 변수나 함수들에 접근할 수 있다.
*/
class A {
	// 원래 클래스의 변수와 함수를 정의
	int private_num;
	void private_func() {}

	// B 는 A 의 친구! : 1. class A인 원래 클래스에서 다른 클래스를 friend 로 정의
	friend class B;

	// func 은 A 의 친구! : 2. .class A인 원래 클래스 다른 함수를 friend 로 정의
	friend void func();
};

// 1. 클래스 안에 있는 다른 클래스가 원래 클래스의 변수나 함수를 접근하는 예시
class B {
// 짝사랑 관계: B 안에서 A 를 friend 로 지정하지 않는다면, A 는 B 의 private 변수나 함수에 접근할 수 없다.
public:
	void b() {
		A a; // 클래스 A 의 객체(인스턴스) a 선언

		
		// 비록 private 함수의 필드들의 함수와 변수들이지만 친구이기 때문에 접근 가능하다.
		a.private_num = 2;
		a.private_func();
	}
};
// 2. 클래스 안에 있는 다른 함수가 원래 클래스의 변수나 함수를 접근하는 예시
void func() {
	A a;

	// class A인 원래 클래스에서 private 필드 영역이지만,
	// class B와 void func()은 friend 이기 때문에 
	// 원래 클래스인 class A 의 변수와 함수에 접근 가능하다.

	a.private_num = 2;
	a.private_func();	 
}

int main() {}