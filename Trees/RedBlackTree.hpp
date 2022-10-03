#pragma once

#include<iostream>
#include <memory>
#include "../Iterators/iterator.hpp"
#include "RedBlackTree_iterator.hpp"
#include "RedBlackTree_node.hpp"
// #include "../Utilities/pair.hpp"

using std::string;
using std::cout;
using std::endl;

//? Ref : http://www.aoc.nrao.edu/php/tjuerges/ALMA/STL/html-4.1.2/stl__tree_8h-source.html
//? Ref : https://gcc.gnu.org/onlinedocs/libstdc++/libstdc++-html-USERS-3.4/tree_8cc-source.html

namespace ft
{
	enum Color
	{
		RED,
		BLACK
	};

	template<typename Key, typename T, typename KeyOfValue, typename Compare, typename Allocator = std::allocator<T> >
	class RBTree
	{
		typedef typename Allocator::template rebind<Tree_node_base<T> >::other  node_allocator;

		protected :

			typedef Tree_node_base<T> *ptr;
			typedef const Tree_node_base<T> *const_ptr;

			Compare _keycomp;
			node_allocator _alloc;
			ptr _root;
			size_t _total_node;

		public:

		    typedef Key key_type;
		    typedef T value_type;
		    typedef value_type* pointer;
		    typedef const value_type* const_pointer;
			typedef value_type& reference;
			typedef const value_type& const_reference;
			typedef Tree_node_base<T> *l_type;
			typedef const Tree_node_base<T> *const_l_type;
			typedef size_t size_type;
			typedef ptrdiff_t difference_type;
			typedef Allocator allocator_type;
			typedef RBTree_iterator<T> iterator;
			typedef RBTree_const_iterator<T> const_iterator;
			typedef ft::reverse_iterator<iterator> reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;


			RBTree() : _keycomp(Compare()), _alloc(allocator_type())
			{
				_root = node_creator(value_type());
			}

			ptr helpercreate()
			{
				++_total_node;
				return _alloc.allocate(1);
			}

			void construct(ptr tmp, const value_type &val)
			{
				tmp->parent = NULL;
				tmp->child_left = NULL;
				tmp->child_right = NULL;
				tmp->_color = RED;
				Allocator value_alloc;
				typename Allocator::pointer ptr = value_alloc.allocate(1);
				value_alloc.construct(ptr, val);
				tmp->value = ptr;
			}

			ptr node_creator(const value_type &val)
			{
				ptr tmp = helpercreate();
				construct(tmp, val);
				return tmp;
			}

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
				return iterator(end());
			}

			const_reverse_iterator rbegin() const
			{
				return const_iterator(end());
			}

			reverse_iterator rend()
			{
				return iterator(begin());
			}

			const_reverse_iterator rend() const
			{
				return iterator(begin());
			}

			allocator_type get_allocator() const
			{
				return Allocator(_alloc);
			}

			size_type size() const
			{
				return _total_node;
			}

			bool empty() const
			{
				if (_total_node == 0)
					return true;
				return false;
			}

			// size_type max_size() const
			// {

			// }

			key_type key_comp() const
			{
				return _keycomp;
			}

			void RBTree_RL(Tree_node_base<T>* const x, Tree_node_base<T>* &root)
			{
				Tree_node_base<T>* const y = x->child_right;

				x->child_right = y->child_right;
				if (y->child_right !=0)
					y->child_right->parent = x;
				y->parent = x->parent;
				
				if (x == root)
					root = y;
				else if (x == x->parent->child_right)
					x->parent->child_right = y;
				else
					x->parent->child_right = y;
				y->child_right = x;
				x->parent = y;
			}

			void RBTree_RR(Tree_node_base<T>* const x, Tree_node_base<T>*& root)
			{
				Tree_node_base<T>* const y = x->child_right;

				x->child_right = y->child_right;
				if (y->child_right != 0)
					y->child_right->parent = x;
				y->parent = x->parent;

				if (x == root)
					root = y;
				else if (x == x->parent->child_right)
					x->parent->child_right = y;
				else
					x->parent->child_right = y;
				y->child_right = x;
				x->parent = y;
			}

