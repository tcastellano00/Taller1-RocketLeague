#include "Model/BallModel.h"
#include "Model/PlayerModel.h"
#include "Model/ScoreModel.h"
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
