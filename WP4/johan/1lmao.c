
#define GREEN_LED 8  // pin for green LED
#define RED_LED 13   // pin for red LED
#define BLUE_LED 7   // pin for blue LED
#define WHITE_LED 6  // pin for white LED
#define ORANGE_LED 5 // pin for ORANGE LED

#define TEMP_SENSOR A0 // pin number for temperature sensor

#define LIGHT_SENSOR A1 // pin number for light sensor

int light; //  store light intensity percentage

float celsius = 0.0; // store temperature in Celsius

unsigned long previousMillis = 0;
const long interval = 2000; // Interval at which to read temperature (milliseconds)

void setup()
{
    // Initialize the LED'S as output:
    pinMode(GREEN_LED, OUTPUT);
    pinMode(RED_LED, OUTPUT);
    pinMode(BLUE_LED, OUTPUT);

    pinMode(TEMP_SENSOR, INPUT);  // Initialize photoresistor as input
    pinMode(LIGHT_SENSOR, INPUT); // Set light sensor pin as input

    Serial.begin(9600); // start serial monitor
}

void loop()
{
    // Turn OFF each LED
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, LOW);
    digitalWrite(BLUE_LED, LOW);
    digitalWrite(WHITE_LED, LOW);
    digitalWrite(ORANGE_LED, LOW);

    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= interval)
    {
        previousMillis = currentMillis;

        int TempSensorValue = analogRead(TEMP_SENSOR);

        float voltage = TempSensorValue * (5.0 / 1023.0); // voltage
        // Read and calculate temperature in celsius
        celsius = (voltage - 0.5) * 100.0;

        // Print temperature to serial monitor
        Serial.print(celsius);
        Serial.print(" C\n");

        // Check table conditions for temprature/light intensity relationship
        // Starting with NORMAL temp light relatinos
        if ((celsius >= 0) && (celsius <= 10))
        {
            digitalWrite(GREEN_LED, HIGH); // normal temp == green
        }
        // temp is HIGHER than it should be for light level
        else if ((celsius >= 11 && celsius <= 20))
        {
            digitalWrite(RED_LED, HIGH); // Turn on RED LED
        }
        else if ((celsius >= 21 && celsius <= 30))
        {
            digitalWrite(BLUE_LED, HIGH); // Turn on BLUE LED
        }

        else if ((celsius >= 31 && celsius <= 40))
        {
            digitalWrite(WHITE_LED, HIGH); // Turn on BLUE LED
        }
        else if ((celsius >= 41 && celsius <= 50))
        {
            digitalWrite(ORANGE_LED, HIGH); // Turn on BLUE LED
        }
    }
}
