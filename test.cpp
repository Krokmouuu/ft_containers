#include "vector.hpp"
#include "vector"

int main()
{
    ft::vector<int> oui;
    for (size_t i = 0; i < 10; i++)
        oui.push_back(i);
    // std::vector<int> real;
    // for (size_t i = 0; i < 10; i++)
    //     real.push_back(i);
    // string coucou = oui.back();
    try 
    {
        ft::vector<int>::iterator ok = oui.begin();
        oui.erase(ok);
        for (size_t i = 0; i < oui.size(); i++)
            cout << oui[i] << endl;
        // cout << real.at(0) << endl;
    }
    catch (const exception &o)
    {
        cerr << o.what() << endl;
    }
    // system("leaks ft_containers");
	return 0;
}