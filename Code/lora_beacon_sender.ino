#include <SPI.h>
#include <LoRa.h>


int counter = 0;
void setup() {
  LoRa.setPins(5,15,2);
  Serial.begin(9600);
   while (!Serial);

  Serial.println("LoRa Sender");

  if (!LoRa.begin(868E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }

  
}

void loop() {
  
  Serial.print("Sending packet no: ");
  Serial.println(counter);

  LoRa.beginPacket();
  LoRa.print("chutfuckautrop ");  
  LoRa.print(counter);
  LoRa.endPacket();

  counter++;

  delay(1000);
}