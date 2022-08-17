#pragma once

#include <iostream>
#include "limits.h"
#include <memory>

using std::string;
using std::exception;
using std::cout;
using std::endl;
using std::cerr;
using std::ptrdiff_t;

namespace ft
{
    template <typename T, typename Allocator = std::allocator<T> >
    class vector
    {
        public :
            
            typedef T value_type;
            typedef Allocator allocator_type;
            typedef size_t size_type;
            typedef ptrdiff_t difference_type;
            typedef typename allocator_type::reference reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::pointer pointer;
            typedef typename allocator_type::const_pointer const_pointer;
            //! iterator
            //! const iterator
            //! reverse iterator
            //! const reverse iterator

            vector(const allocator_type& alloc = allocator_type()) : _start(0), _end(0), _maxcapacity(0), _alloc(alloc) {}
            vector(size_type n, const value_type &value = value_type(), const allocator_type& alloc = allocator_type())
            {
                this->_alloc = alloc;
                this->_start = this->_alloc.allocate(n);
                this->_end = this->_start;
                this->_maxcapacity = this->_start + n;
                while (n--)
                {
                    this->_alloc.construct(this->_end++, value);
                }
                cout << _start << endl;
                cout << _end << endl;
            }
            vector(const vector &params) : _alloc(params._alloc)
            {
                size_type size = params.size();
                this->_start = this->_alloc.allocate(size);
                this->_end = this->_start;
                this->_maxcapacity = this->_start + size;
                pointer uwu = params._start;
                while (size--)
                    this->_alloc.construct(this->_end++, *uwu++);
            }
            // vector &operator=(const vector &params)
            // {

            // }
            ~vector()
            {
                // this->_alloc.deallocate(this->_start,)
            }

            reference at(size_type value) const
            {
                if (value >= 2) //! CHANGE 2 TO SIZE
                    throw OutOfRangeException();
                return (this->_start[value]);
            }
            reference at(size_type value)
            {
                if (value >= 2) //! CHANGE 2 TO SIZE
                    throw OutOfRangeException();
                return (this->_start[value]);
            }
            
            T operator[](size_type n)
            {
                if (n >= 2)
                    throw OutOfRangeException();
                return (this->_start[n]);
            }
            T &operator[](size_type n) const
            {
                if (n >= 2)
                    throw OutOfRangeException();
                return (this->_start[n]);
            }
            // size_type size()
            // {
            //     return ()
            // }
            // reference front()
            // {
            //     return (this->_start[0]);
            // }

            // reference back()
            // {
            //     return (this->_start[_end]);
            // }

        private :

            pointer _start;
            pointer _end;
            pointer _maxcapacity;
            allocator_type _alloc;

        class OutOfRangeException : public exception
        {
            const char *what() const throw()
            {
                return ("Out of range");
            }
        };
    };
};