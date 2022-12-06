#include "GameLoop.h"

void GameLoop::run(bool& isRunning, NonBlockingQueue<std::shared_ptr<ActionsClient>>& recibingQueue, Physics& gamePhysics, BlockingQueue<GameStatus>& senderQueue) {
    int commandsCounter = 0;
    while (isRunning) {
        auto timeStart = Clock::now();

        while (!recibingQueue.empty() && commandsCounter < LIMITOFCOMANDS) {
            std::shared_ptr<ActionsClient> action = recibingQueue.pop();

            if (action == NULL) {
                continue;
            }

            if (gamePhysics.getIsInReplay() && !action->getSkipReplay()) {
                continue;
            }

            if (!gamePhysics.getIsInReplay() && action->getSkipReplay()) {
                continue;
            }

            action->execute(gamePhysics);

            commandsCounter += 1;
        }
        
        if (!gamePhysics.getIsInReplay()) {
            gamePhysics.simulateTimeStep();
        }

        GameStatus gameStatus = gamePhysics.getGameStatus();

        senderQueue.push(gameStatus);

        gamePhysics.resetPositionsIfGoal();
        gamePhysics.fillTurbos();
        gamePhysics.accelerateCars();
        gamePhysics.applyTurboToCars();
        gamePhysics.updateReplayStaus();
        
        auto timeFinish = Clock::now();

        synchronizeFrameRate(timeStart, timeFinish);

        commandsCounter = 0;

        if (gameStatus.isClosed()) {
            isRunning = false;
        }

    }

}

void GameLoop::synchronizeFrameRate(
    std::chrono::_V2::system_clock::time_point timeStart,
    std::chrono::_V2::system_clock::time_point timeFinish
) {
    int elapsed = std::chrono::duration_cast<std::chrono::microseconds>(timeFinish - timeStart).count();
    if (DELTA - elapsed > 0) {
        usleep(DELTA - elapsed);
    }
}