//동적 메모리 할당
// -malloc / free
#include <iostream>
using namespace std;

int g[100000] = {1, 2, 3};
// 수명 : 프로그램 시작 - 끝
// 장점 : 언제 어디서든 쉽게 접근이 가능하다.
//              -복잡도를 낮출수 있다.
// 단점 : 함수가 전역 변수에 의존할 경우,
//        함수의 재사용성이 떨어진다.

int add(int a, int b)
{
    return a + b;
}
void foo()
{
    int a;
    // 지역 변수(auto 변수)
    //      스택에 저장
    //      foo함수가 실행될 때 생성되고, foo함수가 끝날 때 해지됨
    // > 메모리 할당 해지의 비용의 없다.
    static int b;
    // 내부 정적 변수
    // - 전역변수와 동일한 영역으로 관리. (데이터 영역)
    // > foo함수가 처음 실행 될때 생성디고, 프로그램이 종료할 때 까지 유지됩니다.
    // : 함수가 상태를 가져야 할 때 사용합니다.
}

#include <string.h>

//동적 메모리 할당
// - 힙(자유영역)에 생성되는 변수 입니다.
// > 개발자가 원하는 시점에 생성할 수 있고, 개발자가 원하는 시점에 파괴할 수 있습니다.
//  1) 메모리 누수의 위험성이 있다.
//  2)성능 오버헤드가 있습니다.
//  

// int main()
// {
//     char str[] = "hello world show e the money";

//     char *p = strtok(str, " ");
//     printf("%s\n", p);
    
//     for(char *p = strtok(str, " "); p != NULL; p= strtok(NULL, " "))
//         printf("%s\n", p);


// }


//C++은 동적 메모리 관련 연산자를 제공합니다.
// new / delate
//  1. malloc/free는 함수지만, new/delete는 연산자 입니다.
//  2. malloc은 메모리 크기를 인자로 전달하지만, new는 타입을 전달합니다.
//  3.malloc은 void*를 반환하기 때문에, 캐스팅이 필요하지만,
//    
//  4. malloc은 free로 해지하지만, new는 elete를 통해 해지해야 합니다.

int main()
{
    // int *p = static_cast<int *>(malloc(sizeof(int)));
    // *p = 20;
    // cout << *p << endl;

    int *p = new int;

    //free(p);
    delete p;

    int *arr = static_cast<int *>(malloc(sizeof(int)* 5));
    arr[0] = 10;
    cout << arr[0] << endl;
    free(arr);

    //int arr[5]
    arr = new int[5];
    //주의사항
    //  -연속된 메모리를 할당한 경우, delete에 대해서 배열 형태의 해지 연산을 사용해야 합니다.
    delete[] arr;

}