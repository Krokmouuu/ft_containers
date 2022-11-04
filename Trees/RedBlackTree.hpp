#pragma once

#include "./RedBlackTree_node.hpp"
#include "RedBlackTree_iterator.hpp"
#include "../Utilities/pair.hpp"
#include "../Utilities/enable_if.hpp"
#include "../Utilities/compares.hpp"

//? Ref : https://www.geeksforgeeks.org/red-black-tree-set-1-introduction-2/
//? Ref : https://www.programiz.com/dsa/red-black-tree
//? Ref : https://www.rpi.edu/dept/acm/packages/stl/stl_tree.h
//? Ref : https://www.youtube.com/watch?v=3RQtq7PDHog
//? Ref : https://www.youtube.com/watch?v=qA02XWRTBdw
//? Ref : https://www.youtube.com/watch?v=w5cvkTXY0vQ

//// Fuck this project for real.

namespace ft {

template <typename Key, typename T, typename KeyValue, typename _Compare, typename _Alloc = std::allocator<T> >
class Red_Black_Tree 
{
	typedef typename _Alloc::template rebind<Tree_node<T> >::other _node_allocator;

protected:

	typedef Tree_node<T>* _node;
	typedef const Tree_node<T>* _const_node;

public:

	typedef Key key_type;
	typedef T type_val;
	typedef type_val* pointer;
	typedef const type_val* const_pointer;
	typedef type_val& reference;
	typedef const type_val& const_reference;
	typedef size_t size_type;
	typedef ptrdiff_t type_difference;
	typedef _Alloc allocator_type;
	typedef _Compare compareKey;
	typedef RBT_iterator<type_val> iterator;
	typedef RBT_const_iterator<type_val> const_iterator;
	typedef ft::reverse_iterator<iterator> reverse_iterator;
	typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

	iterator begin() 
    { 
		return iterator(_root->child_left); 
    }

	const_iterator begin() const 
    { 
        return const_iterator(_root->child_left); 
    }

	iterator end() 
    { 
        return iterator(_root); 
    }

	const_iterator end() const 
    { 
        return const_iterator(_root); 
    }

	reverse_iterator rbegin() 
    { 
        return reverse_iterator(end()); 
    }

	const_reverse_iterator rbegin() const 
    { 
        return const_reverse_iterator(end()); 
    }

	reverse_iterator rend() 
    { 
        return reverse_iterator(begin()); 
    }

	const_reverse_iterator rend() const 
    { 
        return const_reverse_iterator(begin()); 
    }

	compareKey key_comp() const 
    { 
        return _compareKey; 
    }

	allocator_type get_allocator() const 
    { 
        return allocator_type(_node_alloc); 
    }

	bool empty() const 
    { 
        if (_total_node == 0)
            return true;
        return false;
    }

	size_type size() const 
    { 
        return _total_node; 
    }

    //! What is no sense ? Thanks Sspina for the solution 
	size_type max_size() const 
    {
		size_t div = sizeof(_node) * 4 + sizeof(type_val);
		// Without the next line it will give a wrong max_size()
		div = (div / 8) * 8;
		return std::numeric_limits<size_type>::max() / div;
	}

	key_type _trueKey(_node x) const 
	{
		return KeyValue()(*(x->value)); 
	}

	key_type _trueKey(_const_node x) const 
	{ 
		return KeyValue()(*(x->value));
	}

	key_type _trueKey(type_val x) const 
	{ 
		return KeyValue()(x); 
	}

	key_type _trueKey(iterator x) const 
	{ 
		return KeyValue()(*x); 
	}

	key_type _trueKey(const_iterator x) const 
	{ 
		return KeyValue()(*x); 
	}
	
	_node _true_end() 
	{ 
		return _root;
	}

	_const_node _true_end() const 
	{ 
		return _root; 
	}

	_node _true_root() 
	{ 
		return _root->_parent;
	}

	_const_node _true_root() const 
	{ 
		return _root->_parent; 
	}

