#include <iostream>
#include <thread>

using namespace std;

void threadFn(){
    cout << "Inside thread function" << endl;
}
void threadFnValue(int value){
    cout << "Inside thread function, pass by value, value = " << value << endl;
}

void threadFnRef(int & value){
    cout << "Inside thread function, pass by reference, value = " << value++ << endl;
}

int main() {
    cout << "Create threads" << endl;

    //Create a simple thread, both () and {} works
    //thread t1(threadFn);
    thread t1{threadFn};

    //Create a thread and pass an argument by value
    thread t2(threadFnValue, 100);

    //Create a thread and pass an argument by reference
    int i = 30;
    thread t3(threadFnRef, ref(i));

    //Create a thread using lambda
    thread t4{ [](){
        cout << "Thread inside lambda" << endl;
    } };


    t1.join();
    t2.join();
    t3.join();
    t4.join();

    cout << "i after thread runs = " << i << endl;
    return 0;
}