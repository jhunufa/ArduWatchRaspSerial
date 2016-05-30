# ArduTermoWatchRaspSerial

Comunicação entre Arduino Watch e Rasp Pi via PySerial

#### Projeto:
  Relógio monodígito controlado por Arduino e RaspPi com comunicação via biblioteca PySerial.

-----------
#### Funcionamento:

######  No Arduino:
O controlador lê as informações de temperatura e umidade do sensor DHT11 e salva sob a forma de String. Recebe via Serial as informações das horas, também em String, e prepara o blink dos dígitos para transmitir a informação.

######  No Display:
O Display pode reproduzir apenas um dígito por vez, sendo assim é necessário ler apenas um algarismo em cada passo. A sequência de informações é Horas>Minutos>Temperatura>Umidade. As horas são separadas dos minutos por um piscar duplo do ponto no display assim como a temperatura e a umidade. Um piscar longo do ponto separa os minutos da temperatura.

######  Na Raspberry:
A Rasp roda o script em Python que lê as horas da própria placa e os transmite via Serial para o Arduino conectado na Rasp.

----------------
#### Componentes:
  - Arduino ou equivalente com pelo menos 10 portas digitais (8 para o display e as 2 da comunicação serial: RX e TX)
  - Display de 7 segmentos com ânodo comum (HS-5101AS)
  - 2 resistores de 220ohms **(é altamente recomendável usar 8 resistores ao invés de 2)**
  - *(Opcional)* Comunicador FDTI caso sua placa não possua um embutido)
  - Sensor DHT11 de temperatura e umidade

--------------------
#### Montagem do circuito:

1. Pinagem e montagem do Display:

| Arduino | Display |
| ------- | ------- |
| D5      | 6       |
| D6      | 7       |
| D7      | 9       |
| D8      |10       |
| D9      | 1       |
| D10     | 2       |
| D11     | 4       |
| D12     | 5       |


- Nos pinos 8 e 3 do display (GND) entram as resistências

 **OBS:** É altamente recomendável o uso de 8 resistências ao invés de 2 (uma em cada cátodo do display ao invés de uma em cada ânodo) para melhor controle de corrente e brilho constante do display.

2) O sensor DHT11 liga-se na porta digital 13 (D13)

-------------------
#### Interfaces:

###### RaspPi-Python:
 - Abre o arquivo .py no booting da máquina e o mantém aberto desde então

###### Python-Serial:
 - Recebe informações da máquina via biblioteca Datetime acerca da hora no instante, manipula a informação e a transmite via biblioteca Serial sob a forma de String

###### Serial-Arduino:
 - Recebe a informação e imprime, caractere por caractere, no display
