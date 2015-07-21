// Arquivo upado na placa Arduino

int portas[8] = {5, 6, 7, 8, 9, 10, 11, 12};
String mensagem = "";
char caractere;

void setup() {
  Serial.begin(9600);
  for (int i = 5; i < 13; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  while (Serial.available()) {
    mensagem = Serial.readString();
    for (int i = 0; i < 4; i++) {
      if (i == 2) {
        digitalWrite(12, HIGH);
        delay(75);
        digitalWrite(12, LOW);
        delay(75);
        digitalWrite(12, HIGH);
        delay(100);
        for (int i = 0; i < 8; i++) {
          digitalWrite(portas[i], LOW);
        }
        delay(125);
      }
      caractere = mensagem[i];
      Serial.println(caractere);
      switch_blink();
    }
  }
}

void switch_blink() {
  switch (caractere) {
    case '0':
      digitalWrite(5, HIGH);
      delay(125);
      digitalWrite(11, HIGH);
      delay(125);
      digitalWrite(10, HIGH);
      delay(125);
      digitalWrite(9, HIGH);
      delay(125);
      digitalWrite(7, HIGH);
      delay(125);
      digitalWrite(6, HIGH);
      delay(250);
      for (int i = 0; i < 8; i++) {
        digitalWrite(portas[i], LOW);
      }
      delay(125);
      break;
    case '1':
      digitalWrite(5, HIGH);
      delay(125);
      digitalWrite(11, HIGH);
      delay(250);
      for (int i = 0; i < 8; i++) {
        digitalWrite(portas[i], LOW);
      }
      delay(125);
      break;
    case '2':
      digitalWrite(6, HIGH);
      delay(125);
      digitalWrite(5, HIGH);
      delay(125);
      digitalWrite(8, HIGH);
      delay(125);
      digitalWrite(9, HIGH);
      delay(125);
      digitalWrite(10, HIGH);
      delay(250);
      for (int i = 0; i < 8; i++) {
        digitalWrite(portas[i], LOW);
      }
      delay(125);
      break;
    case '3':
      digitalWrite(8, HIGH);
      delay(125);
      digitalWrite(5, HIGH);
      digitalWrite(11, HIGH);
      delay(125);
      digitalWrite(6, HIGH);
      digitalWrite(10, HIGH);
      delay(250);
      for (int i = 0; i < 8; i++) {
        digitalWrite(portas[i], LOW);
      }
      delay(125);
      break;
    case '4':
      digitalWrite(7, HIGH);
      delay(125);
      digitalWrite(8, HIGH);
      delay(125);
      digitalWrite(5, HIGH);
      digitalWrite(11, HIGH);
      delay(250);
      for (int i = 0; i < 8; i++) {
        digitalWrite(portas[i], LOW);
      }
      delay(125);
      break;
    case '5':
      digitalWrite(6, HIGH);
      delay(125);
      digitalWrite(7, HIGH);
      delay(125);
      digitalWrite(8, HIGH);
      delay(125);
      digitalWrite(11, HIGH);
      delay(125);
      digitalWrite(10, HIGH);
      delay(250);
      for (int i = 0; i < 8; i++) {
        digitalWrite(portas[i], LOW);
      }
      delay(125);
      break;
    case '6':
      digitalWrite(6, HIGH);
      delay(125);
      digitalWrite(7, HIGH);
      delay(125);
      digitalWrite(9, HIGH);
      delay(125);
      digitalWrite(10, HIGH);
      delay(125);
      digitalWrite(11, HIGH);
      delay(125);
      digitalWrite(8, HIGH);
      delay(250);
      for (int i = 0; i < 8; i++) {
        digitalWrite(portas[i], LOW);
      }
      delay(125);
      break;
    case '7':
      digitalWrite(6, HIGH);
      delay(125);
      digitalWrite(5, HIGH);
      delay(125);
      digitalWrite(11, HIGH);
      delay(250);
      for (int i = 0; i < 8; i++) {
        digitalWrite(portas[i], LOW);
      }
      delay(125);
      break;
    case '8':
      digitalWrite(8, HIGH);
      delay(125);
      digitalWrite(5, HIGH);
      digitalWrite(9, HIGH);
      delay(125);
      digitalWrite(6, HIGH);
      digitalWrite(10, HIGH);
      delay(125);
      digitalWrite(7, HIGH);
      digitalWrite(11, HIGH);
      delay(250);
      for (int i = 0; i < 8; i++) {
        digitalWrite(portas[i], LOW);
      }
      delay(125);
      break;
    case '9':
      digitalWrite(8, HIGH);
      delay(125);
      digitalWrite(7, HIGH);
      delay(125);
      digitalWrite(6, HIGH);
      delay(125);
      digitalWrite(5, HIGH);
      delay(125);
      digitalWrite(11, HIGH);
      delay(125);
      digitalWrite(10, HIGH);
      delay(250);
      for (int i = 0; i < 8; i++) {
        digitalWrite(portas[i], LOW);
      }
      delay(125);
      break;
  }
}
