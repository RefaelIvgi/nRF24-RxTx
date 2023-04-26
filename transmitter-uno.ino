// Transmitter

#include <SPI.h>

#include <RF24.h>




RF24 radio(9, 10); // define CE, CSN Pins for the NRF24L01

const byte addresses[6] = "00001";

const uint8_t channel =100;


void setup() {

  Serial.begin(9600);

  radio.begin();

  radio.setChannel(channel);

  radio.openWritingPipe(addresses); // Writing To Pipe 00001

  radio.setPALevel(RF24_PA_MIN);

  radio.stopListening();

}


void loop() 

{

      

  const char *text = "Hello";

  radio.write(text, strlen(text) + 1);

  Serial.println(text);

  delay(1000);


}
