#pragma once

#include <iostream>

namespace ft
{
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
        typedef ptrdiff_t difference_type;
        typedef T         value_type;
        typedef T*        pointer;
        typedef T&        reference;
    };

    template <class T>
    struct iterator_traits<T* const> 
    {
        typedef ptrdiff_t difference_type;
        typedef T         value_type;
        typedef T*        pointer;
        typedef T&        reference;
    };

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

            reverse_iterator() : _actual() {}

            explicit reverse_iterator(iterator_type value) : _actual(value) {}

            template <class T>
            reverse_iterator(const reverse_iterator<T>& params) : _actual(params) {}

            virtual ~reverse_iterator() {}

            iterator_type base() const
            {
                return _actual;
            }

            operator reverse_iterator<const Iterator>() const
            {
                return _actual;
            }

            reference operator*() const
            {
                Iterator tmp = _actual;
                return *(tmp--);
            }

            reverse_iterator &operator++()
            {
                --_actual;
                return *this;
            }

        protected :

           Iterator _actual;

    };
}