#pragma once

#include "../Iterators/iterator.hpp"
#include "enable_if.hpp"

//? Ref : https://en.cppreference.com/w/cpp/algorithm/lexicographical_compare

namespace ft 
{
    template< class InputIt1, class InputIt2 >
    bool equal( InputIt1 first1, InputIt1 last1, InputIt2 first2)
    {
        for (; first1 != last1; ++first1, ++first2)
            if (!bool(*first1 == *first2))
                return false;
        return true;
    }

    template< class InputIt1, class InputIt2, class BinaryPredicate >
    bool equal( InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate p)
    {
        for (; first1 != last1; ++first1, ++first2)
            if (!bool(p(*first1, *first2)))
                return false;
        return true;
    }

    template < class InputIterator1, class InputIterator2 >
    bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
    {
        for (; (first1 != last1) && (first2 != last2); ++first1, (void)++first2) 
        {
            if (*first1 < *first2) 
                return true;
            if (*first2 < *first1) 
                return false;
        }
        return (first1 == last1) && (first2 != last2);
    }

    template<class InputIt1, class InputIt2, class Compare>
    bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Compare comp)
    {
        for (; (first1 != last1) && (first2 != last2); ++first1, (void)++first2)
        {
            if (comp(*first1, *first2))
                return true;
            if (comp(*first2, *first1))
                return false;
        }
        return (first1 == last1) && (first2 != last2);
    }

    template <typename T>
    struct Identity 
    {
        T& operator()(T& other) const 
        { 
            return other; 
        }
        const T& operator()(const T& other) const 
        { 
            return other;
        }
    };
}