#include <iostream>
#include <exception>
#include <arpa/inet.h>

#include "../Common/Config/ServerConfig.h"
#include "../Common/Config/ClientConfig.h"
#include "../Common/Config/CommonConfig.h"
#include "../Server/ClientIdGenerator.h"
#include "../Server/Server.h"

int main(int argc, char *argv[]) { try {
    int ret = 1;
    const char *port = NULL;

    if (argc == 2) {
        port = argv[1];
    } else {
        std::cerr << "Bad program call. Expected "
                << argv[0]
                << " <servname>\n";
        return ret;
    }

    Server server(port);

    server.run();

    ServerConfig::deleteConfig();
    ClientConfig::deleteConfig();
    CommonConfig::deleteConfig();
    ClientIdGenerator::deleteConfig();

    ret = 0;
    return ret;
} catch (const std::exception& err) {
    std::cerr
        << "Something went wrong and an exception was caught: "
        << err.what()
        << "\n";
    return -1;
} catch (...) {
    std::cerr << "Something went wrong and an unknown exception was caught.\n";
    return -1;
} }
