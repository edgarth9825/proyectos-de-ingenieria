// Actividad 2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <filesystem>

using namespace std;
using std::filesystem::directory_iterator;
using std::ofstream;
using std::fstream;

void MayusToMinus(string rutaPorOrdenar, string nombreArchivo);

int main()
{
    int opcion;
	ofstream log;

	do
	{
		cout << "1. Mayusculas a minusculas y ordenar" << endl;
		cout << "2." << endl;
		cout << "0. Salir" << endl;

		cin >> opcion;

			switch (opcion)
			{
			case 1:
				string rutaLimpiosMayus = "D:\\Universidad\\OCTAVO SEMESTRE\\Proyectos de ingenieria\\Actividad 1\\Ordenar_palabras";
				//log.open("mayusculas-minusculas.txt", std::ofstream::trunc);
				//log.close();
				for (const auto& file : directory_iterator(rutaLimpiosMayus))
				{
					string nombreArchivo = file.path().filename().string();
					MayusToMinus(file.path().string(), nombreArchivo);
				}
				break;
			}

	} while (opcion != 0);
}

// Pasar de mayusculas a minusculas y ordenar alfabeticamente

void MayusToMinus (string rutaPorOrdenar, string nombreArchivo){

	ofstream archivosMayusToMinus;
	string linea;
	ofstream log;

	archivosMayusToMinus.open("D:\\Universidad\\OCTAVO SEMESTRE\\Proyectos de ingenieria\\Actividad 2\\Archivos de mayusculas a minusculas\\" + nombreArchivo, std::ofstream::trunc);

	//Revisa que se pueda abrir la nueva ruta
	if (archivosMayusToMinus.fail())
	{
		cout << "No se pueden crear los archivos: " << endl;
		exit(1);
	}

	ifstream archivosPorOrdenar(rutaPorOrdenar);

	if (archivosPorOrdenar)
	{
		cout << rutaPorOrdenar << endl;

		while (getline(archivosPorOrdenar, linea))
		{
			vector <string> textoLinea;

			while (archivosPorOrdenar >> linea)
			{
				for (int i = 0; i < linea.size(); i++)
				{
					//Recorres caracter por caracter para pasar a minuscula
					linea[i] = tolower(linea[i]);
					//archivosMayusToMinus << linea[i];
				}

				textoLinea.push_back(linea);
			}

			sort(textoLinea.begin(), textoLinea.end());

			for (vector <string>::const_iterator i = textoLinea.begin(); i != textoLinea.end(); i++)
			{
				if (i->length() == 0)
				{
					continue;
				}
				else
				{
					archivosMayusToMinus << *i << endl;
				}
			}

			//archivosMayusToMinus << endl;
			getline(archivosPorOrdenar, linea);
		} //CIERRA WHILE

		archivosMayusToMinus.close();
	}
	else
	{
		cout << "No se pueden abrir los archivos: " << endl;
	}
	
}