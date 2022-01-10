#include <iostream>
using namespace std;


//암묵적(implicit) : 개발자가 별다른 조치를 취하지 않아도 허용해줌.
//명시적(explicit) : 개발자가 코드를 작성해야만 허용해줌.

int main()
{
    double d=3.4;
    int n = d;  //암묵전인 변환 허용. double ->int

    //int *p = &d;    //double* -> int* 암묵적인 변환이 허요되지 않습니다.
    int *p =(int*) &d;  //명시적인 변환은 가능


}



//static(정적) : 컴파일 타임에 결정됩니다.
//dynamic(동적), virtual(가상) : 런타임에 결정됩니다.


//C언어의 캐스팅은 대부분 성공하기 때문에, 많은 버그의 원인이 됩니다.
// > C++ 에서는 C 캐스팅의 문제점을 해결하기 위해서 4가지의 캐스팅 연산자를 제공합니다.
// 1) static_cast
// : 가장 기본적인 변환 연산자 입니다.
//  컴파일 시간에 타입을 체크해서 캐스팅을 수행합니다.
//      -서로 연관성이 없는 타입은 캐스팅이 허용되지 않습니다.


//void *: 모든타입의 주소를 담을 수 있는 포인터 타입입니다.
//        하지만 참조하는 대상체의 크기를 알 수 없기 때문에
//        참조연산은 수행이 불가능합니ㅏ.
int main()
{
    //int *p - (int*)malloc(sizeof(int)); -C
    void *p = static_cast<int *>(p);

    //int * -> double *
    //double *pd = static_cast<double *>(p1);
    //잘못된 형식 변환입니다. c/c++(171)

    //메모리를 읽는 방법을 변경하고자 할 때 사용한다.
    // int * -> double *
    //double *pd = reinterpret_cast *> (pi);  
}





// 2) dynamic_cast - *
// 3) const_cast 

int main()
{
    const int n = 10;

    //const int* => int*
    //int *p = reinterpret_cast<int*>(&n);
    //int *p = reinterpret_cast<int*>(&n);
    int *p = const_cast<int*>(&n);
}



// 4) reinterpret_cast

