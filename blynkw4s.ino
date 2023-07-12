#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// WiFi parameters
char ssid[] = "User name";
char pass[] = "Password";

// Blynk authentication token
char auth[] = "authentication token";

// Digital pin for relay signal
int D1 = 5;
int D2 = 4;
int D3 = 0;
int D4 = 2;

void setup() {
  // Start serial communication
  Serial.begin(115200);
  // Connect to WiFi
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  // Connect to Blynk server
  Blynk.begin(auth, WiFi.SSID().c_str(), WiFi.psk().c_str());
  // Set relay pin as output
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
}

void loop() {
  // Run Blynk
  Blynk.run();
}

// Button widget handlers
BLYNK_WRITE(V1) {
  // Turn switch 1 on or off depending on button state
  if (param.asInt() == HIGH) {
    digitalWrite(D1, LOW);
  } else {
    digitalWrite(D1, HIGH);
  }
}

BLYNK_WRITE(V2) {
  // Turn switch 2 on or off depending on button state
  if (param.asInt() == HIGH) {
    digitalWrite(D2, LOW);
  } else {
    digitalWrite(D2, HIGH);
  }
}

BLYNK_WRITE(V3) {
  // Turn switch 3 on or off depending on button state
  if (param.asInt() == HIGH) {
    digitalWrite(D3, LOW);
  } else {
    digitalWrite(D3, HIGH);
  }
}

BLYNK_WRITE(V4) {
  // Turn switch 4 on or off depending on button state
  if (param.asInt() == HIGH) {
    digitalWrite(D4, LOW);
  } else {
    digitalWrite(D4, HIGH);
  }
}
