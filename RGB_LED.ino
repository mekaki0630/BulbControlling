#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "****************";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "********";
char pass[] = "********";

// These are used to set the direction of the bridge driver.

#define  n D3 //IN3
#define  m D4 //IN4
#define  l D1 //IN1
#define  o D2 //IN2




// SETUP
void setup()
{
  // Configure pins

  pinMode(m, OUTPUT);
  pinMode(l, OUTPUT);
  pinMode(n, OUTPUT);
  pinMode(o, OUTPUT);

  
  // Start serial communication
  Serial.begin(9600);

  // Connect Blynk
  Blynk.begin(auth, ssid, pass);
}


// red light
BLYNK_WRITE(V0) {
  int button = param.asInt(); // read button
  if (button == 1) {
    Serial.println("RED");
    digitalWrite (l,LOW);
    digitalWrite (m,HIGH);
    digitalWrite (n,LOW);
    digitalWrite (o,LOW);
    
  }

}

// GREEN LIGHT
BLYNK_WRITE(V1) {
  int button = param.asInt(); // read button
  if (button == 1) {
    Serial.println("Turning GREEN");
    digitalWrite(l, LOW);
    digitalWrite(m, LOW);
    digitalWrite(n, HIGH);
    digitalWrite(o,LOW);
  
  }
 
}

// BLUE LIGHT
BLYNK_WRITE(V2) {
  int button = param.asInt(); // read button
  if (button == 1) {
    Serial.println("BLUE");
    digitalWrite(l, HIGH);
    digitalWrite (m, LOW);
    digitalWrite(n,LOW);
    digitalWrite(o,LOW);
    
  }
}
// MAIN CODE
void loop()
{
  Blynk.run();
}
