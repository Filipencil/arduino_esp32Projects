#include <DHT.h>

DHT dht(4,DHT22);

float temperatura, umidade;
int contador;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  
  pinMode(4, INPUT);
}

void loop() {
  temperatura = dht.readTemperature();
  umidade = dht.readHumidity();

  Serial.println("\n-------------");
  Serial.println("Leitura:" + String(contador));
  //temperatura
  Serial.println("Temperatura:\t");
  
  Serial.print(dht.readTemperature(false));
  Serial.println("°C");

  //percentual de umidade
  Serial.println("Umidade:\t " + String(umidade) + "%");

  delay(1000);

  for(int i=0; i<=10,i++;){
    Serial.print(".");
    delay(1000);
  }

    contador++;
  

}
