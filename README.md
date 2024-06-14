# Microcontroller Adder Project

This repository contains the source code for a microcontroller-based 4-bit adder, originally developed by Glauber Kiss de Souza for the SENAC NH course.

## Project Overview

This project is designed to run on an Arduino microcontroller. It performs bitwise addition of two 4-bit numbers and outputs the result along with the carry bit. The addition operation is controlled via an external signal.

## Table of Contents

- [Introduction](#introduction)
- [Hardware Setup](#hardware-setup)
- [Software Setup](#software-setup)
- [Code Explanation](#code-explanation)
- [How to Use](#how-to-use)
- [Acknowledgments](#acknowledgments)

## Introduction

The primary goal of this project is to demonstrate basic digital arithmetic operations using a microcontroller. The program reads two 4-bit numbers from input pins, performs an addition operation, and outputs the result to designated output pins. The addition is controlled by a "soma" signal.

## Hardware Setup

To set up the hardware, you will need an Arduino microcontroller and the following connections:

- **Input Pins for First 4-bit Number**: Pins 0, 1, 2, 3
- **Input Pins for Second 4-bit Number**: Pins 4, 5, 6, 7
- **Output Pins for Result**: Pins 8, 9, 10, 11
- **Output Pin for Carry Bit**: Pin 12
- **Input Pin for Soma Signal**: Pin 13

## Software Setup

1. Install the Arduino IDE from the [official website](https://www.arduino.cc/en/software).
2. Open the Arduino IDE and create a new project.
3. Copy and paste the provided code into the new project.

## Code Explanation

### Variables

- `somaPin`: Input pin for the 'soma' signal.
- `carryBit`: Variable to store the carry bit.
- `nib1a, nib1b, nib1c, nib1d`: Variables for the first 4-bit number.
- `nib2a, nib2b, nib2c, nib2d`: Variables for the second 4-bit number.
- `res1a, res1b, res1c, res1d`: Variables to store the result bits.

### Setup Function

The `setup()` function initializes the pins for input and output.

### Helper Functions

- `somaBit(int b1a, int b2a, int cBit)`: Calculates the sum bit of two bits with the carry-in.
- `somaCarryBit(int b1a, int b2a, int cBit)`: Calculates the carry-out of two bits with the carry-in.

### Main Loop

The `loop()` function reads the input bits and performs bitwise addition when the soma signal is active. It updates the result and carry bits and writes them to the output pins.

## How to Use

1. Connect the hardware as described in the Hardware Setup section.
2. Upload the code to your Arduino microcontroller.
3. Use external switches or sensors to provide the 4-bit numbers and soma signal.
4. Observe the result on the output pins.

## Acknowledgments

Original creator: Glauber Kiss de Souza  
Editor and Enhancer: Vítor Luciano Cardoso Noé
Course: Técnico em Desenvolvimento de Sistemas - SENAC NH  
Discipline: Tecníco de Desenvolvimento de Sistemas Bilingue
