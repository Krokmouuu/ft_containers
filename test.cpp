#include "vector.hpp"
#include "vector"
#include <list>
#include "stack"
#include "stack.hpp"

template <typename T_STACK>
void	print(T_STACK &stck, bool print_content = 1)
{
	std::cout << "size: " << stck.size() << std::endl;
	if (print_content)
	{
		std::cout << std::endl << "Content was:" << std::endl;
		while (stck.size() != 0) {
			std::cout << "- " << stck.top() << std::endl;
			stck.pop();
		}
	}
	std::cout << "###############################################" << std::endl;
}


template <typename T_STACK>
void	printSize(T_STACK &stck, bool print_content = 1)
{
	std::cout << "size: " << stck.size() << std::endl;
	if (print_content)
	{
		std::cout << std::endl << "Content was:" << std::endl;
		while (stck.size() != 0) {
			std::cout << "- " << stck.top() << std::endl;
			stck.pop();
		}
	}
	std::cout << "###############################################" << std::endl;
}

// void realtest(void)
// {
// 	std::stack<int>	ctnr;

// 	ctnr.push_back(21);
// 	ctnr.push_back(42);
// 	ctnr.push_back(1337);
// 	ctnr.push_back(19);
// 	ctnr.push_back(0);
// 	ctnr.push_back(183792);

// 	std::stack<int>	stck(ctnr);
// 	std::stack<int>	stck2(cntr);

// 	cmp(stck, stck);  // 0
// 	cmp(stck, stck2); // 1

// 	stck2.push(60);
// 	stck2.push(61);
// 	stck2.push(62);

// 	cmp(stck, stck2); // 2
// 	cmp(stck2, stck); // 3

// 	stck.push(42);

// 	cmp(stck, stck2); // 4
// 	cmp(stck2, stck); // 5

// 	stck.push(100);

// 	cmp(stck, stck2); // 6
// 	cmp(stck2, stck); // 7
	
// 	return ;
// }


void test(void)
{
	return ;
}

int		main(void)
{
	test();
	cout << endl << endl << "-----------------------------------------" << endl << endl;
	// realtest();
	system("leaks ft_containers");
	return (0);
}
a