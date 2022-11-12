#include "../Common/Model/BallModel.h"
#include "../Common/Model/PlayerModel.h"
#include "../Common/Model/ScoreModel.h"
#include <list>
#include <string>

class ParserGameStatus {
private:
    int numberOfPlayers;
    BallModel ball;
    ScoreModel score;
    std::list<PlayerModel> players;

public:
    ParserGameStatus(std::string reply);
    int getNumberOfPlayers();
    BallModel getBall();
    ScoreModel getScore();
    std::list<PlayerModel> getPlayers();
};
