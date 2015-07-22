// Arquivo upado na placa Arduino

#include "DHT.h"
#define DHTPIN 13
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
int portas[8] = {5, 6, 7, 8, 9, 10, 11, 12};
String info_hour = "";
String info_temp = "";
String h1 = "";
String t1 = "";
char caractere;
int t, h;

void setup() {
  Serial.begin(9600);
  dht.begin();
  for (int i = 5; i < 13; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  while (Serial.available()) {
    get_dht();
    info_hour = Serial.readString();
    info_temp = t1 + h1;
    for (int i = 0; i < 4; i++) {
      if (i == 2) {
        for (int i = 0; i < 2; i++) {
          digitalWrite(12, HIGH);
          delay(75);
          digitalWrite(12, LOW);
          delay(75);
        }
        for (int i = 0; i < 8; i++) {
          digitalWrite(portas[i], LOW);
        }
        delay(50);
      }
      caractere = info_hour[i];
      switch_blink();

    }
    digitalWrite(12, HIGH);
    delay(750);
    digitalWrite(12, LOW);
    delay(750);
    for (int i = 0; i < 4; i++) {
      if (i == 2) {
        for (int i = 0; i < 3; i++) {
          digitalWrite(12, HIGH);
          delay(75);
          digitalWrite(12, LOW);
          delay(75);
        }
        for (int i = 0; i < 8; i++) {
          digitalWrite(portas[i], LOW);
        }
        delay(50);
      }
      caractere = info_temp[i];
      switch_blink();
    }
  }
}

void switch_blink() {
  switch (caractere) {
    case '0':
      digitalWrite(5, HIGH);
      delay(50);
      digitalWrite(11, HIGH);
      delay(50);
      digitalWrite(10, HIGH);
      delay(50);
      digitalWrite(9, HIGH);
      delay(50);
      digitalWrite(7, HIGH);
      delay(50);
      digitalWrite(6, HIGH);
      delay(250);
      for (int i = 0; i < 8; i++) {
        digitalWrite(portas[i], LOW);
      }
      delay(50);
      break;
    case '1':
      digitalWrite(5, HIGH);
      delay(50);
      digitalWrite(11, HIGH);
      delay(250);
      for (int i = 0; i < 8; i++) {
        digitalWrite(portas[i], LOW);
      }
      delay(50);
      break;
    case '2':
      digitalWrite(6, HIGH);
      delay(50);
      digitalWrite(5, HIGH);
      delay(50);
      digitalWrite(8, HIGH);
      delay(50);
      digitalWrite(9, HIGH);
      delay(50);
      digitalWrite(10, HIGH);
      delay(250);
      for (int i = 0; i < 8; i++) {
        digitalWrite(portas[i], LOW);
      }
      delay(50);
      break;
    case '3':
      digitalWrite(8, HIGH);
      delay(50);
      digitalWrite(5, HIGH);
      digitalWrite(11, HIGH);
      delay(50);
      digitalWrite(6, HIGH);
      digitalWrite(10, HIGH);
      delay(250);
      for (int i = 0; i < 8; i++) {
        digitalWrite(portas[i], LOW);
      }
      delay(50);
      break;
    case '4':
      digitalWrite(7, HIGH);
      delay(50);
      digitalWrite(8, HIGH);
      delay(50);
      digitalWrite(5, HIGH);
      digitalWrite(11, HIGH);
      delay(250);
      for (int i = 0; i < 8; i++) {
        digitalWrite(portas[i], LOW);
      }
      delay(50);
      break;
    case '5':
      digitalWrite(6, HIGH);
      delay(50);
      digitalWrite(7, HIGH);
      delay(50);
      digitalWrite(8, HIGH);
      delay(50);
      digitalWrite(11, HIGH);
      delay(50);
      digitalWrite(10, HIGH);
      delay(250);
      for (int i = 0; i < 8; i++) {
        digitalWrite(portas[i], LOW);
      }
      delay(50);
      break;
    case '6':
      digitalWrite(6, HIGH);
      delay(50);
      digitalWrite(7, HIGH);
      delay(50);
      digitalWrite(9, HIGH);
      delay(50);
      digitalWrite(10, HIGH);
      delay(50);
      digitalWrite(11, HIGH);
      delay(50);
      digitalWrite(8, HIGH);
      delay(250);
      for (int i = 0; i < 8; i++) {
        digitalWrite(portas[i], LOW);
      }
      delay(50);
      break;
    case '7':
      digitalWrite(6, HIGH);
      delay(50);
      digitalWrite(5, HIGH);
      delay(50);
      digitalWrite(11, HIGH);
      delay(250);
      for (int i = 0; i < 8; i++) {
        digitalWrite(portas[i], LOW);
      }
      delay(50);
      break;
    case '8':
      digitalWrite(8, HIGH);
      delay(50);
      digitalWrite(5, HIGH);
      digitalWrite(9, HIGH);
      delay(50);
      digitalWrite(6, HIGH);
      digitalWrite(10, HIGH);
      delay(50);
      digitalWrite(7, HIGH);
      digitalWrite(11, HIGH);
      delay(250);
      for (int i = 0; i < 8; i++) {
        digitalWrite(portas[i], LOW);
      }
      delay(50);
      break;
    case '9':
      digitalWrite(8, HIGH);
      delay(50);
      digitalWrite(7, HIGH);
      delay(50);
      digitalWrite(6, HIGH);
      delay(50);
      digitalWrite(5, HIGH);
      delay(50);
      digitalWrite(11, HIGH);
      delay(50);
      digitalWrite(10, HIGH);
      delay(250);
      for (int i = 0; i < 8; i++) {
        digitalWrite(portas[i], LOW);
      }
      delay(50);
      break;
  }
}

void get_dht() {
  h = dht.readHumidity();
  t = dht.readTemperature();
  h1 = String(h);
  t1 = String(t);
}
