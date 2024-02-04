#define BLYNK_PRINT Serial
#include <BlynkSimpleSerialBLE.h>
#include <SoftwareSerial.h>
SoftwareSerial SwSerial(0, 1); // RX, TX


// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "86461585acdc4f2e8891686ff446c601";

SoftwareSerial SerialBLE(0, 1); // RX, TX

void setup()
{
  // Debug console
  Serial.begin(9600);

  SerialBLE.begin(9600);
  Blynk.begin(SerialBLE, auth);

  Serial.println("Waiting for connections...");
}

void loop()
{
  Blynk.run();
}
