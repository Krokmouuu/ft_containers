#pragma once

#include "iterator.hpp"
#include "random_access_iterator.hpp"
#include "../Utilities/enable_if.hpp"

namespace ft 
{

    template <typename T>
    class random_access_iterator : public ft::iterator<ft::random_access_iterator_tag, T> 
    {
        protected:
            T* _val;

        public:
            typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category iterator_category;
            typedef T* pointer;
            typedef T& reference;
            typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type difference_type;        
            typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type value_type;

            random_access_iterator(pointer _val = NULL) : _val(_val){};

            random_access_iterator(const random_access_iterator<T>& other) : _val(other._val) {};
            
            ~random_access_iterator() {}

            operator random_access_iterator<const T>() const 
            { 
                return this->_val; 
            }

            pointer base() const 
            {
                return _val;
            }

            reference operator*() const 
            {
                return *_val;
            }

            pointer operator->() const 
            {
                return &(operator *());
            }

            reference operator[](difference_type n) const 
            {
                return *(*this+n);
            }

            random_access_iterator& operator++() 
            {
                ++_val;
                return *this;
            }

            random_access_iterator& operator--() 
            {
                --_val;
                return *this;
            }

            random_access_iterator operator++(int) 
            {
                random_access_iterator tmp = *this;
                ++_val;
                return tmp;
            }

            random_access_iterator operator--(int)
            {
                random_access_iterator tmp = *this;
                --_val;
                return tmp;
            }

            random_access_iterator operator+(difference_type n) const 
            {
                return random_access_iterator(_val + n);
            }

            random_access_iterator operator-(difference_type n) const 
            {
                return random_access_iterator(_val - n);
            }

            random_access_iterator& operator+=(difference_type n) 
            {
                _val += n;
                return *this;
            }

            random_access_iterator& operator-=(difference_type n) 
            {
                _val -= n;
                return *this;
            }
        };

    template <class Iterator1, class Iterator2>
    bool operator==(const ft::random_access_iterator<Iterator1>& lhs,const ft::random_access_iterator<Iterator2>& rhs) 
    {
        return (lhs.base() == rhs.base());
    }

    template <class Iterator1, class Iterator2>
    bool operator!=(const ft::random_access_iterator<Iterator1>& lhs, const ft::random_access_iterator<Iterator2>& rhs) 
    {
        return (lhs.base() != rhs.base());
    }

    template <class Iterator1, class Iterator2>
    bool operator<(const ft::random_access_iterator<Iterator1>& lhs, const ft::random_access_iterator<Iterator2>& rhs) 
    {
        return (lhs.base() < rhs.base());
    }
    template <class Iterator1, class Iterator2>
    bool operator<=(const ft::random_access_iterator<Iterator1>& lhs, const ft::random_access_iterator<Iterator2>& rhs) 
    {
        return (lhs.base() <= rhs.base());
    }

    template <class Iterator1, class Iterator2>
    bool operator>(const ft::random_access_iterator<Iterator1>& lhs, const ft::random_access_iterator<Iterator2>& rhs) 
    {
        return (lhs.base() > rhs.base());
    }

    template <class Iterator1, class Iterator2>
    bool operator>=(const ft::random_access_iterator<Iterator1>& lhs, const ft::random_access_iterator<Iterator2>& rhs) 
    {
        return (lhs.base() >= rhs.base());
    }

    template <class Iter>
    ft::random_access_iterator<Iter> operator+(typename ft::random_access_iterator<Iter>::difference_type n, const ft::random_access_iterator<Iter>& it) 
    {
        return ft::random_access_iterator<Iter>(it.base() + n);
    }

    template <class Iterator1, class Iterator2>
    typename ft::random_access_iterator<Iterator1>::difference_type operator-(const ft::random_access_iterator<Iterator1>& lhs, const ft::random_access_iterator<Iterator2>& rhs) 
    {
        return lhs.base() - rhs.base();
    }
};