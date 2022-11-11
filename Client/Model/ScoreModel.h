class ScoreModel {
private:
    int minutesLeft;
    int secondsLeft;
    int miliSecondsLeft;
    int goalsFirstTeam;
    int goalsSecondTeam;
    
public:
    int getMinutesLeft();
    int getSecondsLeft();
    int getMiliSecondsLeft();
    int getGoalsFirstTeam();
    int getGoalsSecondTeam();
};
