import math
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import os

def main():
  dataframes = []
  dirname = "Result/one_ace/mamba=0.300000"

  where = 3
  
  for curDir, dirs, files in os.walk(dirname):
    for file in files:
      filename = f"{dirname}/{file}"
      dataframes.append(pd.read_csv(filename))
  
  fig = plt.figure()
  ax1 = fig.add_subplot(3, 1, 1)
  ax1.set_title("score")
  ax1.plot(dataframes[where]["poss"], dataframes[where]["score"])
  ax2 = fig.add_subplot(3, 1, 3)
  ax2.set_title("mental track")
  line, = ax2.plot(dataframes[where]["poss"], dataframes[where]["mental1"], color="#ff6347", label="mamba", linestyle="--")
  handles = [line]
  for column in ["mental2", "mental3", "mental4", "mental5"]:
    line, = ax2.plot(dataframes[where]["poss"], dataframes[where][column], label='other',color="#d3d3d3", linestyle="--")
    handles.append(line)
  ax2.legend(handles, ["mamba", "other"])
  
  ax3 = fig.add_subplot(3, 1, 2)
  ax3.set_title("shot accuracy track")
  line, = ax3.plot(dataframes[where]["poss"], dataframes[where]["shot_acc1"], color="#ff6347", label="mamba")
  handles = [line]
  for column in ["shot_acc2", "shot_acc3", "shot_acc4", "shot_acc5"]:
    line, = ax3.plot(dataframes[where]["poss"], dataframes[where][column], label='other',color="#d3d3d3")
    handles.append(line)
  ax3.legend(handles, ["mamba", "other"])
  plt.tight_layout()
  plt.show()

if __name__ == "__main__":
  main()