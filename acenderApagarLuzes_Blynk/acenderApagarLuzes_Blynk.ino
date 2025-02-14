#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "TMPL2ASGuQs2p"
#define BLYNK_TEMPLATE_NAME "filiphTeste"
#define BLYNK_AUTH_TOKEN "ijNGZT9R499LoGh8rE4gz6Ntu0kUDV-n"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
char auth[] = "ijNGZT9R499LoGh8rE4gz6Ntu0kUDV-n";
char ssid[] = "Filiph";
char pass[] = "12345678";
int LEDVermelho = 32;
int LEDAmarelo = 26;
int LEDVerde = 13;

BLYNK_WRITE (V0){
int valor = param.asInt();
digitalWrite(LEDVermelho, valor);
}
BLYNK_WRITE (V1){
int valor = param.asInt();
digitalWrite(LEDAmarelo, valor);
}
BLYNK_WRITE (V2){
  int valor = param.asInt();
digitalWrite(LEDVerde, valor);
}
/* // */
void setup()
{
Serial.begin (115200);
//Blynk.begin(auth, ssid, pass);
pinMode(LEDVermelho, OUTPUT);
pinMode(LEDAmarelo, OUTPUT);
pinMode(LEDVerde, OUTPUT);
}
void loop()
{
Blynk.run();
/*digitalWrite(LEDVermelho,1);
digitalWrite(LEDVerde,1);
digitalWrite(LEDAmarelo,1);*/
}