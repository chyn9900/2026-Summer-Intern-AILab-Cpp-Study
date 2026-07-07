/* 'is -a' 와 'has -a' */
// 클래스 사이에 관계를 표현
/*
Manager 가 Employee 를 상속받는다

class Manager : public Employee


1. Manager 클래스는 Employee 의 모든 기능을 포함한다.
2. Manager 클래스는 Employee 의 기능을 모두 수행할 수 있기 때문에 Manager 를 Employee 라고 칭해도 무방하다.
3. 즉 모든 Manager 는 Employee 이다.
4. Manage is a Employee !!

따라서, 모든 상속 관계는 is a 관계라고 볼 수 있다. 당연한 점은, 이를 뒤바꾸면 성립되지 않는다.
즉, Manager 는 Employee 이지만, Employee 는 Manager 가 아니다.
이렇기에 Manager 를 Employee 로 부를 수 있지만, Employee 는 Manager 로 부를 수 없다.
*/

class Car { // Car has a Engine, Car has a Brake
private:
	Engine e;
	Brake b; // NOT break
	// ....
};

// EmployeeList 는 Employee 들과 has - a 관계 이다. 
// EmployeeList 클래스는 Employee 들을 포함하고 있다.
class EmployeeList {
	int alloc_employee;			// 할당한 총 직원 수
	int current_employee;		// 현재 직원 수
	Employee **employee_list;	// 직원 데이터
};