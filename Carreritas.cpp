#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string.h>
#include <cstdlib>
#include <windows.h>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <random>
using namespace std;
#define colaEsperaMax  110000
#define colaEsperaMin  100000
#define TrazaOBJMax  1500 
#define TrazaOBJMin  1000 
#define EventoMax  80000
#define EventoMin  60000

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

int formacion1(){ //generar los numeros de forma ordenada
	int actualim = 0,cont1=0,cont2= 0,cont3 = 0;
	int limiteIntervalo = rand()%(110000 - 100000 + 1) + 100000;
	int orden[limiteIntervalo];
	 for (int i = 1; i <= limiteIntervalo; i++) {
	 	actualim++;
	 	cont1++;
        orden[i]= i;
    }
    if(actualim >= colaEsperaMin){
    	cout<<"C1 lista"<<endl;
	}else{
		return -1;
	}
    actualim = 0;
    
   	int limiteIntervalo2 = rand()%(1500 - 1000 + 1) + 1000;
   	 int orden2[limiteIntervalo2];
	 for (int i = 1; i <= limiteIntervalo2; i++) {
	 	actualim++;
	 	cont2 ++;
        orden2[i]=i;
    }
     if(actualim >= TrazaOBJMin){
    	cout<<"C1 lista"<<endl;
	}else{
		return -1;
	}
    actualim = 0;
    
	int limiteIntervalo3 = rand()%(80000 - 60000 + 1) + 60000;
   int orden3[limiteIntervalo3];
	 for (int i = 1; i <= limiteIntervalo3; i++) {
	 	actualim++;
	 	cont3++;
        orden3[i]= i;
    }
     if(actualim >= EventoMin){
    	cout<<"C1 lista"<<endl;
	}else{
		return -1;
	}
	
	//aca se inicializaran las carreritas
	/*insertion_sort(orden[],cont1);
	insertion_sort(orden2[],cont2);
	insertion_sort(orden3[],cont3);*/

	
}

//esta parte se realizara mediante una cola para poder tener un mayor rango en la caacidad de gregar los numeros
int formacion2(){ //generar los numeros de forma desordenada   sin repeticion   
	int actualim = 0,cont1=0,cont2= 0,cont3 = 0;
	
	int desorden1[colaEsperaMax];
	for (int i = 0; i < colaEsperaMax; ++i) {
		actualim++;
		cont1++;
        desorden1[i] = i + 1;                         // Llenar el arreglo con números en orden
    }
    //                                             Mezclar el arreglo desordenadamente
    random_device rd;
    mt19937 gen(rd());
    shuffle(desorden1, desorden1 + colaEsperaMax, gen);
	if(actualim >= colaEsperaMin){
    	cout<<"C1 lista"<<endl;
	}else{
		return -1;
	}
	//--------------------------------------------
	actualim = 0;
	int desorden2[TrazaOBJMax];
	for (int i = 0; i < TrazaOBJMax; ++i) {
		actualim++;
		cont1++;
        desorden2[i] = i + 1;  
    }
    random_device rd2;
    mt19937 gen2(rd2());
    shuffle(desorden2, desorden2 + TrazaOBJMax, gen2);
	if(actualim >= TrazaOBJMin){
    	cout<<"C1 lista"<<endl;
	}else{
		return -1;
	}
	//--------------------------------------------
	actualim = 0;
	int desorden3[EventoMax];
	for (int i = 0; i < EventoMax; ++i) {
		actualim++;
		cont1++;
        desorden3[i] = i + 1;
    }
    random_device rd3;
    mt19937 gen3(rd3());
    shuffle(desorden3, desorden3 + EventoMax, gen3);	
	if(actualim >= EventoMin){
    	cout<<"C1 lista"<<endl;
	}else{
		return -1;
	}
	
	
}
void formacion3(){ //generar los numeros a la inversa de la primera con posible repeticion
	int cont1 = 0, cont2 = 0, cont3 = 0, actualim = 0;
 	int limiteIntervalo = rand()%(110000 - 100000 + 1) + 100000;
 	int ivdef[limiteIntervalo];
	for(int i = limiteIntervalo; i >= 1 ; i--){
		cont1++;
		actualim++;                                 // se supone que este for debe tomar el valor maximo permitido e ir decreciendo hasta el 1 y cada posicion se ira agregando 
		ivdef[i] = i;
	}
	
	
	
	//---------------------------------------------------------
	actualim = 0;
	int limiteIntervalo2 = rand()%(1500 - 1000 + 1) + 1000;
 	int ivdef2[limiteIntervalo2];
	for(int i = limiteIntervalo2; i >= 1 ; i--){
		cont2++;
		actualim++;                                 // se supone que este for debe tomar el valor maximo permitido e ir decreciendo hasta el 1 y cada posicion se ira agregando 
		ivdef2[i] = i;
	}
	
	
	
	//--------------------------------------------------------
	int limiteIntervalo3 = rand()%(80000 - 60000 + 1) + 60000;
 	int ivdef3[limiteIntervalo3];
	for(int i = limiteIntervalo3; i >= 1 ; i--){
		cont3++;
		actualim++;                                 // se supone que este for debe tomar el valor maximo permitido e ir decreciendo hasta el 1 y cada posicion se ira agregando 
		ivdef3[i] = i;
	}
}
int formacion4(){ // generar umeros desordenados con repeticion repeticion
	int cont1 = 0, cont2 = 0, cont3 = 0, actualim = 0;

    // Generar números aleatorios para el primer conjunto
    int inverso1[colaEsperaMax];
    for(int i = 0; i < colaEsperaMax; ++i){
        cont1++;
        actualim++;
        inverso1[i] = rand()% colaEsperaMax + 1;  // Generar número aleatorio entre 1 y colaEsperaMax
    }
    if(actualim >= colaEsperaMin){
    	cout<<"C1 lista"<<endl;
	}else{
		return -1;
	}
	//--------------------------------------------
	actualim = 0;
	int inverso2[TrazaOBJMax];
    for(int i = 0; i < TrazaOBJMax; ++i){
        cont2++;
        actualim++;
        inverso2[i] = rand()% TrazaOBJMax + 1;  // Generar número aleatorio entre 1 y TrazaOBJMax
    }
    //cout << "C2 inversa generada aleatoriamente" << std::endl;
     if(actualim >= TrazaOBJMin){
    	cout<<"C2 lista"<<endl;
	}else{
		return -1;
	}
	//--------------------------------------------
	actualim = 0;
    
    int inverso3[EventoMax];
    for(int i = 0; i < EventoMax; ++i){
        cont3++;
        actualim ++;
        inverso3[i] = rand()% EventoMax + 1;  // Generar número aleatorio entre 1 y EventoMax
    }
    //cout << "C3 inversa generada aleatoriamente" << std::endl;
	if(actualim >= EventoMin){
    	cout<<"C3 lista"<<endl;
	}else{
		return -1;
	}
	
	
}


int main(){
int wh1 = 0;
//srand(time(NULL));	
	
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
