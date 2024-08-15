#pragma once

// #include <cstddef>
#include <cstring>
#include <iostream>
// #include <iterator>
#include <string>

namespace util {
    bool is_binary(std::string src);

    std::string absolute_path(const std::string & src);

    inline bool is_equals(const char* p1, std::string p2) {
        return (std::strcmp(p1, p2.c_str()) == 0);
    }
}