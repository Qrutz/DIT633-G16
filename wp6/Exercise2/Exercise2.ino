#define REDLED1 13
#define REDLED2 12
#define REDLED3 11
#define REDLED4 10
#define REDLED5 9

#define TRIGGER 5
#define ECHO 7

#define BUZZER 3

long static duration, cm;

int static distance;
int static *distancePtr = &distance;
int static brightness;
int *brightnessPtr = &brightness;


void setup() {

  pinMode(REDLED1, OUTPUT);
  pinMode(REDLED2, OUTPUT);
  pinMode(REDLED3, OUTPUT);
  pinMode(REDLED4, OUTPUT);
  pinMode(REDLED5, OUTPUT);

  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);

  Serial.begin(9600);

}

void loop() {
  // First detect the distance to object
  distance = detectDistance();
  // Use distance as input for lighting LEDs
  lightLED(distancePtr);
  // Small delay, adjust accordingly..
  delay(250);

}

int detectDistance(){

  // Write a zero to the output to clear the system
  digitalWrite(TRIGGER, LOW);
  // Wait 2 microseconds
  delayMicroseconds(2);
  // Write a one to the output to send a ping
  digitalWrite(TRIGGER, HIGH);
  // Wait 10 microseconds
  delayMicroseconds(10);
  // Write a zero to the output to stop sending the pin
  digitalWrite(TRIGGER, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(ECHO, INPUT);
  duration = pulseIn(ECHO, HIGH);
 
  // Convert the time into a distance
  cm = (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
  
  Serial.print("Distance to object: ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  return cm;
}

// Using PWM we can increase the brightness of the LED
// Currently using this instead since we dont have a buzzer :(
void fadeLED(int *brightness){
  analogWrite(REDLED5, *brightness);
}

// Take distance as input and lights up the LEDs based on the distance.
void lightLED(int *distance){
  if(*distance < 200 && *distance >= 143){
    *brightnessPtr = 10;
    digitalWrite(REDLED1, HIGH);
    digitalWrite(REDLED2, LOW);
    digitalWrite(REDLED3, LOW);
    digitalWrite(REDLED4, LOW);
    fadeLED(brightnessPtr);
  }
  else if(*distance < 143 && *distance >= 87){
    *brightnessPtr = 30;
    digitalWrite(REDLED1, HIGH);
    digitalWrite(REDLED2, HIGH);
    digitalWrite(REDLED3, LOW);
    digitalWrite(REDLED4, LOW);
    fadeLED(brightnessPtr);
  }
  else if(*distance < 87 && *distance > 30){
    *brightnessPtr = 70;
    digitalWrite(REDLED1, HIGH);
    digitalWrite(REDLED2, HIGH);
    digitalWrite(REDLED3, HIGH);
    digitalWrite(REDLED4, LOW);
    fadeLED(brightnessPtr);
  }
  else if(*distance <= 30 && *distance >= 25){
    *brightnessPtr = 100;
    digitalWrite(REDLED1, HIGH);
    digitalWrite(REDLED2, HIGH);
    digitalWrite(REDLED3, HIGH);
    digitalWrite(REDLED4, HIGH);
    fadeLED(brightnessPtr);
  }
  else if(*distance < 25){
    *brightnessPtr = 255;
    fadeLED(brightnessPtr);
    digitalWrite(REDLED1, HIGH);
    digitalWrite(REDLED2, HIGH);
    digitalWrite(REDLED3, HIGH);
    digitalWrite(REDLED4, HIGH);
    delay(250);
    digitalWrite(REDLED1, LOW);
    digitalWrite(REDLED2, LOW);
    digitalWrite(REDLED3, LOW);
    digitalWrite(REDLED4, LOW);
  }
  else{
    digitalWrite(REDLED1, LOW);
    digitalWrite(REDLED2, LOW);
    digitalWrite(REDLED3, LOW);
    digitalWrite(REDLED4, LOW);
    analogWrite(REDLED5, 0);
  }
}

