import math
import numpy as np
import matplotlib.pyplot as plt

eta = 0.1
def mental_function(mental, mamba):
  next_mt = mental - eta*(1 - mamba)
  return next_mt if (next_mt) > 0 else 0

mt1, mt2 = 1, 1
mt1s, mt2s = [1], [1]
for p in range(20):
  mt1 = mental_function(mt1, mamba=0.9)
  mt2 = mental_function(mt2, mamba=0.5)

  mt1s.append(mt1)
  mt2s.append(mt2)

plt.plot(range(21), mt1s, label="mamba = 0.9")
plt.plot(range(21), mt2s, label="mamba = 0.3")
plt.legend()
plt.show()