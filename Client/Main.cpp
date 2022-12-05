#include <iostream>
#include <sstream>
#include <exception>

#include "Client.h"

int main(int argc, char* argv[]) { try {
    int ret = 1;

    Client clt(argv[1], argv[2]);
    clt.start();

    ret = 0;
    return ret;
} catch (const std::exception& err) {
    std::cerr
        << "Something went wrong and an exception was caught: "
        << err.what()
        << "\n";
    return 1;
} catch (...) {
    std::cerr << "Something went wrong and an unknown exception was caught.\n";
    return 1;
} }

