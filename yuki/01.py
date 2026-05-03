#１かaまでの総和を求めたい
a=int(input())
sum=0
for i in range(1,a+1):
  #i=1
  #i=2
  #i=3
  sum=sum+i
print(sum)
if a==1:
  print("aは一です")