// ---------------------------------------------------------------------------
// Example NewPing library sketch that pings 3 sensors 20 times a second.
// ---------------------------------------------------------------------------
#include <Arduino.h>
#include <NewPing.h>

#define SONAR_NUM 2      // Number of sensors.
#define MAX_DISTANCE 200 // Maximum distance (in cm) to ping.
const byte TRANS_ARR[] = {D5,D6};

NewPing sonar[SONAR_NUM] = {   // Sensor object array.
  NewPing(D1, D2, MAX_DISTANCE), // Each sensor's trigger pin, echo pin, and max distance to ping. 
  NewPing(D3, D4, MAX_DISTANCE)
};

void setup() {
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
  for (uint8_t i = 0; i < SONAR_NUM; i++) {
      pinMode(TRANS_ARR[i], OUTPUT);
      delay(50);
  }
}

void loop() { 
  for (uint8_t i = 0; i < SONAR_NUM-1; i++) {
        digitalWrite(TRANS_ARR[i], HIGH);
  }
  for (uint8_t i = 0; i < SONAR_NUM-1; i++) { // Loop through each sensor and display results.
    delay(50); // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
    digitalWrite(TRANS_ARR[i], HIGH);
    delay(5000);
    Serial.print(i);
    Serial.print("=");
    Serial.print(sonar[i].ping_cm());
    Serial.print("cm ");
    digitalWrite(TRANS_ARR[i], LOW);
  }
  Serial.println();
  for (uint8_t i = 0; i < SONAR_NUM-1; i++) {
        digitalWrite(TRANS_ARR[i], LOW);
  }
}