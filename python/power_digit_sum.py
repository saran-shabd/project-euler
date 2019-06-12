product = pow(2, 1000)
sum = 0
while product > 0:
    sum += product % 10
    product = product // 10
print(sum)
