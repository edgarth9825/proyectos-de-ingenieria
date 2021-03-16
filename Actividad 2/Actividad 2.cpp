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

//Metodos de actividades
void MayusToMinus(string rutaPorOrdenar, string nombreArchivo);

//Variables de tiempo
double t0, t1, tt0, tt1;
double tTotal = 0, tProceso = 0;

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
				tt0 = clock();
				log.open("Mayusculas a minusculas.txt", std::ofstream::trunc);
				log.close();

				string rutaLimpiosMayus = "D:\\Universidad\\OCTAVO SEMESTRE\\Proyectos de ingenieria\\Actividad 1\\Ordenar_palabras";
				//log.open("mayusculas-minusculas.txt", std::ofstream::trunc);
				//log.close();
				for (const auto& file : directory_iterator(rutaLimpiosMayus))
				{
					string nombreArchivo = file.path().filename().string();
					MayusToMinus(file.path().string(), nombreArchivo);
				}

				log.open("Mayusculas a minusculas.txt", std::ofstream::app);
				tt1 = clock();
				tProceso = ((tt1 - tt0) / CLOCKS_PER_SEC);
				cout << "\n" << "El tiempo total de ordenar y pasar de mayusculas a minusculas es: " << tTotal << endl;
				cout << "\n" << "El tiempo total del proceso es: " << tProceso << endl;
				log << endl << "El tiempo total de ordenar y pasar de mayusculas a minusculas es: " << tTotal << endl;
				log << endl << "El tiempo total del proceso es: " << tProceso << endl;
				log.close();
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

	t0 = clock();
	log.open("Mayusculas a minusculas.txt", ofstream::app);
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
				}

				textoLinea.push_back(linea);
			}

			sort(textoLinea.begin(), textoLinea.end());

			//Ciclo para escribir el vector sorteado al nuevo archivo
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

			
			getline(archivosPorOrdenar, linea);
		} //CIERRA WHILE

		archivosMayusToMinus.close();
	}
	else
	{
		cout << "No se pueden abrir los archivos: " << endl;
	}
	t1 = clock();
	double tiempo = ((t1 - t0) / CLOCKS_PER_SEC);
	cout << "Tiempo de pasar de mayusculas a minusculas y ordenar: " << fixed << setprecision(4) << tiempo << endl;
	tTotal += tiempo;
	log << rutaPorOrdenar << "    Tiempo de pasar de mayusculas a minusculas y ordenar: " << fixed << setprecision(4) << tiempo << endl;
	log.close();
}