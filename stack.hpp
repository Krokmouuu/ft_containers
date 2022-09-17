#pragma once

#include "vector.hpp"

//? Ref : https://en.cppreference.com/w/cpp/container/stack

namespace ft
{
    template< class T, class Container = ft::vector<T> >
    class stack
    {
        public :

            typedef T value_type;
            typedef Container container_type;
            typedef size_t size_type;
            typedef typename Container::reference reference;
            typedef typename Container::const_reference const_reference;


            explicit stack(const container_type &params = container_type()) : cont(params) {}
            stack(const stack &params) : cont(params.cont) {}
            stack &operator=(const stack &params)
            {
                if (this != &params)
                {
                    cont = params.cont;
                }
                return *this;
            }

            ~stack() {}

            value_type top()
            {
                return cont.back();
            }

            const value_type& top() const
            {
                return cont.back();
            }

            bool empty() const
            {
               return cont.empty();
            }

            size_type size() const
            {
                return cont.size();
            }

            void push(const value_type &value)
            {
                return cont.push_back(value);
            }

            void pop()
            {
                return cont.pop_back();
            }
            

        protected :

            container_type cont;

            template< class T2, class Container2 >
            friend bool operator==( const ft::stack<T2,Container2>& lhs, const ft::stack<T2,Container2>& rhs );
            template< class T2, class Container2 >
            friend bool operator!=( const ft::stack<T2,Container2>& lhs, const ft::stack<T2,Container2>& rhs );
            template< class T2, class Container2 >
            friend bool operator<=( const ft::stack<T2,Container2>& lhs, const ft::stack<T2,Container2>& rhs );
            template< class T2, class Container2 >
            friend bool operator<( const ft::stack<T2,Container2>& lhs, const ft::stack<T2,Container2>& rhs );
            template< class T2, class Container2 >
            friend bool operator>( const ft::stack<T2,Container2>& lhs, const ft::stack<T2,Container2>& rhs );
            template< class T2, class Container2 >
            friend bool operator>=( const ft::stack<T2,Container2>& lhs, const ft::stack<T2,Container2>& rhs );
    };

    template< class T2, class Container2 >
    bool operator==( const ft::stack<T2,Container2>& lhs, const ft::stack<T2,Container2>& rhs )
    {
        return (lhs.cont == rhs.cont);
    }

    template< class T2, class Container2 >
    bool operator!=( const ft::stack<T2,Container2>& lhs, const ft::stack<T2,Container2>& rhs )
    {
        return (lhs.cont != rhs.cont);
    }

    template< class T2, class Container2 >
    bool operator<=( const ft::stack<T2,Container2>& lhs, const ft::stack<T2,Container2>& rhs )
    {
        return (lhs.cont <= rhs.cont);
    }

    template< class T2, class Container2 >
    bool operator<( const ft::stack<T2,Container2>& lhs, const ft::stack<T2,Container2>& rhs )
    {
        return (lhs.cont < rhs.cont);
    }

    template< class T2, class Container2 >
    bool operator>( const ft::stack<T2,Container2>& lhs, const ft::stack<T2,Container2>& rhs )
    {
        return (lhs.cont > rhs.cont);
    }

    template< class T2, class Container2 >
    bool operator>=( const ft::stack<T2,Container2>& lhs, const ft::stack<T2,Container2>& rhs )
    {
        return (lhs.cont >= rhs.cont);
    }
};