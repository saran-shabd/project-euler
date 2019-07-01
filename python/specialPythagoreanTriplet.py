from math import floor

'''
    Hint: Solve the given equations
'''

for a in range(2, floor(1000/3)):
    num = 1000 * (1000 - 2 * a)
    denum = 2 * (1000 - a)
    if 0 == num % denum:
        print(int(a * (num/denum) * (1000 - a - (num / denum))))
        break
