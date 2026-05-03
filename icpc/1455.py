n = int(input())

d = list(map(int,input().split()))
b = [-1] * n
ans = 0
i = 0
while i < n:
  j = i
  while j < n and d[i] <= d[j]:
    if b[j] != -1:
      ans += 1
      break
    if d[i] == d[j]:
      b[j] = 1
      #print(j)
    j += 1
  i += 1
print(ans)