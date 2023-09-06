import math
import numpy as np
import matplotlib.pyplot as plt

eta = 0.5
def shot_acc_update(base, made, miss):
  if(made+miss == 0):
    return base
  return base + eta * logistic((made+miss), offset=5) * ((made/(made+miss) - base))

def logistic(x, offset, l=1, k=1):
  return l/(1+math.exp(-k*(x-offset)))

def reality_rate(base, made, miss, is_made=False):
  rate = 1
  if(made + miss < 1):
    return rate
  
  if is_made:
    made_num = int(made)
    for mc in range(made_num):
      rate *= shot_acc_update(base=base, made=mc, miss=0)
    return rate
  
  miss_num = int(miss)
  for mc in range(miss_num):
    rate *= (1-shot_acc_update(base=base, made=0, miss=mc))
  return rate

shot_base = 0.4
misses = mades = np.arange(0,10.1,0.1)

shot_accuracies_miss = [shot_acc_update(base=shot_base, made=0, miss=miss) for miss in misses]
reality_miss = [reality_rate(base=shot_base, made=0, miss=miss) for miss in misses]
print(reality_miss[-1])

shot_accuracies_made = [shot_acc_update(base=shot_base, made=made, miss=0) for made in mades]
reality_made = [reality_rate(base=shot_base, made=made, miss=0, is_made=True) for made in mades]

fig = plt.figure()
ax1 = fig.add_subplot(2, 2, 1)
ax1.set_title("shot accuracy vs. misses in a row")
ax1.plot(misses, shot_accuracies_miss)
ax2 = fig.add_subplot(2, 2, 2)
ax2.set_title("reality rate")
ax2.plot(misses, reality_miss)
ax3 = fig.add_subplot(2, 2, 3)
ax3.set_title("shot accuracy vs. mades in a row")
ax3.plot(mades, shot_accuracies_made)
ax4 = fig.add_subplot(2, 2, 4)
ax4.set_title("reality rate")
ax4.plot(mades, reality_made)
plt.tight_layout()
plt.savefig("preparation/shot_acc.png")
plt.show()