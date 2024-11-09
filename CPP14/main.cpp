#include <iostream>
#include <vector>
#include <chrono>
#include <tuple>

using namespace std;
using namespace std::chrono;

//C++14 is more like a bug fix for C++11

/*********************
 * 1. Auto return type deduction
 * This is useful if the return type is very long and complex to type.
 * The downside is you need to look inside the function implementation
 *********************/
template <typename T>
auto countThings(const T &vec, int value) {
    const auto count = std::count(begin(vec), end(vec), value);
    return count;
}

/*********************
 * 3. lambda - generic
 *
 *********************/
template <typename T>
void countThingsLessThan3(const T &vec, int value){
    const auto count = std::count(begin(vec), end(vec),
                                  [](const auto i){return i < 3;}
    );
}

/*********************
 * 5. make_unique
 *
 *********************/
#include <memory>
void allocateMemory() {
    auto ptr{std::make_unique<int>(5)};
}
//ptr is destroyed when it goes out of scope, and the memory is freed automatically
// this is more advantageous than using a raw pointer where we have to manually take care if freeing (or implementing  a destructor)

void print(milliseconds ms) {
    cout << ms.count() << "ms \n";
}

int main() {

    //Hex and binary numbers can be expressed this way
    //Separator is also allowed for better readability
    auto registerValue = 0x47;
    auto registerValue2 = 0b01110101;
    auto registerValue3 = 0b01110011'00110101;
    long counter = 10'000'000;  //10M

    //Chrono literals like h, min, s, ms, us, ns
    auto x = 2s;
    cout << "2s = "; print(x);  //notice how the chrono library automatically converts s to ms

    auto y = 150ms;
    cout << "150ms = "; print(y);

    auto z = x+y;       //chrono library automatically converts to match the  unit of time
    cout << "2s + 150ms = "; print(z);

    constexpr auto timeLimit = 3s;
    cout << "\n time limit = "; print(timeLimit);
    if (z < timeLimit){ //chrono library automatically converts to match the unit of time to make a meaningful comparison
        cout << "All right! \n";
    } else {
        cout << "Out of time\n";
    }

    //tuple is similar to pair
    //But instead of just 2 elements, there are n elements of heteregeneous data types
    //use std::get<0> to access each element

    std::cout << "Hello, World!" << std::endl;
    return 0;
}