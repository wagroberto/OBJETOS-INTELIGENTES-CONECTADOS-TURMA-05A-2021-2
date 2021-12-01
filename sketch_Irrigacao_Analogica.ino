#include <Boards.h>
#include <Firmata.h>
#include <FirmataConstants.h>
#include <FirmataDefines.h>
#include <FirmataMarshaller.h>
#include <FirmataParser.h>
#include <SPI.h>
#include <Ethernet.h>
#include <PubSubClient.h>
#include <Firmata.h>

//Wagner Roberto Silva
//Professor: Wilian Franca Costa
//OBJ_INT_CONT_A04 - Aplicando conhecimento

#define pinoAnalog A0 //Pino analógico do sensor de umidade
#define pinoRele 8 // Pino do rele


int ValAnalogIn;



void setup() {
 Serial.begin(9600);
 Serial.println("OBJ_INT_CONT_A03 - Aplicando conhecimento");
 pinMode(pinoRele, OUTPUT);


}

void loop()
{
  ValAnalogIn = analogRead(pinoAnalog);
  int Porcento = map(ValAnalogIn, 1023, 0, 0, 100);

  Serial.print(Porcento);
  Serial.println("%");

  if (Porcento <= 45)
  {
    Serial.println("Sua planta necessita de água,ela esta sendo irrigada...");
    digitalWrite(pinoRele, HIGH);
  }

  else
  {
    Serial.println("Sua planta encontra-se irrigada ...");
    digitalWrite(pinoRele, LOW);
  }
  delay (3000);
}
