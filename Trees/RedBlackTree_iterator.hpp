#pragma once

#include "../Utilities/enable_if.hpp"
#include "../Iterators/iterator.hpp"
#include "../Utilities/pair.hpp"
#include "../Utilities/compares.hpp"

#include "RedBlackTree_node.hpp"
#include "RedBlackTree.hpp"



namespace ft 
{

    template <typename T>
    struct RBT_iterator 
    {

        typedef T value_type;
        typedef T& reference;
        typedef T* pointer;
        typedef ft::bidirectional_iterator_tag iterator_category;
        typedef ptrdiff_t difference_type;
        typedef RBT_iterator<T> RBIter;
        typedef typename Tree_node<T>::node node;

        Color get_color() 
        { 
            return _current_node->_color;
        }

        node get_link() 
        { 
            return _current_node; 
        }

        RBT_iterator() : _current_node() {}

        explicit RBT_iterator(node x) : _current_node(x) {}

        reference operator*() const 
        { 
            return *_current_node->value; 
        }

        const pointer operator->() const 
        { 
            return &(operator*()); 
        }

        RBIter& operator++() 
        {
            _current_node = tree_increment(_current_node);
            return *this;
        }
        RBIter operator++(int) 
        {
            RBIter tmp = *this;
            _current_node = tree_increment(_current_node);
            return tmp;
        }

        RBIter& operator--() 
        {
            _current_node = tree_decrement(_current_node);
            return *this;
        }

        RBIter operator--(int)
        {
            RBIter tmp = *this;
            _current_node = tree_decrement(_current_node);
            return tmp;
        }

        bool operator==(const RBIter& x) const 
        { 
            return _current_node == x._current_node; 
        }

        bool operator!=(const RBIter& x) const 
        { 
            return _current_node != x._current_node; 
        }

        node _current_node;
    };

    template <typename T>
    struct RBT_const_iterator 
    {
        typedef T value_type;
        typedef const T& reference;
        typedef const T* pointer;
        typedef RBT_iterator<T> RBIter;
        typedef ft::bidirectional_iterator_tag iterator_category;
        typedef ptrdiff_t difference_type;
        typedef RBT_const_iterator<T> RBT_const_iter;
        typedef const Tree_node<T>* node;

        RBT_const_iterator() : _current_node() {}

        explicit RBT_const_iterator(node x) : _current_node(x) {}

        RBT_const_iterator(const RBIter& x) : _current_node(x._current_node) {}

        RBIter const_current_node() const 
        { 
            return RBIter(const_cast<typename RBIter::node>(_current_node)); 
        }

        reference operator*() const 
        { 
            return *_current_node->value; 
        }

        const pointer operator->() const 
        { 
            return &(operator*()); 
        }

        RBT_const_iter& operator++() 
        {
            _current_node = tree_increment(_current_node);
            return *this;
        }

        RBT_const_iter operator++(int) 
        {
            RBT_const_iter tmp = *this;
            _current_node = tree_increment(_current_node);
            return tmp;
        }

        RBT_const_iter& operator--() 
        {
            _current_node = tree_decrement(_current_node);
            return *this;
        }

        RBT_const_iter operator--(int) 
        {
            RBT_const_iter tmp = *this;
            _current_node = tree_decrement(_current_node);
            return tmp;
        }

        bool operator==(const RBT_const_iter& x) const 
        { 
            return _current_node == x._current_node; 
        }

        bool operator!=(const RBT_const_iter& x) const 
        {
            return _current_node != x._current_node; 
        }

        node _current_node;
    };

    template <typename T>
    inline bool operator!=(const RBT_iterator<T>& x, const RBT_const_iterator<T>& y) 
    {
        return x._current_node != y._current_node;
    }

    template <typename T>
    static Tree_node<T>* staticTree_increment(Tree_node<T>* x) 
    {
        if (x->child_right == x) 
            return x;
        if (x->child_right != 0) 
        {
            x = x->child_right; 
            while (x->child_left != 0) 
                x = x->child_left; 
        }
        else 
        {
            Tree_node<T>* y = x->_parent;
            while (x == y->child_right) 
            {
                x = y;
                y = y->_parent;
            }
            if (x->child_right != y)
                x = y;
        }
        return x;
    } 

    template <typename T>
    Tree_node<T>* tree_increment(Tree_node<T>* x) 
    {
        return staticTree_increment(x);
    }

    template <typename T>
    const Tree_node<T>* tree_increment(const Tree_node<T>* x) 
    {
        return staticTree_increment(const_cast<Tree_node<T>*>(x));
    }

    template <typename T>
    static Tree_node<T>* staticTree_decrement(Tree_node<T>* x) 
    {
        if (x->child_right == x) 
            return x;
        if (x->_color == RED && x->_parent->_parent == x) 
            x = x->child_right;
        else if (x->child_left != 0) 
        {
            Tree_node<T>* y = x->child_left;
                while (y->child_right != 0) y = y->child_right;
                x = y;
        } 
        else 
        {
            Tree_node<T>* y = x->_parent;
            while (x == y->child_left) {x = y; y = y->_parent;}
                x = y;
        }
        return x;
    }

    template <typename T>
    Tree_node<T>* tree_decrement(Tree_node<T>* x) 
    {
        return staticTree_decrement(x);
    }

    template <typename T>
    const Tree_node<T>* tree_decrement(const Tree_node<T>* x) 
    {
        return staticTree_decrement(const_cast<Tree_node<T>*>(x));
    }

} //! ft 