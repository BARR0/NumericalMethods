import matplotlib.pyplot as plt
import numpy as np

x = [
    10.2,
    11.4,
    11.5,
    12.5,
    13.1,
    13.4,
    13.6,
    15,
    15.2,
    15.3,
    15.6,
    16.4,
    16.5,
    17,
    17.1
]

y = [
    69.81,
    82.75,
    81.75,
    80.38,
    85.89,
    75.32,
    69.81,
    78.54,
    81.29,
    99.2,
    86.35,
    110.23,
    106.55,
    85.5,
    90.02
]

t = np.arange(min(x), max(x), 0.01)
s = 37.1618 + 3.39553*t

plt.plot(x, y, 'ro', label = 'Datos originales')
# plt.plot(t, s, label = 'Regresión')

plt.xlabel('Diferencia de Temperatura (ºC)')
plt.ylabel('Consumo (kWh)')
plt.title('Problema 4-13')
plt.grid(True)
plt.savefig("test.png")
plt.legend()
plt.show()
