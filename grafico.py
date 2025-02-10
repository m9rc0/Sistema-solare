import matplotlib.pyplot as plt
import numpy as np



Sun = np.loadtxt("Sun.txt", unpack = True)
Mercury = np.loadtxt("Mercury.txt", unpack = True)
Venus = np.loadtxt("Venus.txt", unpack = True)
Earth = np.loadtxt("Earth.txt", unpack = True)
Mars = np.loadtxt("Mars.txt", unpack = True)
Jupiter = np.loadtxt("Jupiter.txt", unpack = True)
Saturn = np.loadtxt("Saturn.txt", unpack = True)
Uranus = np.loadtxt("Uranus.txt", unpack = True)
Neptune = np.loadtxt("Neptune.txt", unpack = True)
Pluto = np.loadtxt("Pluto.txt", unpack = True)

fig = plt.figure()
ax = plt.axes(projection='3d')
ax.plot(Sun[0], Sun[1], Sun[2], label = "Sun")
ax.plot(Mercury[0], Mercury[1], Mercury[2], label = "Mercury")
ax.plot(Venus[0], Venus[1], Venus[2], label = "Venus")
ax.plot(Earth[0], Earth[1], Earth[2], label = "Earth")
ax.plot(Mars[0], Mars[1], Mars[2], label = "Mars")
ax.plot(Jupiter[0], Jupiter[1], Jupiter[2], label = "Jupiter")
ax.plot(Saturn[0], Saturn[1], Saturn[2], label = "Saturn")
ax.plot(Uranus[0], Uranus[1], Uranus[2], label = "Uranus")
ax.plot(Neptune[0], Neptune[1], Neptune[2], label = "Neptune")
ax.plot(Pluto[0], Pluto[1], Pluto[2], label = "Pluto")

plt.legend()
plt.savefig("SistemaSolare.png", dpi=1200)
plt.show()
