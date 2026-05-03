n=int(input());t=list(map(int,input().split()))
s=sum(t)
ss=sum(i*i for i in t)
if s==0:
  print(0)
  exit()
def my_round_int(number):
    return int((number * 2 + 1) // 2)
def f(x):
  return n*x*x-2*s*x+ss
print(f(my_round_int(n/s)))