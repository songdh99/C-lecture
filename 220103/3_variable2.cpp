// 3_variable2.cpp
#include <iostream>
using namespace std;

struct Point
{
  int x, y;
};

/*
int main()
{
  int n1 = 42;
  int n2(42); // C++ 초기화 문법
  // 1. 일반 변수는 '=' / '()'로 초기화 합니다.
  cout << n1 << ", " << n2 << endl;
  // () 초기화: 직접 초기화(direct initialization)
  // = 초기화: 복사 초기화(copy initialization)
  // 2. 배열과 구조체 초기화 방법.
  Point p = {10, 20};
  int x[3] = {10, 20, 30};
}
*/

// C++11 - Uniform initialization
// > 일관된 방법을 통해 변수를 초기화할 수 있다.
int main()
{
  // int n3 = 3.14; // warning
  // cout << n3 << endl;

  int n4{3.14};
  // 데이터 손실이 발생하는 잘못된 초기화에 대해서 컴파일 오류가 발생합니다.

  // char c1 = 300;
  char c2{300};

  // =(등호): Copy initialization
  int n1 = {0};
  int x[3] = {1, 2, 3};
  Point p1 = {10, 20};

  // Direct initialization
  int n2{0};
  int x2[3]{1, 2, 3};
  Point p2{10, 20};
}