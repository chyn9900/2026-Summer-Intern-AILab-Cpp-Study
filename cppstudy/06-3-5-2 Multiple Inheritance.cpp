/* 다중 상속시 주의할 점 

두 개의 클래스에서 같은 멤버 변수나 함수가 있다고 해보자.
예를 들어, 클래스 A 와 B 에 모두 a 라는 멤버 변수가 있다.


컴파일오류	C2385	'a' 액세스가 모호합니다.	
A의 a 인지, B 의 a 인지 구분할 수 없다.

다이아몬드 상속(diamond inheritance), 공포의 다이아몬드 상속 (dreadful diamond of derivaton)

*/
class A {
public:
	int a;
};
class B {
public:
	int a;
};
class C : public A, public B {
public:
	int c;
};
int main() {
	C c;
	c.a = 3;
}

class Human {
public:
	// ...
};
class HandsomeHuman : public virtual Human {
	// ...
};
class SmartHuman : public virtual Human {
	// ...
};
class Me : public HandsomeHuman, public SmartHuman {
	// ...
};

/* 
이러한 형태로 Human 을 virtual 로 상속받는다면, Me 에서 다중 상속 시에도
컴파일러가 언제나 Human 을 한 번만 포함하도록 지정할 수 있게 된다.
참고로, 가상 상속 시에, Me 의 생성자에서
HandsomeHuman 과 SmartHuman 의 생성자를 호출함은 당연하고, Human 의 생성자 또한 호출해주어야만 한다.
*/


/*
가상 상속(virtual 상속)은, 다이아몬드 형태로 여러 경로를 거쳐 같은 조상 클래스를 상속받게 될 때, 
그 조상 클래스가 여러 번 복제되지 않고 "딱 하나만" 존재하도록 만들어서, 
멤버 변수의 중복(그리고 그로 인한 접근 모호성 에러)을 없애주는 기법입니다. 

다만 그 대가로, 그 조상 클래스의 초기화 책임이 가장 마지막 파생 클래스로 넘어가기 때문에, 
Me처럼 최종적으로 다이아몬드를 완성하는 클래스가 
Human의 생성자를 직접 호출해줘야 한다는 걸 잊지 말아야 합니다.

*/