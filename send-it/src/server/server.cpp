#include "server.hpp"
#include "rpc/server.h"
#include "../util/util.hpp"
#include "../util/files.hpp"

namespace server {
    
    std::tuple<const std::string, std::vector<char>> send(const std::string &src) {
        try {
            const auto file_name = src.substr(2);

            if (util::is_binary(src)) {
                auto buffer = util::files::read(src);
                if (buffer.has_value()) 
                    return  {file_name, buffer.value()};
            } else {
                auto buffer = util::files::read(src);
                if (buffer.has_value()) {
                    return {file_name, buffer.value()};
                }
            }

        } catch (const std::exception & e) {
            std::cerr << e.what() << std::endl;
        }
        return { };
    }
}