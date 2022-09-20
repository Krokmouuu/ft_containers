#pragma once

//? Ref : https://en.cppreference.com/w/cpp/types/enable_if
//? Ref : https://h-deb.clg.qc.ca/Sujets/TrucsScouts/Comprendre_enable_if.html
//? Ref : https://www.cs.auckland.ac.nz/references/unix/digital/AQTLTBTE/DOCU_032.HTM
//? Ref : https://www.enseignement.polytechnique.fr/informatique/INF478/docs/Cpp/en/cpp/types/is_integral.html

#include "../Iterators/iterator.hpp"

namespace ft {

    template <bool B, class T = void>
    struct enable_if {};

    template <class T>
    struct enable_if<true, T>
    {
        typedef T type;
    };

    struct type_true
    {
        static const bool value = true;
        typedef type_true type;
        typedef bool type_value;
    };

    struct type_false
    {
        static const bool value = false;
        typedef type_false type;
        typedef bool type_value;
    };

    template<class T>
    struct is_integral : public type_false {};

    template<>
    struct is_integral<bool> : public type_true {};

    template<>
    struct is_integral<char> : public type_true {};

    template<>
    struct is_integral<char16_t> : public type_true {};

    template<>
    struct is_integral<char32_t> : public type_true {};

    template<>
    struct is_integral<wchar_t> : public type_true {};

    template<>
    struct is_integral<short> : public type_true {};

    template<>
    struct is_integral<int> : public type_true {};

    template<>
    struct is_integral<unsigned int> : public type_true {};

    template<>
    struct is_integral<long> : public type_true {};

    template<>
    struct is_integral<long long> : public type_true {};

    template<>
    struct is_integral<unsigned long> : public type_true {};


    struct nullptr_t 
    {
        private:
            void operator&() const;

        public:
            template <class T>
            inline operator T*() const { return 0; }

            template <class C, class T>
            inline operator T C::*() const { return 0; }
    };
    
    static nullptr_t null_pointer = {};
};
