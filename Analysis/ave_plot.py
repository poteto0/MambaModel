import math
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import os

dataframes = []

def calc_ave(key):
  global dataframes

  sum_val = [0 for i in range(len(dataframes[0]["poss"]))]
  for df in dataframes:
    sum_val += df[key].values
  
  return sum_val / len(dataframes)

def calc_std(key):
  global dataframes

  aves = calc_ave(key)
  sum_val = [0 for i in range(len(dataframes[0]["poss"]))]
  for df in dataframes:
    sum_val += np.array(df[key].values - aves)**2
  
  sum_val = sum_val / len(dataframes)
  return np.sqrt(sum_val)

handles = []
def plot(ax, key, color, handle=False, ls="-"):
  global handles

  poss_list = dataframes[0]["poss"].values

  means, stds = calc_ave(key), calc_std(key)
  
  line, = ax.plot(poss_list, means, color=color, linestyle=ls)
  ax.fill_between(poss_list, means + stds, means - stds, alpha=0.2, color=color)
  if handle:
    handles.append(line)


def main():
  global handles

  dirname = "Result/one_ace/mamba=0.900000"

  for curDir, dirs, files in os.walk(dirname):
    for file in files:
      filename = f"{dirname}/{file}"
      dataframes.append(pd.read_csv(filename))
  
  score_aves, score_stds = calc_ave("score"), calc_std("score")
  print(f"スコア平均: {score_aves[-1]}, ± {score_stds[-1]}")

  fig = plt.figure()
  ax1 = fig.add_subplot(4, 1, 1)
  ax1.set_title("score")
  plot(ax1, "score", '#1e90ff')

  ax2 = fig.add_subplot(4, 1, 2)
  ax2.set_title("shot accuracy track")
  plot(ax2, "shot_acc1", '#ff6347', handle=True)
  for column in ["shot_acc2", "shot_acc3", "shot_acc4", "shot_acc5"]:
    plot(ax2, column, '#d3d3d3', handle=True)
  ax2.legend(handles, ["mamba", "other"])

  handles = []

  ax3 = fig.add_subplot(4, 1, 3)
  ax3.set_title("mental track")
  plot(ax3, "mental1", '#ff6347', handle=True, ls="--")
  for column in ["mental2", "mental3", "mental4", "mental5"]:
    plot(ax3, column, '#d3d3d3', handle=True, ls="--")
  ax3.legend(handles, ["mamba", "other"])

  handles = []
  ax4 = fig.add_subplot(4, 1, 4)
  ax4.set_title("ace shot take track")
  plot(ax4, "made1", '#00ff7f', handle=True, ls="-.")
  plot(ax4, "miss1", '#8fbc8f', handle=True, ls="-.")
  ax4.legend(handles, ["made", "miss"])

  plt.tight_layout()
  plt.show()

if __name__ == "__main__":
  main()