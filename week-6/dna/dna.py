import csv
import sys


def main():
    # Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py <database.csv> <sequence.txt>")
        sys.exit(1)

    # Read database file into a variable
    database = []
    with open(sys.argv[1], 'r') as file:
        reader = csv.DictReader(file)
        for row in reader:
            database.append(row)

    # Read DNA sequence file into a variable
    with open(sys.argv[2], 'r') as file:
        dna_sequence = file.read().strip()

    # Find longest match of each STR in DNA sequence
    subsequences = list(database[0].keys())[1:]
    result = {subseq: longest_match(dna_sequence, subseq) for subseq in subsequences}

    # Check database for matching profiles
    for person in database:
        if all(int(person[subseq]) == result[subseq] for subseq in subsequences):
            print(person["name"])
            return

    print("No match")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""
    longest_run = 0
    subseq_len = len(subsequence)
    seq_len = len(sequence)

    for i in range(seq_len):
        count = 0
        while sequence[i + count * subseq_len:i + (count + 1) * subseq_len] == subsequence:
            count += 1
        longest_run = max(longest_run, count)

    return longest_run


if __name__ == "__main__":
    main()
