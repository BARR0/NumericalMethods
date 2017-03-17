W = [
    25,
    25,
    28,
    29,
    29,
    28,
    27,

    23,
    23,
    24,
    26,
    26,
    25,
    23,

    23,
    25,
    25,
    22,
    24,
    22,
    24,

    26,
    27,
    26,
    25,
    27,
    27,
    26,

    23,
    25,
    23
]

print('Average')
s = 0
for i in W:
    s += i
avg = s/len(W)
print(avg)
print('Std Deviation')
si = 0
for i in W:
    si += (i - avg)**2
var = (si/len(W)-1)
stdd = var**(1/2)
print(stdd)
print('Varianza')
print(var)
print('Variation coeficient')
print(stdd/avg)
