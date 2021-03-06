#include <iostream>
#include <vector>
using namespace std;

// 도형 편집기로 배우는 객체지향 설계 개념
// 1. 모든 도형을 타입화 하면 편리합니다.

// 2. 모든 도형의 공통의 부모가 있다면 모든 도형을 묶어서 관리할 수 있습니다.
//   - "A와 B를 묶기 위해서는 공통의 부모가 필요하다."

// 3. 모든 자식의 공통의 특징이 있다면 반드시 부모에도 있어야 한다.
//    그래야 부모 포인터(레퍼런스)로 묶어서 사용할 때
//    해당 특징을 사용할 수 있다.
// => LSP(Liskov Substitution Principle)이라는 개념
//  : 자식 클래스는 부모 클래스로 대체할 수 있어야 한다.

// 4. 부모의 함수 중 자식이 재정의하는 모든 함수는 반드시 가상함수이어야 한다.
//   "가상함수가 아닌 함수는 재정의하면 안됩니다."
//   => Effective C++ 격언

class Shape {
public:
    virtual void Draw()
    {
        cout << "Shape Draw" << endl;
    }
};

class Rect : public Shape {
public:
    void Draw() override
    {
        cout << "Rect draw" << endl;
    }
};

class Circle : public Shape {
public:
    void Draw() override
    {
        cout << "Circle draw" << endl;
    }
};

int main()
{
    // vector<Rect*> rects;
    // vector<Circle*> circles;
    vector<Shape*> v;

    while (1) {
        int cmd;
        cin >> cmd;

        if (cmd == 1) {
            v.push_back(new Rect);
        } else if (cmd == 2) {
            v.push_back(new Circle);
        } else if (cmd == 9) {
            for (Shape* p : v) {
                p->Draw();
            }
        }
    }
}