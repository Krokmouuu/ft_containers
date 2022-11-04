#include "../stack.hpp"

int main()
{
    ft::stack<int> coucou;

    cout << "push 5 elements in stack" << endl;
    for(size_t i = 0; i < 5; i++)
        coucou.push(i);
    cout << "what on top of stack ?" << endl;
    cout << "top : " << coucou.top() << endl;
    cout << "let's delete stack" << endl;
    cout << "top : " << coucou.top() << endl;
    cout << "delete element" << endl;
    coucou.pop();
    cout << "top : " << coucou.top() << endl;
    cout << "delete element" << endl;
    coucou.pop();
    cout << "top : " << coucou.top() << endl;
    cout << "delete element" << endl;
    coucou.pop();
    cout << "top : " << coucou.top() << endl;
    cout << "delete element" << endl;
    coucou.pop();
    cout << "top : " << coucou.top() << endl;
    coucou.pop();
    cout << "stack empty : " << coucou.empty() << endl;

    system("leaks ft_containers");
    return 0;
}