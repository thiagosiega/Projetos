import os

# Path: compilador.py

comando = "g++ -o main main.cpp -std=c++17 -I${workspaceFolder}/SFML/SFML-2.6.1/include -L${workspaceFolder}/SFML/SFML-2.6.1/lib -lsfml-window -lsfml-system -lsfml-graphics"

executar = "./main"

os.system(comando)
os.system(executar)