#pragma once

#include <functional>
#include <memory>
#include <limits>
#include "Iterators/iterator.hpp"
#include "Iterators/random_access_iterator.hpp"
#include "Trees/RedBlackTree.hpp"

using std::string;
using std::cout;
using std::endl;

//? Ref : https://en.cppreference.com/w/cpp/container/map

namespace ft
{
    template<class Key,class T,class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key, T> > >
    class map
    {
        public :
        struct MapKeyOfT
		{
			const Key& operator()(const ft::pair<const Key, T>& kv)
			{
				return kv.first;
			}
		};

            typedef Key key_type;
            typedef T mapped_type;
            typedef typename ft::pair<const Key, T> value_type;
            typedef size_t size_type;
            typedef ptrdiff_t difference_type;
            typedef Compare key_compare;
            typedef Allocator allocator_type;
            typedef value_type& reference;
            typedef const value_type& const_reference;
            typedef typename allocator_type::pointer pointer;
            typedef typename allocator_type::const_pointer const_pointer;
            typedef typename RBTree<Key, ft::pair<const Key, T>, MapKeyOfT>::iterator iterator;
            typedef typename ft::random_access_iterator<const value_type> const_iterator;
            typedef typename ft::reverse_iterator<iterator> reverse_iterator;
            typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;

            //? Ref : https://en.cppreference.com/w/cpp/container/map/value_compare
            //? Ref : https://en.cppreference.com/w/cpp/utility/functional/binary_function

            class value_compare : std::binary_function<value_type, value_type, bool>
            {
                friend class map;
                protected :

                    key_compare comp;
                    value_compare(key_compare c) : comp(c) {}

                public :

                    bool operator()( const value_type& lhs, const value_type& rhs ) const
                    {
                        return comp(lhs.first, rhs.first);
                    }
            };

            map() : _t() {}
            explicit map(const Compare& comp,const Allocator& alloc = Allocator()) : _t(comp, alloc) {}

            template< class InputIt >
            map( InputIt first, InputIt last,const Compare& comp = Compare(),const Allocator& alloc = Allocator() ) : _t(comp, alloc)
            {
                insert(first, last);
            }
            map( const map& params ) : _t(params._t) {}
            map operator=(const map &params)
            {
                if (this != &params)
                    _t = params._t;
                return *this;
            }
            virtual ~map() {};

            iterator begin()
            {
                return _t.begin();
            }
            
            iterator end()
            {
                return _t.end();
            }

            ft::pair<iterator,bool> insert(const ft::pair<const Key, T>& kv)
            {
                return _t.insert(kv);
            }

            T& operator[](const Key& key)
            {
                ft::pair<iterator, bool> ret = Insert(ft::make_pair(key, T()));
                iterator it = ret.first;
                return it->second;
            }

            iterator find(const Key& key)
            {
                return _t.Find(key);
            }

        protected :

            RBTree<Key, ft::pair<const Key, T>, MapKeyOfT> _t;
    };
}