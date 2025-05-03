//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "reset_button.h"
#include "water_sensor.h"
#include "irrigation_valve.h"
#include "alarm.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

DigitalIn  resetButton(D2);        //Botón de Reset para apagar el buzzer

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================
static bool readResetButton();

//=====[Implementations of public functions]===================================

void resetButtonInit()
{
    resetButton.mode(PullDown);
}

void resetButtonUpdate()
{
}

bool resetButtonRead()
{
    return resetButton;
}

//=====[Implementations of private functions]==================================

static bool readResetButton(){
    if(resetButton){
        delay(DEBOUNCE_BUTTON_TIME_MS);
        if(resetButton)
            return true;
    }
    return false;
}