#include <iostream>
#include "client/client.hpp"
#include "server/server.hpp"
#include "util/util.hpp"

int main(int argc, char** argv) {

    if (util::is_equals(argv[1], "-R")) {
        client::client client("localhost", 8080);
        client.receive();

    } else if (util::is_equals(argv[1], "-S")) {
        rpc::server server(8080);
        server.bind("receive", [&] () {
            return server::send(argv[2]);
        });
        server.run();
    }
    
    return 0;
}
