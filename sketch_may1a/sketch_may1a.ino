// Reading the Infrared Sensors
#define IR_1 2
#define IR_2 4
#define IR_3 7
#define IR_4 8

// Timer to track the last report of the IR sensors
unsigned long irSensorMillis = 0;

// Global variable to track the reporting period of the color sensor
unsigned long colorSensorMillis = 0; 

// TSC3200 library
#include <tcs3200.h>

// Pin definitions
#define COLOR_0 A0
#define COLOR_1 A1
#define COLOR_2 A2
#define COLOR_3 A3
#define COLOR_OUT A4

void setup() {
// put your setup code here, to run once:

//Serial begin
Serial.begin(9600);

// Setup Infrared Pins
pinMode(IR_1, INPUT);
pinMode(IR_2, INPUT);
pinMode(IR_3, INPUT);
pinMode(IR_4, INPUT);
}

void loop() {
// put your main code here, to run repeatedly:
// Get the current run time in milliseconds
unsigned long currentMillis = millis();

// Check the states of the IR sensors every 500ms / 0.5 seconds
if (currentMillis - irSensorMillis >= 500) {
  irSensorMillis = currentMillis;
  readInfrared();
}

// Read the color sensor
if (currentMillis - colorSensorMillis >= 250) {
  colorSensorMillis = currentMillis;
  readColorSensor();
}
}
