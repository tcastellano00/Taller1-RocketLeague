#include "CoordsTransformator.h"
#include "../../Common/Config/ClientConfig.h"
#include "../../Common/Config/ServerConfig.h"

#define METERTOPIXEL ClientConfig::getScreenHeight()/ServerConfig::getFieldHeight()
#define GROUNDFROMCEILING ClientConfig::getScreenHeight()
#define PI  3.14159265358979323846


float CoordsTransformator::transformX(float x) {
    return x*METERTOPIXEL;
}

float CoordsTransformator::transformY(float y) {
    return y*(-1)*METERTOPIXEL + GROUNDFROMCEILING;
}

float CoordsTransformator::radianToDegree(float angle) {
    return (angle * 180.0) / PI;
}
