#include "vector.hpp"
#include "vector"
#include <list>

#define T_SIZE_TYPE typename ft::vector<T>::size_type

template <typename T>
void	printSize(ft::vector<T> const &vct, bool print_content = true)
{
	const T_SIZE_TYPE size = vct.size();
	const T_SIZE_TYPE capacity = vct.capacity();
	const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";
	// Cannot limit capacity's max value because it's implementation dependent

	std::cout << "size: " << size << std::endl;
	std::cout << "capacity: " << isCapacityOk << std::endl;
	std::cout << "max_size: " << vct.max_size() << std::endl;
	if (print_content)
	{
		typename ft::vector<T>::const_iterator it = vct.begin();
		typename ft::vector<T>::const_iterator ite = vct.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << *it << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}


void test(void)
{
	ft::vector<int> vct(10);
	ft::vector<int> vct2;
	ft::vector<int> vct3;

	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = (vct.size() - i) * 3;
	cout << "NON" << endl;
	printSize(vct);

	vct2.insert(vct2.end(), 42);
	vct2.insert(vct2.begin(), 2, 21);
	cout << "OUI" << endl;
	printSize(vct2);

	vct2.insert(vct2.end() - 2, 42);
	cout << "BOF" << endl;
	printSize(vct2);

	vct2.insert(vct2.end(), 2, 84);
	cout << "UWU" << endl;
	printSize(vct2);

	vct2.resize(4);
	cout << "HAHAHAHA" << endl;
	printSize(vct2);

	vct2.insert(vct2.begin() + 2, vct.begin(), vct.end());
	vct.clear();
	printSize(vct2);

	cout << "sdgsdgsdgds" << endl;
	printSize(vct);

	for (int i = 0; i < 5; ++i)
		vct3.insert(vct3.end(), i);
	vct3.insert(vct3.begin() + 1, 2, 111);
	cout << "NFPSAbhfu9pswFGBWUOEFBO" << endl;
	printSize(vct3);
	return ;
}

// int		main(void)
// {
// 	ft::vector<int> vct(5);
// 	ft::vector<int> vct2;
// 	const int cut = 3;

// 	for (unsigned long int i = 0; i < vct.size(); ++i)
// 		vct[i] = (vct.size() - i) * 7;
// 	printSize(vct);

// 	vct2.insert(vct2.begin(), vct.begin(), vct.begin() + cut);
// 	printSize(vct2);
// 	vct2.insert(vct2.begin(), vct.begin() + cut, vct.end());
// 	printSize(vct2);
// 	vct2.insert(vct2.end(), vct.begin(), vct.begin() + cut);
// 	printSize(vct2);

// 	std::cout << "insert return:" << std::endl;

// 	std::cout << *vct2.insert(vct2.end(), 42) << std::endl;
// 	std::cout << *vct2.insert(vct2.begin() + 5, 84) << std::endl;
// 	std::cout << "----------------------------------------" << std::endl;

// 	printSize(vct2);
// 	return (0);
// }

int		main(void)
{
	test();
	// system("leaks ft_containers");
	return (0);
}
