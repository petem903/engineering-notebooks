/*
 * Hex Display Counter via 74HC595 Shift Register
 *
 * Reads a hex character (0-9, A-F) over Serial and drives
 * a common-cathode 7-segment display through a 74HC595 shift register.
 *
 * Wiring:
 *   Arduino pin 9  → 74HC595 RCLK (latch)
 *   Arduino pin 10 → 74HC595 SRCLK (clock)
 *   Arduino pin 8  → 74HC595 SER (data)
 */

#include <SPI.h>

const byte SEVEN_SEG[16] = {
  0b11111100,  // 0
  0b01100000,  // 1
  0b11011010,  // 2
  0b11110010,  // 3
  0b01100110,  // 4
  0b10110110,  // 5
  0b10111110,  // 6
  0b11100000,  // 7
  0b11111110,  // 8
  0b11100110,  // 9
  0b11101110,  // A
  0b00111110,  // B
  0b10011100,  // C
  0b01111010,  // D
  0b10011110,  // E
  0b10001110   // F
};

const int LATCH_PIN = 9;
const int CLOCK_PIN = 10;
const int DATA_PIN  = 8;

void setup() {
  pinMode(LATCH_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(DATA_PIN,  OUTPUT);
  Serial.begin(9600);
  Serial.println("Send a hex digit (0-9, A-F):");
}

void sevenSegWrite(byte digit) {
  digitalWrite(LATCH_PIN, LOW);
  shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, SEVEN_SEG[digit]);
  digitalWrite(LATCH_PIN, HIGH);
}

void loop() {
  if (!Serial.available()) return;

  char c = Serial.read();

  if (c >= '0' && c <= '9') {
    sevenSegWrite(c - '0');
  } else if (c >= 'A' && c <= 'F') {
    sevenSegWrite(c - 'A' + 10);
  } else if (c >= 'a' && c <= 'f') {
    sevenSegWrite(c - 'a' + 10);
  }
}
