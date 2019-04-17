#include <SoftwareSerial.h>//declaração da biblioteca Serial do módulo Bluetooth
SoftwareSerial bluetooth(2, 3);//declaração da porta de comunicação do módulo Bluetooth (TX=2, RX=3)
//declaração dos pinos de comando
int IN1 = 4;
int IN2 = 5;
int IN3 = 6;
int IN4 = 7;
char comando;//declaração da variável que recebe o comando emitido pelo celular
//inicio da variavel de inicialização do código
void setup() {
  //Definição dos pinos de saida

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  bluetooth.begin(9600);//definição da velocidade da comunicação do módulo bluetooth
  Serial.begin(9600);//definição da velocidade da comunicação do serial do módulo
  
  delay(1000);//atraso de 1 segundo para iniciar o código loop
}
//inicio da padrão de loop
void loop() {
  while (bluetooth.available()) {//enquanto receber sinal do celular
    comando = bluetooth.read();//variável comando recebe leitura do sinal recebido do celular
    Serial.println(comando);//printa no serial a variável comando
    
    if (comando == 'F') {//se receber o sinal F
      frente();//vai para a função FRENTE
    }
    else if (comando == 'B') {//se receber o sinal B
      tras();//vai para a função TRAS
    }
    else if (comando == 'L') {//se receber o sinal L
      esquerda();//vai para a função ESQUERDA
    }
    else if (comando == 'R') {//se receber o sinal R
      direita();//vai para a função DIREITA
    } else {
      parado();//vai para a função PARADO
    }
  }
}//final 

void frente() {
  //Gira o Motor A e B no sentido horario
  digitalWrite(IN1, LOW);//desliga o motor 1
  digitalWrite(IN2, HIGH);//liga no motor 2
  digitalWrite(IN3, HIGH);//desliga o motor 3
  digitalWrite(IN4, LOW);//liga o motor 4
}

void tras() {
  //Gira o Motor A e B no sentido anti-horario
  digitalWrite(IN1, HIGH);//liga o motor 1
  digitalWrite(IN2, LOW);//desliga o motor 2
  digitalWrite(IN3, LOW);//desliga o motor 3
  digitalWrite(IN4, HIGH);//liga o motor 4
}

void esquerda() {
  //Gira o Motor A sentido anti-horario e B no sentido horario
  digitalWrite(IN1, LOW);//desliga o motor 1
  digitalWrite(IN2, HIGH);//liga o motor 2
  digitalWrite(IN3, LOW);//desliga o motor 3
  digitalWrite(IN4, HIGH);//liga o motor 4
}

void direita() {
  //Gira o Motor A sentido horario e B no sentido anti-horario
  digitalWrite(IN1, HIGH);//liga o motor 1
  digitalWrite(IN2, LOW);//desliga o motor 2
  digitalWrite(IN3, HIGH);//liga o motor 3
  digitalWrite(IN4, LOW);//desliga o motor 4
}

void parado() {
  digitalWrite(IN1, LOW);//liga o motor 1
  digitalWrite(IN2, LOW);//liga o motor 2
  digitalWrite(IN3, LOW);//liga o motor 3
  digitalWrite(IN4, LOW);//liga o motor 4
}