	_node& _ref_true_root() 
	{ 
		return _root->_parent; 
	}

	_const_node _ref_true_root() const 
	{
		return _root->_parent; 
	}

	_node right_node() //! return the higher node
	{
		_node current = _true_root();
		if (current == NULL) return _root;
		while (current->child_right) 
			current = current->child_right;
		return current;
	}

	_node left_node() //! return the lowest node
	{
		_node current = _true_root();
		if (current == NULL) return _root;
		while (current->child_left) 
			current = current->child_left;
		return current;
	}

	_const_node right_node() const //! Surcharge const node
	{
		return (_const_node)right_node();
	}

	_const_node left_node() const 
	{
		return (_const_node)left_node();
	}
	
	void _reinitialize() 
	{
		_root->_color = RED;
		_root->_parent = 0;
		_root->child_left = _root;
		_root->child_right = _root;
		_total_node = 0;
	}

	void node_move(Red_Black_Tree& _starting_tree)
	{
		_root->_color = _starting_tree._root->_color;
		_ref_true_root() = _starting_tree._root->_parent;
		_root->child_left = _starting_tree._root->child_left;
		_root->child_right = _starting_tree._root->child_right;
		_true_root()->_parent = _root;
		_total_node = _starting_tree._total_node;
		_starting_tree._reinitialize();
	}

	void clear() 
	{
		_erase(_true_root());
		_reinitialize();
	}

	Red_Black_Tree() : _compareKey(compareKey()), _node_alloc(_node_allocator()) 
	{
		_root = _node_creator(type_val());
		_reinitialize();
	}

	Red_Black_Tree(const compareKey& key_comp, const _node_allocator& alloc) : _compareKey(key_comp), _node_alloc(alloc)
	{
		_root = _node_creator(type_val());
		_reinitialize();
	}

	Red_Black_Tree(Red_Black_Tree const& other) 
	{
		_root = _node_creator(type_val());
		_reinitialize();
		_compareKey = other._compareKey;
		_node_alloc = other._node_alloc;
		if (other._ref_true_root() != 0)
		{
			_ref_true_root() = _node_copier(other._root->_parent, _root);
			_root->child_right = right_node();
			_root->child_left = left_node();
		}
	}

	~Red_Black_Tree() 
	{
		_erase(_true_root());
		++_total_node;
		destroy_current_node(_root);
	}

	Red_Black_Tree& operator=(const Red_Black_Tree& other) 
	{
		if (this == &other) 
			return *this;
		_erase(_true_root());
		_reinitialize();
		_compareKey = other._compareKey;
		_node_alloc = other._node_alloc;
		if (other._total_node) 
		{
			_ref_true_root() = _node_copier(other._root->_parent, _root);
			_root->child_left = left_node();
			_root->child_right = right_node();
		}
		return *this;
	}
	_node insertNode_in_RBT(_node root, _node new_node)
	{
		if (root == NULL) 
			return new_node;
		if (_compareKey(_trueKey(new_node), _trueKey(root))) //! Looking for the good position
		{
			root->child_left = insertNode_in_RBT(root->child_left, new_node);
			root->child_left->_parent = root;
		} 
		else if (_compareKey(_trueKey(root), _trueKey(new_node))) 
		{
			root->child_right = insertNode_in_RBT(root->child_right, new_node);
			root->child_right->_parent = root;
		}
		return root;
	}

	void left_rotate(_node x) 
	{
		_node a_parent = x->child_right; //! Create node will be child_right
		if (x == _true_root()) 
			_ref_true_root() = a_parent;
		x->move_down(a_parent);
		x->child_right = a_parent->child_left; //! x right = new node right
		if (a_parent->child_left != NULL) 
			a_parent->child_left->_parent = x;
		a_parent->child_left = x;
	}

