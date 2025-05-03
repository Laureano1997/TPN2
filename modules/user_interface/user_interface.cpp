#include "mbed.h"
#include "arm_book_lib.h"

#include "display.h"
#include "temperature_sensor.h"
#include "water_sensor.h"
#include "alarm.h"
#include "greenhouse_system.h"

//=====[Declaration of private defines]========================================
#define DISPLAY_REFRESH_TIME_MS 1000

static void userInterfaceDisplayInit();

void userInterfaceInit()
{
    userInterfaceDisplayInit();
}

static void userInterfaceDisplayInit()
{
    displayInit( DISPLAY_CONNECTION_I2C_PCF8574_IO_EXPANDER );
     
    displayCharPositionWrite ( 0,0 );
    displayStringWrite( "Temperatura:" );

    displayCharPositionWrite ( 0,1 );
    displayStringWrite( "Tanque: " );
    
    //displayCharPositionWrite ( 0,2 );
    //displayStringWrite( "Alarm:" );
}

static void userInterfaceDisplayUpdate()
{
    static int accumulatedDisplayTime = 0;
    char temperatureString[3] = "";
    
    if( accumulatedDisplayTime >=
        DISPLAY_REFRESH_TIME_MS ) {

        accumulatedDisplayTime = 0;

        sprintf(temperatureString, "%.0f", temperatureSensorReadCelsius());
        displayCharPositionWrite ( 12,0 );
        displayStringWrite( temperatureString );
        displayCharPositionWrite ( 14,0 );
        displayStringWrite( "'C" );

        displayCharPositionWrite ( 4,1 );

        if ( waterSensorRead() ) {
            displayStringWrite( "lleno" );
        } else {
            displayStringWrite( "vacío" );
        }

    } else {
        accumulatedDisplayTime =
            accumulatedDisplayTime + SYSTEM_TIME_INCREMENT_MS;        
    } 
}