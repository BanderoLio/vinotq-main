import numpy as np
import matplotlib.pyplot as plt


def f(x):
    return -(x**2) / (5 - x)


x1 = np.linspace(-150, 4.9, 1000)
x2 = np.linspace(5.1, 150, 1000)

plt.figure(figsize=(10, 6))

plt.plot(x1, f(x1), "red", label=r"Функция $y = -\frac{x^2}{5-x}$")
plt.plot(x2, f(x2), "red")

plt.axvline(x=5, color="black", linestyle="--", label="Асимптота $x=5$")

x_asymp = np.linspace(-150, 150, 1000)
plt.plot(x_asymp, x_asymp + 5, "g--", label="Асимптота $y = x + 5$")

plt.axhline(0, color="black", linewidth=1)
plt.axvline(0, color="black", linewidth=1)
plt.xlim(-160, 160)
plt.ylim(-100, 100)
plt.xticks(np.arange(-150, 151, 50))
plt.yticks(np.arange(-100, 101, 50))
plt.grid(True, linestyle="--", linewidth=0.5)

plt.scatter([0, 10], [0, 20], color="red", zorder=8)
plt.text(
    0,
    2,
    "(0,0)",
    fontsize=14,
    verticalalignment="bottom",
    horizontalalignment="right",
    color="black",
)
plt.text(
    15,
    15,
    "(10,20)",
    fontsize=14,
    verticalalignment="bottom",
    horizontalalignment="left",
    color="black",
)

plt.xlabel("x")
plt.ylabel("y")
plt.legend()
plt.title("График функции $y = -\\frac{x^2}{5 - x}$")

plt.show()
