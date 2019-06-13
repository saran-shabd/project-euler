num = int(input())

arr = [[0 for i in range(num+1)] for j in range(num+1)]

for i in range(num):
    arr[i][num] = 1
    arr[num][i] = 1

for i in range(num-1, -1, -1):
    for j in range(num-1, -1, -1):
        arr[i][j] = arr[i+1][j] + arr[i][j+1]

print(arr[0][0])
