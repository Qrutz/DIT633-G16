// C++ code
//
#include <Adafruit_NeoPixel.h>


#define TEMP_SENSOR A0
#define NUMPIXELS 24
#define REDLED 8
#define PIN 2

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int temperature;

void setup()
{
  pinMode(TEMP_SENSOR, INPUT);
  pinMode(REDLED, OUTPUT);
  pixels.begin();
  
  cli();//stop interrupts

//set timer1 interrupt at 1Hz
  TCCR1A = 0;// set entire TCCR1A register to 0
  TCCR1B = 0;// same for TCCR1B
  TCNT1  = 0;//initialize counter value to 0
  // set compare match register for 1hz increments
  OCR1A = 15624;// = (16*10^6) / (1*1024) - 1 (must be <65536)
  // turn on CTC mode
  TCCR1B |= (1 << WGM12);
  // Set CS10 and CS12 bits for 1024 prescaler
  TCCR1B |= (1 << CS12) | (1 << CS10);  
  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);
  
  sei();//allow interrupts
  //END TIMER SETUP
  
  Serial.begin(9600);
}



ISR(TIMER1_COMPA_vect) { // Interrupt at freq of 1kHz to measure reed switch
  temperature = map(((analogRead(TEMP_SENSOR) - 20) * 3.04), 0, 1023, -40, 125);
  pixels.clear();
  if(temperature > pixels.numPixels()){
    digitalWrite(REDLED, HIGH);
  }
  else{
    digitalWrite(REDLED, LOW);
  }
  for(int i = 0; i < temperature; i++){
    pixels.setPixelColor(i, pixels.Color(255, 0, 0));
}
  pixels.show();
  }



void loop()
{
  
  Serial.print(temperature);
  
}

