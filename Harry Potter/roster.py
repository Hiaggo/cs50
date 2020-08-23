from sys import argv
from cs50 import SQL
import csv

if len(argv) != 2:
    print("Missing command-line argument!")  # Checks if the user wrote the names of the two input files
    exit(1)

house = argv[1]  # Gets the house name of the students the user is looking for

db = SQL("sqlite:///students.db")  # Sets the database

# Selects all the data in the correct order
students = db.execute("SELECT first, middle, last, birth FROM students WHERE house = ? ORDER BY last ASC, first ASC;", house)

for row in students:
    if row["middle"] is None:  # Checks if the middle name is NULL or else
        print(f"{row['first']} {row['last']}, born  {row['birth']}")

    else:
        print(f"{row['first']} {row['middle']} {row['last']}, born {row['birth']}")