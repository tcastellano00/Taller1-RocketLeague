#include "CoordsTransformator.h"
#define METERTOPIXEL 10
#define GROUNDFROMCEILING 400


float CoordsTransformator::transformX(float x) {
    return x*METERTOPIXEL;
}

float CoordsTransformator::transformY(float y) {
    return y*(-1)*METERTOPIXEL + GROUNDFROMCEILING;
}
