#!/usr/bin/python3

def base_for():
    fruits = [dict(name='banana'), dict(name='apple'), dict(name='mango')]
    for fruit in fruits:
        print(str(fruit))

def newNumeralSystem(number):
    S = ('A', 'B', 'C', 'D', 'E', 'F', 'G',
         'H', 'I', 'J', 'K', 'L', 'M', 'N',
         'O', 'P', 'Q', 'R', 'S', 'T', 'U',
         'V', 'W', 'X', 'Y', 'Z')
    O = []
    number_int = 0
    for i in range(0, 26):
        if S[i] == number:
            number_int = i
            break

    print(number_int)
    if number_int < 0:
        return
    else:
        for i in range(0, int(number_int/2) + 1):
            O.append(S[i] + " + " + S[number_int-i])
    return O

if __name__ == "__main__":
    base_for()
    print(newNumeralSystem('G'))

