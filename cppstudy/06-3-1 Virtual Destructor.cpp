/* virtual 소멸자 

virtual keyword: 동적 바인딩

Parent 클래스 와 Child 클래스에 모두 f() 라는 virtual function 이 정의되어 있다고 하자.

Child 클래스가 Parent 클래스를 상속받는다고 하자.

동일한 Parent* 타입의 포인터들도 각각 Parent 객체와 Child 객체를 가리킨다고 하자.

Parent* p = new Parent();
Parent* c = new Child();

컴퓨터 입장에서 p 와 c 모두 Parent 를 가리키는 포인터들이므로, 당연히

p->f();
c->f();

를 했을 때 모두 Parent 의 f() 가 호출되어야 하겠지만,
실제로는 f 가 virtual function 이므로,
'실제로 p 와 c 가 가리키는 객체의 f', 

즉, p->f() 는 Parent의 f 를,
c->f() 는 Child 의 f 가 호출 된다.

이와 같은 일이 가능한 이유는 f 를 가상함수로 만들었기 때문이다.

*/

#include <iostream>

class Parent {
public:
	Parent() { std::cout << "Parent 생성자 호출" << std::endl; }
	virtual ~Parent() { std::cout << "Parent 소멸자 호출" << std::endl; }
};
class Child : public Parent {
public:
	Child() { std::cout << "Child 생성자 호출" << std::endl; }
	~Child() { std::cout << "Child 소멸자 호출" << std::endl; }
};
int main() {
	std::cout << "--- 평범한 Child 만들었을때 ---" << std::endl;
	{ 
		// 이 {} 를 빠져나가면 c 가 소멸된다.
		Child c; 
	}
	std::cout << "--- Parent 포인터로 Child 가리켰을 때 ---" << std::endl;
	{
		Parent* p = new Child();
		delete p;
	}
}

/*
--- 평범한 Child 만들었을때 ---
Parent 생성자 호출
Child 생성자 호출
Child 소멸자 호출
Parent 소멸자 호출
--- Parent 포인터로 Child 가리켰을 때 ---
Parent 생성자 호출
Child 생성자 호출
Parent 소멸자 호출


// Child 소멸자가 호출되지 않는다.
*/