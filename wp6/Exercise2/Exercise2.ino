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

int detectDistance(){

  digitalWrite(TRIGGER, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);
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

void fadeLED(int *brightness){
  analogWrite(REDLED5, *brightness);
}

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
    *brightnessPtr = 50;
    digitalWrite(REDLED1, HIGH);
    digitalWrite(REDLED2, HIGH);
    digitalWrite(REDLED3, HIGH);
    digitalWrite(REDLED4, LOW);
    fadeLED(brightnessPtr);
  }
  else if(*distance <= 30 && *distance >= 25){
    *brightnessPtr = 70;
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
    delay(250);
  }
  else{
    digitalWrite(REDLED1, LOW);
    digitalWrite(REDLED2, LOW);
    digitalWrite(REDLED3, LOW);
    digitalWrite(REDLED4, LOW);
    analogWrite(REDLED5, 0);
  }
}

void loop() {

  distance = detectDistance();

  lightLED(distancePtr);

  delay(50);


}

