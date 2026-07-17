#include <iostream>

class A {
public:
	A() { std::cout << "ctor\n"; }
	A(const A& a) { std::cout << "copy ctor\n"; }
	A(A&& a) { std::cout << "move ctro\n"; }
};

class B {
public:
	// B(const A& a) : a_(a) {}
	// const A& a) : a_(std::move(a)) {}
	// B(A&& a) : a_(a) {}
	B(A&& a) : a_(std::move(a)) {}

	A a_;
};
int main() {
	A a;

	std::cout << "create B-- \n";
	// B b(a);
	B b(std::move(a));
}
/*
ctor
create B--
copy ctor
*/

/*
ctor
create B--
copy ctor
*/

/*
ctor
create B--
copy ctor
*/


/*
ctor
create B--
move ctro
*/