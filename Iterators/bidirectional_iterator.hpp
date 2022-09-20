#pragma once

#include "iterator.hpp"
#include "../Utilities/enable_if.hpp"
#include "../Utilities/compares.hpp"

namespace ft 
{

	template <class T>
	class bidirectional_iterator : public ft::iterator<ft::bidirectional_iterator_tag, T> 
	{

	public:
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::iterator_category iterator_category;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::value_type value_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::difference_type difference_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::pointer pointer;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::reference reference;

	protected:
		pointer _val;

	public:

		bidirectional_iterator(pointer _val = NULL) : _val(_val) {};

		bidirectional_iterator(const bidirectional_iterator &params) : _val(params._val) {};

		template <typename T>
		bidirectional_iterator(const bidirectional_iterator<T> &params) : _val(params.base()) {}

		reference operator*() const 
		{ 
			return *_val; 
		};

		pointer operator->() const 
		{ 
			return &(operator*()); 
		};

		pointer const& base() const 
		{ 
			return _val; 
		}

		bool operator==(const bidirectional_iterator<T> &params) 
		{
			return (this->_val == params._val);
		};

		bool operator!=(const bidirectional_iterator<T>& params) 
		{
			return (this->_val != params._val);
		};

		bidirectional_iterator& operator++() 
		{
			++_val;
			return *this;
		};

		bidirectional_iterator operator++(int) 
		{
			bidirectional_iterator tmp = *this;
			++(*this);
			return tmp;
		};

		bidirectional_iterator& operator--() 
		{
			--_val;
			return *this;
		};

		bidirectional_iterator operator--(int) 
		{
			bidirectional_iterator tmp = *this;
			--(*this);
			return tmp;
		};
	};
};