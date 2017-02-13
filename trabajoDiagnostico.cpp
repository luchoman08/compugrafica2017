#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>

int **matriz1;
int **matriz2;
int N;
using namespace std;

int crearMatrizDinamica(int filas, int columnas, int** &punteroMatriz){
	punteroMatriz = new int* [filas];
				for (int i = 0; i < columnas; i++) {
					punteroMatriz[i] = new int[columnas];
				}
				return 0;
}
int** calcularTranspuestaMatrizDinamica(int** &punteroMatriz, int numFilas, int numColumnas){
	int** matrizTranspuesta;
	crearMatrizDinamica(numFilas, numColumnas, matrizTranspuesta);
	for(int i = 0; i < numFilas; i++){
		for(int j = 0; j < numColumnas; j++){
			matrizTranspuesta[i][j] = punteroMatriz[j][i];
		}
	}
	return matrizTranspuesta;
}

int productoPuntoVectores(int * &punteroVecor1, int * &punteroVector2, int N){
	
	int resultado = 0;
	for(int i = 0; i < N; i++){
		resultado += punteroVecor1[i] * punteroVector2[i];
	}
	
	return resultado;
}

int** calcularMultiplicacionMatrices(int** &punteroMatriz1, int** &punteroMatriz2, int N){
	int** resultadoMultiplicacion;
	crearMatrizDinamica(N , N ,resultadoMultiplicacion);
	int** transpuestaMatriz2 = calcularTranspuestaMatrizDinamica(punteroMatriz2, N, N);
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			resultadoMultiplicacion[i][j] = productoPuntoVectores(punteroMatriz1[i], transpuestaMatriz2[j], N) ;
		}
		
	}
		
	return resultadoMultiplicacion;
}




int imprimirMatrizDinamica(int** punteroMatriz, int numFilas, int numColumnas){
	for(int i = 0; i < numFilas; i++){
		for(int j = 0; j < numColumnas; j++){
			cout << punteroMatriz[i][j]  << " ";
		}
		cout << endl;
	}
	return 0;
}


int leerMatrices(std::string nombreArchivo, string separador){
	ifstream fe(nombreArchivo);
	string lineaTemporal;
	int i = 0;
	while (!fe.eof()){

		fe >> lineaTemporal;

		if (i == 0){
			try{
				N = stoi(lineaTemporal);
				crearMatrizDinamica(N,N,matriz1);
				crearMatrizDinamica(N,N,matriz2);
			}
			catch( int e){
				cout << "El primer valor debe ser el numero de filas/columnas que tienen las matrices cuadradas, codigo error "<< e << endl;
			}
		}
		
		while( i>= 1 && i <= N){
			for(int j = 0; j < N; j++){
				matriz1[i-1][j]  = stoi(lineaTemporal);
				fe >> lineaTemporal;
			}
			i++;
		}
		
		if (i > N){
		for(int k = 0; k < N; k++){
			for(int j = 0; j < N; j++){
				matriz2[k][j]  = stoi(lineaTemporal);
				
				fe >> lineaTemporal;
			}

		}
	}
		lineaTemporal = "";
		i++;
	}
	return 0;
}

using namespace std;
int main(){


	leerMatrices("matrices.txt", " ");
	cout<< "Matriz 1" << endl;
	imprimirMatrizDinamica(matriz1, N,N);
	cout << "---------------" << endl;
	cout<< "Matriz 2" << endl;
	imprimirMatrizDinamica(matriz2, N,N);
	cout << "---------------" << endl;
	cout<< "Transpuesta Matriz 1" << endl;
    imprimirMatrizDinamica(calcularTranspuestaMatrizDinamica(matriz1, N,N), N,N);
	cout << "---------------" << endl;
	cout<< "Transpuesta Matriz 2" << endl;
    imprimirMatrizDinamica(calcularTranspuestaMatrizDinamica(matriz2, N,N), N,N);
	cout << "---------------" << endl;
	cout<< "Multiplicacion entre matrices: " << endl;
	imprimirMatrizDinamica(calcularMultiplicacionMatrices(matriz1, matriz2, N), N, N);
}
