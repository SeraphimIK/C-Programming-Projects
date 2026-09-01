# Student-Course-Schedule Management System

A C program that uses structs to model Student and Course records and a union to model Schedule data, then joins them by matching ID keys to generate a transcript report.

## Why I built it
This project was written to practice structs and unions in C, and to understand how related records can be linked together by a shared key, similar to how tables are joined in a relational database.

## What it does
- Defines `Student` and `Course` structs and a `Schedule` union
- Stores a small set of student, course, and schedule records
- Matches schedule entries to the correct student and course by ID
- Prints a formatted transcript report combining data from all three sources

## How to run
```bash
gcc schedule_system.c -o schedule_system
./schedule_system
```
