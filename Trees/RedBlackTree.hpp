#pragma once

#include<iostream>
#include <memory>
#include "../Iterators/iterator.hpp"

using std::string;
using std::cout;
using std::endl;

//? Ref :http://www.aoc.nrao.edu/php/tjuerges/ALMA/STL/html-4.1.2/stl__tree_8h-source.html

namespace ft
{
	enum Color
	{
		RED,
		BLACK
	};

	template <class T, class Allocator>
	struct Tree_node
	{
		public :

			Tree_node(T data)
			{
				_color = RED;
				parent = nullptr;
				child_right = nullptr;
				child_left = nullptr;
				value = _alloc.allocate(1);
				_alloc.construct(this->value, T(data.first, data.second));
			}

			Tree_node(const T &data)
			{
				_color = data._color;
				parent = data.parent;
				child_right = data.child_right;
				child_left = data.child_left;
				value = _alloc.allocate(1);
				_alloc.construct(value, data.value);
			}

			~Tree_node()
			{
				if (value)
				{
					_alloc.destroy(value);
					_alloc.deallocate(value, 1);
				}
			}

			Tree_node &operator==(const T &data)
			{
				if (this != &data)
				{
					_color = data._color;
					parent = data.parent;
					child_left = data.child_left;
					child_right = data.child_right;
					value = _alloc.allocate(1);
					_alloc.construct(value, data.value);
				}
				return *this;
			}

		protected :

			bool _color;
			Allocator _alloc;
			T *value;
			Tree_node* parent;
			Tree_node* child_right;
			Tree_node* child_left;

	};

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
			typedef typename Tree_node<T, std::allocator<T> >::node node;


			RBTree_iterator() : _current_node() {}

			explicit RBTree_iterator(node data) : _current_node(data) {}

			RBTree_iterator(const RBTiter &data) : _current_node(data._current_node) {}

			RBTiter &operator=(const RBTiter data)
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

		protected :

		node _current_node;
	};

	template<typename T>
	struct RBTree_const_iterator
	{
		public :

			typedef T value_type;
			typedef T& reference;
			typedef T* pointer;
			typedef ft::bidirectional_iterator_tag iterator_category;
			typedef ptrdiff_t difference_type;
			typedef RBTree_iterator<T> RBTiter_const;
			typedef typename Tree_node<T, std::allocator<T> >::node node;


			RBTree_const_iterator() : _current_node() {}

			explicit RBTree_const_iterator(node data) : _current_node(data) {}

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

			const pointer operator->() const
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

		protected :

			node _current_node;
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
