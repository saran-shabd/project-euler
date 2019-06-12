import time


c_lengths = {}


def collatz_length(n):
    if 1 == n:
        return 1

    if not n in c_lengths:
        num_length = 1
        num = n
        while num != 1:
            num_length += 1
            if 0 == num % 2:
                return collatz_length(num // 2) + 1
            else:
                return collatz_length(3*num + 1) + 1

        c_lengths[n] = num_length

    return c_lengths[n]


max_length = 0
max_num = 0

start = time.time()

for i in range(2, 1000000):
    length = collatz_length(i)
    print(f'{i} : {length}')
    if length > max_length:
        max_length = length
        max_num = i

end = time.time() - start

print('\n\n\n')
print(f'{max_num} : {max_length}')

print(f'total time taken = {end} seconds')
