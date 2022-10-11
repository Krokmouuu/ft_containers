#pragma once

#include "../Utilities/compares.hpp"
#include "../Iterators/iterator.hpp"
#include "../Utilities/pair.hpp"
#include "../Utilities/enable_if.hpp"

namespace ft 
{
    enum Color
    {
        RED,
        BLACK
    };

    template <typename T>
    struct Tree_node 
    {
        typedef Tree_node<T>* node;

        Color _color;
        node _parent;
        node child_left;
        node child_right;
        T* value;

        bool is_left_node() 
        { 
            return this == _parent->child_left; 
        }
        
        bool child_is_red() 
        { 
            return (child_left && child_left->_color == RED) || (child_right && child_right->_color == RED); 
        }

        node uncle()
        {
            if (_parent == NULL || _parent->_parent == NULL) 
                return NULL;
            if (_parent->is_left_node()) 
                return _parent->_parent->child_right;
            else 
                return _parent->_parent->child_left;
        }

        node sibling() 
        {
            if (_parent == NULL) 
                return NULL;
            if (is_left_node()) 
                return _parent->child_right;
            return _parent->child_left;
        }

        void move_down(node new_parent){   //! Moving down the node
            if (_parent != NULL) 
            {
                if (is_left_node())
                    _parent->child_left = new_parent;
                else 
                    _parent->child_right = new_parent;
                new_parent->_parent = _parent;
                _parent = new_parent;
            }
        }

        void swap_node(node& other) 
        {
            node other_parent = other->_parent;
            node other_right = other->child_right;
            node other_left = other->child_left;
            node this_parent = _parent;
            node this_right = child_right;
            node this_left = child_left;

            if (other_parent->child_left == other)
                other_parent->child_left = this;
            else if (other_parent->child_right == other) 
                other_parent->child_right = this;
            if (other_left)
                other_left->_parent = this;
            if (other_right) 
                other_right->_parent = this;

            if (is_left_node()) 
                this_parent->child_left = other;
            else 
                this_parent->child_right = other;
            if (this_left) 
                this_left->_parent = other;
            if (this_right) 
                this_right->_parent = other;

            std::swap(_color, other->_color);
            std::swap(_parent, other->_parent);
            std::swap(child_right, other->child_right);
            std::swap(child_left, other->child_left);
        }
    };

} //! ft