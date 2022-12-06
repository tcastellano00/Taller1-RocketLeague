#ifndef ENTITY_CATEGORY_H
#define ENTITY_CATEGORY_H


/*
Catergorias de cada tipo de elemento en la fisica de box2d.
Esto sirve para registrar que tipos de cuerpos pueden 
colisionar o no entre ellos.
*/
enum _entityCategory {
  BOUNDARY = 0x0001,
  CAR  = 0x0002,
  BALL = 0x0004,
  GOALSENSOR = 0x0008,
  CAR_FRONT_SENSOR = 0x0010,
  CAR_BOTTOM_SENSOR = 0x0020,
  CORNER = 0x0040,
  SAVING_AREA_SENSOR = 0x0080
};

#endif