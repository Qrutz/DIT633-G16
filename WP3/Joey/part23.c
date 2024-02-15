// C++ code
//this code will light up an LED depending on deviations based
//on light levels and temperature. 

int temperature;
int sol;
int temp_level;
int sol_level;

void setup()
{
  //initialising out pins
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(8, OUTPUT);
  //initialising in pins
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  //initialising serial monitor
  Serial.begin(9600);
}

void loop()
{
  //reading input pins
  sol = analogRead(A0);
  temperature = analogRead(A1);
  
  //processing temperature levels
  if (temperature < 78) {
    temp_level = 0;
  } else if (temperature <= 104) {
    temp_level = 1;
  } else if (temperature <= 141) {
    temp_level = 2;
  } else {
    temp_level = 3;
  }
  
  //processing light levels
  if (sol < 213) {
    sol_level = 0;
  } else if (sol <= 986) {
    sol_level = 1;
  } else if (sol <= 1007) {
    sol_level = 2;
  } else {
    sol_level = 3;
  }
  
  //logic to activate LEDS
  if (sol_level == temp_level) {
    digitalWrite(13, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(8, LOW);
  } else if (sol_level < temp_level) {
    digitalWrite(13, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(8, LOW);
  } else if (sol_level > temp_level) {
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(8, HIGH);
  } else {
    //ERROR
    digitalWrite(13, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(8, HIGH);
  }
  
  //serial monitor output
  Serial.print(sol);
  Serial.print(",  ");
  Serial.println(temperature * 5 / 1023.0);
  
  delay(10);
}