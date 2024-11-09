#include <iostream>
#include <map>  //for map and multimap
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    cout << "Associative container - map and multimap, ordered and unordered" << endl;

    pair<int, int> p = make_pair(10,20);
    cout << p.first << " - " << p.second << endl;

#if 0
    //Key/value pair
    map <int, int> mp;
    //Different ways of creating a key/value pair
    mp[4] = 400;
    mp[3] = 300;
    mp.insert(make_pair(30, 300));
    mp[7] = 7000;
    //can change the value of an existing pair
    //Only one unique key is allowed
    mp[3] = 301;

    //Iterate a map
    //Map iterator returns a pair
    //Notice that the map is sorted by key
    for (auto it = mp.begin(); it != mp.end(); it++){
        cout << it->first << " - " << it->second << endl;
    }
#endif
#if 0
    multimap <int, int> mp;
    //Multimap allows same key with different values
    //But updating values is not allowed
    mp.insert(make_pair(4, 400));
    mp.insert(make_pair(10, 700));
    mp.insert(make_pair(3, 300));
    mp.insert(make_pair(10, 1000));
    mp.insert(make_pair(10, 900));
    //subscript operator is not allowed, because we don't know which key value pair is to be updated
    //And updating of value is not allowed also
    //mp[11] = 1100;

    for (auto it = mp.begin(); it != mp.end(); it++){
        cout << it->first << " - " << it->second << endl;
    }

#endif
#if 0
    //Stored as a hash
    //Much faster than maps
    unordered_map <int, int> mp;

    //Elements are not sorted
    //Updating values is allowed
    mp[4] = 400;
    mp[3] = 300;
    mp.insert(make_pair(4, 400));
    mp.insert(make_pair(10, 700));
    mp.insert(make_pair(3, 300));
    mp.insert(make_pair(21, 1000));
    mp.insert(make_pair(11, 900));
    mp[10] = 100;

    for (auto it = mp.begin(); it != mp.end(); it++){
        cout << it->first << " - " << it->second << endl;
    }
#endif
#if 0
    //Stored as a hash
    //Much faster than maps
    unordered_multimap <int, int> mp;

    //Elements are not sorted
    //Updating values is NOT allowed
    //mp[4] = 400;
    mp.insert(make_pair(4, 400));
    mp.insert(make_pair(10, 700));
    mp.insert(make_pair(3, 300));
    mp.insert(make_pair(21, 1000));
    mp.insert(make_pair(11, 900));


    for (auto it = mp.begin(); it != mp.end(); it++){
        cout << it->first << " - " << it->second << endl;
    }
#endif

#if 1
    //Stored as a hash
    //Much faster than maps
    map <string, float> mp = {
            {"K1", 1.1},
            {"K2", 0.0}
    };


    for (auto it = mp.begin(); it != mp.end(); it++){
        cout << it->first << " - " << it->second << endl;
    }
#endif
    return 0;
}