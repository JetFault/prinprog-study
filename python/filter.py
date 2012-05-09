def isEven (x):
  return (x%2 == 0)

nums = range(0,15)

print filter(isEven, nums)

#Output: 
  #[0, 2, 4, 6, 8, 10, 12, 14]
