#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string.h>
#include <cstdlib>
#include <windows.h>
#include <queue>
#include <unordered_map>
using namespace std;
#define colaEsperaMax = 110000
#define colaEsperaMin = 100000
#define TrazaOBJMax = 1500 
#define TrazaOBJMin = 1000 
#define EventoMax = 80000
#define EventoMin = 60000

//cuadraticos
void insertion_sort(int arr[], int n){
	for(int i = 1; i < n; ++i){
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1]=key;
    }
	
}
void bubble_sort(int arr[], int n){
	    for(int i = 0; i < n - 1; ++i){
        for(int j = 0; j < n - i - 1; ++j){
            if (arr[j] > arr[j + 1]){
                // Intercambiaa arr[j] y arr[j + 1]
                int tempo = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tempo;
            }
        }
    }
	
}
void selection_sort(int arr[], int n){
	for(int i = 0; i < n - 1; ++i){
        // Encontrar el índice del elemento mínimo en el arreglo
        int indice = i;
        for(int j = i + 1; j < n; ++j){
            if(arr[j] < arr[indice]){
                indice = j;
            }
        }

        // Intercambiar el elemento mínimo con el primero
        int tempo = arr[i];
        arr[i] = arr[indice];
        arr[indice] = tempo;
    }
}
void shell_sort(int arr[], int n){
	for(int gap = n / 2; gap > 0; gap /= 2){
        // Realizar el ordenamiento por inserción para el intervalo actual
        for(int i = gap; i < n; ++i){
            int temp = arr[i];
            int j;

            for(j = i; j >= gap && arr[j - gap] > temp; j -= gap){
                arr[j] = arr[j - gap];
            }

            arr[j] = temp;
        }
    }
	
}


//logaritmicos
void merge_sort(){
	
}
void quick_sort(){
	
}
void heap_sort(){
	
}

void formacion1(){ //generar los numeros de forma ordenada
int actualim = 0;
	vector<int>orden(actualim);
	 for (int i = 1; i <= colaEsperaMax; ++i) {
	 	actualim++;
        orden.push_back(i);
    }
    actualim = 0;
    vector<int>orden2(actualim);
	 for (int i = 1; i <= TrazaOBJMax; ++i) {
	 	actualim++;
        orden2.push_back(i);
    }
    actualim = 0;
   	vector<int>orden3(actualim);
	 for (int i = 1; i <= EventoMax; ++i) {
	 	actualim++;
        orden3.push_back(i);
    }
	//return orden;	
}

//esta parte se realizara mediante una cola para poder tener un mayor rango en la caacidad de gregar los numeros
void formacion2(){ //generar los numeros de forma desordenada     
	
}
void formacion3(){ //generar los numeros a la inversa de la primera 
	
}
void formacion4(){ // generar umeros desordenados sin repetir
	
}


int main(){
int wh1 = 0;
	
	
cout<<"___________________________________________________"<<endl;
cout<<"________________Carrera  del  orden________________"<<endl;
Sleep(1000);
cout<<"      deberas elegir con cual de ls 4 opciones       "<<endl;
cout<<"  crees que se ordenara mas rapido los numeros y de la forma en la que se entregaran    \n     para ser de los mejores guardianes del reino"<<endl;
cout<<"___________________________________________________"<<endl;
Sleep(1000);
cout<<"."<<endl;
Sleep(1000);
cout<<"."<<endl;
Sleep(1000);
cout<<"."<<endl;
Sleep(1000);
cout<<"."<<endl;
Sleep(1000);
cout<<"."<<endl;
Sleep(1000);
system("cls");


int question = 0;
while(wh1== 0){
	wh1 = 0;
	cout<<"______________Que opcion desea elegir______________"<<endl;
	cout<<"           Opcion________ordenado_________1             "<<endl;  //acas edaran las opciones de que deben elegirr suceptible a cambio
	cout<<"           Opcion______ desordenado ______2             "<<endl;
	cout<<"           Opcion________invertido________3             "<<endl;
	cout<<"           Opcion_desordenado sin repetir_4             "<<endl;
	cout<<"           Opcion___________salir_________5             "<<endl;
	cout<<"___________________________________________________"<<std::endl;
	cin>> question;
	switch(question){
		case 1:
			
			break;
		case 2:
			
			break;
		case 3:
				
	
			break;
		case 4:
			
			break;
		case 5:	
			wh1= 1;
			break;
		default: cout<<"incorrecto vuelva a ingresar"<<endl;
	}
}
	
	
	
	
	return 0;
}
