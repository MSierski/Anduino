#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27,16,2);  
int odczytanaWartosc1 = 0; //Zmienna do przechowywania odczytu ADC
int buttonState = 0;  
int odczytanaWartosc2 = 0;
const int buttonPin = 9; 
int odczytanaWartosc3 = 0;
 
void setup() {
  pinMode(3, OUTPUT); //Konfiguracja wyjść pod diodę LED czerwoną
  pinMode(5, OUTPUT); //Konfiguracja wyjść pod diodę LED zieloną
  pinMode(6, OUTPUT); //Konfiguracja wyjść pod diodę LED niebieską
  Serial.begin(9600);
  lcd.init();
  lcd.clear();         
  lcd.backlight();
  pinMode(buttonPin, INPUT_PULLUP);
}
 
void loop() {
  odczytanaWartosc1 = analogRead(A3);//Odczytanie wartości z ADC czerwony
  odczytanaWartosc2 = analogRead(A2);//Odczytanie wartości z ADC zielony
  odczytanaWartosc3 = analogRead(A1);//Odczytanie wartości z ADC niebieski
  odczytanaWartosc1 = map(odczytanaWartosc1, 0, 1023, 255, 0);
  odczytanaWartosc2 = map(odczytanaWartosc2, 0, 1023, 255, 0);
  odczytanaWartosc3 = map(odczytanaWartosc3, 0, 1023, 255, 0);
  Serial.println("kolor czerwony");
  Serial.println(odczytanaWartosc1);
  Serial.println("kolor zielony");
  Serial.println(odczytanaWartosc2);
  Serial.println("kolor niebieski");
  Serial.println(odczytanaWartosc3);
  analogWrite(3, odczytanaWartosc1);
  analogWrite(5, odczytanaWartosc2);
  analogWrite(6, odczytanaWartosc3);
  buttonState = digitalRead(buttonPin);
    if (buttonState == LOW) {
      lcd.clear();
      lcd.setCursor(2,0);   //Set cursor to character 2 on line 0
      lcd.print("Kod RGB");
      lcd.setCursor(0,1);   //Move cursor to character 2 on line 1
      lcd.print(odczytanaWartosc1);
      lcd.setCursor(4,1);   //Move cursor to character 2 on line 1
      lcd.print(odczytanaWartosc2);
      lcd.setCursor(8,1);   //Move cursor to character 2 on line 1
      lcd.print(odczytanaWartosc3);
    } else {
      lcd.clear();
      }   
}
