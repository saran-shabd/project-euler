
def isLeapYear(year):
    if 0 == year % 4:
        if 0 == year % 100:
            if 0 == year % 400:
                return True
            else:
                return False
        else:
            return True
    else:
        return False


count = 0
totalDays = 365
if isLeapYear(1900):
    totalDays += 1

thirties = {4, 6, 9, 11}  # months that have 30 days

for year in range(1901, 2001):
    for month in range(1, 13):
        if 6 == totalDays % 7:  # check 'Sunday' condition
            count += 1

        # increment totalDays according to current month
        if 2 == month:
            totalDays += 28
            if isLeapYear(year):
                totalDays += 1
        elif month in thirties:
            totalDays += 30
        else:
            totalDays += 31

print(count)
