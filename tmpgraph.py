import math
import matplotlib.pyplot as plt
import numpy as np

x = [
    1,
    2,
    3,
    4,
    5,
    6,
    7,
    8,
    9,
    10
]

y = [
    5,
    10,
    18,
    28,
    40,
    56,
    70,
    95,
    110,
    140,
]

# x = [
#     10.2,
#     11.4,
#     11.5,
#     12.5,
#     13.1,
#     13.4,
#     13.6,
#     15,
#     15.2,
#     15.3,
#     15.6,
#     16.4,
#     16.5,
#     17,
#     17.1
# ]

# y = [
#     69.81,
#     82.75,
#     81.75,
#     80.38,
#     85.89,
#     75.32,
#     69.81,
#     78.54,
#     81.29,
#     99.2,
#     86.35,
#     110.23,
#     106.55,
#     85.5,
#     90.02
# ]

t = np.arange(min(x) - 1, max(x) + 1, 0.01)
s1 = -24.2 + 14.8*t
s2 = 2.38333 + 1.50833*t + 1.20833*t**2
s3 = 1.03333 + 2.70571*t + 0.948718*t**2 + 0.0157343*t**3
s4 = 4.58333 + -1.84557*t + 2.61407*t**2 + -0.21183*t**3 + 0.0103438*t**4

plt.plot(x, y, 'ro', label = 'Datos originales')
plt.plot(t, s1, label = 'Grado 1')
plt.plot(t, s2, label = 'Grado 2')
plt.plot(t, s3, label = 'Grado 3')
plt.plot(t, s4, label = 'Grado 4')

plt.xlabel('Diferencia de Temperatura (ºC)')
plt.ylabel('Consumo (kWh)')
plt.title('Problema 4-13')
plt.grid(True)
plt.savefig("test.png")
plt.legend()
plt.show()
