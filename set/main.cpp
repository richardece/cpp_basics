#include <iostream>
#include <set>
#include <map>

using namespace std;

/*
Sets are a type of associative containers in which each element has to be unique because the value of the element identifies it (hashed). 
The values are stored in a specific order. 
Properties:
- The set stores the elements in sorted order.
- All the elements in a set have unique values.
- The value of the element cannot be modified once it is added to the set, though it is possible to remove and then add the modified value of that element. Thus, the values are immutable.
- Sets follow the Binary search tree implementation.
- The values in a set are unindexed.
*/

//Custom comparator is useful for more complex data structures.
//For example, if you want to sort according to the value, instead of according to keys
template <typename type>
struct mycomp {
    bool operator()(const type & first, const type & second) const {
        //return first < second;
        return first > second;
    }
};

int main() {
    cout << "Associative container - set and multiset" << endl;
#if 1
    set<int> myset;
    myset.insert(100), myset.insert(200), myset.insert(40), myset.insert(90);
    //Set is sorted by value (ascending order, by default)
    //Set can only have unique values
    myset.insert(40);

    for(auto & setval : myset) {
        cout << " "<< setval;
    }
    cout << endl;
#else
    multiset<int> myset;
    myset.insert(100), myset.insert(200), myset.insert(40), myset.insert(90);
    //Also sorted by value
    //Multiset can have multiple duplicate values
    myset.insert(40);

    for(auto & setval : myset) {
        cout << setval <<endl;
    }
    cout<<endl;

    //Will erase all instances of 40
    myset.erase(40);
    myset.erase(myset.begin());
    for(auto & setval : myset) {
        cout << setval <<endl;
    }
#endif
    cout <<endl;

    //Comparator will determine how the elements will be sorted
    //set<int, less<int>> newset;
    set<int, greater<int>> newset;

    newset.insert(100), newset.insert(200), newset.insert(40), newset.insert(90);
    for(auto & setval : newset) {
        cout << setval <<endl;
    }

    //Comparator also works with map
    //map<int, string, less<int>> mymap;
    //map<int, string, greater<int>> mymap;
    //You can also supply your own comparator
    map<int, string, mycomp<int>> mymap;

    mymap[10] = "abc", mymap[30] = "tuv", mymap[20] = "xyz";
    for(auto & mapval : mymap) {
        cout << mapval.first<<" - " << mapval.second <<endl;
    }
    return 0;
}