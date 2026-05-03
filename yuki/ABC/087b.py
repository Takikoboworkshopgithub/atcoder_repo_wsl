A=int(input())
B=int(input())
C=int(input())
X=int(input())
count=0
for i in range(0,A+1):
  for j in range(0,B+1):
    for k in range(0,C+1):
      #iは500円玉の枚数、jは100円玉の枚数、kは50円玉の枚数
      print(i,j,k,500*i+100*j+50*k)