	void right_rotate(_node x) //! Same but for right rotate
	{
		_node a_parent = x->child_left;
		if (x == _true_root()) 
			_ref_true_root() = a_parent;
		x->move_down(a_parent);
		x->child_left = a_parent->child_right;
		if (a_parent->child_right != NULL) 
			a_parent->child_right->_parent = x;
		a_parent->child_right = x;
	}

	void no_red_red_nodes(_node& ptr)
	{
		_node ptr_parent = NULL;
		_node ptr_grand_parent = NULL;
		while ((ptr != _true_root()) && (ptr->_color != BLACK) && (ptr->_parent->_color == RED)) 
		{
			ptr_parent = ptr->_parent;
			ptr_grand_parent = ptr->_parent->_parent;
			if (ptr_parent == ptr_grand_parent->child_left) 
			{
				_node ptr_uncle = ptr_grand_parent->child_right;
				if (ptr_uncle != NULL && ptr_uncle->_color == RED) 
				{
					ptr_grand_parent->_color = RED;
					ptr_parent->_color = BLACK;
					ptr_uncle->_color = BLACK;
					ptr = ptr_grand_parent;
				} 
				else 
				{
					if (ptr == ptr_parent->child_right) {
						left_rotate(ptr_parent);
						ptr = ptr_parent;
						ptr_parent = ptr->_parent;
					}
					right_rotate(ptr_grand_parent);
					std::swap(ptr_parent->_color, ptr_grand_parent->_color);
					ptr = ptr_parent;
				}
			} 
			else 
			{
				_node ptr_uncle = ptr_grand_parent->child_left;
				if (ptr_uncle != NULL && ptr_uncle->_color == RED) {
						ptr_grand_parent->_color = RED;
						ptr_parent->_color = BLACK;
						ptr_uncle->_color = BLACK;
						ptr = ptr_grand_parent;
					} else {
						if (ptr == ptr_parent->child_left) {
							right_rotate(ptr_parent);
							ptr = ptr_parent;
							ptr_parent = ptr->_parent;
						}
						left_rotate(ptr_grand_parent);
						std::swap(ptr_parent->_color, ptr_grand_parent->_color);
						ptr = ptr_parent;
					}
			}
		}
		_ref_true_root()->_color = BLACK;
	}

	void no_black_black(_node node) 
	{
		if (node == _true_root()) 
			return;
		_node node_sibling = node->sibling();
		_node node_parent = node->_parent;
		if (node_sibling == NULL) 
			no_black_black(node_parent);
		else 
		{
			if (node_sibling->_color == RED) 
			{
				node_parent->_color = RED;
				node_sibling->_color = BLACK;
				if (node_sibling->is_left_node())
					right_rotate(node_parent);
				else
					left_rotate(node_parent);
				no_black_black(node);
			} 
			else 
			{
				if (node_sibling->child_is_red()) 
				{
					if (node_sibling->child_left != NULL && node_sibling->child_left->_color == RED) 
					{
						if (node_sibling->is_left_node()) 
						{
							node_sibling->child_left->_color = node_sibling->_color;
							node_sibling->_color = node_parent->_color;
							right_rotate(node_parent);
						} 
						else 
						{
							node_sibling->child_left->_color = node_parent->_color;
							right_rotate(node_sibling);
							left_rotate(node_parent);
						}
					} 
					else 
					{
						if (node_sibling->is_left_node()) 
						{
							node_sibling->child_right->_color = node_parent->_color;
							left_rotate(node_sibling);
							right_rotate(node_parent);
						} 
						else 
						{
						node_sibling->child_right->_color = node_sibling->_color;
						node_sibling->_color = node_parent->_color;
						left_rotate(node_parent);
						}
					}
					node_parent->_color = BLACK;
				} 
				else 
				{
					node_sibling->_color = RED;
					if (node_parent->_color == BLACK)
						no_black_black(node_parent);
					else node_parent->_color = BLACK;
				}
			}
		}
	}

	_node node_without_left(_node other) 
	{
		_node temp = other;
		while (temp->child_left != NULL) 
			temp = temp->child_left;
		return temp;
	}

