#include "../set.hpp"

int main()
{
    ft::set<string> setOfNumbers;
    cout << "Insert 3 elements" << endl;
    setOfNumbers.insert("first");
    setOfNumbers.insert("second");
    setOfNumbers.insert("third");

    cout << "create iterator, he trying to find everything until 'second'" << endl;
    ft::set<string>::iterator it = setOfNumbers.find("second");
    if(it != setOfNumbers.end())
        std::cout<<"'first'  found"<<std::endl;
    else
        std::cout<<"'first' not found"<<std::endl;
   cout << "Trying to find 'fourth'" << endl;
    it = setOfNumbers.find("fourth");
    if(it != setOfNumbers.end())
        std::cout<<"'fourth'  found"<<std::endl;
    else
        std::cout<<"'fourth' not found"<<std::endl;
    cout << "Erase 'second'" << endl;
    setOfNumbers.erase("second");
    it = setOfNumbers.find("second");
    if (it != setOfNumbers.end())
        cout << "Second found" << endl;
    else
        cout << "Second not found" << endl;
    
    cout << "creating set2 with 5 elements and swap ";
    ft::set<string> set2;
    set2.insert("1");
    set2.insert("2");
    set2.insert("3");
    set2.insert("4");
    set2.insert("5");
    set2.swap(setOfNumbers);
    cout << "Let's see the size the size will be different" << endl;
    cout << "size of set 1 : " << setOfNumbers.size() << endl;
    cout << "size of set 2 : " << set2.size() << endl;
    cout << "Set don't allow duplicate so the function count return a 0 or 1 if the containers contain the element, '1' exist ? : " << setOfNumbers.count("1") << endl;
    cout << "ok, '56' exist ? : " << setOfNumbers.count("56") << endl << endl;

    cout << "Iterator find the value upper 2 : ";
    it = setOfNumbers.upper_bound("2");
    cout << *it << endl;
    ft::pair<ft::set<string>::iterator, ft::set<string>::iterator> it2;
    it2 = setOfNumbers.equal_range("4");
    cout << "Now equal range return lower and upper bound of 4" << endl;
    cout << *it2.first << " and " << *it2.second << endl << endl;

    cout << "Last test, create a set with 2 iterators" << endl;
    ft::set<string> set3(setOfNumbers.begin(), setOfNumbers.end());
    cout << "set3 created with set1 (1, 2, 3, 4, 5) so the size = " << set3.size() << endl;
    system("leaks ft_containers");
    return 0;
}