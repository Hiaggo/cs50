from sys import argv
from cs50 import SQL
import csv

if len(argv) != 2:
    print("Missing command-line argument!")  # Checks if the user wrote the names of the two input files
    exit(1)

database = argv[1]  # Gets the name of the database

db = SQL("sqlite:///students.db")  # Sets the database

with open(database, "r") as data:
    data_reader = csv.DictReader(data)  # Creates a dictionary

    for row in data_reader:
        names = list(row["name"].split())
        if len(row["name"].split()) > 2:  # Checks if there is a middle name or not
            db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                       names[0], names[1], names[2], row["house"], row["birth"])

        else:
            db.execute("INSERT INTO students (first, last, house, birth) VALUES(?, ?, ?, ?)",
                       names[0], names[1], row["house"], row["birth"])