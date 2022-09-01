#pragma once

#include <iostream>
#include "vector.hpp"

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

    template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
    struct iterator
    {
        typedef T value_type;
        typedef Distance difference_type;
        typedef Pointer pointer;
        typedef Reference reference;
        typedef Category iterator_category;
    };
    
    template <class Iterator>
    struct iterator_traits
    {
        typedef typename Iterator::iterator_category iterator_category;
        typedef typename Iterator::difference_type difference_type;
        typedef typename Iterator::value_type value_type;
        typedef typename Iterator::pointer pointer;
        typedef typename Iterator::reference reference;
    };
    
    template <class T>
    struct iterator_traits<T*>
    {
        typedef ft::random_access_iterator_tag iterator_category;
        typedef ptrdiff_t difference_type;
        typedef T         value_type;
        typedef T*        pointer;
        typedef T&        reference;
    };

    template <class T>
    struct iterator_traits<T* const> 
    {
        typedef ft::random_access_iterator_tag iterator_category;
        typedef ptrdiff_t difference_type;
        typedef T         value_type;
        typedef const T*        pointer;
        typedef const T&        reference;
    };

    template<typename Iterator, typename container>
    class classic_iterator
    {
        protected :

            Iterator _val;
            typedef iterator_traits<Iterator> traits_type;

        public :

            typedef Iterator    iterator_type;
            typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
            typedef typename iterator_traits<Iterator>::value_type value_type;
            typedef typename iterator_traits<Iterator>::difference_type difference_type;
            typedef typename iterator_traits<Iterator>::pointer pointer;
            typedef typename iterator_traits<Iterator>::reference reference;

            classic_iterator() : _val() {}
            
            explicit classic_iterator(iterator_type value) : _val(value) {}

            classic_iterator(const classic_iterator &params) : _val(params._val) {}

            template <class T>
            classic_iterator(const classic_iterator<T, container> &params) : _val(params.base()) {} 

            virtual ~classic_iterator() {}

            iterator_type base() const
            {
                return _val;
            }

            reference operator*() const
            {
                Iterator tmp = _val;
                return *++tmp;
            }

            pointer operator->() const
            {
                return &(operator*());
            }

            classic_iterator& operator++()
            {
                ++_val;
                return *this;
            }

            classic_iterator operator++(int)
            {
                classic_iterator tmp = *this;
                ++_val;
                return tmp;
            }

            classic_iterator& operator--()
            {
                --_val;
                return *this;
            }

            classic_iterator operator--(int)
            {
                classic_iterator tmp = *this;
                --_val;
                return tmp;
            }

            classic_iterator operator+(difference_type n) const
            {
                return classic_iterator(_val + n);
            }


            classic_iterator& operator+=(difference_type n)
            {
               _val += n;
               return *this;
            }

            classic_iterator operator-(difference_type n) const
            {
                return classic_iterator(_val - n);
            }

            classic_iterator& operator-=(difference_type n)
            {
                _val -= n;
                return *this;
            }

            reference operator[](difference_type n) const
            {
                return *(*this + n);
            }
    };

        template<typename Iterator1, typename Iterator2, typename container>
        bool operator==(const ft::classic_iterator<Iterator1, container>& x, const ft::classic_iterator<Iterator2, container>& y)
        {
            return x.base() == y.base();
        }

        template<typename Iterator1, typename Iterator2, typename container>
        bool operator<(const classic_iterator<Iterator1, container>& x, const classic_iterator<Iterator2, container>& y)
        {
            return y.base() < x.base();
        }

        template<typename Iterator1, typename Iterator2, typename container>
        bool operator>(const classic_iterator<Iterator1, container>& x, const classic_iterator<Iterator2, container>& y)
        {
            return y < x;
        }

        template<typename Iterator1, typename Iterator2, typename container>
        bool operator<=(const classic_iterator<Iterator1, container>& x, const classic_iterator<Iterator2, container>& y)
        {
            return !(y < x);
        }

        template<typename Iterator1, typename Iterator2, typename container>
        bool operator>=(const classic_iterator<Iterator1, container>& x, const classic_iterator<Iterator2, container>& y)
        {
            return !(x < y);
        }

        template<typename Iterator1, typename Iterator2, typename container>
        bool operator!=(const classic_iterator<Iterator1, container>& x, const classic_iterator<Iterator2, container>& y)
        {
            return !(x.base() == y.base());
        }

    template <class Iterator>
    class reverse_iterator
    {
        public :

            typedef Iterator    iterator_type;
            typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
            typedef typename iterator_traits<Iterator>::value_type value_type;
            typedef typename iterator_traits<Iterator>::difference_type difference_type;
            typedef typename iterator_traits<Iterator>::pointer pointer;
            typedef typename iterator_traits<Iterator>::reference reference;

        protected :

            Iterator _actual;
        
            typedef iterator_traits<Iterator> traits_type;
        
        public :

            reverse_iterator() : _actual() {}

            explicit reverse_iterator(iterator_type value) : _actual(value) {}

            reverse_iterator(const reverse_iterator& params) : _actual(params._actual) {}
        
            template <class T>
            reverse_iterator(const reverse_iterator<T> &params) : _actual(params.base()) {}

            virtual ~reverse_iterator() {}

            iterator_type base() const
            {
                return _actual;
            }

            reference operator*() const
            {
                Iterator tmp = _actual;
                return *--tmp;
            }

            pointer operator->() const
            {
                return &(operator*());
            }

            reverse_iterator& operator++()
            {
                --_actual;
                return *this;
            }

            reverse_iterator operator++(int)
            {
                reverse_iterator tmp = *this;
                --_actual;
                return tmp;
            }

            reverse_iterator& operator--()
            {
                ++_actual;
                return *this;
            }

            reverse_iterator operator--(int)
            {
                reverse_iterator tmp = *this;
                ++_actual;
                return tmp;
            }

            reverse_iterator operator+(difference_type n) const
            {
                return reverse_iterator(_actual - n);
            }

            reverse_iterator& operator+=(difference_type n)
            {
               _actual -= n;
               return *this;
            }

            reverse_iterator operator-(difference_type n) const
            {
                return reverse_iterator(_actual + n);
            }

            reverse_iterator& operator-=(difference_type n)
            {
                _actual += n;
                return *this;
            }

            reference operator[](difference_type n) const
            {
                return *(*this + n);
            }
    };

        template<typename Iterator1, typename Iterator2>
        bool operator==(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y)
        {
            return x.base() == y.base();
        }

        template<typename Iterator1, typename Iterator2>
        bool operator<(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y)
        {
            return y.base() < x.base();
        }

        template<typename Iterator1, typename Iterator2>
        bool operator>(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y)
        {
            return y < x;
        }

        template<typename Iterator1, typename Iterator2>
        bool operator<=(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y)
        {
            return !(y < x);
        }

        template<typename Iterator1, typename Iterator2>
        bool operator>=(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y)
        {
            return !(x < y);
        }

        template<typename Iterator1, typename Iterator2>
        bool operator!=(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y)
        {
            return !(x.base() == y.base());
        }
};