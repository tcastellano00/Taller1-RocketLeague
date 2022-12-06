#ifndef SERVER_CLIENTIDGENERATOR_H
#define SERVER_CLIENTIDGENERATOR_H

/*
Esta clase como su nombre lo indica funciona como un generador de
ids, es utilizada por el ClientConnection para generarse un id
durante su construcción
*/
class ClientIdGenerator {
private:
    static ClientIdGenerator* clientIdGenerator;
    
    int actualId;

    static ClientIdGenerator *getInstance();
    
public:
    ClientIdGenerator();

    static int getId();
    static void reset();
    static void deleteConfig();

    ClientIdGenerator(ClientIdGenerator &other) = delete;
    void operator=(ClientIdGenerator const&) = delete;

    ~ClientIdGenerator() = default;
};

#endif