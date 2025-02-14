//Sensor ultrassônico
const int pinTriguer = 19; // Pino D4 conectado ao TRIG do HC-SR04
const int pinEcho = 18; // Pino D2 conectado ao ECHO do HC-SR04
const int ledVermelho = 26;
const int ledVerde = 32;
const int ledAmarelo = 33;


void setup() {
  Serial.begin(115200); // Inicializa a comunicação serial
  pinMode(pinTriguer, OUTPUT); // Configura o pino TRIG como saída
  pinMode(pinEcho, INPUT); // Configura o pino ECHO como entrada
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
}

void loop() {
  digitalWrite(pinTriguer, LOW);
  delayMicroseconds(2);
  digitalWrite(pinTriguer, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTriguer, LOW);
 
  long duracao = pulseIn(pinEcho, HIGH); // Mede o tempo de resposta do ECHO  
  float distancia = (duracao * 0.0343) / 2;// Calcula a distância usando a velocidade do som (aproximadamente 343 m/s)
  Serial.print("Distância: ");
  Serial.print(distancia);
  Serial.println(" cm");

  if(distancia >=60){
    digitalWrite(ledVerde,1);
  }else{
    digitalWrite(ledVerde,0);
  }

  if(distancia >10 && distancia <60){
    digitalWrite(ledAmarelo,1);
  }else{
    digitalWrite(ledAmarelo,0);
  }

  if(distancia <=10){
    digitalWrite(ledVermelho,1);
  }else{
    digitalWrite(ledVermelho,0);
  }
 
  delay(1000); // Aguarda 1 segundo antes de fazer a próxima leitura
}
//long -> A variável "long" é utilizada para armazenar números inteiros longos, ou seja, números inteiros maiores do que os que podem ser armazenados em uma variável "int"
//delayMicroseconds -> A função delayMicroseconds() lida com microssegundos (10 elevado a -6 segundos), enquanto a função delay() lida com milissegundos (10 elevado a -3 segundos).