#include <iostream>
#include <vector>
#include <array>
/*********************
 * 1. Auto
 * use auto if you don't care what the data type is.
 *********************/

template <typename T>
void countThings(const T &vec, int value) {
    const auto count = std::count(begin(vec), end(vec), value);
}

/*********************
 * 2. range for loop
 * use auto if you don't care what the data type is.
 *********************/
template <typename T>
void doThings(const T &vec, int value) {
    //C++ 98 style
    for(std::vector<int>::const_iterator itr = vec.begin(); itr != vec.end(); ++itr ){
        //do something with itr
    }

    //C++11 style
    //observe how much boiler plate code was removed
    for(const auto &elem : vec) {
        //do something with itr
    }

}

/*********************
 * 3. lambda
 *
 *********************/
template <typename T>
void countThingsLessThan3(const T &vec, int value){
    const auto count = std::count(begin(vec), end(vec),
                                  [](int i){return i < 3;}
    );
}

/*********************
 * 4. variadic templates
 *
 *********************/
//Can't understand what this is for

/*********************
 * 5. unique_ptr
 *
 *********************/
#include <memory>
void allocateMemory() {
    std::unique_ptr<int> ptr(new int(5));
}
//ptr is destroyed when it goes out of scope, and the memory is freed automatically

/*********************
 * 6. constexpr
 * Result is computed during compile time, instead of run-time
 * But the implementation is  a bit constrained, like it is not possible to use control statements nor
 * declare local variables inside the constexpr function
 *********************/
 //Need to get more sensible examples
constexpr int get_value() {
    return 3 * 5;
}


int main() {

    constexpr auto value = get_value(); //constexpr can only read other constexpr
                                        //value is available at compile time
    std::array<int, value> values;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}