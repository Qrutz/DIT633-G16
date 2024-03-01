#include <Servo.h>

#define SERVOPIN 7

Servo servo;
int interruptCounter = 0;
int seconds = 0;
int angle = 0;

void setup()
{

    servo.attach(SERVOPIN);

    cli(); // Stop interrupts

    // Set up Timer 2 for a 1Hz interrupt frequency if possible
    // THIS TIMER IS NOT OPTIMAL BUT THE DAMN SERVO LIBRARY ALREADY USES
    // TIMER1 which is more optimal for counting seconds..
    TCCR2A = 0; // Set entire TCCR2A register to 0
    TCCR2B = 0; // Same for TCCR2B
    TCNT2 = 0;  // Initialize counter value to 0
    // Assuming a 16MHz clock, prescaler 1024, the closest we can get might not be exactly 1Hz due to the 8-bit limit
    OCR2A = 155;                                       // Adjust this value to try to get as close as possible to 1Hz
    TCCR2A |= (1 << WGM21);                            // Turn on CTC mode
    TCCR2B |= (1 << CS22) | (1 << CS21) | (1 << CS20); // Set prescaler to 1024
    TIMSK2 |= (1 << OCIE2A);                           // Enable timer compare interrupt

    sei(); // Allow interrupts

    Serial.begin(9600);
}
ISR(TIMER2_COMPA_vect)
{
    interruptCounter++;
    int count = 0;
    if (interruptCounter >= 90)
    { // approximate a second
        Serial.println(seconds);
        seconds++;

        if (angle == 180)
        {
            angle = 0;
        }
        else
        {
            angle = angle + 3; // 180 / 60 = 3
        }

        servo.write(angle);
        interruptCounter = 0; // Reset counter
    }
}

void loop()
{
}