#include "vector.hpp"
#include "vector"

int main()
{
	// ft::vector<int> oui;
    ft::vector<int> non (5, 10);
    ft::vector<int> oui (3, 2);
    std::vector<int> real(3, 20);
    try 
    {
        oui.assign(10, 10);
        for (size_t i= 0; i < oui.size(); i++)
            cout << oui[i] << endl;
        real.get_allocator();
        oui.get_allocator();
    }
    catch (const exception &o)
    {
        cerr << o.what() << endl;
    }
    // system("leaks ft_containers");
	return 0;
}