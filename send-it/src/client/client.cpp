#include "client.hpp"

namespace client {
    void client::receive() { 
        try {
            auto [file_name, buffer] = this->c.call("receive").as<std::tuple<std::string, std::string>>();
            
            auto res = util::files::write(("./"+file_name), buffer);
        } catch (const std::exception & e) {
            std::cerr << "excepted: " + std::string(e.what()) << std::endl;
        }
    }
}