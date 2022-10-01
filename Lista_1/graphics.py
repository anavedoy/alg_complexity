import pandas as pd
from matplotlib import pyplot as plt

tempos = pd.read_csv('tempos_por_n.csv')
print(tempos)
tempos.plot()
plt.savefig('tempos_linear.png')