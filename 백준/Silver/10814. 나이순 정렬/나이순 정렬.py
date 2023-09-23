number = int(input())
box = []
for i in range(number):
  box.append(list(input().split()))
box.sort(key = lambda x : int(x[0]))
for i in box:
  print(i[0], i[1])