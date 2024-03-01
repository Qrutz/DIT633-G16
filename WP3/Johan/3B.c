
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
    // iterate over each column
    for (byte col = 0; col < COLS; col++)
    {
        digitalWrite(colPins[col], LOW); // Set the current column pin to low

        // scan row for a pressed key
        for (byte row = 0; row < ROWS; row++)
        {
            // check if a key is pressed in the current row
            if (digitalRead(rowPins[row]) == LOW)
            {
                Serial.println(keys[row][col]); // Print the key
                delay(1000);                    // delay 1 sec
            }
        }
        // set current column back to high before moving to following column
        digitalWrite(colPins[col], HIGH);
    }
}
