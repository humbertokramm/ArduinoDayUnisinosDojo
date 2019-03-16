#include <WiFi.h>
#include <WiFiMulti.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#define BOTtoken "875639737:AAEjrEp6BE0-PEB7dYGtQ2gLBj8s3XRR-tk"//Define o Token do *seu* BOT
 WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);
WiFiMulti WiFiMulti;
WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);
 
String id, text;//Váriaveis para armazenamento do ID e TEXTO gerado pelo Usuario
unsigned long tempo;
 
#define LED   14
#define LED2   26
 
void setup()
{
    Serial.begin(115200);
    delay(10);
    
    pinMode(LED, OUTPUT);//LED conectado à saida
    digitalWrite(LED, LOW);
   
   

    // We start by connecting to a WiFi network
    WiFiMulti.addAP("ArduinoDay", "Arduino2019");

    Serial.println();
    Serial.println();
    Serial.print("Wait for WiFi... ");

    while(WiFiMulti.run() != WL_CONNECTED) {
        Serial.print(".");
        delay(500);
    }

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());

    delay(500);
}
 
void loop()
{
   if (millis() - tempo > 2000)//Faz a verificaçao das funçoes a cada 2 Segundos
   {
      readTel();//Funçao para ler o telegram
      tempo = millis();//Reseta o tempo
   }
}
 
 
void readTel()//Funçao que faz a leitura do Telegram.
{
   int newmsg = bot.getUpdates(bot.last_message_received + 1);
 
   for (int i = 0; i < newmsg; i++)//Caso haja X mensagens novas, fara este loop X Vezes.
   {
      id = bot.messages[i].chat_id;//Armazenara o ID do Usuario à Váriavel.
      text = bot.messages[i].text;//Armazenara o TEXTO do Usuario à Váriavel.
      text.toUpperCase();//Converte a STRING_TEXT inteiramente em Maiuscúla.
 
      if (text.indexOf("ON") > -1)//Caso o texto recebido contenha "ON"
      {
         digitalWrite(LED, 0);//Liga o LED
         bot.sendMessage(id, "LED ON", "");//Envia uma Mensagem para a pessoa que enviou o Comando.
      }
 
      else if (text.indexOf("OFF") > -1)//Caso o texto recebido contenha "OFF"
      {
         digitalWrite(LED, 1);//Desliga o LED
         bot.sendMessage(id, "LED OFF", "");//Envia uma Mensagem para a pessoa que enviou o Comando.
      }
 
      else if (text.indexOf("START") > -1)//Caso o texto recebido contenha "START"
      {
         bot.sendSimpleMessage(id, id, "");//Envia uma mensagem com seu ID.
      }
 
      else//Caso o texto recebido nao for nenhum dos acima, Envia uma mensagem de erro.
      {
         bot.sendSimpleMessage(id, "Comando Invalido", "");
      }
   }
 
}
