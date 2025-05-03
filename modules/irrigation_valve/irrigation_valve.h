//=====[#include guards - begin]===============================================

#ifndef _IRRIGATION_VALVE_H_
#define _IRRIGATION_VALVE_H_

//=====[Declaration of public defines]=========================================

#define IRRIGATION_TIME 10000   //Tiempo de riego en ms

//=====[Declaration of public data types]======================================

//=====[Declarations (prototypes) of public functions]=========================

void irrigationValveInit();
void irrigationValveUpdate();
bool irrigationValveRead();

//=====[#include guards - end]=================================================

#endif // _IRRIGATION_VALVE_H_
