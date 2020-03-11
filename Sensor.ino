/*
    Name:       Sensor.ino
    Created:	05.03.2020 08:37:52
    Author:     DREEBITNET\PfeifferP

    Command:    0 = leer
                1 = Start
                2 = Stop
                3 = Cal
                4 = Read Status
                5 = Read Para
*/

String inputString = "";         // a String to hold incoming data
bool stringComplete = false;     // whether the string is complete
unsigned long resp_time;         // speicher für ablauf 
int last_cmd;                    // Befehl senden und warten auf Antwort

void setup()
{
  // initialize serial:
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
  resp_time = millis();
}

void loop()
{
  if (stringComplete) {
    switch (last_cmd) {
      case 1:

        break;
      case 2:

        break;
      default:

        break;
    }
    // clear the string:
    last_cmd = 0;
    inputString = "";
    stringComplete = false;
  }

}



/*
  SerialEvent occurs whenever a new data comes in the hardware serial RX. This
  routine is run between each time loop() runs, so using delay inside loop can
  delay response. Multiple bytes of data may be available.
*/
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == 0x15 ) {
      inputString = "Error";
      stringComplete = true;
    }
    if (inChar == "\r" ) {
      stringComplete = true;
    }
  }
}


void sendStart() {
  Serial.print("=CYE\r");
  resp_time = millis();
  
}

void sendStop() {
  Serial.print("=CYD\r");
}

void sendCal() {
  
}
