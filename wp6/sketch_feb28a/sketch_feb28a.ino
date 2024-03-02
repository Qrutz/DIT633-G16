#include <Stepper.h>

const int stepsPerRevolution = 2038; // Defines the number of steps per revolution

// Creates an instance of stepper class
// Pins entered in sequence IN1-IN3-IN2-IN4 for proper step sequence
Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  // Initialize serial communication at a baud rate of 9600:
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    // Read the incoming string until newline
    String input = Serial.readStringUntil('\n');
    
    // Split the input into speed and direction
    int commaIndex = input.indexOf(',');
    if (commaIndex != -1) {
      // Extract speed and direction from input
      int speedInput = input.substring(0, commaIndex).toInt();
      int directionInput = input.substring(commaIndex + 1).toInt();

      // Print the received inputs back to the serial monitor
      Serial.print("Speed: ");
      Serial.println(speedInput);
      Serial.print("Direction: ");
      Serial.println(directionInput);

      if(directionInput == 0){
        Serial.println("Going right");
        // Set the motor speed (RPM) and direction
        myStepper.setSpeed(abs(speedInput)); // Speed should be a positive value
        myStepper.step(stepsPerRevolution);
      }
      else if(directionInput == 1){
        Serial.println("Going left");
        // Set the motor speed (RPM) and direction
        myStepper.setSpeed(abs(speedInput)); // Speed should be a positive value
        myStepper.step(-stepsPerRevolution);
      }
    }
  }
  delay(1000); // Simple delay to avoid flooding; adjust as needed
}