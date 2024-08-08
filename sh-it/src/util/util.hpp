#pragma once

#include <filesystem>
#include <iterator>
#include <regex>
#include <sstream>
#include <string>

namespace util {
    inline bool is_binary(std::string src) {

        const std::string binary_patterns[] = {
            ".*(.mp3).*",
            ".*(.mp4).*",
            ".*(.mkv).*"
        };

        for (auto pattern : binary_patterns) {
            if (std::regex_match(src, std::regex(pattern)))
                return true;
        }

        return false;
    } 

    inline std::string absolute_path(const std::string & src) {
        std::filesystem::path file_name(src);
        auto absolute_path = std::filesystem::absolute(file_name.parent_path());

        std::stringstream path;

        path << absolute_path;
        auto source = path.str();

        return source.substr(1, std::size(source) - 3) + src.substr(2);
    }
}