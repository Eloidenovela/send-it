#pragma once

#include "rpc/client.h"
#include "rpc/server.h"
#include <exception>
#include <fstream>
#include <stdexcept>
#include <string>
#include <iostream>
#include "../util/files.hpp"

namespace client {
    class client {
        rpc::client c;
        public:
            client(std::string ipv4, const int port) : 
                c(ipv4, port) { }

            inline void receive() {
                try {
                    auto [file_name, buffer] = this->c.call("receive").as<std::tuple<std::string, std::string>>();
                    
                    auto res = util::files::write(("./"+file_name), buffer);
                } catch (const std::exception & e) {
                    std::cerr << "excepted: " + std::string(e.what()) << std::endl;
                }
            }
    };
}