#pragma once

#include <string>
#include <vector>

namespace server {

    std::tuple<const std::string, std::vector<char>> send(const std::string &src);
}