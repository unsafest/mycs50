from cs50 import get_string


input = get_string("text: ")

letters = 0
words = 1
sentences = 0

for i in range(len(input)):
    if input[i].isalpha():
        letters += 1
    elif input[i].isspace():
        words += 1
    elif input[i] == "." or input[i] == "!" or input[i] == "?":
        sentences += 1

l = letters / words * 100
s = sentences / words * 100
grade = round(0.0588 * l - 0.296 * s - 15.8)

if grade < 1:
    print("Before Grade 1")
elif grade > 16:
    print("Grade 16+")
else:
    print(f"Grade {grade}")
