//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "alarm.h"
#include "greenhouse_system.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

DigitalOut emptyWaterLED(LED1);//D11);     //LED de alarma (Ausencia de agua)
DigitalOut emptyWaterBuzzer(LED2);//D12);  //Buzzer de alarma (Ausencia de agua prolongada)

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

static bool alarmLEDState = OFF;
static bool alarmBuzzerState = OFF;

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void alarmInit()
{
    emptyWaterLED = OFF;
    emptyWaterBuzzer = OFF;
}

bool alarmLEDStateRead()
{
    return alarmLEDState;
}

bool alarmBuzzerStateRead()
{
    return alarmBuzzerState;
}

void alarmLEDStateWrite( bool state )
{
    alarmLEDState = state;
}

void alarmBuzzerStateWrite( bool state )
{
    alarmBuzzerState = state;
}

void alarmUpdate()
{
    static int accumulatedTimeAlarm = 0;
    accumulatedTimeAlarm = accumulatedTimeAlarm + SYSTEM_TIME_INCREMENT_MS;
    
    if( alarmLEDState ) {
        emptyWaterLED = ON;
    } else {
        emptyWaterBuzzer = OFF;
    }

    if( alarmBuzzerState ) {
        if( accumulatedTimeAlarm >= ALARM_BUZZ_TIME ) {
                accumulatedTimeAlarm = 0;
                emptyWaterBuzzer= !emptyWaterBuzzer;
        }
    } else {
        emptyWaterBuzzer = OFF;
    }
}

//=====[Implementations of private functions]==================================

