#include <iostream>
using namespace std;

// C++에서는 파라미터의 타입이나 개수가 다르면,
// 동일한 이름의 함수를 여러개 만들 수 있습니다.
// => "함수 오버로딩"이라고 부릅니다.
// => 컴파일러가 함수의 파라미터 정보를 통해 이름을 생성합니다.
//    > 파라미터의 개수와 타입이 다르면 다른 이름이 생성됩니다.
//     "네임 맹글링"
// 주의사항
//  - 반환 타입은 함수 이름에 영향을 미치지 않습니다.
//   > 파라미터가 동일하고 반환타입이 다른 함수는 오버로딩이 불가능합니다.
// int foo() {}
// void foo() {}

void goo(int a) {}
void goo(int a, int b = 100) {}
// goo(10);
// > 컴파일러는 어떤 함수를 호출할지 결정할 수 없습니다. - 컴파일 오류!

int square(int x)
{
  return x * x;
}

double square(double x)
{
  return x * x;
}

char square(char c)
{
  return c * c;
}

int main()
{
  // goo(10);
  // call to 'goo' is ambiguous
}

int square(int n)
{
    printf("int\n");
    return n * n;
}





//오버로딩 규칙
//-정확한 타입을 찾습니다.
//square(42) -> square(int)