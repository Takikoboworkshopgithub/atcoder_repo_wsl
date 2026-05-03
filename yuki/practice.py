#aからbまでの中で、偶数だけを出力してください
a=int(input())
b=int(input())
for i in range(a,1+b):
  if i%2==0 and i%3==0:
    print(i,"は6の倍数")