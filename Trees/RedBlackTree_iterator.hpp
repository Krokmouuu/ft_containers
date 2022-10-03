#pragma once

#include "RedBlackTree_iterator.hpp"
#include "RedBlackTree_node.hpp"

namespace ft {

    template<typename T>
        struct RBTree_iterator
        {
            public :

                typedef T value_type;
                typedef T& reference;
                typedef T* pointer;
                typedef ft::bidirectional_iterator_tag iterator_category;
                typedef ptrdiff_t difference_type;
                typedef RBTree_iterator<T> RBTiter;
                typedef typename Tree_node_base<T>::ptr ptr;

                RBTree_iterator() : _current_node() {}

                explicit RBTree_iterator(ptr data) : _current_node(data) {}

                RBTree_iterator(const RBTiter &data) : _current_node(data._current_node) {}

                RBTiter &operator=(const RBTiter &data)
                {
                    if (this != &data)
                        _current_node = data._current_node;
                    return *this;
                }
                
                virtual ~RBTree_iterator() {}

                RBTiter &operator++()
                {
                    _current_node = RBTree_increment(_current_node);
                    return *this;
                }

                RBTiter operator++(int)
                {
                    RBTiter tmp = *this;
                    _current_node = RBTree_increment(_current_node);
                    return tmp;
                }

                RBTiter &operator--()
                {
                    _current_node = RBTree_decrement(_current_node);
                    return *this;
                }
                RBTiter &operator--(int)
                {
                    RBTiter tmp = *this;
                    _current_node = RBTree_decrement(_current_node);
                    return tmp;
                }

                reference operator*() const
                {
                    return *_current_node->value;
                }
                
                const pointer operator->() const
                {
                    return &(operator*());
                }

                bool operator==(const RBTiter& x) const
                {
                    return _current_node == x._current_node;
                }

                bool operator!=(const RBTiter& x) const 
                { 
                    return _current_node != x._current_node;
                }

            Tree_node_base<T> *RBTree_increment(Tree_node_base<T> *x);

            Tree_node_base<T> *RBTree_decrement(Tree_node_base<T> *x);

            protected :

            ptr _current_node;
        };

        template<typename T>
        struct RBTree_const_iterator
        {
            public :

                typedef T value_type;
                typedef const T& reference;
                typedef const T* pointer;
                typedef RBTree_iterator<T> iterator;
                typedef ft::bidirectional_iterator_tag iterator_category;
                typedef ptrdiff_t difference_type;
                typedef RBTree_iterator<T> RBTiter_const;
                typedef const Tree_node_base<T> * const_ptr;

                RBTree_const_iterator() : _current_node() {}

                explicit RBTree_const_iterator(const_ptr data) : _current_node(data) {}

                RBTree_const_iterator(const RBTiter_const &data) : _current_node(data._current_node) {}

                RBTree_const_iterator &operator=(const RBTiter_const &data)
                {
                    if (this != &data)
                        _current_node = data._current_node;
                    return *this;
                }

                virtual ~RBTree_const_iterator() {}

                reference operator*() const
                {
                    return *_current_node->value;
                }

                pointer operator->() const
                {
                    return &(operator*());
                }

                RBTiter_const &operator++()
                {
                    _current_node = tree_increment(_current_node);
                    return *this;
                }

                RBTiter_const operator++(int)
                {
                    RBTiter_const tmp = *this;
                    _current_node = tree_increment(_current_node);
                    return tmp;
                }

                RBTiter_const &operator--()
                {
                    _current_node = tree_decrement(_current_node);
                    return *this;
                }

                RBTiter_const operator--(int)
                {
                    RBTiter_const tmp = *this;
                    _current_node = tree_decrement(_current_node);
                    return *this;
                }

                bool operator==(const RBTiter_const &x) const
                {
                    return _current_node == x._current_node;
                }

                bool operator!=(const RBTiter_const &x) const
                {
                    return _current_node != x._current_node;
                }

            Tree_node_base<T> *RBTree_increment(Tree_node_base<T> *x);

            Tree_node_base<T> *RBTree_decrement(Tree_node_base<T> *x);

            protected :

                const_ptr _current_node;
        };

        template<typename uwu>
        inline bool operator==(const RBTree_iterator<uwu> &x, const RBTree_const_iterator<uwu> &y)
        {
            return x._current_node == y._current_node;
        }

        template<typename uwu>
        inline bool operator!=(const RBTree_iterator<uwu> &x, const RBTree_const_iterator<uwu> &y)
        {
            return x._current_node != y._current_node;
        }
};