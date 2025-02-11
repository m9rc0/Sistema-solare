import matplotlib.pyplot as plt
import numpy as np

ris = np.loadtxt('prova.txt', unpack = True)

plt.plot(ris, color = 'blue')
plt.grid()
plt.title('$|L-L_0|/|L0|$')
plt.savefig('momentoAngolare.png')
plt.show()

