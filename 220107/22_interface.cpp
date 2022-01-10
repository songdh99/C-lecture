// 22_interface.cpp
#include <iostream>
#include <vector>
using namespace std;

// 1. 자식 클래스의 공통의 기능을 부모 타입 포인터를 통해 이용하기 위해서는, 해당 기능이 반드시 부모 클래스에서 비롯되어야 한다.
// 2. 부모 클래스가 제공하는 함수를 자식 클래스가 오버라이딩 할 경우,
//    해당 함수는 반드시 가상 이어야 한다.
// 3. 가상 함수가 존재하는 모든 부모 클래스는 반드시 가상 소멸자이어야 한다.

class Shape {
public:
    virtual ~Shape() { }

    virtual void Draw()
    {
        cout << "Shape Draw" << endl;
    }
};

class Rect : public Shape {
public:
    ~Rect() { cout << "~Rect" << endl; }

    void Draw() override
    {
        cout << "Rect draw" << endl;
    }
};

class Circle : public Shape {
public:
    ~Circle() { cout << "~Circle" << endl; }

    void Draw() override
    {
        cout << "Circle draw" << endl;
    }
};

// 부모 타입을 통해 Rect와 Circle을 동시에 다룰 수 있습니다.
int main()
{
    vector<Shape*> v;

    v.push_back(new Rect);
    v.push_back(new Circle);
    v.push_back(new Rect);
    v.push_back(new Circle);
    v.push_back(new Rect);
    v.push_back(new Circle);

    // for (int i = 0; i < v.size(); ++i) {
    //    v[i]->Draw();
    // }
    for (Shape* p : v) {
        p->Draw();
    }

    for (Shape* p : v) {
        delete p;
    }
}