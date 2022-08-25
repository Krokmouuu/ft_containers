#include "vector.hpp"
#include "vector"

int main()
{
	// ft::vector<int> oui;
    // ft::vector<int> non (5, 10);
    ft::vector<int> oui (5, 5);
    // std::vector<int> real(3, 20);
    ft::vector<int>::iterator uwu;
    try 
    {
       cout << "cc" << endl;
    }
    catch (const exception &o)
    {
        cerr << o.what() << endl;
    }
    // system("leaks ft_containers");
	return 0;
}