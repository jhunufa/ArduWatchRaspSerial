// Arquivo upado na placa Arduino

int portas[8] = {5, 6, 7, 8, 9, 10, 11, 12};
int digito0[8] = {1, 1, 1, 0, 1, 1, 1, 0};
int digito1[8] = {1, 0, 0, 0, 0, 0, 1, 0};
int digito2[8] = {1, 1, 0, 1, 1, 1, 0, 0};
int digito3[8] = {1, 1, 0, 1, 0, 1, 1, 0};
int digito4[8] = {1, 0, 1, 1, 0, 0, 1, 0};
int digito5[8] = {0, 1, 1, 1, 0, 1, 1, 0};
int digito6[8] = {0, 1, 1, 1, 1, 1, 1, 0};
int digito7[8] = {1, 1, 0, 0, 0, 0, 1, 0};
int digito8[8] = {1, 1, 1, 1, 1, 1, 1, 0};
int digito9[8] = {1, 1, 1, 1, 0, 0, 1, 0};
int ponto[8] = {0, 0, 0, 0, 0, 0, 0, 1};

String mensagem = "";
char caractere;
int blink_ponto = 250;
int blink_digito = 100;

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
        for (int i = 0; i < 8; i++) {
          digitalWrite(portas[i], ponto[i]);
        }
        delay(blink_ponto);
        for (int i = 0; i < 8; i++) {
          digitalWrite(portas[i], LOW);
        }
        delay(blink_ponto);
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
      for (int i = 0; i < 8; i++) {
        digitalWrite(portas[i], digito0[i]);
      }
      delay(blink_digito);
      for (int i = 0; i < 8; i++) {
        digitalWrite(portas[i], LOW);
      }
      delay(blink_digito);
      break;
    case '1':
      for (int i = 0; i < 8; i++) {
        digitalWrite(portas[i], digito1[i]);
      }
      delay(blink_digito);
      for (int i = 0; i < 8; i++) {
        digitalWrite(portas[i], LOW);
      }
      delay(blink_digito);
      break;
    case '2':
      for (int i = 0; i < 8; i++) {
        digitalWrite(portas[i], digito2[i]);
      }
      delay(blink_digito);
      for (int i = 0; i < 8; i++) {
        digitalWrite(portas[i], LOW);
      }
      delay(blink_digito);
      break;
    case '3':
      for (int i = 0; i < 8; i++) {
        digitalWrite(portas[i], digito3[i]);
      }
      delay(blink_digito);
      for (int i = 0; i < 8; i++) {
        digitalWrite(portas[i], LOW);
      }
      delay(blink_digito);
      break;
    case '4':
      for (int i = 0; i < 8; i++) {
        digitalWrite(portas[i], digito4[i]);
      }
      delay(blink_digito);
      for (int i = 0; i < 8; i++) {
        digitalWrite(portas[i], LOW);
      }
      delay(blink_digito);
      break;
    case '5':
      for (int i = 0; i < 8; i++) {
        digitalWrite(portas[i], digito5[i]);
      }
      delay(blink_digito);
      for (int i = 0; i < 8; i++) {
        digitalWrite(portas[i], LOW);
      }
      delay(blink_digito);
      break;
    case '6':
      for (int i = 0; i < 8; i++) {
        digitalWrite(portas[i], digito6[i]);
      }
      delay(blink_digito);
      for (int i = 0; i < 8; i++) {
        digitalWrite(portas[i], LOW);
      }
      delay(blink_digito);
      break;
    case '7':
      for (int i = 0; i < 8; i++) {
        digitalWrite(portas[i], digito7[i]);
      }
      delay(blink_digito);
      for (int i = 0; i < 8; i++) {
        digitalWrite(portas[i], LOW);
      }
      delay(blink_digito);
      break;
    case '8':
      for (int i = 0; i < 8; i++) {
        digitalWrite(portas[i], digito8[i]);
      }
      delay(blink_digito);
      for (int i = 0; i < 8; i++) {
        digitalWrite(portas[i], LOW);
      }
      delay(blink_digito);
      break;
    case '9':
      for (int i = 0; i < 8; i++) {
        digitalWrite(portas[i], digito9[i]);
      }
      delay(blink_digito);
      for (int i = 0; i < 8; i++) {
        digitalWrite(portas[i], LOW);
      }
      delay(blink_digito);
      break;
  }
}
