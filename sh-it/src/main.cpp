#include <cstddef>
#include <cstdlib>
#include <filesystem>
#include <iostream>
#include "rpc/client.h"
#include "rpc/config.h"
#include "rpc/server.h"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "server/server.hpp"

int main(int argc, char** argv) {

    rpc::server server(8080);

    std::cout << argv[1] << std::endl;

    server.bind("receive", [&] () {
        return server::send(argv[1]);
    });

    server.run();
    
    return 0;
}
