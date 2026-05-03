while(True):
    n=int(input())
    if n==0:
        exit()
    a=list(map(int,input().split()))
    l=sorted(a,key=lambda x: abs(x-2023))
    ans=l[0]
    for i in range(n):
        if a[i]==ans:
            print(i+1)
            break