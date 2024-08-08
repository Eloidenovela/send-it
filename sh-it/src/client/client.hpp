#pragma once

#include "rpc/client.h"
#include "rpc/server.h"
#include <exception>
#include <fstream>
#include <string>
#include <iostream>

namespace client {
    class client {
        rpc::client c;
        public:
            client(std::string ipv4, const int port) : 
                c(ipv4, port) { }

            inline void receive() {
                try {
                    auto [file_name, file_content] = this->c.call("receive").as<std::tuple<std::string, std::string>>();
                    auto file = std::ofstream(file_name, std::ios::out); 

                    if (file.is_open()) {
                        std::cout << "success" << std::endl;
                    } else {
                        std::cout << "failed" << std::endl;
                    }
                } catch (const std::exception & e) {
                    std::cerr << e.what() << std::endl;
                }
            }
    };
}