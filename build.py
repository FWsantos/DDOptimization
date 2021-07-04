# Build Script
import os
os.system('clear')

# Compila
command = "g++ "
command += "-c "
command += "-Wall "
command += "SCPP.cpp "
command += "main.cpp "

erro = os.system(command)

# Linka
if erro == 0:
	command = "g++ "
	command += "-o "
	command += "DDO.exe "
	command += "SCPP.o "
	command += "main.o "
	erro = os.system(command)

	os.system("rm -rf *.o")
	if erro == 0: 
		os.system("echo 'Buildado com sucesso'")