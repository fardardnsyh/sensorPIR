#include <LiquidCrystal_I2C.h>
#include <Wire.h> 
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);


int pinPIR = 3;     //pin Out PIR 
int buzzer = 2;     // inisialisasi buzzer pin pada 2
int statusPIR = 0;  //variabel untuk menampung status sensor


void setup(){ 
pinMode(pinPIR, INPUT);     //pengaturan pin PIR sebagai input
pinMode(buzzer, OUTPUT);  // Untuk menentukan pin buzzer sebagai output
Serial.begin(9600);         //pengaturan baud rate untuk komunikasi serial sebesar 9600bps
 lcd.init();
 lcd.backlight();
 lcd.clear();
}


void loop(){
statusPIR = digitalRead(pinPIR);
if (statusPIR ==HIGH) {                          //jika sensor membaca gerakan maka BUZZER akan aktif
digitalWrite(buzzer, HIGH); 
  lcd.setCursor(2, 0);
  lcd.print("ADA YG GERAK");
  lcd.clear();
Serial.println("ADA GERAKAN DELAY 10 DETIK");
delay(10000); //Diberikan waktu tunda 10 detik
}

else {
digitalWrite(buzzer, LOW);      //jika sensor tidak membaca gerakan maka BUZZER akan off
  lcd.setCursor(1, 0);
  lcd.print("ADA YG DIAM");
  lcd.clear();
Serial.println("TIDAK ADA GERAKAN");
delay(3000)

}
}
