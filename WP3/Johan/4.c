#include <Keypad.h>

#define ROWS 4 // four rows
#define COLS 4 // three columns

// initialize matrix of keys representing the keypad
char keys[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};

// Arrays to hold pins for rows and cols
byte rowPins[ROWS] = {11, 10, 9, 8}; // Set each row to a pin
byte colPins[COLS] = {7, 6, 5, 4};   // Set each col to a pin

// Initalize keypad object with our values
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup()
{

    Serial.begin(9600); // start serial monitor

    // Pins setup for cols and rows
    for (byte i = 0; i < ROWS; i++)
    {
        // Set columns pins to output
        pinMode(colPins[i], OUTPUT);
        digitalWrite(colPins[i], HIGH);

        // set row pins to input_pullup
        pinMode(rowPins[i], INPUT_PULLUP);
    }
}

void loop()
{
    char key = keypad.getKey(); // get the pressed key

    // check for pressed key
    if (key)
    {
        Serial.println(key); // print key
    }
}
