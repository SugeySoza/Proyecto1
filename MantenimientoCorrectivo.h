#include<iostream>
#include"EstrategiaMantenimiento.h"
using namespace std;

#ifndef PROYECTO1_MANTENIMIENTOCORRECTIVO_H
#define PROYECTO1_MANTENIMIENTOCORRECTIVO_H


class MantenimientoCorrectivo: public  EstrategiaMantenimiento {
public:
    virtual void aplicar(Equipo* equipo)override;
    virtual string descripcion(Equipo* equipo)override;
    ~MantenimientoCorrectivo()override;

};


#endif //PROYECTO1_MANTENIMIENTOCORRECTIVO_H