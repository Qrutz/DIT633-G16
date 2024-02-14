#define BUTTON_PIN 7 //   button pin
#define GREEN_LED 8  //   green LED pin
#define RED_LED 13   //   red LED pin

int buttonState = 0; // variable for reading the button status

void setup()
{
    // Initialize the LED'S as output:
    pinMode(GREEN_LED, OUTPUT);
    pinMode(RED_LED, OUTPUT);

    // Initialize the button pin as an input:
    pinMode(BUTTON_PIN, INPUT);

    Serial.begin(9600); // start serial monitor
}

void loop()
{
    buttonState = digitalRead(BUTTON_PIN); // Read the state of the button value:

    if (buttonState == 1) // if button is pressed
    {
        digitalWrite(RED_LED, HIGH); // Turn on the second LED:
    }
    else // if its not pressed
    {
        digitalWrite(RED_LED, LOW); // Turn off the second LED:
    }

    // Blink the first LED (GREEN)  on/off each second.
    digitalWrite(GREEN_LED, HIGH); // ON
    delay(1000);                   // wait for a second
    digitalWrite(GREEN_LED, LOW);  // OFF
    delay(1000);                   // wait for a second
}
