n=int(input())
a=list(map(int,input().split()))
k=int(input())
count=0
for i in range(n):
  if k<=a[i]:
    count+=1
print(count)