mahJSON = {'name': 'score', 'min': 0, 'max': 10, 'judgeCount': 3}

for key in reversed(sorted(mahJSON)):
  print key, mahJSON[key]

#Output:
  #name score
  #min 0
  #max 10
  #judgeCount 3


dict([('sape', 4139), ('guido', 4127), ('jack', 4098)])
#Output: {'sape': 4139, 'jack': 4098, 'guido': 4127}

dict(sape=4139, guido=4127, jack=4098)
#Output: {'sape': 4139, 'jack': 4098, 'guido': 4127}
