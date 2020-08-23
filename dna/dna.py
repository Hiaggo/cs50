from sys import argv
import csv
import re


# Function that returns the size of the sequence of the STR

def count(STR, s):  # Part of the code found at https://www.reddit.com/r/cs50/comments/gj60hb/pset6_dna_python_spoiler_complete_code/
    p = rf'({STR})\1*'
    pattern = re.compile(p)
    match = [match for match in pattern.finditer(s)]
    max = 0
    for i in range(len(match)):
        if match[i].group().count(STR) > max:
            max = match[i].group().count(STR)
    return str(max)


if len(argv) != 3:
    print("Missing command-line argument!")  # Checks if the user wrote the names of the two input files
    exit(1)

database = argv[1]  # Gets the name of the database of people
sequence = argv[2]  # Gets the name of the database of sequences
data_ppl = [[]]*50


# Opens the file that contains the list of individuals

with open(database, "r") as file_data:
    data_reader = csv.reader(file_data, delimiter=',')
    line = 0
    for row in data_reader:
        if line == 0:  # Gets the STRs and stores it in a list
            data_seq = list(row)
            line += 1
        else:  # Gets the individuals data and stores it in a list
            data_ppl[line - 1] = list(row)
            line += 1

# Opens the file that contains the sequence to identify

with open(sequence, "r") as file_seq:
    seq_reader = file_seq.readline().rstrip("\n")  # Saves the sequence of DNA to identify

# Calls 'count' to each of the STRs that are common between both databases

agatc = count("AGATC", seq_reader)
aatg = count("AATG", seq_reader)
tatc = count("TATC", seq_reader)

if database == "databases/small.csv":
    for i in range(line - 1):
        if (data_ppl[i][1] == str(agatc) and data_ppl[i][2] == str(aatg) and data_ppl[i][3] == str(tatc)):
            name = data_ppl[i][0]
            break
        else:
            name = "No match"

else:

    # Calls 'count' to each of the STRs that are only in the large database

    ttttttct = count("TTTTTTCT", seq_reader)
    tctag = count("TCTAG", seq_reader)
    gata = count("GATA", seq_reader)
    gaaa = count("GAAA", seq_reader)
    tctg = count("TCTG", seq_reader)

    for i in range(line - 1):
        if (data_ppl[i][1] == str(agatc) and data_ppl[i][2] == str(ttttttct) and data_ppl[i][3] == str(aatg) and data_ppl[i][4] == str(tctag) and data_ppl[i][5] == str(gata) and data_ppl[i][6] == str(tatc) and data_ppl[i][7] == str(gaaa) and data_ppl[i][8] == str(tctg)):
            name = data_ppl[i][0]
            break
        else:
            name = "No match"

print(name)
