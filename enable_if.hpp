#pragma once

namespace ft {

    template <bool Condition, class T = void>
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

