#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8);  // CE, CSN
const byte address[6] = "00001";
const int buttPin = 6;

void setup() {
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
  pinMode(buttPin, INPUT);
}

void loop() {
  int buttState = digitalRead(buttPin);
  if (buttState == HIGH) {
    const char text[] = "OFF";
    radio.write(&text, sizeof(text));
  } else {
    const char text[] = "ON";
    radio.write(&text, sizeof(text));
  }
  delay(1000); // Adjust delay as needed
}