#include "files.hpp"
#include <filesystem>
// #include <iostream>

namespace util {

    namespace files {
        std::optional<std::vector<char>> read(const std::string & file_name) {

            auto absolute_path = util::absolute_path(file_name);
            
            if (util::is_binary(file_name)) {
                auto ifile = std::ifstream(absolute_path, std::ios::in | std::ios::binary);

                if (ifile.is_open()) {
                    try {
                        auto file_size = std::filesystem::file_size(absolute_path);
                        std::vector<char> buffer((std::istreambuf_iterator<char>(ifile)), std::istreambuf_iterator<char>());
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
                        auto buffer = std::string();
                        auto line = std::string();

                        while (std::getline(ifile, line)) {
                            buffer += line + "\n";
                        }

                        ifile.close();

                        return std::vector<char>(buffer.begin(), buffer.end());
                    } catch (const std::exception & e) {
                        throw std::runtime_error("excepted: " + std::string(e.what()));
                    }
                }
            }

            return std::nullopt;
        }
    }
}