# Minnesota Earthquake Records Lookup Tool

A C program that stores a dataset of historical Minnesota earthquake records (city, date, magnitude, and intensity) and lets a user search the dataset by city name.

## Why I built it
This project was written to practice array-based data storage and to build a search algorithm from scratch, rather than relying on a built-in library function, by writing a custom string-comparison routine to match user input against stored records.

## What it does
- Stores earthquake records across parallel arrays (city, date, intensity, magnitude)
- Calculates an estimated damage cost from each record's magnitude
- Lets the user repeatedly search records by city name until they type "quit"
- Reports the average magnitude and average damage cost across all records

## How to run
```bash
gcc earthquake_lookup.c -o earthquake_lookup
./earthquake_lookup
```
