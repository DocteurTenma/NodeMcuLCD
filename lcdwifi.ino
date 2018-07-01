#include <LiquidCrystal.h>
const int RS = 12;
const int E = 11;
const int D4 = 5;
const int D5 = 4;
const int D6 = 3;
const int D7 = 2;

const int COLS = 16;
const int ROWS = 2;

int incomingByte = 0;

LiquidCrystal lcd(RS, E, D4, D5, D6, D7);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(19200);  
  Serial1.begin(9600);
  lcd.begin(COLS, ROWS);
  //lcd.setCursor(0, 0);
  //lcd.autoscroll();
}

void loop() {
  // put your main code here, to run repeatedly:

  if (Serial1.available() > 0) {
    delay(100);
    Serial.println("prêt");
    lcd.clear();
    //lcd.setCursor(0, 0);
    int cpt = 0;
    while (Serial1.available() > 0) {
      incomingByte = Serial1.read();

      Serial.print("I received : ");
      Serial.println(incomingByte, DEC);
      Serial.println(char(incomingByte)); 
      
      lcd.print(char(incomingByte));
      cpt += 1;
    }
  }
}
