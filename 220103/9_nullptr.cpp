
//C언어에서 0은 int타입이지만, 컴파일러에 의해서 특별하게 처리됩니다.

int main()
{
//    int *p = 10; //에러!

    //int *p = 0; //ok!
                //0은 정수지만 포인터로 암묵적 형변환이 됩니다

    int *p = nullptr;
    //int p =nullptr;   //error!
    //bool b = nullptr; //error!
    bool b(nullptr); //직접초기화시 nullptr을 bool의 암묵적 변환이 허용됩니다.

}
//C++11에서는 포인터 0을 나타내는 nullptr를 제공합니다.

