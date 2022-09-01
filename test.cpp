#include "vector.hpp"
#include "vector"

int main()
{
    ft::vector<int> oui(5, 10);
    // for (size_t i = 0; i < 10; i++)
    //     oui.push_back(i);
    // std::vector<int> real(5, 10);
    // for (size_t i = 0; i < real.size(); i++)
    //     cout << "Real " << real[i] << endl;
    // string coucou = oui.back();
    try 
    {
        // ft::vector<int>::iterator ok = oui.begin() + 2;
        // ft::vector<int>::iterator ok2 = oui.begin() + 8;
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