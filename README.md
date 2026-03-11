# Impedance Analyzer with Arduino and PmodIA

This project implements an **impedance analyzer** capable of measuring and displaying the characteristics of circuits containing resistors and capacitors in series-parallel configurations. The system measures impedance in real-time and visualizes the results through a graphical interface.

---

## 📋 Project Overview

The impedance analyzer:

- Generates test signals and measures the response of electronic components across various frequencies.
- Calculates impedance magnitude (|Z|), real (R), and imaginary (I) components.
- Supports frequency sweeps with configurable start frequency, step increment, and number of steps.
- Displays results on two separate graphs: one for impedance magnitude and one for phase.
- Includes system calibration using a known reference resistance to calculate gain factors and phase.

---

## 🛠️ Hardware Components

- **Arduino UNO:** Main processing unit with 14 digital I/O pins and 6 analog inputs.  
- **PmodIA Module:** Impedance analysis module using the AD5933 IC for signal generation and response measurement.  
- **Adafruit 2.8" TFT Touch Shield:** High-resolution color touchscreen (240×320 pixels) for the graphical user interface.

---

## 📂 Software Structure

The software is divided into two main modules:

### 1. Graphical User Interface (GUI) Module
- **Files:** `user_interface.h`, `user_interface.cpp`, `Display.cpp`  
- **Functions:** Initialize TFT screen, set resolution and orientation, and define visual elements such as buttons, sliders, and graph axes.

### 2. Main Activity Module
- **Files:** `sketch_mar22a.ino`, `AD5933.h`, `AD5933.cpp`  
- **Logic:**
  - `setup()`: Configures the PmodIA module and initializes the GUI.
  - `loop()`: Collects data from the sensor, manages touch events, and updates the display.
  - `drawGraph()`: Renders collected data points into visual charts on the TFT screen.

---

## ⚙️ Configuration & Control

The system provides granular control over measurements:

- **Power Modes:** Power On, Standby, or Power Down  
- **Clock Source:** Internal or external clock selection  
- **PGA Gain:** Programmable Gain Amplifier settings to optimize signal strength

---

## 💻 Arduino Code

The full Arduino sketch and module files are located in arduino code.


