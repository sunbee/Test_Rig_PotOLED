#include <Arduino.h>

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);


int sensorPin = A0;   // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {

  Serial.begin(9600);

  // put your setup code here, to run once:
  // initialize with the I2C addr 0x3C
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  
  display.clearDisplay();
}

void dazzle() {
  // Clear the buffer.
  display.clearDisplay();

  // Display Text
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,28);
  display.println("Hello world!");
  display.display();
  delay(2001);
  display.clearDisplay();

  // Display Inverted Text
  display.setTextColor(BLACK, WHITE); // 'inverted' text
  display.setCursor(0,28);
  display.println("Fire up your neurons!");
  display.display();
  delay(2001);
  display.clearDisplay();

  // Changing Font Size
  display.setTextColor(WHITE);
  display.setCursor(0,24);
  display.setTextSize(2);
  display.println("What's up nerds!");
  display.display();
  delay(2001);
  display.clearDisplay();

  // Display Numbers
  display.setTextSize(1);
  display.setCursor(0,28);
  display.println(123456789);
  display.display();
  delay(2001);
  display.clearDisplay();

  // Specifying Base For Numbers
  display.setCursor(0,28);
  display.print("0x"); display.print(0xFF, HEX); 
  display.print("(HEX) = ");
  display.print(0xFF, DEC);
  display.println("(DEC)"); 
  display.display();
  delay(2001);
  display.clearDisplay();

  // Display ASCII Characters
  display.setCursor(0,24);
  display.setTextSize(2);
  display.write(3);
  display.display();
  delay(2001);
  display.clearDisplay();

  // Scroll full screen
  display.setCursor(0,0);
  display.setTextSize(1);
  display.println("Let's");
  display.println("light up");
  display.println("our world!");
  display.display();
  display.startscrollright(0x00, 0x07);
  delay(2001);
  display.stopscroll();
  delay(1002);
  display.startscrollleft(0x00, 0x07);
  delay(2001);
  display.stopscroll();
  delay(1002);    
  display.startscrolldiagright(0x00, 0x07);
  delay(2001);
  display.startscrolldiagleft(0x00, 0x07);
  delay(2001);
  display.stopscroll();
  display.clearDisplay();

  // Scroll part of the screen
  display.setCursor(0,0);
  display.setTextSize(1);
  display.println("Make");
  display.println("your");
  display.println("mark.");
  display.display();
  display.startscrollright(0x00, 0x00);
  delay(2001);
  display.stopscroll();
  display.clearDisplay();
}

void displayMessage() {
  // Display Text
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,28);
  display.println("Om Tat Sat!");
  display.display();
  delay(2001);
  display.clearDisplay();
}

void displayMessage(String mess) {
  // Display Text
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,14);
  display.println(mess);
  display.display();
  delay(2001);
  display.clearDisplay();
}

void displayPotOLED() {
  /*
  Read the pot on A0,
  then display to OLED
  using the helper function. 
  */
 sensorValue = analogRead(sensorPin);
 Serial.print("Reading: " + sensorValue);
 float sensorReading = sensorValue * 100.0 / 1023.0;
 char sensorDisplay[7];
 dtostrf(sensorReading, 6, 2, sensorDisplay);
 char readOut[11];
 snprintf(readOut, 11, "Got:%6s", sensorDisplay);
 displayMessage(readOut);
}

void loop() {
  // put your main code here, to run repeatedly:
  displayPotOLED();
  delay(300);
}

