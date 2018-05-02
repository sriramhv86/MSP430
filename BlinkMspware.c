#include <driverlib.h>


void main (void)
{

    WDTCTL = WDTPW | WDTHOLD;    // Stop watchdog timer

    GPIO_setAsOutputPin( GPIO_PORT_P1, GPIO_PIN0 );
    GPIO_setOutputLowOnPin( GPIO_PORT_P1, GPIO_PIN0 );

    PMM_unlockLPM5();

    while(1) {

            GPIO_setOutputHighOnPin( GPIO_PORT_P1, GPIO_PIN0 );
            __delay_cycles(600000);
            GPIO_setOutputLowOnPin( GPIO_PORT_P1, GPIO_PIN0 );
            __delay_cycles(600000);
    }
}
