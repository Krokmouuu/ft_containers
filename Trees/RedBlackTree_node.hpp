#pragma once

#include "RedBlackTree.hpp"

namespace ft
{
    template <typename _Val>
    struct Tree_node_base
    {
        typedef Tree_node_base* ptr;
        typedef const Tree_node_base* const_ptr;

        bool	_color;
        ptr		parent;
        ptr		child_left;
        ptr		child_right;
        _Val    *value;

        static ptr minimum(ptr x)
        {
            while (x->child_left != 0) 
                x = x->child_left;
            return x;
        }

        static const_ptr minimum(const_ptr x)
        {
            while (x->child_left != 0) 
                x = x->child_left;
            return x;
        }

        static ptr maximum(ptr x)
        {
            while (x->child_right != 0)
                x = x->child_right;
            return x;
        }

        static const_ptr maximum(const_ptr x)
        {
            while (x->child_right != 0)
                x = x->child_right;
            return x;
        }
    };
};