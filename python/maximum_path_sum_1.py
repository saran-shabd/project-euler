
# read data from input file
arr = []
with open('in.txt', 'r') as file:
    for line in file:
        temp = list(map(lambda x: int(x), line.replace('\n', '').split(' ')))
        arr.append(temp)


def max_path_sum(stack, sum=0, max_sum=0):
    curr = stack[-1]

    sum += arr[curr[0]][curr[1]]
    if sum > max_sum:
        max_sum = sum

    if curr[0] == len(arr) - 1:
        return max_sum

    stack.append((curr[0] + 1, curr[1]))
    max_sum = max(max_sum, max_path_sum(stack, sum, max_sum))
    stack.pop()

    stack.append((curr[0] + 1, curr[1] + 1))
    max_sum = max(max_sum, max_path_sum(stack, sum, max_sum))
    stack.pop()

    return max_sum


stack = []
stack.append((0, 0))
max_sum = max_path_sum(stack)

print(max_sum)
