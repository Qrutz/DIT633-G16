
#define GREEN_LED 8 // pin for green LED
#define RED_LED 13  // pin for red LED
#define BLUE_LED 7  // pin for blue LED

#define TEMP_SENSOR A0 // pin number for temperature sensor

#define LIGHT_SENSOR A1 // pin number for light sensor

int light; //  store light intensity percentage

float celsius = 0.0; // store temperature in Celsius

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

    light = analogRead(LIGHT_SENSOR); // read raw value

    light = map(light, 0, 1023, 0, 100); // convert raw value to a percentage

    // Print light intensity to serial monitor
    Serial.print("Light Percentage: ");
    Serial.print(light);
    Serial.print("%\n");

    int TempSensorValue = analogRead(TEMP_SENSOR);

    float voltage = TempSensorValue * (5.0 / 1023.0); // voltage
    // Read and calculate temperature in celsius
    celsius = (voltage - 0.5) * 100.0;

    // Print temperature to serial monitor
    Serial.print(celsius);
    Serial.print(" C\n");

    // Check table conditions for temprature/light intensity relationship
    // Starting with NORMAL temp light relatinos
    if ((celsius < -12 && light == 0) ||
        (celsius >= -12 && celsius <= 0 && light >= 1 && light <= 20) ||
        (celsius >= 0 && celsius <= 20 && light >= 21 && light <= 60) ||
        (celsius >= 21 && light >= 61 && light <= 100))
    {
        digitalWrite(GREEN_LED, HIGH); // normal temp == green
    }
    // temp is HIGHER than it should be for light level
    else if ((celsius >= 0 && celsius < 21 && light <= 20) || (celsius >= 21 && light <= 60))
    {
        digitalWrite(RED_LED, HIGH); // Turn on RED LED
    }
    else // temp is LOWER than it should be for light level
    {
        digitalWrite(BLUE_LED, HIGH); // Turn on BLUE LED
    }

    delay(2000);
}
