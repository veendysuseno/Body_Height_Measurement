# Body Height Measurement System

## Description

This project is designed to measure a person's height using an ultrasonic distance sensor. The measured height is displayed on an LCD screen. The system calculates the height by measuring the distance between the sensor and the top of the head, subtracting this from a reference height.

## Components

- Arduino (e.g., Arduino Uno)
- Ultrasonic Distance Sensor (HC-SR04 or similar)
- LCD Display (16x2, using the LiquidCrystal library)
- Jumper Wires
- Breadboard (optional)

## Pin Configuration

| Component              | Pin Number |
| ---------------------- | ---------- |
| Ultrasonic Echo Pin    | 10         |
| Ultrasonic Trigger Pin | 11         |
| LCD RS                 | 2          |
| LCD E                  | 3          |
| LCD D4                 | 4          |
| LCD D5                 | 5          |
| LCD D6                 | 6          |
| LCD D7                 | 7          |

## Code

```cpp
// Code for Body Height Measurement System

#define ECHOPIN 10
#define TRIGPIN 11

#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

int H2, HT, H1;

void setup(){
  lcd.begin(16, 2);
  lcd.print("Tinggi Badan");  // Display "Tinggi Badan" on the LCD
  lcd.setCursor(0, 1);
  lcd.print("TB=");          // Display "TB=" for height

  pinMode(ECHOPIN, INPUT);   // Set echo pin as input
  pinMode(TRIGPIN, OUTPUT); // Set trigger pin as output
  delay(1000);              // Initial delay
  HT = 200;                 // Reference height
}

void loop(){
  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);
  int distance = pulseIn(ECHOPIN, HIGH);
  distance = distance / 58; // Convert to centimeters

  H2 = HT - distance;      // Calculate height
  lcd.setCursor(3, 1);
  lcd.print(H2);
  lcd.print(" cm ");       // Display height in cm
  delay(1000);             // Update every second
}

```

## How It Works

1. Initialization:

   - The setup() function initializes the LCD display and sets up the pins for the ultrasonic sensor.
   - The reference height (HT) is set to 200 cm, which you can adjust as needed.

2. Distance Measurement:

   - In the loop() function, the ultrasonic sensor is triggered to send a pulse.
   - The sensor measures the time taken for the echo to return, which is converted to distance in centimeters.

3. Height Calculation:
   - The height is calculated by subtracting the measured distance from the reference height.
   - The calculated height is displayed on the LCD.

## Usage

1. Connect the ultrasonic sensor and LCD to the appropriate pins on the Arduino.
2. Upload the code to the Arduino board.
3. Power the Arduino and observe the height measurement on the LCD.

## Notes

- Ensure the ultrasonic sensor is properly aligned for accurate measurements.
- Adjust the reference height (HT) as needed based on your specific use case.
