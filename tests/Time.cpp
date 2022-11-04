
#include "../vector.hpp"
#include "../map.hpp"
#include "../stack.hpp"
#include <vector>
#include <map>
#include <stack>
#include <iostream>
#include <string>

#include <ctime>
#include <sstream>
#include <sys/time.h>

void test_vector()
{
    struct timeval tp;
    gettimeofday(&tp, NULL);
    long int begin = tp.tv_sec * 1000 + tp.tv_usec / 1000; 
    ft::vector<std::string>   map_ft;
    ft::vector<std::string>   map_ft2;

    for (int i = 1; i < 1000000; i++)
    {
        map_ft.back();
        map_ft.capacity();
        map_ft.empty();
        map_ft.front();
        map_ft.erase(map_ft.begin());
        map_ft.push_back(std::to_string(i));
        map_ft.pop_back();
        map_ft.push_back(std::to_string(i));
        map_ft.size();
        map_ft.swap(map_ft2);
        map_ft2.swap(map_ft);
    }
    map_ft.erase(map_ft.begin(), map_ft.end());
    gettimeofday(&tp, NULL);
    long int end = tp.tv_sec * 1000 + tp.tv_usec / 1000; 
        
    gettimeofday(&tp, NULL);
    long int begin2 = tp.tv_sec * 1000 + tp.tv_usec / 1000; 
     
    std::vector<std::string>  map_std;
    std::vector<std::string>  map_std2;
    for (int i = 1; i < 10000; i++)
    {
        map_std.insert(map_std.begin(), std::to_string(i));
        map_std.back();
        map_std.capacity();
        map_std.empty();
        map_std.front();
        map_std.erase(map_std.begin());
        map_std.push_back(std::to_string(i));
        map_std.pop_back();
        map_std.push_back(std::to_string(i));
        map_std.size();
        map_std.swap(map_std2);
        map_std2.swap(map_std);
    }
    map_std.erase(map_std.begin(), map_std.end());
    gettimeofday(&tp, NULL);
    long int end2 = tp.tv_sec * 1000 + tp.tv_usec / 1000; 
     
    unsigned int res1 = (end - begin);
    unsigned int res2 = (end2 - begin2);
    std::cout << res1 << "/" << res2 << " : " << (float)res1/(float)res2 << std::endl;

}

void test_map()
{
    struct timeval tp;
    gettimeofday(&tp, NULL);
    long int begin = tp.tv_sec * 1000 + tp.tv_usec / 1000; 
     
    ft::map<std::string, int>   map_ft;
    ft::map<std::string, int>   map_ft2;

    for (int i = 1; i < 30000; i++)
    {
        map_ft.insert(ft::make_pair<std::string>(std::to_string(i), i));
        map_ft.find(std::to_string(i));
        map_ft.count(std::to_string(i));
        map_ft.empty();
        map_ft.size();
        map_ft.begin(); map_ft.end();
        map_ft.erase(std::to_string(i));
        map_ft.insert(ft::make_pair<std::string>(std::to_string(i), i));
        map_ft.swap(map_ft2);
        map_ft2.swap(map_ft);
    }
    map_ft.erase(map_ft.begin(), map_ft.end());
    gettimeofday(&tp, NULL);
    long int end = tp.tv_sec * 1000 + tp.tv_usec / 1000; 
     
        
    gettimeofday(&tp, NULL);
    long int begin2 = tp.tv_sec * 1000 + tp.tv_usec / 1000; 
    std::map<std::string, int>  map_std;
    std::map<std::string, int>  map_std2;
    for (int i = 1; i < 30000; i++)
    {
        map_std.insert(std::make_pair<std::string>(std::to_string(i), i));
        map_std.find(std::to_string(i));
        map_std.count(std::to_string(i));
        map_std.empty();
        map_std.size();
        map_std.begin(); map_std.end();
        map_std.erase(std::to_string(i));
        map_std.insert(std::make_pair<std::string>(std::to_string(i), i));
        map_std.swap(map_std2);
        map_std2.swap(map_std2);
    }
    map_std.erase(map_std.begin(), map_std.end());
    gettimeofday(&tp, NULL);
    long int end2 = tp.tv_sec * 1000 + tp.tv_usec / 1000; 
    unsigned int res1 = (end - begin);
    unsigned int res2 = (end2 - begin2);
    std::cout << res1 << "/" << res2 << " : " << (float)res1/(float)res2 << std::endl;
}

void test_stack()
{
    struct timeval tp;
    gettimeofday(&tp, NULL);
    long int begin = tp.tv_sec * 1000 + tp.tv_usec / 1000; 
    ft::stack<std::string>   map_ft;

    for (int i = 1; i < 100000; i++)
    {
      map_ft.push(std::to_string(i));
      map_ft.pop();
      map_ft.size();
      map_ft.empty();
    }
    gettimeofday(&tp, NULL);
    long int end = tp.tv_sec * 1000 + tp.tv_usec / 1000; 
   
    gettimeofday(&tp, NULL);
    long int begin2 = tp.tv_sec * 1000 + tp.tv_usec / 1000; 
    std::stack<std::string>  map_std;
    std::stack<std::string>  map_std2;
    for (int i = 1; i < 100000; i++)
    {
      map_std.push(std::to_string(i));
      map_std.pop();
      map_std.push(std::to_string(i));
      map_std.size();
    }
    gettimeofday(&tp, NULL);
    long int end2 = tp.tv_sec * 1000 + tp.tv_usec / 1000; 
    unsigned int res1 = (end - begin);
    unsigned int res2 = (end2 - begin2);
    std::cout << res1 << "/" << res2 << " : " << (float)res1/(float)res2 << std::endl;

}

int main()
{
    std::cout << "TIME VECTOR : " << std::endl;
    test_vector();
    std::cout << "TIME MAP: " << std::endl;
    test_map();
    std::cout << "TIME STACK: " << std::endl;
    test_stack();
}