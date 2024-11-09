#include <iostream>

template<typename T, typename U>
struct Point{
    T x;
    U y;
};

int main() {
    // CPP 98 properties

    /******************************
     * 1. The order of construction and destruction is guaranteed
     *
     ******************************/
    {
        std::string s1("Hello World");      // s1 is created here
        std::string s2("Another string");   // s2 is created here
    }
    // s2 is destroyed here
    // s1 is destroyed here

    //std::cout<< s1.size() << std::endl;

    /******************************
     * 3. Deterministic object lifetime
     *
     ******************************/
    struct MyType{
        MyType() : ptr(new int(5)){
            std::cout<< "Inside constructor" << std::endl;
        }
        ~MyType(){ delete ptr;
            std::cout<< "Inside destructor" << std::endl;
        }

        int *ptr;
    };

    {
        MyType a;
    }

    /******************************
     * 4. Templates
     *
     ******************************/

    Point<int, int> p;

return 0;
}