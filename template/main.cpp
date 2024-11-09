#include <iostream>

using namespace std;

//With template, no need to declare many functions with different data type parameters.
// C++ compiler will generate those overloaded functions for us during compilation.
// See compiler explorer for the proof

// An example with just one data type
template<typename T>
T add (T val1, T val2){
    return val1 + val2;
}

//Another example with different data types
template<typename T, typename U>
void PrintAgeHeight(T weight, U height){
    cout << "Height = "<< height<< " cm and weight = " << weight << " lbs" << endl;
}

int main() {
    cout << "1 + 2 = " << add(1,2) << endl;

    cout << "1.1 + 2.5 = " << add(1.1,2.5) << endl;       //implicit, compiler will guess what is the data type
    cout << "1.1 + 2 = " << add<float>(1.1,2) << endl;    //explicit version of the example above

    PrintAgeHeight(160, 170.9);
    PrintAgeHeight(160.1, 172);

    return 0;
}