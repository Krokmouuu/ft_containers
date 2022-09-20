#include "map.hpp"

// void realtest(void)
// {
// 	std::map<std::string, int> mapOfWords;
//     // Inserting data in std::map
//     mapOfWords.insert(std::make_pair("earth", 1));
//     mapOfWords.insert(std::make_pair("moon", 2));
//     mapOfWords["sun"] = 3;
//     // Will replace the value of already added key i.e. earth
//     mapOfWords["earth"] = 4;
//     // Iterate through all elements in std::map
//     std::map<std::string, int>::iterator it = mapOfWords.begin();

//     while(it != mapOfWords.end())
//     {
//         std::cout<<it->first<<" :: "<<it->second<<std::endl;
//         it++;
//     }
//     // Check if insertion is successful or not
//     if(mapOfWords.insert(std::make_pair("uwuna", 1)).second == false)
//     {
//         std::cout<<"Element with key 'earth' not inserted because already existed"<<std::endl;
//     }
//     // Searching element in std::map by key.
//     if(mapOfWords.find("mars") != mapOfWords.end())
//         std::cout<<"word 'sun' found"<<std::endl;
//     if(mapOfWords.find("mars") == mapOfWords.end())
//         std::cout<<"word 'mars' not found"<<std::endl;
// 	return ;
// }


void test(void)
{
	ft::map<string, int> coucou;
    coucou.insert(ft::make_pair("earth", 1));
    coucou.insert(ft::make_pair("sun", 3));
    ft::map<string, int>::iterator pp = coucou.begin();
    ft::map<string, int>::iterator pp2 = coucou.end();
    ft::map<string, int> hello(pp, pp2);

    cout << pp->first << endl;
    return ;
}

int main() 
{
    test();
    cout << "------------------------------------" << endl;
    return 0;
}