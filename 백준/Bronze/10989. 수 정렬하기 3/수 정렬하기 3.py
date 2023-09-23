import sys
num = int(input())
a = [0] * 10001

for _ in range(num):
  n = int(sys.stdin.readline())
  a[n] += 1

for i in range(10001):
  if a[i] != 0:
    for _ in range(a[i]):
      print(i)
