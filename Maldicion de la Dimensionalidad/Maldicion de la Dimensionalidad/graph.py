import numpy as np
import matplotlib.pyplot as plt

plt.style.use('seaborn-pastel');  

maze=np.loadtxt('tablas.txt',dtype=int)

print(maze)


fig, ax = plt.subplots(2,2,constrained_layout=True)

colors=['black','red','green','purple','orange','blue']
dim=['1','2','3','4','5','6','7','8','9','10','20','30','40','50','60','70','80','90','100','200']
eje_x = ['0', '0.1', '0.2', '0.3','0.4','0.5','0.6','0.7','0.8','0.9','1']
r=0
y=0
for i in range(2):
    for j in range(2):
        ax[i,j].bar(eje_x, maze[y],color=colors[r%6])
        ax[i,j].set_ylabel('Frecuencia de Distancias')
        ax[i,j].set_xlabel('Distancias')
        ax[i,j].set_title(dim[r]+' Dimensiones')
        r=r+1
        y=y+1

plt.savefig("Curse of Dimensionality1.png")
plt.show()


fig1, ax1 = plt.subplots(2,2,constrained_layout=True)

for i in range(2):
    for j in range(2):
        ax1[i,j].bar(eje_x, maze[y],color=colors[r%6])
        ax1[i,j].set_ylabel('Frecuencia de Distancias')
        ax1[i,j].set_xlabel('Distancias')
        ax1[i,j].set_title(dim[r]+' Dimensiones')
        r=r+1
        y=y+1

plt.savefig("Curse of Dimensionality2.png")
plt.show()

fig2, ax2 = plt.subplots(2,2,constrained_layout=True)

for i in range(2):
    for j in range(2):
        ax2[i,j].bar(eje_x, maze[y],color=colors[r%6])
        ax2[i,j].set_ylabel('Frecuencia de Distancias')
        ax2[i,j].set_xlabel('Distancias')
        ax2[i,j].set_title(dim[r]+' Dimensiones')
        r=r+1
        y=y+1

plt.savefig("Curse of Dimensionality3.png")
plt.show()


fig3, ax3 = plt.subplots(2,2,constrained_layout=True)

for i in range(2):
    for j in range(2):
        ax3[i,j].bar(eje_x, maze[y],color=colors[r%6])
        ax3[i,j].set_ylabel('Frecuencia de Distancias')
        ax3[i,j].set_xlabel('Distancias')
        ax3[i,j].set_title(dim[r]+' Dimensiones')
        r=r+1
        y=y+1

plt.savefig("Curse of Dimensionality4.png")
plt.show()


fig4, ax4 = plt.subplots(2,2,constrained_layout=True)

for i in range(2):
    for j in range(2):
        ax4[i,j].bar(eje_x, maze[y],color=colors[r%6])
        ax4[i,j].set_ylabel('Frecuencia de Distancias')
        ax4[i,j].set_xlabel('Distancias')
        ax4[i,j].set_title(dim[r]+' Dimensiones')
        r=r+1
        y=y+1

plt.savefig("Curse of Dimensionality5.png")
plt.show()