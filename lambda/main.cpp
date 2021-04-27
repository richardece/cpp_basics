#include <iostream>
using namespace std;

int main() {
    std::cout << "Lambda" << std::endl;
    /*  Basic syntax
     * [](){};
     *  [] capture list
     *  () function arguments
     *  {} function body
     * */

    //Defining and calling  a lambda
    [](){
        cout << "Inside a lambda function" << endl;
    }();    //() will call the function

    //Defining and calling  a lambda with function arguments
    [](int value){
        cout << "Inside a lambda function with value = " << value << endl;
    }(100);    //() will call the function with argument

    //Defining and calling  a lambda using auto keyword
    auto lfn = [](){
        cout << "Inside a lambda function using auto" << endl;
    };
    lfn(); //() call the function

    //Defining and calling a lambda using auto keyword, with parameter
    auto lfn2 = [](int val){
        cout << "Inside a lambda function using auto, value = " << val << endl;
    };
    lfn2(200); //() call the function with argument

    //Defining and calling a lambda using std::function<> instead of auto,  with parameter
    std::function<void (int)> lfn3 = [](int val){
        cout << "Inside a lambda function using std::function, value = " << val << endl;
    };
    lfn3(300); //() call the function with argument

    //Defining and calling a lambda using plain old C style function pointer,  with parameter
    void(*cstylefp)(int)  = [](int val){
        cout << "Inside a lambda function using plain old C style function pointer, value = " << val << endl;
    };
    cstylefp(400); //() call the function with argument

    ///////////////////////
    //Capture list

    //Capture by value
    int a = 100;
    int b = 99;
    [=](){      // = means pass all local variables by value
      cout <<a<<endl;
      cout <<b<<endl;
    }();

    //Capture by reference
    int x = 5;
    int y = 8;
    [&](){      // & means pass all local variables by reference
        x--;
        y++;
        cout <<x<<endl;
        cout <<y<<endl;
    }();

    //Capture by reference
    int m = 23;
    int n = 15;
    [m, &n](){      // m is passed by value, n is passed by reference
        n++;
        cout <<m<<endl;
        cout <<n<<endl;
    }();


    return 0;
}