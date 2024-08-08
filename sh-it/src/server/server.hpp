#pragma once

#include "rpc/server.h"
#include "../util/util.hpp"
#include <cstddef>
#include <exception>
#include <filesystem>
#include <fstream>
#include <ios>
#include <optional>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <iostream>

namespace server {
    inline std::tuple<std::string, std::string> send(const std::string &src) {
        try {
            std::cout<< util::absolute_path(src) << std::endl;
            auto sendable = std::ifstream(util::absolute_path(src).c_str(), std::ios::in);
            auto file_content = std::string();
            auto file_name = src.substr(2);

            if (sendable.is_open()) {
                std::string line;
                while (std::getline(sendable, line)) {
                    file_content += line + "\n";
                }
            } else {
                std::cout << "File not found" << std::endl;
            }

            sendable.close();
            return {file_name, file_content};
        } catch (const std::exception & e) {
            std::cerr << e.what() << std::endl;
        }
        return { };
    }
}