#include "../vector.hpp"

int main()
{
    ft::vector<int> v1;
    ft::vector<int> v2(5, 20);
    ft::vector<int> v2_copy(v2);

    cout << "v1 is empty : " << v1.empty() << endl;
    v1.push_back(5);
    cout << "v1 is empty : " << v1.empty() << endl;

    for(size_t i = 0; i < v2.size(); i++)
        cout << "v2 : " << v2.at(i) << " " << i << endl;

    cout << endl;

    for(size_t i = 0; i < v2_copy.size(); i++)
        cout << "v2_copy : " << v2.at(i) << " " << i << endl;

    cout << endl;

    v1 = v2;
    cout << "v1 = v2" << endl;
    for(size_t i = 0; i < v1.size(); i++)
        cout << "v1 : " << v1.at(i) << " " << i << endl;

    cout << endl;

    ft::vector<int>::iterator it = v2.begin();   
    ft::vector<int>::iterator it2 = v2.end();
    ft::vector<int> v3(it, it2);
    cout << "v3 initialisation with iterator" << endl;

    for(size_t i = 0; i < v3.size(); i++)
        cout << "v3 : " << v3.at(i) << " " << i << endl;

    cout << "\nclear v1" << endl;
    v1.clear();
    cout << "v1 is empty : " << v1.empty() << endl;
    for(size_t i = 0; i < 10; i++)
    {
        cout << "added " << i << " to v1" << endl;
        v1.push_back(i);
    }

    ft::vector<int>::reverse_iterator rit = v1.rbegin();
    ft::vector<int>::reverse_iterator rit2 = v1.rend();

    cout << "reverse iterator : " << *rit << endl;
    cout << "reverse iterator : " << *rit2 << endl;
    cout << "create new iterator with rit" << endl;
    ft::vector<int>::reverse_iterator rit3(rit);
    cout << "reverse iterator rit3(rit): " << *rit3 << endl;

    cout << "fill v1 with iterator of v2" << endl;
    v1.assign(it, it2);
    for(size_t i = 0; i < v1.size(); i++)
        cout << v1.at(i) << endl;
    cout << "\nclear v1 and assign 5 times 3" << endl;
    v1.assign(5, 3);
    for(size_t i = 0; i < v1.size(); i++)
        cout << v1.at(i) << endl;
    cout << "print at index [4]" << endl;
    cout << v1[4] << endl;

    cout << "reserve 10 memory in case I need memory" << endl;
    v1.reserve(10);
    cout << "reserve of v1 : " << v1.capacity() << endl;
    cout << "insert 5 in v1" << endl;
    v1.reserve(5);
    ft::vector<int>::iterator coucou = v1.begin();
    cout << "insert 5 at begin + 1" << endl; 
    v1.insert(coucou + 1, 5);
    for(size_t i = 0; i < v1.size(); i++)
        cout << v1.at(i) << endl;
    v1.erase(v1.begin() + 1);
    cout << "erase begin + 1 (the 5 just added)" << endl;
    for(size_t i = 0; i < v1.size(); i++)
        cout << v1.at(i) << endl;
    cout << "erase with iterator begin to end" << endl;
    v1.erase(v1.begin(), v1.end());
    for(size_t i = 0; i < v1.size(); i++)
        cout << v1.at(i) << endl;
    cout << "v1 is empty ?? : " << v1.empty() << endl;
    cout << "add 1 int and delete it with pop_back()" << endl;
    v1.push_back(10);
    cout << v1[0] << endl;
    v1.pop_back();
    cout << "v1 is empty ?? : " << v1.empty() << endl;
    cout << "swap v1 and v2" << endl;
    v1.swap(v2);
    for(size_t i = 0; i < v1.size(); i++)
        cout << "v1 : " << v1.at(i) << endl;
    cout << "v2 empty : " << v2.empty() << endl;
    cout << "resize v1 with 10" << endl;
    v1.resize(10);
    for(size_t i = 0; i < v1.size(); i++)
        cout << "v1 : " << v1.at(i) << endl;
    cout << "resize v1 with 2" << endl;
    v1.resize(2);
    for(size_t i = 0; i < v1.size(); i++)
        cout << "v1 : " << v1.at(i) << endl;
    system("leaks ft_containers");
    return 0;
}