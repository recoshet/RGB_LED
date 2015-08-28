const int pin1 = P2_4;
const int pin2 = P2_5;
const int pin3 = P1_6;

String inputString = "";
boolean stringComplete = false;

void setup() {
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  
  Serial.begin(9600);
  inputString.reserve(10);
}

void plavnHigh(int pin, int zad){
    for (int brightness = 0; brightness < 255; brightness++) {
      analogWrite(pin, brightness);
      delay(zad);
    } 
}

void plavnLow(int pin, int zad){
    for (int brightness = 255; brightness >= 0; brightness--) {
      analogWrite(pin, brightness);
      delay(zad);
    } 
}

void High(int pin){
  analogWrite(pin, 255);
}

void Low(int pin){
  analogWrite(pin, 0);
}


void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read(); 
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
    stringComplete = true;
    } 
  }
}


void loop() {
  if (stringComplete){
    //Serial.println(inputString);
    if (inputString[0] == 'R'){
      if (inputString[1] == '1'){
        plavnHigh(pin1, 5);
      }
      else if (inputString[1] == '0'){
        plavnLow(pin1, 5);
      }
    }
    if (inputString[0] == 'G'){
      if (inputString[1] == '1'){
        plavnHigh(pin2, 5);
      }
      else if (inputString[1] == '0'){
        plavnLow(pin2, 5);
      }
    }
    if (inputString[0] == 'B'){
      if (inputString[1] == '1'){
        plavnHigh(pin3, 5);
      }
      else if (inputString[1] == '0'){
        plavnLow(pin3, 5);
      }
    }
    inputString = "";
    stringComplete = false;
  }
  /*
  int schet = 0;
  plavnHigh(pin1,1);
  plavnHigh(pin2,1);
  delay(400);
  plavnLow(pin2,4);
  plavnLow(pin1,4);
  
  plavnHigh(pin1,1);
  delay(100);
  plavnLow(pin1,10);
  
  plavnHigh(pin2,1);
  delay(100);
  plavnLow(pin2,10);
  
  delay(500);
  for(schet = 1; schet < 10; schet++){
    High(pin1);
    delay(500/schet);
    Low(pin1);
    delay(100);
    High(pin2);
    delay(500/schet);
    Low(pin2);
    delay(100);
  }
  
  
  
  for(schet = 10; schet > 0; schet--){
    High(pin1);
    delay(500/schet);
    Low(pin1);
    delay(100);
    High(pin2);
    delay(500/schet);
    Low(pin2);
    delay(100);
  }
  delay(500);
  
  High(pin1);
  High(pin2);
  delay(2000);
 */
}
