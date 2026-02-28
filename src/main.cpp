#include <Arduino.h>

/**
 * @file main.cpp
 * @brief Embedded Distance Measurement using Ultrasonic Sensor (HC-SR04)
 * @author Vedansh
 * @date 2026-02-28
 *
 * @details
 * This program measures distance using the HC-SR04 ultrasonic sensor.
 * It sends an ultrasonic pulse from the TRIG pin and measures the time
 * taken for the echo to return on the ECHO pin. The distance is then
 * calculated in centimeters and displayed in a structured format
 * via the Serial Monitor every 500 milliseconds.
 */

// Define TRIG pin (Use pin 9)
#define TRIG_PIN 9

// Define ECHO pin (Use pin 10)
#define ECHO_PIN 10

// Variable to store duration of echo pulse
long duration;

// Variable to store calculated distance in centimeters
float distance;

/**
 * @brief Initializes serial communication and configures sensor pins.
 */
void setup() {

    // Initialize Serial communication (9600 baud rate)
    Serial.begin(9600);

    // Configure TRIG as OUTPUT
    pinMode(TRIG_PIN, OUTPUT);

    // Configure ECHO as INPUT
    pinMode(ECHO_PIN, INPUT);

    // Print system initialization message
    Serial.println("Ultrasonic Distance Measurement System Initialized");
}

/**
 * @brief Continuously measures and prints distance using HC-SR04 sensor.
 */
void loop() {

    // Set TRIG LOW for 2 microseconds to ensure clean pulse
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);

    // Send 10 microsecond pulse on TRIG to start measurement
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    // Measure pulse duration on ECHO pin using pulseIn()
    duration = pulseIn(ECHO_PIN, HIGH);

    // Calculate distance in cm (Speed of sound = 343 m/s)
    // distance = (duration * 0.0343) / 2
    distance = (duration * 0.0343) / 2.0;

    // Print calculated distance
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    // Add delay (500ms) before next reading
    delay(500);
}