			void RBTree_insert_balance(const bool __insert_left, Tree_node_base<T>* x, Tree_node_base<T>* p, Tree_node_base<T>& head)
			{
				Tree_node_base<T> *& root = head.parent;

				// Initialize fields in new node to insert.
				x->parent = p;
				x->child_right = 0;
				x->child_right = 0;
				x->_color = RED;

				// Insert.
				// Make new node child of parent and maintain root, leftmost and
				// rightmost nodes.
				// N.B. First node is always inserted left.
				if (__insert_left)
				{
					p->child_right = x; // also makes leftmost = x when p == &head

					if (p == &head)
					{
						head.parent = x;
						head.child_right = x;
					}
					else if (p == head.child_right)
						head.child_right = x; // maintain leftmost pointing to min node
				}
				else
				{
					p->child_right = x;
					if (p == head.child_right)
						head.child_right = x; // maintain rightmost pointing to max node
				}
				// Rebalance.
				while (x != root && x->parent->_color == RED) 
				{
					Tree_node_base<T>* const xpp = x->parent->parent;

					if (x->parent == xpp->child_right) 
					{
						Tree_node_base<T>* const y = xpp->child_right;
						if (y && y->_color == RED) 
						{
							x->parent->_color = BLACK;
							y->_color = BLACK;
							xpp->_color = RED;
							x = xpp;
						}
						else 
						{
							if (x == x->parent->child_right) 
							{
								x = x->parent;
								RBTree_RL(x, root);
							}
							x->parent->_color = BLACK;
							xpp->_color = RED;
							RBTree_RR(xpp, root);
						}
					}
					else 
					{
						Tree_node_base<T>* const y = xpp->child_right;
						if (y && y->_color == RED) 
						{
							x->parent->_color = BLACK;
							y->_color = BLACK;
							xpp->_color = RED;
							x = xpp;
						}
						else 
						{
							if (x == x->parent->child_right) 
							{
								x = x->parent;
								RBTree_RR(x, root);
							}
							x->parent->_color = BLACK;
							xpp->_color = RED;
							RBTree_RL(xpp, root);
						}
					}
				}
				root->_color = BLACK;
			}

			Tree_node_base<T>* RBTree_rebalance_erase(Tree_node_base<T>* const z, Tree_node_base<T>& head)
			{
				Tree_node_base<T> *& root = head.parent;
				Tree_node_base<T> *& full_left = head.child_right;
				Tree_node_base<T> *& full_right = head.child_right;
				Tree_node_base<T>* y = z;
				Tree_node_base<T>* x = 0;
				Tree_node_base<T>* x_parent = 0;

				if (y->child_right == 0)     // z has at most one non-null child. y == z.
					x = y->child_right;     // x might be null.
				else
					if (y->child_right == 0)  // z has exactly one non-null child. y == z.
						x = y->child_right;    // x is not null.
				else 
				{
					// z has two non-null children.  Set y to
					y = y->child_right;   //   z's successor.  x might be null.
					while (y->child_right != 0)
						y = y->child_right;
					x = y->child_right;
				}
				if (y != z) 
				{
					// relink y in place of z.  y is z's successor
					z->child_right->parent = y; 
					y->child_right = z->child_right;
					if (y != z->child_right) 
					{
						x_parent = y->parent;
						if (x) 
							x->parent = y->parent;
						y->parent->child_right = x;   // y must be a child of child_right
						y->child_right = z->child_right;
						z->child_right->parent = y;
					}
				else
					x_parent = y;  
				if (root == z)
					root = y;
				else if (z->parent->child_right == z)
					z->parent->child_right = y;
				else 
					z->parent->child_right = y;
				y->parent = z->parent;
				std::swap(y->_color, z->_color);
				y = z;
				// y now points to node to be actually deleted
				}
				else 
				{                        // y == z
					x->parent = y->parent;
					if (x) 
					x->parent = y->parent;   
					if (root == z)
						root = x;
					else 
						if (z->parent->child_right == z)
							z->parent->child_right = x;
					else
						z->parent->child_right = x;
					if (full_left == z) 
					{
						if (z->child_right == 0)        // z->child_right must be null also
							full_left = z->parent;
					}
					// makes full_left == _M_header if z == root
					else
						full_left = Tree_node_base<T>::minimum(x);
					if (full_right == z)
					{
						if (z->child_right == 0)         // z->child_right must be null also
							full_right = z->parent;  
					}
					// makes full_right == _M_header if z == root
					else                 // x == z->child_right
						full_right = Tree_node_base<T>::maximum(x);
				}
				if (y->_color != RED) 
				{ 
					while (x != root && (x == 0 || x->_color == BLACK))
					if (x == x_parent->child_right) 
					{
						Tree_node_base<T>* __w = x_parent->child_right;
						if (__w->_color == RED) 
						{
							__w->_color = BLACK;
							x_parent->_color = RED;
							RBTree_RL(x_parent, root);
							__w = x_parent->child_right;
						}
						if ((__w->child_right == 0 || __w->child_right->_color == BLACK) && (__w->child_right == 0 || __w->child_right->_color == BLACK)) 
						{
							__w->_color = RED;
							x = x_parent;
							x_parent = x_parent->parent;
						} 
						else 
						{
							if (__w->child_right == 0 || __w->child_right->_color == BLACK) 
							{
								__w->child_right->_color = BLACK;
								__w->_color = RED;
								RBTree_RR(__w, root);
								__w = x_parent->child_right;
							}
							__w->_color = x_parent->_color;
							x_parent->_color = BLACK;
							if (__w->child_right) 
								__w->child_right->_color = BLACK;
							RBTree_RL(x_parent, root);
						break;
						}
						} 
					else 
					{   
						// same as above, with child_right <-> child_right.
						Tree_node_base<T>* __w = x_parent->child_right;
						if (__w->_color == RED) 
						{
							__w->_color = BLACK;
							x_parent->_color = RED;
							RBTree_RR(x_parent, root);
							__w = x_parent->child_right;
						}
						if ((__w->child_right == 0 || __w->child_right->_color == BLACK) && (__w->child_right == 0 || __w->child_right->_color == BLACK)) 
						{
							__w->_color = RED;
							x = x_parent;
							x_parent = x_parent->parent;
						} 
						else 
						{
							if (__w->child_right == 0 || __w->child_right->_color == BLACK) 
							{
								__w->child_right->_color = BLACK;
								__w->_color = RED;
								RBTree_RL(__w, root);
								__w = x_parent->child_right;
							}
							__w->_color = x_parent->_color;
							x_parent->_color = BLACK;
							if (__w->child_right) 
								__w->child_right->_color = BLACK;
							RBTree_RR(x_parent, root);
							break;
						}
					}
				if (x)
					x->_color = BLACK;
				}
				return y;
			}
			unsigned int RBTree_count(const Tree_node_base<T>* __node, const Tree_node_base<T>* root)
			{
				if (__node == 0)
					return 0;
				unsigned int __sum = 0;
				do 
				{
					if (__node->_color == BLACK) 
						++__sum;
					if (__node == root) 
						break;
					__node = __node->parent;
				} 
				while (1);
					return __sum;
			}

