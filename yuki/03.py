#1から100までの中の数で、fizzbuzz問題を解く
for I in range(1,100+1):
  if I%3==0 and I%5==0:
    print(I,"fizzbuzz")
  else:
    if I%3==0:
      print(I,"fizz")
    else:
      if I%5==0:
        print(I,"buzz")
for i in range(1,101):
  if i%3==0 and i%5==0:
    print(i,"fizzbuzz")
  elif i%3==0:
    print(i,"fizz")
  elif i%5==0:
    print(i,"buzz")