# Student Average Calculator

A C program that reads a series of student grades from user input, validates each entry falls within a 0-100 range, and calculates the class average.

## Why I built it
This project was written to practice loop-controlled input handling and input validation in C, ensuring the program rejects out-of-range values before they can affect a calculation. Input validation is a foundational habit for writing reliable, defensive code.

## What it does
- Continuously prompts for grades until the user enters -1
- Rejects any grade over 100 and re-prompts
- Calculates and prints the class average once input ends

## How to run
```bash
gcc average_calculator.c -o average_calculator
./average_calculator
```