	_node replace_node(_node other) 
	{
		if (other->child_left != NULL && other->child_right != NULL) 
			return node_without_left(other->child_right);
		if (other->child_left == NULL && other->child_right == NULL) 
			return NULL;
		if (other->child_right != NULL) 
			return other->child_right;
		else
			return other->child_left;
	}

	void delete_node(_node deleted) 
	{
		_node delete_helper = replace_node(deleted);

		bool both_black = ((delete_helper == NULL || delete_helper->_color == BLACK) && (deleted->_color == BLACK));
		_node parent = deleted->_parent;
		if (delete_helper == NULL) 
		{
			if (deleted == _true_root()) 
				_ref_true_root() = _root;
			else 
			{
				if (both_black)
					no_black_black(deleted);
				else 
				{
					if (deleted->sibling() != NULL)
						deleted->sibling()->_color = RED;
				}
				if (deleted->is_left_node())
					parent->child_left = NULL;
				else
					parent->child_right = NULL;
			}
			destroy_current_node(deleted);
			return;
		}
		if (deleted->child_left == NULL || deleted->child_right == NULL) 
		{
			if (deleted == _true_root()) 
			{
				_ref_true_root() = delete_helper;
				deleted->swap_node(delete_helper);
				delete_helper->child_left = delete_helper->child_right = NULL;
				destroy_current_node(deleted);
			} 
			else 
			{
				if (deleted->is_left_node())
					parent->child_left = delete_helper;
				else
					parent->child_right = delete_helper;
				destroy_current_node(deleted);
				delete_helper->_parent = parent;
				if (both_black)
					no_black_black(deleted);
				else
					delete_helper->_color = BLACK;
			}
			return;
		}
		if (deleted == _true_root()) 
			_ref_true_root() = delete_helper;
		deleted->swap_node(delete_helper);
		delete_node(deleted);
	}

	void destroy_current_node(_node node) 
	{
		--_total_node;
		_Alloc value_alloc;
		value_alloc.destroy(node->value);
		value_alloc.deallocate(node->value, 1);
		_node_alloc.destroy(node);
		_node_alloc.deallocate(node, 1);
	}

	_node give_me_current_node() 
	{
		++_total_node;
		return _node_alloc.allocate(1);
	}

	void _node_constructor(_node node, const type_val& x) 
	{
		try 
		{
			node->_color = RED;
			node->child_left = NULL;
			node->child_right = NULL;
			node->_parent = NULL;
			_Alloc value_alloc;
			typename _Alloc::pointer ptr = value_alloc.allocate(1);
			value_alloc.construct(ptr, x);
			node->value = ptr;
		} 
		catch (...) 
		{
			destroy_current_node(node);
			throw;
		}
	}

	_node _node_creator(const type_val& node) 
	{
		_node temp = give_me_current_node();
		_node_constructor(temp, node);
		return temp;
	}

	_node _node_cloner(_const_node x) 
	{
		_node temp = _node_creator(*x->value);
		temp->_color = x->_color;
		temp->child_right = 0;
		temp->child_left = 0;
		return temp;
	}

	_node _node_copier (_const_node x, _node y) 
	{
		_node up = _node_cloner(x);
		up->_parent = y;
		try 
		{
			if (x->child_right) up->child_right = _node_copier(x->child_right, up);
			y = up;
			x = x->child_left;
			while (x != 0) 
			{
				_node z = _node_cloner(x);
				y->child_left = z;
				z->_parent = y;
				if (x->child_right) z->child_right = _node_copier(x->child_right, z);
				y = z;
				x = x->child_left;
			}
		} 
		catch (...) 
		{
			_erase(up);
			throw;
		}
		return up;
	}
		

	void _erase(_node x) 
	{
		while (x != 0) 
		{
			_erase(x->child_right);
			_node y = x->child_left;
			destroy_current_node(x);
			x = y;
		}
	}

