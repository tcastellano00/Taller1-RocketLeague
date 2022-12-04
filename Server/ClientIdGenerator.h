#ifndef SERVER_CLIENTIDGENERATOR_H
#define SERVER_CLIENTIDGENERATOR_H

class ClientIdGenerator {
private:
    static ClientIdGenerator* clientIdGenerator;
    
    int actualId;

    static ClientIdGenerator *getInstance();
    
public:
    ClientIdGenerator();

    static int getId();
    static void reset();

    ClientIdGenerator(ClientIdGenerator &other) = delete;
    void operator=(ClientIdGenerator const&) = delete;

    ~ClientIdGenerator() = default;
};

#endif