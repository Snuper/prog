import matplotlib.pyplot as plt
import numpy as np
from matplotlib.ticker import MultipleLocator, FormatStrFormatter, AutoMinorLocator, NullFormatter

def Ch(C, h):
    for i in range(len(C)):
        for j in range(len(C[i])):
            c = i
            if j == i:
                C[i][j] = (h[c] + h[c + 1]) / 3
            elif j == (i + 1):
                C[i][j] = h[c + 1] / 6
            elif j == i - 1:
                C[i][j] = h[i] / 6
            else:
                C[i][j] = 0
    return C

def D(d, y, n):
    i = 0
    for g in range(n):
        if 1 <= g < (n - 1):
            d[i] = ((y[g + 1] - y[g]) / h[g]) - ((y[g] - y[g - 1]) / h[g - 1])
            i += 1
    return d

def Gauss(n, C, M, d):
    k = 0
    while(k < (n - 2)):
        for i in range(k + 1, n - 2, 1):
            temp = C[i][k] / C[k][k]
            #print(C[k][k])
            temp = -temp
            for j in range(k, n - 2, 1):
                C[i][j] += temp * C[k][j]
            d[i] += temp * d[k]
        k += 1
        #print("----------------")

    for i in reversed(range(n - 1)):
        #print('**  ', i)
        if i > 0:
            for j in reversed(range(n - 1)):
                if j > 0:
                    if C[i-1][j-1] != 0:
                        #print(C[i][j])
                        if j == i:
                            break
                        else:
                            d[i-1] = d[i-1] - M[j] * C[i-1][j-1]
                        print(i-1, d[i-1], C[i-1][i-1])
                    #print("----------------")
            M[i] = d[i-1] / C[i - 1][i - 1]
    return M

def S(value, x, y, M, h):
    s = 0
    for i in range(len(x)):
        if i > 0:
            if x[i - 1] <= value <= x[i]:
                s = M[i - 1] * (((x[i] - value)**3) / (6 * h[i])) + M[i] * (((value - x[i - 1])**3) / (6 * h[i])) + (y[i - 1] - (M[i - 1]*h[i]**2) / 6) * ((x[i] - value) / h[i]) + (y[i] - (M[i]*h[i]**2) / 6) * ((value - x[i - 1]) / h[i])
    return s

print('Input value: ')
value = float(input())
print('Input number of interpolation points: ')
n = int(input())
print('Step: ')
step = float(input())
print('Input x start point: ')
startpoint = float(input())
print('Input scale from | to: ')

#print(value, n, step, startpoint, scale)
x = []
M = [0.0] * n
h = [step] * (n)
i = 0
j = startpoint
while i < n:
    x.append(j)
    j = j + step
    i += 1
    

scale = [float(s) for s in input().split()]

if scale[0] > scale[1]:
    print('Error')
    while scale[0] > scale[1]:
        print('Input scale from | to: ')
        scale = [float(s) for s in input().split()]
if scale[0] > x[0]:
    scale[0] = x[0]
if scale[1] < x[len(x) - 1]:
    scale[1] = x[len(x) - 1]

x1 = np.arange(scale[0], scale[1], 0.01)


y = np.sqrt(x)
C = [[0.0] * (n - 2) for i in range(n - 2)]
C = Ch(C, h)
for g in range(n - 2):
    print(C[g])
d = [0.0] * (n - 2)
d = D(d, y, n)
print(d)
print('*******************')
M = Gauss(n, C, M, d)
print(M)

'''for i in range(len(x)):
    if i > 0:
        if x[i - 1] <= value <= x[i]:
            S = M[i - 1] * (((x[i] - value)**3) / (6 * h[i])) + M[i] * (((value - x[i - 1])**3) / (6 * h[i])) + (y[i - 1] - (M[i - 1]*h[i]**2) / 6) * ((x[i] - value) / h[i]) + (y[i] - (M[i]*h[i]**2) / 6) * ((value - x[i - 1]) / h[i])

#S = M[0] * (((x[1] - value)**3) / (6 * h[1])) + M[1] * (((value - x[0])**3) / (6 * h[1])) + (y[0] - (M[0]*h[1]**2) / 6) * ((x[1] - value) / h[1]) + (y[1] - (M[1]*h[1]**2) / 6) * ((value - x[0]) / h[1])
print(S)'''
''''''


#y = np.sqrt(x)
y2 = np.sqrt(x1)

#print(x, len(x))
#print(y)

y1 = []
for i in x:
    y1.append(S(i, x, y, M, h))
#print(y1)
value_y = S(value, x, y, M, h)
print(value_y)


#if scale[0] < 0:
yy = []
for i in x1:
    yy.append(S(i, x, y, M, h))
#print(yy)


majorLocator   = MultipleLocator(step)
#majorFormatter = FormatStrFormatter('%d', step)

fig = plt.figure()
ax1 = fig.add_subplot(111)
xax = ax1.xaxis
xax.set_major_locator(majorLocator)
#xax.set_major_formatter(majorFormatter)

ax1.scatter(x, y1)
ax1.scatter(value, value_y, color='red')
ax1.text(value, value_y, str(value_y))
line1 = ax1.plot(x1, y2, 'k',label = u'y=function', color='blue')
line2 = ax1.plot(x1, yy, 'k', label = u'y=interpolation', color='green')

ax1.set_xlabel(u'X')
ax1.set_ylabel(u'Y')
ax1.grid(True, which='major', color='grey', linestyle='dashed')
lns = line1 + line2
labs = [l.get_label() for l in lns]
ax1.legend(lns, labs, loc=3, frameon=False)
#ax1.legend()
plt.show()
