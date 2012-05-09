def isEven (x):
  return (x%2 == 0)

nums = range(0,15)

print filter(isEven, nums)
