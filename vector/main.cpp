#include <iostream>
#include <vector>
#include <algorithm>
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

    //Yet another way of iterating
    for (auto &val : v) {
        cout << "value = " << val << endl;
    }
    //Clear the vector content
    v.clear();
    cout << "Size = " << v.size() << endl;

    vector <int> w;
    w.push_back(10);
    w.push_back(20);
    w.push_back(30);
    w.push_back(40);
    w.push_back(40);
    w.push_back(40);
    w.push_back(60);
    w.push_back(70);

#if 0
    //will erase the element and then re-arrange the elements to make the vector contiguous
    //vector size will decrease
    w.erase(w.begin() +3, w.begin()+4); //will erase first 40
    w.erase(w.begin() +3, w.end() -1 ); //will erase 40-40-60
#else
    #if 1
    //will remove all values 40,
    //but vector size is same, will duplicate the last few elements to fill up the space
    remove(w.begin(), w.end(), 40);
    #else
    //To actually erase the elements and not duplicate the last few elements
    w.erase(remove(w.begin(), w.end(), 40), w.end());
    #endif
#endif
    for (auto &val : w) {
        cout << "value w= " << val << endl;
    }

    return 0;
}