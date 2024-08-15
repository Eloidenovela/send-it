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

            void receive();
    };
}