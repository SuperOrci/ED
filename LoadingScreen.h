#include <Adafruit_GFX.h>  // Core graphics library
#include <SPI.h>
#include <Wire.h>  // this is needed even tho we aren't using it
#include <Adafruit_ILI9341.h>
#include <Adafruit_STMPE610.h>

// Pins for the TFT and touch screen
#define TFT_CS 10
#define TFT_DC 9
#define STMPE_CS 8

// Initialize Adafruit TFT and touchscreen
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);
Adafruit_STMPE610 ts = Adafruit_STMPE610(STMPE_CS);

void setup() {
  // Initialize the TFT
  tft.begin();
  tft.setRotation(1); // Set rotation to landscape mode
  tft.fillScreen(ILI9341_BLACK); // Clear the screen to black
}

void loop() {
  // Dimensions for the large rectangle
  int largeRectX = 40;
  int largeRectY = 80;
  int largeRectWidth = 240;
  int largeRectHeight = 60;

  // Draw the large rectangle
  tft.drawRect(largeRectX, largeRectY, largeRectWidth, largeRectHeight, ILI9341_WHITE);

  // Draw the "Loading..." text above the large rectangle
  tft.setTextSize(2);
  tft.setTextColor(ILI9341_WHITE);
  tft.setCursor(largeRectX + 20, largeRectY - 20);
  tft.print("Loading");

  // Animation parameters for the small rectangle (loading bar)
  int smallRectHeight = largeRectHeight - 10;

  // Loop for updating the loading bar animation
  for (int i = 0; i <= largeRectWidth - 20; ++i) {
    // Clear the previous small rectangle by drawing over it in black
    tft.fillRect(largeRectX + 10, largeRectY + 5, i, smallRectHeight, ILI9341_WHITE);

    // Draw the loading animation dots
    if (i % 40 == 0) {
      drawLoadingDots(largeRectX + 100, largeRectY - 20, i / 40);
    }
  }

  // After the loading bar animation is complete, clear the screen
  tft.fillScreen(ILI9341_BLACK); // Aici poti sa schimbi ecranul

  // Reset animation parameters for the next loop
}

// Function to draw the loading animation dots
void drawLoadingDots(int x, int y, int count) {
  tft.setTextSize(2);
  switch (count % 5) {
    case 0:
      tft.setTextColor(ILI9341_WHITE);
      tft.setCursor(x, y);
      tft.print("   ");
      break;
    case 1:
      tft.setTextColor(ILI9341_WHITE);
      tft.setCursor(x, y);
      tft.print(" .");
      break;
    case 2:
      tft.setTextColor(ILI9341_WHITE);
      tft.setCursor(x, y);
      tft.print(" . .");
      break;
    case 3:
      tft.setTextColor(ILI9341_WHITE);
      tft.setCursor(x, y);
      tft.print(" . . .");
      break;
    case 4:
      tft.setTextColor(ILI9341_BLACK);
      tft.setCursor(x, y);
      tft.print(" . . .");
      break;
  }
}
