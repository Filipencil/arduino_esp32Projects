// Aula Blynk - Projeto Final 
#define BLYNK_TEMPLATE_ID "TMPL2cCClyb28"
#define BLYNK_TEMPLATE_NAME "FiliphTeste"
#define BLYNK_AUTH_TOKEN "YFoK-iHNGwbo8Xn0xs6nnkrbRDluV0o_"
//Definição do objeto serial
#define BLYNK_PRINT Serial


//Bibliotecas
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
//adicionando a biblioteca do servo motor.
#include <ESP32Servo.h>
#include <DHT.h>

//Definicão do blynk, id, nome e token

/*
Descritivo dos pinos virtuais
v0 - Led Amarelo, inteiro de 0 a 1
v1 - Temperatura, double de 0 a 80
v2 - Umidade, double de 0 a 100
v3 - Tempo, integer de 0 a 60
v4 - Servo Motor, integer de 0 a 180
*/



//Definição de portas e tipos
#define ledAm 2 // declarando a variavel ledAm como porta 21
#define DHTPIN 4 // dht11
#define DHTTYPE DHT22 // definindo do dht11


//Definição do objeto do tipo Servo, porta e angulo(posição).
Servo servo1;
int servoPin = 5;
int angulo;


// Credenciais do Wifi.
char ssid[] = "Filiph";
char pass[] = "12345678";


DHT dht(DHTPIN, DHTTYPE); // criando o objeto dht
BlynkTimer timer;

//A funçao BLYNK_WRITE() é chamada toda vez que o status do Virtual Pin X mudar s
//Aqui o blynk envia para o esp
BLYNK_WRITE(V0) { //V0 é referente ao led Amarelo
  int valor = param.asInt();
  digitalWrite(ledAm, valor); //mudando o estado o led utilizando o valor da variável valor.
  //Blynk.virtualWrite(V1, valor); // se eu quizer utilizar o valor do v0 em outro pino virtual posso utilizar essa linha.
}

//Função para Temperatura, v1 representa a Temperatura do DTH11
void temperatura(){
  // float temp = dht.readTemperature();
  float temp = dht.readTemperature();;
  Blynk.virtualWrite(V1, temp); //envia para o blynk o valor da umidade no pino virtual 2(v2)
}

//Função para Umidade, v2 representa a Umidade do DTH11
void umidade(){
  // float umid = dht.readHumidity();
  float umid = dht.readHumidity();
  Blynk.virtualWrite(V2, umid); //envia para o blynk o valor da umidade no pino virtual 2(v2)

}

// função para mostrar o tempo ligado
void myTimerEvent(){
  Blynk.virtualWrite(V3, millis() / 1000);

}

//v4 representa o servo motor, os dados são enviados do blynk para o servo motor.
BLYNK_WRITE(V4){
  int valor = param.asInt();
  servo1.write(valor); //passa para o servo motor o novo angulo.
  //angulo = valor; //posso utilizar o valor do angulo para qualquer outra coisa, ex. printar no serial monitor.
  //Blynk.virtualWrite(V4, valor); // envio de volta para o pino virtual 4 a posição do servo apenas para segurança, nao é uma linha obrigatória.
}

void setup(){
  // Debug console
  Serial.begin(115200);

  servo1.attach(servoPin);
  //servo1.write(90); //apenas para fixar o servo em uma posição diferente de zero, não é obrigatoria

  pinMode(ledAm, OUTPUT); // Declarando o modo do pino como saida

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);// Definindo o blynk com token e informaçoes de wifi.

  //Funções que são chamadas por tempo.
  timer.setInterval(1000L, myTimerEvent);
  timer.setInterval(5000L, temperatura);
  timer.setInterval(5000L, umidade);  

}

void loop()
{
  Blynk.run();

  timer.run();

  delay(200);
}