
class A
{
public:
	A() {}
};

int main()
{
	A a();  // 함수 연산자다 객체 a를 만들고 기본 생성자 호출하는 것이 아님, 컴파일에러도 안남
	A a;    // 객체 a생성, 생성자 호출
}