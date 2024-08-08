#pragma once

#include "util.hpp"
#include "../error/error.hpp"
#include <array>
#include <exception>
#include <filesystem>
#include <fstream>
#include <ios>
#include <iostream>
#include <iterator>
#include <optional>
#include <stdexcept>
#include <string>
#include <vector>

namespace util {

    namespace files {

        inline std::optional<std::vector<char>> read(const std::string & file_name) {

            auto absolute_path = util::absolute_path(file_name);
            
            if (util::is_binary(file_name)) {
                auto ifile = std::ifstream(absolute_path, std::ios::in | std::ios::binary);

                if (ifile.is_open()) {
                    try {
                        auto file_size = std::filesystem::file_size(absolute_path);
                        std::vector<char> buffer((std::istreambuf_iterator<char>(ifile)), std::istreambuf_iterator<char>());
                        // while (ifile.read(buffer.data(), buffer.size()));
                        ifile.close();

                        return buffer;
                    } catch (const std::exception & e) {
                        throw std::runtime_error("excepted: " + std::string(e.what()));
                    }
                }
            } else {
                auto ifile = std::ifstream(absolute_path, std::ios::in);
                
                if (ifile.is_open()) {
                    try {
                        auto content = std::string();
                        auto line = std::string();

                        while (std::getline(ifile, line)) {
                            content += line + "\n";
                        }

                        ifile.close();

                        return std::vector<char>(content.begin(), content.end());
                    } catch (const std::exception & e) {
                        throw std::runtime_error("excepted: " + std::string(e.what()));
                    }
                }
            }

            return std::nullopt;
        }

        template <typename T>
        inline int write(const std::string & file_name, T content) {
            auto absolute_path = util::absolute_path(file_name);
            if (util::is_binary(file_name)) {
                auto ofile = std::ofstream(absolute_path, std::ios::out | std::ios::binary);

                if (ofile.is_open()) {
                    ofile.write(content.data(), content.size());

                    ofile.close();
                    return (0);
                }

            } else {
                auto ofile = std::ofstream(absolute_path, std::ios::out);

                if (ofile.is_open()) {
                    ofile << content;
                    ofile.close();
                    return (0);
                }
            }

            return error::files::FILE_NOT_OPEN;
        }
    }
}