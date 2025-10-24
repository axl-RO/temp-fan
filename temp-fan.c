// Temperature-Based Fan Control using Arduino and DHT11
#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT11
#define FAN_PIN 8
#define LED_PIN 13

DHT dht(DHTPIN, DHTTYPE);
float temperature;

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(FAN_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(FAN_PIN, LOW);
  digitalWrite(LED_PIN, LOW);
  Serial.println("Temperature-Based Fan Control System Started");
}

void loop() {
  temperature = dht.readTemperature();

  if (isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  if (temperature >= 30.0) {
    digitalWrite(FAN_PIN, HIGH);
    digitalWrite(LED_PIN, HIGH);
    Serial.println("Fan: ON");
  } else {
    digitalWrite(FAN_PIN, LOW);
    digitalWrite(LED_PIN, LOW);
    Serial.println("Fan: OFF");
  }

  delay(2000);
}
