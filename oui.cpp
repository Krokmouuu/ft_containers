#include "vector.hpp"
#include "vector"

int main()
{
	// ft::vector<int> oui;
    ft::vector<int> non (3, 10);
    ft::vector<int> oui (3, 2);
    std::vector<int> real;
    try 
    {
        non.swap(non);
        for (size_t i = 0; i < non.size(); i++)
            cout << non[i] << endl;
        non.swap(non);
        for (size_t i = 0; i < non.size(); i++)
            cout << non[i] << endl;
        // cout << non.at(1) << endl;

        // cout << real.empty() << endl;
    }
    catch (const exception &o)
    {
        cerr << o.what() << endl;
    }
	return 0;
}