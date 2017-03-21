import matplotlib.pyplot as plt
import numpy as np

def fQT(QT):
    return (170 - (1.6 * (10 ** -6) * (QT ** 2)))

def KW1(Q1, QT):
    return (-18.89 + (0.1277 * Q1) - (4.08 * (10 ** -5) * (Q1 ** 2))) * (fQT(QT))

def KW2(Q2, QT):
    return (-24.51 + (0.1358 * Q2) - (4.69 * (10 ** -5) * (Q2 ** 2))) * (fQT(QT))

def KW3(Q3, QT):
    return (-27.02 + (0.1380 * Q3) - (3.84 * (10 ** -5) * (Q3 ** 2))) * (fQT(QT))

def Q1(QT):
    return (QT / 2.93243) - 75.1827

def Q2(QT):
    return (QT / 3.3708) + 20.94978

def Q3(QT):
    return (QT / 2.7599) + 54.2329

def KWT(QT):
    return KW1(Q1(QT), QT) + KW2(Q2(QT), QT) + KW3(Q3(QT), QT)

QTmin = 250
QTmin2 = 953.5755
QTmax = 3231.2001
KW = []
KWT1 = []
KWT2 = []
KWT3 = []

for qt in range(int(QTmin), int(QTmax)):
    KW.append(KWT(qt))
    KWT1.append(KW1(qt, qt))
    KWT2.append(KW2(qt, qt))
    KWT3.append(KW3(qt, qt))


plt.plot(range(int(QTmin), int(QTmax)), KW, label = '3 turbinas')
plt.plot(range(int(QTmin), int(QTmax)), KWT1, label = 'turbina 1')
plt.plot(range(int(QTmin), int(QTmax)), KWT2, label = 'turbina 2')
plt.plot(range(int(QTmin), int(QTmax)), KWT3, label = 'turbina 3')

plt.xlabel('QT')
plt.ylabel('KW')
plt.title('4.-')
plt.grid(True)
plt.savefig("test.png")
plt.legend()
plt.show()
