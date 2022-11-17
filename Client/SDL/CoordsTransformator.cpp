#include "CoordsTransformator.h"
#define METERTOPIXEL 10
#define GROUNDFROMCEILING 400
#include <math.h>


float CoordsTransformator::transformX(float x) {
    return x*METERTOPIXEL;
}

float CoordsTransformator::transformY(float y) {
    return y*(-1)*METERTOPIXEL + GROUNDFROMCEILING;
}

float CoordsTransformator::radianToDegree(float angle) {
    return (angle * 180.0)/M_PIf;
}
