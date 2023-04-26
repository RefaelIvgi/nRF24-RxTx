//Receiver

#include <SPI.h>

#include <RF24.h>




RF24 radio(7, 8);

const byte addresses[6] = "00001";

const uint8_t channel =100;



void setup() {

  Serial.begin(9600);

  radio.begin();

  radio.setChannel(channel);

  radio.openReadingPipe(0, addresses); // Reading from Pipe 00002

  radio.setPALevel(RF24_PA_MIN);

  radio.startListening(); 

}

void loop() {                                           

   if (radio.available()) {

    char text[32];

    radio.read(text, sizeof(text));

    Serial.println(String(text));

  }                    

}