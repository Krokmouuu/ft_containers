#include "../map.hpp"

int main()
{
    ft::map<string, int> m;

    cout << "m is empty : " << m.empty() << endl;

    cout << "doing m[value] on non existing value insert value inside the map" << endl;
    m["a"] = 2;
    m["b"] = 4;
    m["c"] = 7;
    m["d"] = 21;
    m["e"] = 84;
    m["f"] = 24;
    m["g"] = 42;

    cout << "print what at m['e']" << endl;
    cout << "m : " << m["e"] << endl;

    ft::map<string, int> m2(m);

    cout << "copy m inside m2 and print m2['e']" << endl;
    cout << "m2 : " << m2["e"] << endl;

    ft::map<string, int> m3(m.begin(), m.end());
    cout << "create m3 with m iterators" << endl;
    cout << "m3 : " << m3["e"] << endl;
    cout << endl;
    cout << "size of m : " << m.size() << endl << endl;

    cout << "changing value at m['g']" << endl;
    cout << "value at m['g'] : " << m.at("g") << endl;
    m["g"] = 2000;
    cout << "new value at m['g'] : " << m.at("g") << endl << endl;
    cout << "insert 'coucou' with the value 10" << endl;
    m.insert(ft::make_pair("coucou", 10));
    cout << "print coucou : " << m.at("coucou") << endl << endl;
    cout << "let's insert in new map m4 start to end of m" << endl;
    ft::map<string, int> m4;
    m4.insert(m.begin(), m.end());
    for (ft::map<std::string, int>::const_iterator it = m4.begin(); it != m4.end(); it++)
        cout << it->first << " = " << it->second << "; " << endl;
    cout << "clear m2" << endl << endl;
    m2.clear();
    cout << "let's swap m and m2 so m will be empty" << endl;
    m.swap(m2);
    cout << "m is empty : " << m.empty() << endl << endl;
    cout << "let's print m2" << endl;
    for (ft::map<std::string, int>::const_iterator it = m2.begin(); it != m2.end(); it++)
        cout << it->first << " = " << it->second << "; " << endl;
    cout << "create iterator, he's trying to find 'e'" << endl;
    ft::map<string, int>::iterator hi = m2.find("e");
    cout << "print e : " << hi->first << " " << hi->second << endl;
    m2.erase(m2.find("coucou"));
    cout << "erase coucou" << endl;
    for (ft::map<std::string, int>::const_iterator it = m2.begin(); it != m2.end(); it++)
        cout << it->first << " = " << it->second << "; " << endl;
    cout << "delete b" << endl;
    m2.erase("b");
    for (ft::map<std::string, int>::iterator it = m2.begin(); it != m2.end(); it++)
        cout << it->first << " = " << it->second << "; " << endl;
    ft::map<string, int>::iterator hi2 = m2.lower_bound("a");
    cout << "the lowest value of a : " << hi2->first << " " << hi2->second << endl;
    cout << "trying to find the next upper value but b was deleted so c is find" << endl;
    ft::map<string, int>::iterator hi3 = m2.upper_bound("a");
    cout << "next highest value at a : " << hi3->first << " " << hi3->second << endl;
    
    system("leaks ft_containers");
    return 0;
}