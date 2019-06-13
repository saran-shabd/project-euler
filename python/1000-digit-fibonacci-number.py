from math import sqrt, ceil, log10

# using binet's formula for finding nth fibonacci number

# solution source = 'https://blog.dreamshire.com/project-euler-25-solution/'

golden_ration = (1 + sqrt(5)) / 2

digits = int(input())

term = ceil((log10(5)/2 + digits - 1) / log10(golden_ration))
print(int(term))
