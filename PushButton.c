#include <driverlib.h>

volatile unsigned short Button1 = 0;

void main (void)
{

    WDTCTL = WDTPW | WDTHOLD;    // Stop watchdog timer

    GPIO_setAsOutputPin( GPIO_PORT_P1, GPIO_PIN0 );
    GPIO_setOutputLowOnPin( GPIO_PORT_P1, GPIO_PIN0 );

    GPIO_setAsInputPinWithPullUpResistor( GPIO_PORT_P1, GPIO_PIN2 );
    PMM_unlockLPM5();

    while(1) {
        Button1 = GPIO_getInputPinValue( GPIO_PORT_P1, GPIO_PIN2 );

        if ( Button1 == GPIO_INPUT_PIN_LOW ) {
            GPIO_setOutputHighOnPin( GPIO_PORT_P1, GPIO_PIN0 );
        }
        else {
            GPIO_setOutputLowOnPin( GPIO_PORT_P1, GPIO_PIN0 );
        }
    }
}