	iterator _lower_bound(_node x, _node y, const Key& k) 
	{
		while (x != 0) 
		{
			if (!_compareKey(_trueKey(x), k))
				y = x, x = x->child_left;
			else
				x = x->child_right;
		}
		return iterator(y);
	}

	const_iterator _lower_bound(_const_node x, _const_node y, const Key& k) const
	{
		while (x != 0) 
		{
			if (!_compareKey(_trueKey(x), k))
				y = x, x = x->child_left;
			else
				x = x->child_right;
		}
		return const_iterator(y);
	}

	iterator _upper_bound(_node x, _node y, const Key& k) 
	{
		while (x != 0) 
		{
			if (_compareKey(k, _trueKey(x)))
				y = x, x = x->child_left;
			else
				x = x->child_right;
		}
		return iterator(y);
	}

	const_iterator _upper_bound(_const_node x, _const_node y, const Key& k) const 
	{
		while (x != 0) 
		{
			if (_compareKey(k, _trueKey(x)))
				y = x, x = x->child_left;
			else
				x = x->child_right;
		}
		return const_iterator(y);
	}

	ft::pair<iterator, bool> insert(const type_val& other) 
	{
		ft::pair<iterator, bool> current;
		iterator iter = lower_bound(_trueKey(other));
		if (iter != end() && !_compareKey(_trueKey(other), _trueKey(iter))) 
		{
			current.first = iter;
			current.second = false;
			return current;
		}
		_node ptr = _node_creator(other);
		_node previous = ptr;
		_ref_true_root() = insertNode_in_RBT(_true_root(), ptr);
		no_red_red_nodes(ptr);
		_ref_true_root()->_parent = _root;
		_root->child_left = left_node();
		_root->child_right = right_node();
		current.first = (iterator)previous;
		current.second = true;
		return current;
	}

	size_type erase(const key_type& key) 
    {
		if (_true_root() == NULL)
			return 0;
		iterator to_delete = lower_bound(key);
		if (to_delete == end() || _compareKey(key, _trueKey(to_delete))) 
			return 0;
		delete_node(to_delete.get_link());
		if (size()) 
		{
			_ref_true_root()->_parent = _root;
			_root->child_left = left_node();
			_root->child_right = right_node();
		} 
		else 
		{
			_ref_true_root() = NULL;
			_root->child_left = _root;
			_root->child_right = _root;
		}
		return 1;
	}

	void swap(Red_Black_Tree &tree) 
    {
		if (_true_root() == 0) 
        {
			if (tree._true_root() != 0) 
                node_move(tree);
        }
		else if (tree._ref_true_root() == 0)
			tree.node_move(*this);
		else 
        {
			std::swap(_ref_true_root(), tree._ref_true_root());
			std::swap(_root->child_left, tree._root->child_left);
			std::swap(_root->child_right, tree._root->child_right);
			_ref_true_root()->_parent = _true_end();
			tree._ref_true_root()->_parent = tree._true_end();
			std::swap(_total_node, tree._total_node);
		}
		std::swap(_compareKey, tree._compareKey);
		std::swap(_node_alloc, tree._node_alloc);
	}

	iterator find(const Key& key) 
    {
		iterator helperKey = lower_bound(key);
		if (helperKey == end() || _compareKey(key, _trueKey(helperKey)))
			return end();
		else
			return helperKey;
	}

	const_iterator find(const Key& key) const 
    {
		const_iterator helperKey = lower_bound(key);
		if (helperKey == end() || _compareKey(key, _trueKey(helperKey)))
			return end();
		else
			return helperKey;
	}

	iterator lower_bound(const key_type& key) 
    {
		return _lower_bound(_true_root(), _true_end(), key);
	}

	const_iterator lower_bound(const key_type& key) const 
    {
		return _lower_bound(_true_root(), _true_end(), key);
	}

	iterator upper_bound(const key_type& key) 
    {
		return _upper_bound(_true_root(), _true_end(), key);
	}

