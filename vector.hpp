#pragma once

#include <iostream>
#include "limits.h"
#include <memory>
#include "iterator.hpp"
#include "enable_if.hpp"

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
            typedef typename ft::iterator_traits<value_type> iterator; 
            typedef typename ft::iterator_traits<const value_type> const_iterator; 
            typedef typename ft::reverse_iterator<value_type> reverse_iterator; 
            typedef typename ft::reverse_iterator<const value_type> const_reverse_iterator; 

            iterator begin()
            {
                return *this->_start;
            }
            iterator end()
            {
                return *this->_end;
            }

            explicit vector(const allocator_type& alloc = allocator_type()) : _start(0), _end(0), _maxcapacity(0), _alloc(alloc) {}
            explicit vector(size_type n, const value_type &value = value_type(), const allocator_type& alloc = allocator_type())
            {
                this->_alloc = alloc;
                this->_start = this->_alloc.allocate(n);
                this->_end = this->_start;
                this->_maxcapacity = this->_start + n;
                while (n--)
                    this->_alloc.construct(this->_end++, value);
            }
            
            // template<class InputIt>
            // vector (InputIt first, InputIt last, const allocator_type &alloc = allocator_type())
            // {

            // }
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
            //     pointer old_start = this->_start;
            //     // pointer old_end = this->_end;
            //     pointer tmp = params._start;
            //     pointer end = params._end;
            //     while (tmp != end)
            //         this->_alloc.construct(tmp++, *old_start);
            //     // for (size_type len = old_end - old_start; len > 0; len--)
            //     //     this->_alloc.destroy(old_end--); 
            //     return *this;
            // }
            ~vector()
            {
                this->clear();
                size_type i = this->capacity();
                this->_alloc.deallocate(this->_start, i);
            }

            void assign(size_type count, const value_type &value)
            {
                if (count > size())
                {
                    pointer tmp = this->_start;
                    for (; tmp < this->_end; tmp++)
                        this->_alloc.construct(tmp, value);
                    while (count != size())
                        push_back(value);
                }
                else
                {
                    pointer tmp = this->_start;
                    for (size_type i = 0; i < count; i++)
                        this->_alloc.construct(tmp++, value);
                }
            }
            
            allocator_type get_allocator() const
            {
                return this->_alloc;
            }

            const_reference at(size_type value) const
            {
                if (this->size() <= value)
                    throw OutOfRangeException();
                return (this->_start[value]);
            }
            reference at(size_type value)
            {
                if (this->size() <= value)
                    throw OutOfRangeException();
                return (this->_start[value]);
            }
            
            reference operator[](size_type n)
            {
                if (n >= size())
                    throw OutOfRangeException();
                return (this->_start[n]);
            }
            const_reference &operator[](size_type n) const
            {
                if (n >= size())
                    throw OutOfRangeException();
                return (this->_start[n]);
            }
            // reference front()
            // {
            //     return 
            // }

            // reference back()
            
            //     return 
            // }
            bool empty() const
            {
                if (this->_start == this->_end)
                    return true;
                return false;
            }

            size_type size() const
            {
                size_type n = 0;
                pointer tmp = this->_start;
                while (tmp != this->_end)
                {
                    tmp++;
                    n++;
                }
                return n;
            }

            size_type max_size() const
            {
                return (this->_alloc.max_size());
            }

            void reserve (size_type new_cap)
            {
                if (new_cap > this->max_size())
                    throw OutOfRangeException();
                if (new_cap > size())
                {
                    pointer old_start = this->_start;
                    pointer old_end = this->_end;
                    size_type old_maxcapacity = this->capacity();

                    this->_start = this->_alloc.allocate(new_cap);
                    this->_end = this->_start;
                    this->_maxcapacity = this->_start + new_cap;

                    for (pointer new_capacity = old_start; new_capacity != old_end; new_capacity++)
                        this->_alloc.construct(this->_end++, *new_capacity);
                    for (size_type len = old_end - old_start; len > 0; len--)
                        this->_alloc.destroy(old_end--);
                    this->_alloc.deallocate(old_start, old_maxcapacity);
                }
                return ;
            }

            size_type capacity() const
            {
                size_type i = 0;
                pointer tmp = this->_start;
                while (tmp != this->_maxcapacity)
                {
                    tmp++;
                    i++;
                }
                return (i);
            }

            void clear()
            {
                for (size_type len = this->_end - this->_start; len > 0; len--)
                    this->_alloc.destroy(this->_end--); 
            }

            // iterator insert(iterator pos, const value_type &value)
            // {

            // }

            // iterator erase(iterator pos)
            // {

            // }

            void push_back(const value_type &value)
            {
                if (size() + 1 > capacity())
                {
                    reserve(size() + 1);
                    this->_alloc.construct(this->_end++, value);
                }
                else
                    this->_alloc.construct(this->_end++, value);
            }
            void pop_back()
            {
                if (size() == 0)
                    return ;
                else
                    this->_alloc.destroy(this->_end--);
            }

            void resize(size_type count)
            {
                if (count <= size())
                {
                    count = size() - count;
                    while (count--)
                        this->_alloc.destroy(this->_end--);
                }
                else if (count > size())
                {
                    reserve(count);
                    count = count - size();
                    while (count--)
                        this->_alloc.construct(this->_end++, 0);
                }
            }

            void swap(vector &other)
            {
                if (&other == this)
                    return ;
                pointer tmp = this->_start;
                pointer tmp1 = this->_end;
                pointer tmp2 = this->_maxcapacity;

                this->_start = other._start;
                this->_end = other._end;
                this->_maxcapacity = other._maxcapacity;
                other._start = tmp;
                other._end = tmp1;
                other._maxcapacity = tmp2;
            }


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