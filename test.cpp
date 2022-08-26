#include "vector.hpp"
#include "vector"

int main()
{
	// ft::vector<int> oui;
    // ft::vector<int> non (5, 10);
    ft::vector<string> oui (5, "blabla");
    // std::vector<int> real(3, 20);
    // ft::vector<string>::iterator uwu = oui.begin();
    ft::vector<string>::iterator ok = oui.end();
    // string coucou = oui.back();
    try 
    {
        ok--;
       cout << *ok << endl;
    }
    catch (const exception &o)
    {
        cerr << o.what() << endl;
    }
    // system("leaks ft_containers");
	return 0;
}