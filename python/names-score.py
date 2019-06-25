names = []
with open('p022_names.txt', 'r') as file:
    plain_txt = file.read()[1: -1]
    names = str(plain_txt).split('","')

names.sort()

scores = [0 for i in range(len(names))]

for i in range(len(names)):
    curr_score = 0
    for j in range(len(names[i])):
        curr_score += ord(names[i][j]) - ord('A') + 1
    scores[i] = curr_score

for i in range(len(scores)):
    scores[i] *= (i + 1)

print(sum(scores))
