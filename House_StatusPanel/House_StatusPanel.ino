#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

#include <DHT.h>
DHT dht;

int led1 = 9;
int led2 = 10;
int relay1 = 6; 
int relay3 = 7;
int relay4 = 8;
int BUTTON_PIN = 5; //Button controlling button

byte lastButtonState = LOW;
byte ledState = LOW;
unsigned long debounceDuration = 50; // millis
unsigned long lastTimeButtonStateChanged = 0;

 
void setup() {
  Serial.begin(9600);
  lcd.begin ();
  lcd.backlight();
  lcd.home ();


  lcd.setCursor(0,0); 
  lcd.print("    KPS SMART   ");
  lcd.setCursor(0,1);
  lcd.print(" SILKWORM HOUSE");

  delay(5000);
  lcd.clear();
  
  pinMode(BUTTON_PIN, INPUT);
  pinMode(relay1, OUTPUT); 
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT); 

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  dht.setup(2); // data pin 2
}

void loop() {
  
  float humidity = dht.getHumidity(); // ดึงค่าความชื้น
  float temperature = dht.getTemperature(); // ดึงค่าอุณหภูมิ

  if(temperature <= 23){
    digitalWrite(relay4, 0);
    digitalWrite(led1, HIGH);
  }else{
    digitalWrite(relay4, 1);
    digitalWrite(led1, LOW);
  }


  if(temperature >= 27){
    digitalWrite(relay3, 0);
    digitalWrite(led2, HIGH);
    }else{
      digitalWrite(relay3, 1);
      digitalWrite(led2, LOW);
      }

  lcd.setCursor(0,0); 
  lcd.print("Temp:" + String(temperature) + " C");
  lcd.setCursor(0,1);
  lcd.print("Humidity:" + String(humidity) + " %");  // Print humidity value


  button();
  
  
}

void button(){
  
    if (millis() - lastTimeButtonStateChanged > debounceDuration) {
    byte buttonState = digitalRead(BUTTON_PIN);
    if (buttonState != lastButtonState) {
      lastTimeButtonStateChanged = millis();
      lastButtonState = buttonState;
      if (buttonState == LOW) {
        ledState = (ledState == HIGH) ? LOW: HIGH;
        digitalWrite(relay1, ledState);
      }
    }
  }
  }
