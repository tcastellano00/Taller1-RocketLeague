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
#include "ActionClientDoRedShot.h"
#include "ActionClientDoGoldenShot.h"
#include "ActionClientDoPurpleShot.h"
#include "ActionClientDoSkipReplay.h"

#include "../../Common/Constants/ActionsClient.h"

std::shared_ptr<ActionsClient> ActionsClient::get_command_ptr(
    const std::string &name, int cltId) {

    if (name == START_ACCELERATING_BACKWARDS)
        return std::shared_ptr<ActionsClient>(new ActionClientStartAcceleratingBackwards(cltId));
    else if (name == START_ACCELERATING_FORWARD)
        return std::shared_ptr<ActionsClient>(new ActionClientStartAcceleratingForward(cltId));
    else if(name == START_JUMPING)
        return std::shared_ptr<ActionsClient>(new ActionClientJump(cltId));
    else if(name == START_FLIPING_RIGHT)
        return std::shared_ptr<ActionsClient>(new ActionClientFlipRight(cltId));
    else if(name == START_FLIPING_LEFT)
        return std::shared_ptr<ActionsClient>(new ActionClientFlipLeft(cltId));
    else if(name == START_DOING_TURBO)
        return std::shared_ptr<ActionsClient>(new ActionClientTurbo(cltId));
    else if(name == START_TURNING)
        return std::shared_ptr<ActionsClient>(new ActionClientStartTurning(cltId));
    else if(name == STOP_DOING_TURBO)
        return std::shared_ptr<ActionsClient>(new ActionClientStopTurbo(cltId));
    else if(name == STOP_ACCELERATING)
        return std::shared_ptr<ActionsClient>(new ActionClientStopAccelerating(cltId));
    else if (name == STOP_FLIPING)
        return std::shared_ptr<ActionsClient>(new ActionClientStopFlip(cltId));
    else if (name == DO_RED_SHOT)
        return std::shared_ptr<ActionsClient>(new ActionClientDoRedShot(cltId));
    else if (name == DO_GOLDEN_SHOT)
        return std::shared_ptr<ActionsClient>(new ActionClientDoGoldenShot(cltId));
    else if (name == DO_PURPLE_SHOT)
        return std::shared_ptr<ActionsClient>(new ActionClientDoPurpleShot(cltId));
    else if (name == SKIP_REPLAY)
        return std::shared_ptr<ActionsClient>(new ActionClientDoSkipReplay(cltId));
    return NULL;
}

bool ActionsClient::getSkipReplay(){
    return skipReplay;
}