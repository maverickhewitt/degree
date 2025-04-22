#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ezButton.h>

int buttonPin1 = 4; 
unsigned long startTime = 0;
unsigned long timer = 0;

LiquidCrystal_I2C lcd(0x27, 16, 2);
ezButton button(buttonPin1);

void setup() {
  lcd.init(); 
  lcd.backlight(); 

  button.setDebounceTime(20);
  pinMode(buttonPin1, INPUT);
}

void loop() {
  button.loop();

  if(button.isPressed()){
    startTime = millis();
    timer = (millis() - startTime);
    lcd.setCursor(0, 0); 
    lcd.print("Toilet is Occupied");
    lcd.setCursor(0, 1); 
    lcd.print("Time: ");
    lcd.print(timer);
  }
  
  if(button.isReleased()){
    lcd.setCursor(0, 0); 
    lcd.print("Toilet is Available");
    timer = 0;
  }
}
