from sys import argv, exit
from csv import reader, DictReader


def main():
    # ensure correct number of arguments
    if len(argv) < 3:
        print("Usage: python dna.py data.csv sequence.txt")
        exit()
    # read data.csv file
    with open(argv[1]) as database:
        db = reader(database)
        # create a list of STRs listed in first row, from second element onwards (first is name)
        all_STR = next(db)[1:]
    # read sequence.txt file
        with open(argv[2], 'r') as sequence:
            dna = sequence.read()
            # get the max number of STRs in dna from txt file using input of sequence.txt and each STR
            number_STR = [max_no_of_substring(dna, STR) for STR in all_STR]
        # match to person in database and provide name if any using input of database.csv and max no of STRs
        print_match(db, number_STR)


def max_no_of_substring(dna, STR):
    maxim = i = 0
    j = len(STR)
    
    for x in range(len(dna)):
        # if segment of dna matches STR
        if dna[i:j] == STR:
            # create temporary counter of number of times STR repeats
            temp = 0
            
            # count number of times
            while dna[i:j] == STR:
                temp += 1
                i += len(STR)
                j += len(STR)
            
            # update maximum number
            if temp > maxim:
                maxim = temp
        # if no match, move onto next base
        else:
            i += 1
            j += 1
    # output maximum number of times STR repeated for that STR
    return maxim

    
def print_match(db, number_STR):
    # loop over rows in database.csv file
    for row in db:
        # name is first element in each row
        name = row[0]
        # create list of integers for each person unique number of STRs
        person_STR = [int(val) for val in row[1:]]
        
        # if match
        if person_STR == number_STR:
            print(name)
            return
    # if STRs in sequences do not match anyone in all rows of database
    print("No match")


main()