#include "vector.hpp"
#include "vector"

int main()
{
	// ft::vector<int> oui;
    ft::vector<string> non (2, "uwu");
    // std::vector<char> letters {'o', 'm', 'g', 'w', 't', 'f'};
    non.at(0) = "owo";
    try 
    {
        cout << non.back() << endl;
    }
    catch (const exception &o)
    {
        cerr << o.what() << endl;
    }
	return 0;
}