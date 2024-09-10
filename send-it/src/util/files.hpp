#pragma once

#include "util.hpp"
#include <optional>
#include <string>
#include <vector>
#include <fstream>
#include <ios>
#include "../error/error.hpp"

namespace util {

    namespace files {

        std::optional<std::vector<char>> read(const std::string & file_name);

        template <typename T>
        int write(const std::string & file_name, T buffer) {
            auto absolute_path = util::absolute_path(file_name);
            if (util::is_binary(file_name)) {
                auto ofile = std::ofstream(absolute_path, std::ios::out | std::ios::binary);

                if (ofile.is_open()) {
                    ofile.write(buffer.data(), buffer.size());

                    ofile.close();
                    return (0);
                }

            } else {
                auto ofile = std::ofstream(absolute_path, std::ios::out);

                if (ofile.is_open()) {
                    ofile << buffer;
                    ofile.close();
                    return (0);
                }
            }

            return error::files::FILE_NOT_OPEN;
        }
    }
}