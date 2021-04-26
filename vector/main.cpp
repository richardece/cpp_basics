#include <iostream>
#include <vector>

using namespace std;

int main() {
    cout << "Sequence container - vector" << endl;
    vector <int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    cout << "Size = " << v.size() << endl;

    //Iterator is similar to pointer
    vector<int>::iterator itrA = v.begin();
    cout << *itrA << endl;
    cout << *(itrA +3) << endl;

    //One way of accessing the vector elements using iterator
    for (; itrA != v.end(); itrA++) {
        cout << "value = " << *itrA << endl;
    }

    //Another way of doing the above
    auto itrB = v.begin();
    for (; itrB != v.end(); itrB++) {
        cout << "value = " << *itrB << endl;
    }

    //Clear the vector content
    v.clear();
    cout << "Size = " << v.size() << endl;


    return 0;
}