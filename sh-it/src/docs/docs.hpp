#pragma once

#include <iostream>
#include "../error/error.hpp"

namespace docs {

    inline void docs() {
        std::cout << "Name\n"
                  << "\tSH-IT [option] [Args ...]\n\n"
                  << "Description\n"
                  << "\tThis project implements a file transfer system using the RPC library, developed in C++.\n"
                  << "\tThe goal is to provide a lightweight and efficient solution for transmitting files between\n\tdevices on a local network.\n"
                  << "Option\n"
                  << "\t-S if u want to send files\n"
                  << "\t-R if u want to receive files\n"
                  << "Example\n"
                  << "\tsh-it -S ./file_name\n"
                  << "\tsh-it -R\n";  
    }

    inline void error(int type) {
        switch (type) {
            case error::args::WITHOUT_FILE_TO_SEND:
                std::cout << "warning: you must set [./file_name] to continue, couse u're server.\n\n";
                break;
            case error::args::WITHOUT_OPTION_TO_CONTINUE:
                std::cout << "warning: You must pass one the arguments(options) listed in documentation to continue.\n\n";
                break;
        }

        docs::docs();
    }
}