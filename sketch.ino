#include <WiFi.h>
#include <HTTPClient.h>

// WiFi credentials
const char* ssid = "Wokwi-GUEST";
const char* password = "";


// ThingSpeak api and channel id 
String apiKey = "HF6QPSK9PGH7VOY8";
String channelID = "3141702"; 
//ports of ultrasonic sensor that are connected to esp32
const int trigPin = 5;
const int echoPin = 18;

void setup() {
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to WiFi!");
}

void loop() {
  // Send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure echo time
  long duration = pulseIn(echoPin, HIGH);
  float distance = (duration * 0.0343) / 2; // cm

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Send data to ThingSpeak
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    String url = "http://api.thingspeak.com/update?api_key=" + apiKey + "&field1=" + String(distance);
    http.begin(url);
    int httpCode = http.GET();
    if (httpCode > 0) {
      Serial.println("Data sent to ThingSpeak!");
    } else {
      Serial.println("Error sending data!");
    }
    http.end();
  } else {
    Serial.println("WiFi not connected!");
  }

  delay(15000); //one update every 15 seconds
}