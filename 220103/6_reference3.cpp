#include <iostream>
#include <string>

using namespace std;

struct User
{
    std::string name;
    int age;
};
//복사에 의한 오버헤드를 없앨 수 있습니다.
// => call by velue
//  :함수를 통해서 전달받은 파라미터의 값을 변경하지않습니다.
//  void printUser(User user)
//  문제점 : 구조체 등의 크기가 큰 타입이 전달될 경우 복사에 의한 오버헤드가 있습니다.

// 해결
// => call by reference
// => void printUser(user &user)
//      :복사에 의한 오버헤드를 없앨 수 있습니다.
//      const &를 사용해야 합니다.
// => void printUser(const User &user)

void printUser(const User &user)
{
    cout << user.name << ", "<<user.age << endl;

    // user,age += 10; //compile error!!
}

// g++ 6_reference3.cpp -std=c++11
int main()
{
    User user{"Tom", 42};
    printUser(user);
    
}