#include "ActionsClient.h"
#include "ActionClientJump.h"
#include "ActionClientStartAcceleratingForward.h"
#include "ActionClientStartAcceleratingBackwards.h"
#include "ActionClientFlipRight.h"
#include "ActionClientFlipLeft.h"
#include "ActionClientTurbo.h"
#include "ActionClientStopTurbo.h"
#include "ActionClientStopAccelerating.h"
#include "ActionClientStopFlip.h"
#include "ActionClientStartTurning.h"

#include "../../Common/Constants/ActionsClient.h"

std::shared_ptr<ActionsClient> ActionsClient::get_command_ptr(
    const std::string &name, int sktId) {

    if (name == START_ACCELERATING_BACKWARDS)
        return std::shared_ptr<ActionsClient>(new ActionClientStartAcceleratingBackwards(sktId));
    else if (name == START_ACCELERATING_FORWARD)
        return std::shared_ptr<ActionsClient>(new ActionClientStartAcceleratingForward(sktId));
    else if(name == START_JUMPING)
        return std::shared_ptr<ActionsClient>(new ActionClientJump(sktId));
    else if(name == START_FLIPING_RIGHT)
        return std::shared_ptr<ActionsClient>(new ActionClientFlipRight(sktId));
    else if(name == START_FLIPING_LEFT)
        return std::shared_ptr<ActionsClient>(new ActionClientFlipLeft(sktId));
    else if(name == START_DOING_TURBO)
        return std::shared_ptr<ActionsClient>(new ActionClientTurbo(sktId));
    else if(name == START_TURNING)
        return std::shared_ptr<ActionsClient>(new ActionClientStartTurning(sktId));
    else if(name == STOP_DOING_TURBO)
        return std::shared_ptr<ActionsClient>(new ActionClientStopTurbo(sktId));
    else if(name == STOP_ACCELERATING)
        return std::shared_ptr<ActionsClient>(new ActionClientStopAccelerating(sktId));
    else if (name == STOP_FLIPING)
        return std::shared_ptr<ActionsClient>(new ActionClientStopFlip(sktId));

    return NULL;
}