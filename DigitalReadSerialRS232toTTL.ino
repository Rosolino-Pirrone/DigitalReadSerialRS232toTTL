
/*
  DigitalReadSerial

  Reads a digital input on pin 2, prints the result to the Serial Monitor

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/DigitalReadSerial
*/




///////////////////      WARNING ONLY 5 VOLTS TOLLERANT    //////////////////

///////////////////      ATTENZIONE SOLO 5 VOLTS TOLLERANT     //////////////

#define bit9600Delay 100  
#define halfBit9600Delay 50
#define bit4800Delay 192
#define halfBit4800Delay 96


byte SWval;


// digital pin 2 has a pushbutton attached to it. Give it a name:
int inputRs232_3v = 2;
int outputTtl = 5;

int inputTtl = 6;
int outputRs232_3v = 3;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(inputRs232_3v, INPUT);
  pinMode(outputTtl, OUTPUT);
  pinMode(inputTtl, INPUT);
  pinMode(outputRs232_3v, OUTPUT);
  
}



// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
  
  /*if (Serial.available()){
    byte c = Serial.read();
    ss.write(c);
  }

  if (ss.available()){
    byte b = ss.read();
    Serial.write(b);
  }*/
  digitalWrite(outputTtl, !digitalRead(inputRs232_3v));
  digitalWrite(outputRs232_3v, !digitalRead(inputTtl));
 
}
