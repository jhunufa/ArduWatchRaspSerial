# ArduTermoWatchRaspSerial

ArduinoWatch para RaspPi via PySerial:
Implementação leve no Projeto ArduWatchRaspSerial para, agora, ler temperatura e umidade no mesmo display.

Proposta:
  Projeto de um relógio com apenas um dígito controlado por Arduino e implementado em uma RaspPi via PySerial.

Para entrar em contato use o GitHub ou o email jhunu.fernandes@gmail.com
-----------------------------------------------------------------
Funcionamento:

  No Arduino:
    O controlador lê as informações de temperatura e umidade do sensor DHT11 e salva sob a forma de String. Recebe via Serial as informações das horas, também em String, e prepara o blink dos dígitos para transmitir a informação.

  No Display:
    O Display pode reproduzir apenas um dígito por vez, sendo assim é necessário ler apenas um algarismo em cada passo. A sequência de informações é Horas>Minutos>Temperatura>umidade. As horas são separadas dos minutos por um piscar duplo do ponto no display assim como a temperatura e a umidade. Um piscar longo do ponto separa os minutos da temperatura.

  Na Raspberry:
    A Rasp roda o script em Python que lê as horas da própria placa e os transmite via Serial para o Arduino conectado na Rasp.
-----------------------------------------------------------------
Componentes:

  1) Arduino ou equivalente com pelo menos 10 portas digitais (8 para o display e as 2 da comunicação serial: RX e TX)

  2) Display de 7 segmentos com ânodo comum (HS-5101AS)

  3) 2 resistores de 220ohms (é altamente recomendável usar 8 resistores ao invés de 2)

  4) Comunicador FDTI (Opcional) caso sua placa não possua um embutido)

  5) Sensor DHT11 de temperatura e umidade
-----------------------------------------------------------------
Montagem do circuito:

1) Pinagem e montagem do Display:
  Pino Arduino >> Pino Display ()
    D5 >> 6
    D6 >> 7
    D7 >> 9
    D8 >> 10
    D9 >> 1
    D10 >> 2
    D11 >> 4
    D12 >> 5


  Nos pinos 8 e 3 do display (GND) entram as resistências

  Obs: É altamente recomendável o uso de 8 resistências ao invés de 2 (uma em cada cátodo do display ao invés de uma em cada ânodo) para melhor controle de corrente e brilho constante do display.

2) O sensor DHT11 liga-se na porta digital 13 (D13)
-----------------------------------------------------------------
Interfaces:

  1) RaspPi-Python
  2) Python-Serial
  3) Serial-Arduino

  1) RaspPi-Python:
    Abre o arquivo .py no booting da máquina e o mantém aberto desde então

  2) Python-Serial:
    Recebe informações da máquina via biblioteca Datetime acerca da hora no instante, manipula a informação e a transmite via biblioteca Serial sob a forma de String

  3) Serial-Arduino:
    Recebe a informação e imprime, caractere por caractere, no display
