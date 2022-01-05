#include <iostream>
using namespace std;


//  1) call by value

// inc1
// x :10 -> 11
//
// ------
//main
//  n(0x100); 10

void inc(int x)
{
    ++x;
}
//   2) call by reference(pointer)
//inc2
// x(0x100)
//
// ------
//main
//  n(0x100); 10

// void inc2(int *x)
// {
//     ++(*x);
// }
// void inc3(int &x)
// {
//     ++x;
// }
// int main()
// {
//     int n = 10;
//     //inc(n);
//     //inc2(&n);
//     //inc3(n);
    
//     cout << n << endl;
// }

void foo(int *x)
{
    printf("foo : sizeof(%ld)\n", sizeof(x));
}

void goo(int (&x)[5])
{
    printf("goo : sizeof(%ld)\n", sizeof(x));
}

int main()
{
    int x[5];
    printf("sizeof(%ld)\n", sizeof(x));

    foo(x);
    goo(x);
}