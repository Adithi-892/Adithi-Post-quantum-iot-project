#define BLYNK_TEMPLATE_ID "TMPL3o9uLliDm"
#define BLYNK_TEMPLATE_NAME "PQHA"

#include <Arduino.h>
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

// WiFi credentials
const char *ssid = "Maathrushree";
const char *password = "69775928";

// Blynk authentication token
char auth[] = "vkIJKC3-lczlC4AvRw2hSXgqrCl4de8m";

// Define IoT Cloud properties
int temperatureValue;
int irSensorValue;
int gasSensorValue;
int lightSensorValue;
int uvSensorValue;

// XOR encryption/decryption key (for demonstration only)
const char encryptionKey = 'S'; // Change this key for your application

void setup() {
  Serial.begin(115200);

  // Initialize WiFi connection
  connectWiFi();

  // Initialize Blynk
  Serial.println("Connecting to Blynk...");
  Blynk.begin(auth, ssid, password);

  // Connect to Blynk
  while (Blynk.connect() == false) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("Connected to Blynk!");
}

void loop() {
  Blynk.run();
  
  // Read sensor values and update IoT properties
  readSensors();

  // Encrypt sensor values
  encryptSensorValues();

  // Print encrypted values
  Serial.print("Encrypted temperatureValue: ");
  Serial.println(temperatureValue);
  Serial.print("Encrypted irSensorValue: ");
  Serial.println(irSensorValue);
  Serial.print("Encrypted gasSensorValue: ");
  Serial.println(gasSensorValue);
  Serial.print("Encrypted lightSensorValue: ");
  Serial.println(lightSensorValue);
  Serial.print("Encrypted uvSensorValue: ");
  Serial.println(uvSensorValue);

  // Update Blynk virtual pins with encrypted values
  Blynk.virtualWrite(V1, temperatureValue);
  Blynk.virtualWrite(V2, irSensorValue);
  Blynk.virtualWrite(V3, gasSensorValue);
  Blynk.virtualWrite(V4, lightSensorValue);
  Blynk.virtualWrite(V5, uvSensorValue);

  delay(1000); // Example delay
}

void connectWiFi() {
  Serial.print("Connecting to WiFi...");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("WiFi connected!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void readSensors() {
  // Replace with actual sensor readings
  temperatureValue = random(0, 100); // Simulated value, replace with actual sensor reading
  irSensorValue = digitalRead(22);   // Security IR - D22
  gasSensorValue = digitalRead(25);  // Gas - D25
  lightSensorValue = analogRead(19); // Light Sensor - A19
  uvSensorValue = analogRead(32);    // UV - A32

  // Print sensor readings
  Serial.print("Raw temperatureValue: ");
  Serial.println(temperatureValue);
  Serial.print("Raw irSensorValue: ");
  Serial.println(irSensorValue);
  Serial.print("Raw gasSensorValue: ");
  Serial.println(gasSensorValue);
  Serial.print("Raw lightSensorValue: ");
  Serial.println(lightSensorValue);
  Serial.print("Raw uvSensorValue: ");
  Serial.println(uvSensorValue);
}

void encryptSensorValues() {
  // Encrypt sensor values using XOR encryption
  temperatureValue ^= encryptionKey;
  irSensorValue ^= encryptionKey;
  gasSensorValue ^= encryptionKey;
  lightSensorValue ^= encryptionKey;
  uvSensorValue ^= encryptionKey;
}

void decryptSensorValues() {
  // Decrypt sensor values using XOR decryption
  temperatureValue ^= encryptionKey;
  irSensorValue ^= encryptionKey;
  gasSensorValue ^= encryptionKey;
  lightSensorValue ^= encryptionKey;
  uvSensorValue ^= encryptionKey;
}
