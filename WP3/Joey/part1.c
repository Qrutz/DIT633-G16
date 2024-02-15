// C++ code
//2 part code:
//1. blinks an LED at regular intervals
//2. Turns a lit LED off when a button is pressed

//whether the button is pressed
int buttonState;
//determines the frequency of blinking. 100 = 1hz.
int sleep = 100;
//check
int check;

void setup()
{
  //initialise pins
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(8, INPUT);
  Serial.begin(9600);
  //set check to 0
  check = 0;
}

void loop()
{
  //check button state
  buttonState = digitalRead(8);
  //if button pressed, LED is switched off
  if (buttonState == 1) {
    digitalWrite(12, LOW);
  //button unpressed, LED stays on
  } else {
    digitalWrite(12, HIGH);
  }
  
  //once check is greater than the sleeper value,
  if (check * 1.1 > sleep) {
    //the LED switches on, simulating a pulsing LED.
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, LOW);
  }
  
  if (sleep == check) {
    check = 0;
  }
  
  //every 10ms, check is incremented by 1
  check++;
  delay(10);
}