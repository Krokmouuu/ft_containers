#pragma once

#include <iostream>
#include "limits.h"
#include <memory>

using std::string;
using std::exception;
using std::cout;
using std::endl;
using std::cerr;

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

            explicit vector(const allocator_type& alloc = allocator_type()) : _array(0), _start(0), _end(0), _maxcapacity(0), _alloc(alloc) {}
            explicit vector(size_type n, const value_type &value = value_type(), const allocator_type& alloc = allocator_type())
            {
                try
                {
                    this->_alloc = alloc;
                    this->_start = this->_alloc.allocate(n);
                    this->_end = this->_start;
                    while (n--)
                    {
                        this->_alloc.construct(this->_end++, value);
                        this->_maxcapacity++;
                    }
                }
                catch (const exception &a)
                {
                    cerr << a.what() << endl;
                }
            }
            explicit vector(const vector &params) : _alloc(params._alloc)
            {
                this->_start = params._start;
                this->_end = params._start;
                this->_maxcapacity = params._maxcapacity;
                pointer help = _maxcapacity;
                while (help--)
                    this->_alloc.construct(_end++, *params);
            }
            ~vector()
            {
                // this->_alloc.deallocate(this->_start,)
            }


        private :

        T *_array;
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