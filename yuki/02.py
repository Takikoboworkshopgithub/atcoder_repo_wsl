#3の倍数だったらfizz,5の倍数だったらbuzz,3の倍数かつ5の倍数だったらfizzbuzzというコード
a=int(input())
if a%3==0 and a%5==0:
  print("fizzbuzz")
else:
  if a%3==0:
    print("fizz")
  else:
    if a%5==0:
      print("buzz")
    else:
      print("gomi")
#elseは上の条件に当てはまらないときに使う文
"""
if a%6==0:
  print("a,"は六の倍数"")
else:

"""