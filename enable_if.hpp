#pragma once

//? Ref : https://en.cppreference.com/w/cpp/types/enable_if
//? Ref : https://h-deb.clg.qc.ca/Sujets/TrucsScouts/Comprendre_enable_if.html

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
        typedef value_type value;
    };

    struct type_false
    {
        static const bool value = false;
        typedef type_false type;
        typedef value_type value;
    }
};

