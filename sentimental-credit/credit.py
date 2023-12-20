from cs50 import get_int

cc = 0
while cc < 1:
    cc = get_int("Number: ")

# reverse string
temp = str(cc)[::-1]
luhnsum = 0
for i, digit in enumerate(temp):
    # every other digit
    if i % 2 == 0:
        luhnsum += int(digit)
    else:
        doubled = int(digit) * 2
        if doubled < 10:
            luhnsum += doubled
        else:
            luhnsum += doubled - 9


if luhnsum % 10 == 0:
    if len(str(cc)) in [13, 16] and str(cc)[0] == "4":
        print("VISA")
    elif len(str(cc)) == 15 and str(cc)[:2] in ["34", "37"]:
        print("AMEX")
    elif len(str(cc)) == 16 and 50 < int(str(cc)[:2]) < 56:
        print("MASTERCARD")
    else:
        print("INVALID")
else:
    print("INVALID")