	const_iterator upper_bound(const key_type& key) const 
    {
		return _upper_bound(_true_root(), _true_end(), key);
	}

	ft::pair<iterator, iterator> equal_range(const Key& key) 
	{
		_node x = _true_root();
		_node y = _true_end();
		while (x != 0) 
		{
			if (_compareKey(_trueKey(x), key))
				x = x->child_right;
			else if (_compareKey(key, _trueKey(x)))
				y = x, x = x->child_left;
			else 
			{
				_node x1(x);
				_node y1(y);
				y = x;
				x = x->child_left;
				x1 = x1->child_right; 
				return ft::pair<iterator, iterator>(_lower_bound(x, y, key), _upper_bound(x1, y1, key));
      		}
    	}
    	return ft::pair<iterator, iterator>(iterator(y), iterator(y));
  	}

	ft::pair<const_iterator, const_iterator> equal_range(const key_type& key) const 
	{
		_const_node x = _true_root();
		_const_node y = _true_end();
		while (x != 0) 
		{
			if (_compareKey(_trueKey(x), key))
				x = x->child_right;
			else if (_compareKey(key, _trueKey(x)))
				y = x, x = x->child_left;
			else 
			{
				_const_node x1(x);
				_const_node y1(y);
				y = x;
				x = x->child_left;
				x1 = x1->child_right; 
				return ft::pair<const_iterator, const_iterator>(_lower_bound(x, y, key), _upper_bound(x1, y1, key));
			}
    	}
    return ft::pair<const_iterator, const_iterator>(const_iterator(y), const_iterator(y));
  }

    private:
	
        _node _root;
        size_type _total_node;
        compareKey _compareKey;
        _node_allocator _node_alloc;
};

    template <typename Pair>
    struct pick_first 
    {
        typename Pair::first_type& operator()(Pair& x) const 
        { 
            return x.first; 
        }
        const typename Pair::first_type& operator()(const Pair& x) const 
        { 
            return x.first; 
        }
    };

    template <typename Key, typename T, typename Compare, typename _Alloc>
    inline bool operator==(const ft::Red_Black_Tree<Key, T, Compare, _Alloc>& lhs, const ft::Red_Black_Tree<Key, T, Compare, _Alloc>& rhs) 
    {
        return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
    }

    template <typename Key, typename T, typename Compare, typename _Alloc>
    inline bool operator!=(const ft::Red_Black_Tree<Key, T, Compare, _Alloc>& lhs, const ft::Red_Black_Tree<Key, T, Compare, _Alloc>& rhs) 
    {
        if (lhs != rhs)
            return true;
        else
            return false;
    }

    template <typename Key, typename T, typename Compare, typename _Alloc>
    inline bool operator<=(const ft::Red_Black_Tree<Key, T, Compare, _Alloc>& lhs,const ft::Red_Black_Tree<Key, T, Compare, _Alloc>& rhs) 
    {
        if (lhs < rhs)
            return true;
        else
            return false;
    }

    template <typename Key, typename T, typename Compare, typename _Alloc>
    inline bool operator<(const ft::Red_Black_Tree<Key, T, Compare, _Alloc>& lhs, const ft::Red_Black_Tree<Key, T, Compare, _Alloc>& rhs) 
    {
        return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }

    template <typename Key, typename T, typename Compare, typename _Alloc>
    inline bool operator>(const ft::Red_Black_Tree<Key, T, Compare, _Alloc>& lhs, const ft::Red_Black_Tree<Key, T, Compare, _Alloc>& rhs) 
    {
        if (lhs < rhs)
            return true;
        else
            return false;
    }

    template <typename Key, typename T, typename Compare, typename _Alloc>
    inline bool operator>=(const ft::Red_Black_Tree<Key, T, Compare, _Alloc>& lhs,const ft::Red_Black_Tree<Key, T, Compare, _Alloc>& rhs) 
    {
        if (lhs <= rhs)
            return true;
        else
            return false;
    }

} //! ft