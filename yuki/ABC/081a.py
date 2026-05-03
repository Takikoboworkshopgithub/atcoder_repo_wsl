n=int(input())
a=list(map(int,input().split()))
minimum=10000000000000000000
for i in range(0,n):
  number=a[i]
  count=0
  while(number%2==0):
    number=number//2
    count+=1
  if minimum>count:
    minimum=count
print(minimum)