#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>

using namespace std;

int main() {
    cout << "Container adapters - stack, queue and priority queue" << endl;
    //Container adapter uses other underlying data structure internally

    /////////////////////////////
    //First in, last out
    stack<int> stk;

    //Stack uses other primitive containers as an underlying data structure
    //stack<int, deque<int>> stk;
    //stack<int, vector<int>> stk;
    //stack<int, list<int>> stk;

    stk.push(100);
    stk.push(200);
    stk.push(300);
    while (stk.size() != 0){
        //top is last in
        cout << stk.top()<<endl;
        //pop will remove last in
        stk.pop();
    }

    cout <<endl;

    /////////////////////////////
    //Has front and back
    queue<int> q;
    //queue<int, deque<int>> q;
    //queue<int, list<int>> q;
    //Cannot use vector unlike in stack because vector does not have a pop functionality

    //First in will be in front
    //Last in is at the back
    q.push(100);
    q.push(200);
    q.push(300);
    while (!q.empty() ){
        cout << q.front()<<endl;    //will just access the front element
        //cout << q.back()<<endl;   //will just access the rear element
        q.pop();    //Will remove the front element
    }

    cout <<endl;

    /////////////////////////////
    //It only has top
    //Elements are sorted
    //Can use  vector and deque as underlying data structure
    //Can also use a comparator to change teh sort behavior
    priority_queue<int> pq;
    pq.push(100);
    pq.push(30);
    pq.push(400);
    pq.push(120);

    while (!pq.empty() ){
        cout << pq.top()<<endl;    //will just access the top element
        pq.pop();    //Will remove the top element
    }

    return 0;
}