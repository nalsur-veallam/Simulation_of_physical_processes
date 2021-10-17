import matplotlib.pyplot as plt
import numpy as np

omega = 0.5
    
data = np.loadtxt('points.txt')
X = np.array([x[0] for x in data])
X1 = np.array([x[1] for x in data])
V = np.array([v[2] for v in data])
V1 = np.array([v[3] for v in data])
T = np.array([t[4] for t in data])

fig, ax = plt.subplots()

ax.plot(T, X, 'b', label="Euler")
ax.plot(T, X1, 'g', label="Hoin")
ax.set_xlabel('time')
ax.set_ylabel('position') 
ax.set_title("MOTION FUNCTION")
ax.legend();

fig1, bx = plt.subplots()
bx.plot(V, X, 'r', label="Euler")
bx.plot(V1, X1, 'y', label="Hoin")
bx.set_xlabel('velocity')
bx.set_ylabel('position') 
bx.set_title("PHASE DIAGRAM")
bx.legend();

fig2, cx = plt.subplots()
cx.plot(T, (V ** 2)/2 + omega*(X ** 2)/2, 'b', label="Euler")
cx.plot(T, V1**2/2 + omega*X1**2/2, 'g', label="Hoin")
cx.set_xlabel('time')
cx.set_ylabel('energy') 
cx.set_title("FULL ENERGY")
cx.legend();

plt.show()
