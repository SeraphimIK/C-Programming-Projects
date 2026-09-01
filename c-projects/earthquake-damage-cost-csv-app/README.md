# Earthquake Damage Cost App (CSV File Handling)

A C program that reads real USGS earthquake CSV datasets, parses each record, and calculates an estimated damage cost from the magnitude, along with summary statistics across the dataset.

## Why I built it
This project was written to practice file I/O and parsing real-world CSV data in C: reading a file line by line, tokenizing fields with `strtok`, handling messy data (quoted fields containing commas, missing values), and validating input before using it in a calculation.

## What it does
- Lets the user choose between two USGS datasets (all earthquakes or significant-only)
- Parses each CSV row for time, magnitude, and place, safely handling quoted place names that contain commas
- Calculates an estimated damage cost per record using the formula `magnitude^3 x 1,000,000`
- Reports summary statistics: total, average, minimum, and maximum magnitude and cost across the dataset

## Data source
Expects a USGS earthquake CSV file (`all_month.csv` or `significant_month.csv`) in the same directory. Live feeds are available at https://earthquake.usgs.gov/earthquakes/feed/v1.0/csv.php

## How to run
```bash
gcc earthquake_damage_cost.c -o earthquake_damage_cost -lm
./earthquake_damage_cost
```
