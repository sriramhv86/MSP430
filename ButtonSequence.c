#include <driverlib.h>

volatile unsigned short Button1 = 0, Button2 =0;

void main (void)
{

    WDTCTL = WDTPW | WDTHOLD;    // Stop watchdog timer

    GPIO_setAsOutputPin( GPIO_PORT_P1, GPIO_PIN0 );
    GPIO_setOutputLowOnPin( GPIO_PORT_P1, GPIO_PIN0 );
    GPIO_setAsOutputPin( GPIO_PORT_P4, GPIO_PIN0 );
    GPIO_setOutputLowOnPin( GPIO_PORT_P4, GPIO_PIN0 );

    GPIO_setAsInputPinWithPullUpResistor( GPIO_PORT_P1, GPIO_PIN2 );
    GPIO_setAsInputPinWithPullUpResistor( GPIO_PORT_P2, GPIO_PIN6 );
    PMM_unlockLPM5();

    while(1) {
        Button1 = GPIO_getInputPinValue( GPIO_PORT_P1, GPIO_PIN2 );
        Button2 = GPIO_getInputPinValue( GPIO_PORT_P2, GPIO_PIN6 );

        if ( Button1 == GPIO_INPUT_PIN_LOW ) {
            GPIO_setOutputLowOnPin( GPIO_PORT_P1, GPIO_PIN0 );
            GPIO_setOutputLowOnPin( GPIO_PORT_P4, GPIO_PIN0 );
            __delay_cycles(600000);
            GPIO_setOutputLowOnPin( GPIO_PORT_P1, GPIO_PIN0 );
            GPIO_setOutputHighOnPin( GPIO_PORT_P4, GPIO_PIN0 );
            __delay_cycles(600000);
            GPIO_setOutputHighOnPin( GPIO_PORT_P1, GPIO_PIN0 );
            GPIO_setOutputLowOnPin( GPIO_PORT_P4, GPIO_PIN0 );
            __delay_cycles(600000);
            GPIO_setOutputHighOnPin( GPIO_PORT_P1, GPIO_PIN0 );
            GPIO_setOutputHighOnPin( GPIO_PORT_P4, GPIO_PIN0 );
            __delay_cycles(600000);

        }
        else if( Button2 == GPIO_INPUT_PIN_LOW ) {

            GPIO_setOutputLowOnPin( GPIO_PORT_P1, GPIO_PIN0 );
            GPIO_setOutputLowOnPin( GPIO_PORT_P4, GPIO_PIN0 );
        }
    }
}
