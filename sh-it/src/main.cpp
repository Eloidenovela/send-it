#include <exception>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include "client/client.hpp"
#include "docs/docs.hpp"
#include "error/error.hpp"
#include "server/server.hpp"
#include "util/util.hpp"

int main(int argc, char** argv) {
    if (argv[1] == nullptr) {
        docs::error(error::args::WITHOUT_OPTION_TO_CONTINUE);

    } else {

        if (util::is_equals(argv[1], "-R")) {
            client::client client("localhost", 8080);
            client.receive();

        } else if (util::is_equals(argv[1], "-S")) {
            if (argv[2] != nullptr) {
                rpc::server server(8080);
                server.bind("receive", [&] () {
                    return server::send(argv[2]);
                });
                server.run();
            } else {
                docs::error(error::args::WITHOUT_FILE_TO_SEND);
            }
        } else {
            docs::docs();
        }
    }
}
