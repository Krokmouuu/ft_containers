#pragma once

#include <cstddef>
#include <iostream>

//? Ref : https://en.cppreference.com/w/cpp/iterator/iterator
//? Ref : https://en.cppreference.com/w/cpp/iterator/iterator_traits
//? Ref : https://en.cppreference.com/w/cpp/iterator/reverse_iterator

namespace ft 
{
    struct input_iterator_tag {};
    struct output_iterator_tag {};
    struct forward_iterator_tag : public input_iterator_tag {};
    struct bidirectional_iterator_tag : public forward_iterator_tag {};
    struct random_access_iterator_tag : public bidirectional_iterator_tag {};

    template <class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T&>
    struct iterator 
    {
        typedef Category iterator_category;
        typedef T value_type;
        typedef Distance difference_type;
        typedef Pointer pointer;
        typedef Reference reference;
    };

    template <class Iterator>
    struct iterator_traits
    {
        typedef typename Iterator::iterator_category iterator_category;
        typedef typename Iterator::value_type value_type;
        typedef typename Iterator::difference_type difference_type;
        typedef typename Iterator::pointer pointer;
        typedef typename Iterator::reference reference;
    };

    template <class T>
    struct iterator_traits<T*> 
    {
        typedef ptrdiff_t difference_type;
        typedef T value_type;
        typedef T* pointer;
        typedef T& reference;
        typedef ft::random_access_iterator_tag iterator_category;
    };


    template <class T>
    struct iterator_traits<T* const> 
    {
        typedef ptrdiff_t difference_type;
        typedef T value_type;
        typedef const T* pointer;
        typedef const T& reference;
        typedef ft::random_access_iterator_tag iterator_category;
    };

    template <class Iterator>
    class reverse_iterator
    {
        public:
            typedef Iterator iterator_type;
            typedef iterator_traits<Iterator> traits;

        protected:
            Iterator _value;

        public:
            typedef typename traits::iterator_category iterator_category;
            typedef typename traits::value_type value_type;
            typedef typename traits::difference_type difference_type;
            typedef typename traits::pointer pointer;
            typedef typename traits::reference reference;

        reverse_iterator() : _value() {}
        
        explicit reverse_iterator(iterator_type x) : _value(x) {}

        template <class Other>
        reverse_iterator(const reverse_iterator<Other>& other) : _value(other.base()) {}

        virtual ~reverse_iterator(){};

        iterator_type base() const 
        { 
            return _value; 
        }

        operator reverse_iterator<const Iterator>() const 
        { 
            return this->_value; 
        }

        reference operator*() const 
        { 
            iterator_type tmp = _value; 
            return *(--tmp); 
        }
       
        pointer operator->() const 
        { 
            return &(operator*()); 
        }

        reference operator[](difference_type n) const 
        {
            return *(*this + n); 
        }
        
        reverse_iterator& operator++() 
        {
            --_value;
            return *this;
        }

        reverse_iterator& operator--() 
        {
            ++_value;
            return *this;
        }

        reverse_iterator operator++(int) 
        {
            reverse_iterator tmp = *this;
            --_value;
            return tmp;
        }

        reverse_iterator operator--(int) 
        {
            reverse_iterator tmp = *this;
            ++_value;
            return tmp;
        }

        reverse_iterator operator+(difference_type n) const 
        {
            return reverse_iterator(_value - n);
        }

        reverse_iterator operator-(difference_type n) const 
        {
            return reverse_iterator(_value + n);
        }

        reverse_iterator& operator+=(difference_type n) 
        {
            _value -= n;
            return *this;
        }

        reverse_iterator& operator-=(difference_type n) 
        {
            _value += n;
            return *this;
        }
    };

    template <class Iterator1, class Iterator2>
    bool operator==(const ft::reverse_iterator<Iterator1>& lhs,const ft::reverse_iterator<Iterator2>& rhs) 
    {
        return (lhs.base() == rhs.base());
    }

    template <class Iterator1, class Iterator2>
    bool operator!=(const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs) 
    {
        return (lhs.base() != rhs.base());
    }

    template <class Iterator1, class Iterator2>
    bool operator<(const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs) 
    {
        return (lhs.base() > rhs.base());
    }

    template <class Iterator1, class Iterator2>
    bool operator>(const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs) 
    {
        return (lhs.base() < rhs.base());
    }

    template <class Iterator1, class Iterator2>
    bool operator<=(const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs) 
    {
        return (lhs.base() >= rhs.base());
    }

    template <class Iterator1, class Iterator2>
    bool operator>=(const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs) 
    {
        return (lhs.base() <= rhs.base());
    }

    template <class Iter>
    ft::reverse_iterator<Iter> operator+(typename ft::reverse_iterator<Iter>::difference_type n, const ft::reverse_iterator<Iter>& it) 
    {
        return ft::reverse_iterator<Iter>(it.base() - n);
    }
    
    template <class Iterator, class Iterator2>
    typename ft::reverse_iterator<Iterator>::difference_type operator-(const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator2>& rhs) 
    {
        return rhs.base() - lhs.base();
    }

};