import math

a = float(raw_input())
if a < 1.0:
    print a * math.sqrt(2.0)
else :
    x = 0.0
    ans = 0.0
    while x <= a:
         y = math.sqrt(a * a - x * x)
         ans = max(ans, x + y)
         x += 1.0
    x = 1.0
    while x <= a:
        if a * a - x * x < 1:
            y = math.sqrt(a * a - x * x)
            ans = max(x + 1, ans)
        x += 1.0
    ans = max(ans, a * math.sqrt(2.0))
    print ans


