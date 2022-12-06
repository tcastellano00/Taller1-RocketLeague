#ifndef COORDS_TRANSFORMATOR_H
#define COORDS_TRANSFORMATOR_H


/*
Transforma las coordenadas que llegan en el formato utilizado en Box2D
(x crece hacia la derecha, y crece hacia arriba, z crece antihorario)
al formato utilizado en SDL (x crece hacia la derecha, y crece hacia abajo,
z crece horario).
*/
class CoordsTransformator {
public:
    static float transformX(float x);
    static float transformY(float y);
    static float radianToDegree(float angle);
    
};

#endif
