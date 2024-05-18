class SliderBox {
public:
  int x, y, width, height;
  int color;
  int value;
  int position;
  int old_position;
  int minValue;
  int maxValue;
  const char* label;
  void (*on_value_changed)(int current_value) = nullptr;
  SliderBox(int x, int y, int width, int height, int color, int minValue, int maxValue, const char* label, void (*callback)(int current_value) = print_value)
    : x(x), y(y), width(width), height(height), color(color), value(minValue), position(y + height), on_value_changed(callback), old_position(y + height), minValue(minValue), maxValue(maxValue), label(label) {}

  void draw() {
    // Draw the slider line
    tft.drawFastVLine(x, y, height, ILI9341_WHITE);

    // Draw the initial value box
    drawValueBox();

    // Draw the initial slider position
    tft.drawFastHLine(x - 20, position, 40, ILI9341_WHITE);
  }

  void update(int touch_x, int touch_y) {
    if (touch_x > x - 20 && touch_x < x + 20 && touch_y > y && touch_y < y + height) {

      value = map(touch_y, y + height, y, minValue, maxValue);
      old_position = position;
      position = touch_y;

      float sliderPercentage = (float)(position - y) / height;
      float valueRange = maxValue - minValue;
      float sliderValue = valueRange * sliderPercentage;
      float absolut_value = minValue + sliderValue;
      on_value_changed(maxValue-absolut_value);
      // Black out the old slider position without erasing the vertical line
      tft.drawFastHLine(x - 20, old_position, 40, ILI9341_BLACK);
      tft.drawPixel(x, old_position, ILI9341_WHITE);  // Ensure the vertical line is redrawn

      // Draw the new slider position
      tft.drawFastHLine(x - 20, position, 40, ILI9341_WHITE);

      // Update the value box
      drawValueBox();
    }
  }

  void drawValueBox() {
    // Clear the previous value and label
    tft.fillRect(x - 20, y - 60, 40, 50, ILI9341_BLACK);
    tft.drawRect(x - 20, y - 40, 40, 30, ILI9341_WHITE);

    // Draw the label
    tft.setCursor(x - 15, y - 55);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(1);
    tft.print(label);

    // Draw the new value
    tft.setCursor(x - 15, y - 35);
    tft.setTextColor(color);
    tft.setTextSize(2);
    tft.print(value);
  }
};
void loop() {
  // See if there's any touch data for us
  if (ts.bufferEmpty()) {
    return;
  }

  // Retrieve a point
  TS_Point p = ts.getPoint();

  // Scale from ~0->4000 to tft.width using the calibration #'s
  p.x = map(p.x, TS_MINX, TS_MAXX, 0, tft.width());
  p.y = map(p.y, TS_MINY, TS_MAXY, 0, tft.height());

  // Update sliders
  redSlider.update(p.x, p.y);
  greenSlider.update(p.x, p.y);
  blueSlider.update(p.x, p.y);
}

