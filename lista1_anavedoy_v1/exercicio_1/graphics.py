import pandas as pd
from matplotlib import pyplot as plt

tempos = pd.read_csv('tempos_por_n.csv')
tempos.plot()
plt.savefig('tempos_comparacao.png')