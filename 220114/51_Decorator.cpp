#include <iostream>
using namespace std;

// 광고 기능을 추가하고 싶습니다.
// 1. 상속
//  - 정적인 기능의 추가
//   > 기존 클래스에 기능이 추가되는 것이 아니라, 새로운 기능을 가지는 클래스를 만든다.

#if 0
class Ad1 : public Ticket {
public:
    void Print() const
    {
        Ticket::Print();
        cout << "자동차 광고" << endl;
    }
};

class Ad2 : public Ad1 {
public:
    void Print() const
    {
        cout << "TV 광고" << endl;
        Ad1::Print();
    }
};

int main()
{
    // Ticket t;
    // t.Print();

    // Ad1 t;
    // t.Print();

    Ad2 t;
    t.Print();
}
#endif

// 2. 포함
//  : 동적인 기능의 추가
//  => 실행 시간에 기능을 확장할 수 있다.
#if 0
class Ticket {
public:
    void Print() const
    {
        cout << "작은 음악회 - 2022.12.25" << endl;
    }
};

class Ad1 {
    Ticket& ticket; // 포함!
public:
    Ad1(Ticket& t)
        : ticket(t)
    {
    }

    void Print()
    {
        ticket.Print();
        cout << "자동차 광고" << endl;
    }
};

class Ad2 {
    Ad1& ticket;

public:
    Ad2(Ad1& a)
        : ticket(a)
    {
    }

    void Print()
    {
        cout << "TV 광고" << endl;
        ticket.Print();
    }
};
#endif

// Ticket과 기능을 추가한 Ad1, Ad2가 공통의 부모를 가진다면,
// => 기능을 추가한 객체에 다시 기능 추가를 유연하게 할 수 있습니다.
// => 데코레이터 패턴(Decorator Pattern) / 포장지 패턴

class Item {
public:
    virtual ~Item() { }

    virtual void Print() const = 0;
};

class Ticket : public Item {
public:
    void Print() const override
    {
        cout << "작은 음악회 - 2022.12.25" << endl;
    }
};

// 포장지의 공통의 특징을 부모 클래스로 뽑아냅니다.
class Decorator : public Item {
    Item& ticket;

public:
    Decorator(Item& t)
        : ticket(t)
    {
    }

    void Print() const override { ticket.Print(); }
};

class Ad1 : public Decorator {
public:
    Ad1(Item& t)
        : Decorator(t)
    {
    }

    void Print() const override
    {
        Decorator::Print();
        cout << "자동차 광고" << endl;
    }
};

class Ad2 : public Decorator {
public:
    Ad2(Item& a)
        : Decorator(a)
    {
    }

    void Print() const override
    {
        cout << "TV 광고" << endl;
        Decorator::Print();
    }
};

// 디자인 패턴에서 "재귀적 합성"을 사용하는 패턴 2가지
// 1) Composite Pattern
//  => 재귀적 합성을 이용한 복합 객체의 구성
//  ex) Menu, Folder, MacroCommand
//
// 2) Decorator Pattern
//  => 재귀적 합성을 이용한 동적 기능 추가
//   : 포장지는 객체를 포장하지만, 포장된 객체를 다시 포장할 수 있어야 한다.
//     포장지와 객체는 동일 부모를 가져야 한다.

int main()
{
    Ticket t;
    // Ad1 ad1(t);
    // Ad2 ad2(ad1);

    Ad2 ad2(t);
    Ad1 ad1(ad2);
    Ad2 ad3(ad1);

    ad3.Print();
}