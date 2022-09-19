from cs50 import get_string

# get input
text = get_string("Text: ")

# letter sentence and word count
letters = sentences = words = i = 0

# count letters, sentences and words
while i in range(len(text)):
    if text[i].isalpha():
        letters += 1
    elif text[i] == " ":
        words += 1
    elif text[i] == '.' or text[i] == '?' or text[i] == '!':
        sentences += 1
    i += 1

# adding first word
words += 1
    
# getting average number of letters per 100 words
L = (letters / words * 100)
    
# getting average number of sentences per 100 words
S = (sentences / words * 100)

# getting index
index = round((0.0588 * L) - (0.296 * S) - 15.8)

# print grade
if index <= 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")