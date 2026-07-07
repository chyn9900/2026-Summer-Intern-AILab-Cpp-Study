/*

static_cast: 일반적인 타입 변환
const_cast: 객체의 상수성(const)를 없애는 타입 변환, 쉽게 말해 const int 가 int 로 바뀐다.
dynamic_cast: 파생 클래스 사이에서의 다운 캐스팅
reinterpret_cast: 위험을 감수하고 하는 캐스팅으로 서로 관련이 없는 포인터들 사이의 캐스팅 등

*/

// 원하는 캐스팅 종류 <바꾸려는 타입> (무엇을 바꿀 것인가?)

// cpp style
static_cast<int>(float_variable) // float 타입의 float_variable 변수를 int 타입의 변수로 타입 변환

// cstyle
(int)(float_variable)