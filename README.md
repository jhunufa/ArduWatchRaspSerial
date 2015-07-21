# ArduTermoWatchRaspSerial

ArduinoWatch para RaspPi via PySerial:
Implementação leve do Projeto ArduWatchRaspSerial agora com leituras de temperatura e umidade

Proposta: Projeto de um relógio com apenas um dígito controlado por Arduino e implementado em uma RaspPi via PySerial.
-----------------------------------------------------------------
Componentes:

1)Arduino ou equivalente com pelo menos 10 portas digitais (8 para o display e as 2 da comunicação serial: RX e TX)

2)Display de 7 segmentos com ânodo comum (HS-5101AS)

3)2 resistores de 220ohms (é altamente recomendável usar 8 resistores ao invés de 2)

4)Comunicador FDTI (Opcional) caso sua placa não possua um embutido)

O controlador comanda o blink dos LEDs através de suas portas digitais conforme recebe o valor das horas.
Neste sketch os pinos digitais estão ligados diretamente nos pinos do display comforme o seguinte esquema:

Pino Arduino >> Pino Display
  5 >> 6
  6 >> 7
  7 >> 9
  8 >> 10
  9 >> 1
  10 >> 2
  11 >> 4
  12 >> 5


Nos pinos 8 e 3 do display (GND) entram as resistências

Obs: É altamente recomendável o uso de 8 resistências ao invés de 2 (uma em cada cátodo do display) para melhor controle de corrente e brilho constante do display
-----------------------------------------------------------------
Interfaces:
1)RaspPi-Python
2)Python-Serial
3)Serial-Arduino

1)RaspPi-Python:
Abre o arquivo .py no booting da máquina e o mantém aberto desde então

2)Python-Serial:
Recebe informações da máquina via biblioteca Datetime acerca da hora no instante, manipula a informação e a transmite via biblioteca Serial sob a forma de String

3)Serial-Arduino:
Recebe a informação e imprime, caractere por caractere, no display