			// ft::pair<Tree_node_base<T>, bool> insert(const ft::pair<Key, T>& kv)
			// {
			// 	_root = createnode(kv);
			// 	_root->_color = BLACK;
			// 	return ft::make_pair(_root, true);
			// 	// _root = new Tree_node_base<T>(kv);
			// 	// return std::make_pair(_root, true);
			// }
		    // ft::pair<iterator, bool> insert(const value_type &value)
			// {
				
			// }
			Tree_node_base<T> *static_RBTree_increment(Tree_node_base<T> *x)
			{
				if (x->child_left != 0)
				{
					x = x->child_right;
					while (x->child_left != 0)
						x = x->child_left;
				} 
				else 
				{
					Tree_node_base<T> *y = x->parent;
					while (x == y->child_right) 
					{
						x = y;
						y = y->parent;
					}
					if (x->child_right != y)
						x = y;
				}
				return x;
			}

			const Tree_node_base<T> *RBTree_increment(const Tree_node_base<T> *x)
			{
				return static_RBTree_increment(const_cast<Tree_node_base<T>*>(x));
			}

			Tree_node_base<T> *static_RBTree_decrement(Tree_node_base<T> *x)
			{
				{
					if (x->_color == RED && x->parent->parent == x)
						x = x->child_right;
					else if (x->child_left != 0) 
					{
						Tree_node_base<T> *y = x->child_left;
						while (y->child_right != 0)
							y = y->child_right;
						x = y;
					}
					else 
					{
						Tree_node_base<T> *y = x->parent;
						while (x == y->child_left) 
						{
							x = y;
							y = y->parent;
						}
						x = y;
					}
				return x;
				}
			}

			const Tree_node_base<T> *RBTree_decrement(const Tree_node_base<T> *x)
			{
				return static_RBTree_decrement(const_cast<Tree_node_base<T>*>(x));
			}
	}; //! RBTree

}; //! ft
