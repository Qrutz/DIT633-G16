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

const int DISTANCE_THRESHOLD_1 = 200;
const int DISTANCE_THRESHOLD_2 = 143;
const int DISTANCE_THRESHOLD_3 = 87;
const int DISTANCE_THRESHOLD_4 = 30;
const int DISTANCE_THRESHOLD_5 = 25;



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
  if(*distance < DISTANCE_THRESHOLD_1 && *distance >= DISTANCE_THRESHOLD_2){
    *brightnessPtr = 10;
    digitalWrite(REDLED1, HIGH);
    digitalWrite(REDLED2, LOW);
    digitalWrite(REDLED3, LOW);
    digitalWrite(REDLED4, LOW);
    fadeLED(brightnessPtr);
  }
  else if(*distance < DISTANCE_THRESHOLD_2 && *distance >= DISTANCE_THRESHOLD_3){
    *brightnessPtr = 30;
    digitalWrite(REDLED1, HIGH);
    digitalWrite(REDLED2, HIGH);
    digitalWrite(REDLED3, LOW);
    digitalWrite(REDLED4, LOW);
    fadeLED(brightnessPtr);
  }
  else if(*distance < DISTANCE_THRESHOLD_3 && *distance >= DISTANCE_THRESHOLD_4){
    *brightnessPtr = 70;
    digitalWrite(REDLED1, HIGH);
    digitalWrite(REDLED2, HIGH);
    digitalWrite(REDLED3, HIGH);
    digitalWrite(REDLED4, LOW);
    fadeLED(brightnessPtr);
  }
  else if(*distance < DISTANCE_THRESHOLD_4 && *distance >= DISTANCE_THRESHOLD_5){
    *brightnessPtr = 100;
    digitalWrite(REDLED1, HIGH);
    digitalWrite(REDLED2, HIGH);
    digitalWrite(REDLED3, HIGH);
    digitalWrite(REDLED4, HIGH);
    fadeLED(brightnessPtr);
  }
  else if(*distance < DISTANCE_THRESHOLD_5){
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

