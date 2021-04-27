#include <iostream>
#include <set>
#include <map>

using namespace std;

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
#if 0
    set<int> myset;
    myset.insert(100), myset.insert(200), myset.insert(40), myset.insert(90);
    //Set is sorted by value
    //Set can only have unique values
    myset.insert(40);

    for(auto & setval : myset) {
        cout << setval <<endl;
    }
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