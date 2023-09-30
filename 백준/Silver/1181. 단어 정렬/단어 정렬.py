#[BOJ] 백준 파이썬 1181번 단어 정렬
n = int(input())
dic = [input() for i in range(n)]
# 단어 중복 -> 한번만 출력
dic= list(set(dic))
# 1. 길이가 짧은 것부터 2. 사전순
dic = sorted(dic, key = lambda x:(len(x),x))
for i in dic:print(i)