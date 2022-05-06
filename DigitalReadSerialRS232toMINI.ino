
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
#define halfBit4800Delay 966


byte SWval;


// digital pin 2 has a pushbutton attached to it. Give it a name:
int inputRs232_3v = 2;
int outputTtl = 5;

int inputTtl = 4;
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

void SWprint(int data)
{
  byte mask;
  //startbit
  digitalWrite(outputRs232_3v, HIGH);
  delayMicroseconds(bit4800Delay / 2);
  for (mask = 0x01; mask > 0; mask <<= 1) {
    if (data & mask) { // choose bit
      digitalWrite(outputRs232_3v, LOW); // send 1
    }
    else {
      digitalWrite(outputRs232_3v, HIGH); // send 0
    }
    delayMicroseconds(bit4800Delay / 2);
  }
  //stop bit
  digitalWrite(outputRs232_3v, LOW);
  delayMicroseconds(bit4800Delay / 2);
  delayMicroseconds(bit4800Delay / 2);
}

int SWread()
{
  byte val = 0;
  while (!digitalRead(inputRs232_3v));
  //wait for start bit
  if (digitalRead(inputRs232_3v)) {
    delayMicroseconds(halfBit4800Delay / 2);
    for (int offset = 0; offset < 8; offset++) {
      delayMicroseconds(bit4800Delay / 2);
      val |= !digitalRead(inputRs232_3v) << offset;
    }
    //wait for stop bit + extra
    delayMicroseconds(bit4800Delay / 2);
    delayMicroseconds(bit4800Delay / 2);
    
    return val;
  }
}

// the loop routine runs over and over again forever:
void loop() {
  
  if (digitalRead(inputRs232_3v)) {
    SWval = SWread();
    Serial.write(SWval);
  }
  if (Serial.available()) {
    byte c = Serial.read();
    SWprint(c);
    
  }
  

}
