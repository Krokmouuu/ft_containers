#include "vector.hpp"
#include "vector"
#include <list>

#define T_SIZE_TYPE typename std::vector<T>::size_type

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

template <typename T>
void	print(std::vector<T> const &vct, bool cc = true)
{
	const T_SIZE_TYPE size = vct.size();
	const T_SIZE_TYPE capacity = vct.capacity();
	const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";
	// Cannot limit capacity's max value because it's implementation dependent

	std::cout << "size: " << size << std::endl;
	std::cout << "capacity: " << isCapacityOk << std::endl;
	std::cout << "max_size: " << vct.max_size() << std::endl;
	if (cc)
	{
		typename std::vector<T>::const_iterator it = vct.begin();
		typename std::vector<T>::const_iterator ite = vct.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << *it << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

// void	checkErase(std::vector<string> const &vct,
// 					std::vector<string>::const_iterator const &it)
// {
// 	static int i = 0;
// 	std::cout << "[" << i++ << "] " << "erase: " << it - vct.begin() << std::endl;
// 	printSize(vct);
// }

void realtest(void)
{
	std::vector<int> vct(5);
	std::vector<int> vct2;
	const int cut = 3;

	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = (vct.size() - i) * 7;
	print(vct);

	vct2.insert(vct2.begin(), vct.begin(), vct.begin() + cut);
	print(vct2);
	vct2.insert(vct2.begin(), vct.begin() + cut, vct.end());
	print(vct2);
	vct2.insert(vct2.end(), vct.begin(), vct.begin() + cut);
	print(vct2);

	std::cout << "insert return:" << std::endl;

	std::cout << *vct2.insert(vct2.end(), 42) << std::endl;

	std::cout << *vct2.insert(vct2.begin() + 5, 84) << std::endl;
	// std::cout << "----------------------------------------" << std::endl;

	// print(vct2);

}

void		test(void)
{
	ft::vector<int> vct(5);
	ft::vector<int> vct2;
	const int cut = 3;

	ft::vector<int>::iterator oo = vct2.begin();

	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = (vct.size() - i) * 7;
	printSize(vct);

	vct2.insert(oo + 2, 42);
	vct2.insert(oo + 2, 42);
	vct2.insert(oo + 2, 42);
	vct2.insert(vct2.begin(), vct.begin(), vct.begin() + cut);
	printSize(vct2);
	vct2.insert(vct2.begin(), vct.begin() + cut, vct.end());
	printSize(vct2);
	vct2.insert(vct2.end(), vct.begin(), vct.begin() + cut);
	printSize(vct2);

	std::cout << "insert return:" << std::endl;

	std::cout << *vct2.insert(vct2.end(), 42) << std::endl;
	// std::cout << *vct2.insert(vct2.begin() + 5, 84) << std::endl;
	// std::cout << "----------------------------------------" << std::endl;

	// printSize(vct2);

	return ;
}

int		main(void)
{
	test();
	cout << endl << endl << "-----------------------------------------" << endl << endl;
	realtest();
	// system("leaks std_containers");
	return (0);
}
