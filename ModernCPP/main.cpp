#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>
using namespace std;

/* Modern C++ refers to C++11 and C++14
 *
 * */

enum Color {
    Red, Green, Blue
};
enum class Size {
    Small, Medium, Large
};

template <typename  T, size_t Size>
class Values {
    static_assert(Size > 1, "Use scalar");  //will generate a compile error if condition is false
    T values[Size];
};

auto sum() {return 0;}
template <typename H, typename ... T>
auto sum(H h, T ... t) {
    return h+sum(t...);
}
int main() {
    ///////////////////////////
    //Uniform initialization

    //int a = 1;    //old way
    int a{1};       //new way
    //string s  = "foo";
    string s{"foo"};
    //vector<int> values;
    //values.push_back(1);
    vector<int> values {1,2,3};
    map<string, string> capitals {{"UK", "London"}, {"Manila", "Philippines"}};


    ///////////////////////////
    //enum class
    Color c1 = Blue;        //old way
    Size s1 = Size::Large; //new way

    ///////////////////////////
    //static assert
    Values<int, 5> someStuff;
    //Values<int, 1> otherStuff;  //will generate a compile error

    ///////////////////////////
    //variadic template
    //We don't need to declare too many functions that accept different numbers of argument
    //Compiler will generate those functions for us automatically (see compiler explorer)
    cout << sum(5, 3.1) << endl;
    cout << sum(1, 2, 3, 4) << endl;

    //unique_ptr
    //shared_ptr


    std::cout << "Hello, World!" << std::endl;
    return 0;
}