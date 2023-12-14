#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string.h>
#include <cstdlib>
#include <windows.h>
#include <queue>
#include <algorithm>
#include <random>
#include <chrono>
#include <iomanip>
using namespace std;
using namespace chrono;

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
void merge(int arr[], int min, int medio, int max){
	int n1 = medio - min + 1;
    int n2 = max - medio;
	//ahora crear arrelgos
	int izquierda[n1];
	int derecha[n2];
	for(int i = 0; i < n1; ++i){
		izquierda[i] = arr[min + i];
	}
        
    for(int j = 0; j < n2; ++j){
    	derecha[j] = arr[medio + 1 + j];
	}
    int i = 0, j = 0, k = min;
    while(i < n1 && j < n2){
        if(izquierda[i] <= derecha[j]){
            arr[k] = izquierda[i];
            ++i;
        }else{
            arr[k] = derecha[j];
            ++j;
        }
        ++k;
    }
	while(j < n2){
        arr[k] = derecha[j];
        ++j;
        ++k;
    }
}
void mergeSort(int arr[], int min, int max){
    if(min < max){
        // Encuentra el punto medio
        int medio = min + (max - min)/2;
        // Ordena la primera y la segunda mitad
        mergeSort(arr, min, medio);
        mergeSort(arr, medio + 1, max);
        merge(arr, min, medio, max);
    }
}
//quick sort<------------<----------<-------------<-----------------
void intercambio(int a, int b){
	int tim = a;
	a= b;
	b= tim;
}
int particion(int arr[], int inicio, int fin){
    int pivote = arr[fin];
    int i = inicio - 1;
		cout<<"parte 5"<<endl;

    for (int j = inicio; j < fin; j++){
        if (arr[j] <= pivote) {
            i++;
            intercambio(arr[i], arr[j]);
        }
    }
cout<<"parte 6"<<endl;


    intercambio(arr[i + 1], arr[fin]);
    		cout<<"parte 7"<<endl;

    return i + 1;
}
void quick_sort(int arr[], int inicio, int fin){
	if (inicio < fin){
		cout<<"parte 1"<<endl;
        int indiceParticion = particion(arr, inicio, fin);
       	cout<<"parte 2"<<endl;

        quick_sort(arr, inicio, indiceParticion - 1);
       	cout<<"parte 3"<<endl;
        quick_sort(arr, indiceParticion + 1, fin);
        cout<<"parte 4"<<endl;

    }	
	
	
}
void heapify(int orden[], int n, int i){
    int max = i; // Inicializa el raíz como máximo
    int izquierda = 2 * i + 1;
    int derecha = 2 * i + 2;

    // Si el izq es mayor
    if(izquierda < n && orden[izquierda] > orden[max])
        max = izquierda;

    // Si derecha es mayor
    if(derecha < n && orden[derecha] > orden[max])
        max = derecha;

    // Si el máximo no es la raíz
    if(max != i){
        // Intercambiar el máximo con la raíz
        std::swap(orden[i], orden[max]);
        heapify(orden, n, max);
    }
}
void heapSort(int orden[], int max){
    //reorganizar el arreglo
    for (int i = max / 2 - 1; i >= 0; i--){
    	heapify(orden, max, i);
	}
    
    // Extraer elementos uno por uno
    for(int i = max - 1; i > 0; i--){
        // Mover la raíz actual al final
        swap(orden[0], orden[i]);
        // Llamar a heapify
        heapify(orden, i, 0);
    }
}

int colaDEspera(){
	//numero ordenado
	float ganador = -1, ganador2 = -1,ganador3 =-1,ganador4 = -1;

	int actualim = 0,cont1=0,cont2= 0,cont3 = 0,cont4 = 0;
	int limiteIntervalo = rand()%(110000 - 100000 + 1) + 100000;
	int orden[limiteIntervalo];
	for (int i = 0; i <= limiteIntervalo; i++) {
	 	actualim++;
	 	cont1++;
        orden[i]= i+1;
    }
    cout<<limiteIntervalo<<endl;
    if(actualim >= colaEsperaMin){
    	cout<<"C1a lista"<<endl;
	}else{
		return -1;
	}
	//numero desordenado sin repeticion
	actualim = 0;
	int desorden1[limiteIntervalo];
	for (int i = 0; i < colaEsperaMax; ++i) {
		actualim++;
		cont2++;
        desorden1[i] = i + 1;                         // Llenar el arreglo con números en orden
    }
    //                                             Mezclar el arreglo desordenadamente
    random_device rd;
    mt19937 gen(rd());
    shuffle(desorden1, desorden1 + colaEsperaMax, gen);
	if(actualim >= colaEsperaMin){
    	cout<<"C1b lista"<<endl;
	}else{
		return -1;
	}
	
	
	//inverso
	
 	int ivdef[limiteIntervalo];
	for(int i = limiteIntervalo; i >= 1 ; i--){
		cont3++;
		actualim++;                                 // se supone que este for debe tomar el valor maximo permitido e ir decreciendo hasta el 1 y cada posicion se ira agregando 
		ivdef[i] = i;
	}
	cout<<"C1c lista"<<endl;
	
	
	//numero desordenado con repeticion
	actualim = 0;
	int deso1[limiteIntervalo];
    for(int i = 0; i < limiteIntervalo; ++i){
        cont4++;
        actualim++;
        deso1[i] = rand()% limiteIntervalo + 1;  // Generar número aleatorio entre 1 y colaEsperaMax
    }
    if(actualim >= colaEsperaMin){
    	cout<<"C1d lista"<<endl;
	}else{
		return -1;
	}
	
	
	//ahora se debe tomar el timepo y se tomara el tiempo de cada funcion
	cout<<"ORDEN:  "<<endl;
	double tiempo_selection_sort = 0;
	double tiempo_insertion_sort = 0;
	double tiempo_bubble_sort = 0;
	double tiempo_shell_sort = 0;
	double tiempo_merge_sort = 0;
	double tiempo_quick_sort = 0;
	double tiempo_heap_sort = 0;

	auto start_time = high_resolution_clock::now();
	insertion_sort(orden,limiteIntervalo);
	cout<<"1 bien"<<endl;
	auto end_time = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_insertion_sort = duration.count();
	if(ganador < 0 || tiempo_insertion_sort < ganador ){
		ganador = tiempo_insertion_sort;
	}
//---------------------------------------------------------------------------	
	start_time = high_resolution_clock::now();
	bubble_sort(orden,limiteIntervalo);
		cout<<"2bien"<<endl;
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_bubble_sort = duration.count();
	if(ganador < 0 || tiempo_bubble_sort < ganador ){
		ganador = tiempo_bubble_sort;
	}
//---------------------------------------------------------------------------
	start_time = high_resolution_clock::now();	
	selection_sort(orden,limiteIntervalo);
	cout<<"3 bien"<<endl;
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_selection_sort = duration.count();
	if(ganador < 0 || tiempo_selection_sort < ganador ){
		ganador = tiempo_selection_sort;
	}
//---------------------------------------------------------------------------
	start_time = high_resolution_clock::now();	
	shell_sort(orden,limiteIntervalo);
	cout<<"4 bien"<<endl;
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_shell_sort = duration.count();
	if(ganador < 0 || tiempo_shell_sort < ganador ){
		ganador = tiempo_shell_sort;
	}
//---------------------------------------------------------------------------
	start_time = high_resolution_clock::now();	
	//mergeSort(orden,0,limiteIntervalo);
	//cout<<"5 bien"<<endl;
	
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_merge_sort = duration.count();
	
//--------------------------------------------------------------------------
	start_time = high_resolution_clock::now();	
//	quick_sort(orden,0,limiteIntervalo-1);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_quick_sort = duration.count();
	
//	--------------->_------------->--------->heap_sort<----------<------<-<-<-<--------<------------
	start_time = high_resolution_clock::now();	
	heapSort(orden,limiteIntervalo);
	cout<<"7 bien"<<endl;
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_heap_sort = duration.count();
	if(ganador < 0 || tiempo_heap_sort < ganador ){
		ganador = tiempo_heap_sort;
	}
//--------------------------------------------------------------------------
	cout<<setprecision(10)<<"Insertion sort "<<tiempo_insertion_sort<<"\n"<<"Bubble sort "<<tiempo_bubble_sort<<endl;
	cout<<"Selection sort "<<tiempo_selection_sort<<"\n"<<"Shell  sort "<<tiempo_shell_sort<<endl;
//	cout<<"Merge sort "<<tiempo_merge_sort<<"\n"<<"Quick sort "<<tiempo_quick_sort<<endl;
	cout<<"Heap Sort "<<tiempo_heap_sort<<endl;
	cout<<"El ganador es:"<<ganador<<endl;

	//aca tomar el tiempo de la segunda opcion desordenado y asi mas abajo
	cout<<" \ndesordenado"<<endl;
	ganador2 = -1;
	double tiempo_selection_sort2 = 0;
	double tiempo_insertion_sort2 = 0;
	double tiempo_bubble_sort2 = 0;
	double tiempo_shell_sort2 = 0;
	double tiempo_merge_sort2 = 0;
	double tiempo_quick_sort2 = 0;
	double tiempo_heap_sort2 = 0;
	
	
	start_time = high_resolution_clock::now();
	insertion_sort(desorden1,cont2);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_insertion_sort2 = duration.count();
	if(ganador2 < 0 || tiempo_insertion_sort2 < ganador2 ){
		ganador2 = tiempo_insertion_sort2;
	}
	start_time = high_resolution_clock::now();
	bubble_sort(desorden1,cont2);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_bubble_sort2 = duration.count();
	if(ganador2 < 0 || tiempo_bubble_sort2 < ganador2 ){
		ganador2 = tiempo_bubble_sort2;
	}
	start_time = high_resolution_clock::now();
	selection_sort(desorden1,cont2);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_selection_sort2 = duration.count();
	if(ganador2 < 0 || tiempo_selection_sort2 < ganador2 ){
		ganador2 = tiempo_selection_sort2;
	}
	start_time = high_resolution_clock::now();
	shell_sort(desorden1,cont2);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_shell_sort2 = duration.count();
	if(ganador2 < 0 || tiempo_shell_sort2 < ganador2 ){
		ganador2 = tiempo_shell_sort2;
	}
	start_time = high_resolution_clock::now();	
	//mergeSort(desorden1,0,limiteIntervalo-1);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_merge_sort2 = duration.count();

	start_time = high_resolution_clock::now();	
//	quick_sort(desorden1,0,limiteIntervalo-1);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_quick_sort2 = duration.count();
//------------------------------------------------------------------------
//	--------------->_------------->--------->heap_sort<----------<------<-<-<-<--------<------------
	start_time = high_resolution_clock::now();	
	heapSort(desorden1,limiteIntervalo);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_heap_sort2 = duration.count();
	if(ganador2 < 0 || tiempo_heap_sort2 < ganador2 ){
		ganador2 = tiempo_heap_sort2;
	}
	cout<<"Insertion sort "<<tiempo_insertion_sort2<<"\n"<<"Bubble sort "<<tiempo_bubble_sort2<<endl;
	cout<<"Selection sort "<<tiempo_selection_sort2<<"\n"<<"Shell  sort "<<tiempo_shell_sort2<<endl;
//	cout<<"Merge sort "<<tiempo_merge_sort2<<"\n"<<"Quick sort "<<tiempo_quick_sort2<<endl;
	cout<<"Heap Sort "<<tiempo_heap_sort2<<endl;
	cout<<"Ganador: "<<ganador2<<endl;
	
	//inverso
	ganador3 = -1;
	cout<<"\ninverso"<<endl;
	double  tiempo_selection_sort3 = 0;
	double tiempo_insertion_sort3 = 0;
	double tiempo_bubble_sort3 = 0;
	double tiempo_shell_sort3 = 0;
	double tiempo_merge_sort3 = 0;
	double tiempo_quick_sort3 = 0;
	double tiempo_heap_sort3 = 0;
	
	start_time = high_resolution_clock::now();
	insertion_sort(ivdef,cont3);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_insertion_sort3 = duration.count();
	if(ganador3 < 0 || tiempo_insertion_sort3 < ganador3 ){
		ganador3 = tiempo_insertion_sort3;
	}
//------------------------------------------------------------

	start_time = high_resolution_clock::now();
	bubble_sort(ivdef,cont3);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_bubble_sort3 = duration.count();
	if(ganador3 < 0 || tiempo_bubble_sort3 < ganador3 ){
		ganador3 = tiempo_bubble_sort3;
	}
	//------------------------------------------------------------

	start_time = high_resolution_clock::now();
	selection_sort(ivdef,cont3);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_selection_sort3 = duration.count();
	if(ganador3 < 0 || tiempo_selection_sort3 < ganador3 ){
		ganador3 = tiempo_selection_sort3;
	}
	//------------------------------------------------------------
	start_time = high_resolution_clock::now();
	shell_sort(ivdef,cont3);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_shell_sort3  = duration.count();
	if(ganador3 < 0 || tiempo_shell_sort3 < ganador3 ){
		ganador3 = tiempo_shell_sort3;
	}
	//------------------------------------------------------------

	start_time = high_resolution_clock::now();	
	//mergeSort(ivdef,0,limiteIntervalo-1);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_merge_sort3 = duration.count();
//----------------------------------------------------------------
	start_time = high_resolution_clock::now();	
//	quick_sort(ivdef,0,limiteIntervalo-1);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_quick_sort3 = duration.count();
//--------------------------------------------------------------------------------------------------
//	--------------->_------------->--------->heap_sort<----------<------<-<-<-<--------<------------
	start_time = high_resolution_clock::now();	
	heapSort(ivdef,limiteIntervalo);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_heap_sort3 = duration.count();	
	if(ganador3 < 0 || tiempo_heap_sort3 < ganador3 ){
		ganador3 = tiempo_heap_sort3;
	}
	cout<<"Insertion sort "<<tiempo_insertion_sort3<<"\n"<<"Bubble sort "<<tiempo_bubble_sort3<<endl;
	cout<<"Selection sort "<<tiempo_selection_sort3<<"\n"<<"Shell  sort "<<tiempo_shell_sort3<<endl;
//	cout<<"Merge sort "<<tiempo_merge_sort3<<"\n"<<"Quick sort "<<tiempo_quick_sort3<<endl;
	cout<<"Heap Sort "<<tiempo_heap_sort3<<endl;
	cout<<"Ganador: "<<ganador3<<endl;

	
	//desordenado con repeticion
	ganador4 = -1;
	cout<<"\ndesorden con repetir"<<endl;
	double tiempo_selection_sort4 = 0;
	double tiempo_insertion_sort4 = 0;
	double tiempo_bubble_sort4 = 0;
	double tiempo_shell_sort4 = 0;
	double tiempo_merge_sort4 = 0;
	double tiempo_quick_sort4 = 0;
	double tiempo_heap_sort4 = 0;
	
	start_time = high_resolution_clock::now();
	insertion_sort(deso1,cont4);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_insertion_sort4 = duration.count();
	if(ganador4 < 0 || tiempo_insertion_sort4 < ganador4 ){
		ganador4 = tiempo_insertion_sort4;
	}
	start_time = high_resolution_clock::now();
	bubble_sort(deso1,cont4);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_bubble_sort4 = duration.count();
	if(ganador4 < 0 || tiempo_bubble_sort4 < ganador4 ){
		ganador4 = tiempo_bubble_sort4;
	}
	
	start_time = high_resolution_clock::now();
	selection_sort(deso1,cont4);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_selection_sort4 = duration.count();
	if(ganador4 < 0 || tiempo_selection_sort4 < ganador4 ){
		ganador4 = tiempo_selection_sort4;
	}
	start_time = high_resolution_clock::now();
	shell_sort(deso1,cont4);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_shell_sort4  = duration.count();
	if(ganador4 < 0 || tiempo_shell_sort4 < ganador4 ){
		ganador4 = tiempo_shell_sort4;
	}
	start_time = high_resolution_clock::now();	
	//mergeSort(deso1,0,limiteIntervalo-1);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_merge_sort4 = duration.count();
	
	start_time = high_resolution_clock::now();	
//	quick_sort(deso1,0,limiteIntervalo-1);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_quick_sort4 = duration.count();
//--------------------------------------------------------------------------------------------------
//	--------------->_------------->--------->heap_sort<----------<------<-<-<-<--------<------------
	start_time = high_resolution_clock::now();	
	heapSort(deso1,limiteIntervalo);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_heap_sort4 = duration.count();	
	if(ganador4 < 0 || tiempo_heap_sort4 < ganador4 ){
		ganador4 = tiempo_heap_sort4;
	}
	cout<<"Insertion sort "<<tiempo_insertion_sort4<<"\n"<<"Bubble sort "<<tiempo_bubble_sort4<<endl;
	cout<<"Selection sort "<<tiempo_selection_sort4<<"\n"<<"Shell  sort "<<tiempo_shell_sort4<<endl;
//	cout<<"Merge sort "<<tiempo_merge_sort4<<"\n"<<"Quick sort "<<tiempo_quick_sort4<<endl;
	cout<<"Heap Sort "<<tiempo_heap_sort4<<endl;
	cout<<"Ganador:"<<ganador4<<endl;
	
	cout<<"\n\nLos ganadores fueron :"<<ganador<<"  2:  "<<ganador2<<"   3:  "<<ganador3<<"  4:  "<<ganador4<<endl;
	
	
}


int TrazaObjetos(){
	int actualim = 0,cont1=0,cont2= 0,cont3 = 0,cont4 = 0;
	float ganador = -1,ganador2 = -1,ganador3 =-1,ganador4 = -1;
	// ordenado
	actualim = 0;
   	int limiteIntervalo2 = rand()%(1500 - 1000 + 1) + 1000;
   	 int orden2[limiteIntervalo2];
	 for (int i = 1; i <= limiteIntervalo2; i++) {
	 	actualim++;
	 	cont1 ++;
        orden2[i]=i;

    }
     if(actualim >= TrazaOBJMin){
    	cout<<"C21 lista"<<endl;
	}else{
		return -1;
	}
	
	//desordenado sin repeticion
	actualim = 0;
	int desorden2[limiteIntervalo2];
	for (int i = 0; i < limiteIntervalo2; ++i) {
		actualim++;
		cont2++;
        desorden2[i] = i + 1;  
    }
    random_device rd2;
    mt19937 gen2(rd2());
    shuffle(desorden2, desorden2 + limiteIntervalo2, gen2);
	if(actualim >= TrazaOBJMin){
    	cout<<"C2.2 lista"<<endl;
	}else{
		return -1;
	}	
	
	// inverso
	actualim = 0;
 	int ivdef2[limiteIntervalo2];
	for(int i = limiteIntervalo2; i >= 1 ; i--){
		cont3++;
		actualim++;                                 // se supone que este for debe tomar el valor maximo permitido e ir decreciendo hasta el 1 y cada posicion se ira agregando 
		ivdef2[i] = i;
	}
	
	//desordenado con repeticion
	actualim = 0;
	int deso2[limiteIntervalo2];
    for(int i = 0; i < limiteIntervalo2; ++i){
        cont4++;
        actualim++;
        deso2[i] = rand()% limiteIntervalo2 + 1;  // Generar número aleatorio entre 1 y TrazaOBJMax
    }
     if(actualim >= TrazaOBJMin){
    	cout<<"C2 lista"<<endl;
	}else{
		return -1;
	}
	
	//medicion de tiempo <-----------<-------------<---------------<---------------<------------
	
	//ahora se debe tomar el timepo y se tomara el tiempo de cada funcion
	cout<<"ORDEN:  "<<endl;
	double tiempo_selection_sort = 0;
	double tiempo_insertion_sort = 0;
	double tiempo_bubble_sort = 0;
	double tiempo_shell_sort = 0;
	double tiempo_merge_sort = 0;
	double tiempo_quick_sort = 0;
	double tiempo_heap_sort = 0;

	auto start_time = high_resolution_clock::now();
	insertion_sort(orden2,cont1);
	auto end_time = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_selection_sort = duration.count();
	
	start_time = high_resolution_clock::now();
	bubble_sort(orden2,cont1);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_bubble_sort = duration.count();
	
	start_time = high_resolution_clock::now();	
	selection_sort(orden2,cont1);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_selection_sort = duration.count();
	
	start_time = high_resolution_clock::now();	
	shell_sort(orden2,cont1);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_shell_sort = duration.count();
	//----------------------------------------------------------
	start_time = high_resolution_clock::now();	
	mergeSort(orden2,0,limiteIntervalo2-1);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_merge_sort = duration.count();
	
	start_time = high_resolution_clock::now();	
//	quick_sort(orden2,0,limiteIntervalo2-1);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_quick_sort = duration.count();
//------------------------------------------------------------------------
//	--------------->--------->heap_sort<----------<-----------<-----------
	start_time = high_resolution_clock::now();	
	heapSort(orden2,limiteIntervalo2);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_heap_sort = duration.count();
	if(ganador < 0 || tiempo_insertion_sort < ganador ){
		ganador = tiempo_insertion_sort;
	}
	if(ganador < 0 || tiempo_bubble_sort < ganador ){
		ganador = tiempo_bubble_sort;
	}
	if(ganador < 0 || tiempo_selection_sort < ganador ){
		ganador = tiempo_selection_sort;
	}
	if(ganador < 0 || tiempo_shell_sort < ganador ){
		ganador = tiempo_shell_sort;
	}
	if(ganador < 0 || tiempo_merge_sort < ganador ){
		ganador = tiempo_merge_sort;
	}
	if(ganador < 0 || tiempo_heap_sort < ganador ){
		ganador = tiempo_heap_sort;
	}
	cout<<setprecision(10)<<"Insertion sort "<<tiempo_insertion_sort<<"\n"<<"Bubble sort "<<tiempo_bubble_sort<<endl;
	cout<<"Selection sort "<<tiempo_selection_sort<<"\n"<<"Shell  sort "<<tiempo_shell_sort<<endl;
	cout<<"Merge sort "<<tiempo_merge_sort<<"\n"<<"Quick sort "<<tiempo_quick_sort<<endl;
	cout<<"Heap Sort "<<tiempo_heap_sort<<endl;
	cout<<"Ganador: "<<ganador<<endl;
	// -------------->------------> desorden <---------<--------------<-------------------<-----------
	ganador2 = -1;
	cout<<" \ndesordenado"<<endl;
	double tiempo_selection_sort2 = 0;
	double tiempo_insertion_sort2 = 0;
	double tiempo_bubble_sort2 = 0;
	double tiempo_shell_sort2 = 0;
	double tiempo_merge_sort2 = 0;
	double tiempo_quick_sort2 = 0;
	double tiempo_heap_sort2 = 0;
	
	
	start_time = high_resolution_clock::now();
	insertion_sort(desorden2,cont2);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_insertion_sort2 = duration.count();
	
	start_time = high_resolution_clock::now();
	bubble_sort(desorden2,cont2);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_bubble_sort2 = duration.count();
	
	start_time = high_resolution_clock::now();
	selection_sort(desorden2,cont2);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_selection_sort2 = duration.count();
	
	start_time = high_resolution_clock::now();
	shell_sort(desorden2,cont2);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_shell_sort2 = duration.count();
	//----------------------------------------------------------
	start_time = high_resolution_clock::now();	
	mergeSort(desorden2,0,limiteIntervalo2-1);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_merge_sort2 = duration.count();
	
	start_time = high_resolution_clock::now();	
//	quick_sort(desorden2,0,limiteIntervalo2-1);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_quick_sort2= duration.count();
//------------------------------------------------------------------------
//	--------------->--------->heap_sort<----------<-----------------------
	start_time = high_resolution_clock::now();	
	heapSort(desorden2,limiteIntervalo2);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_heap_sort2 = duration.count();	
	if(ganador2 < 0 || tiempo_insertion_sort2 < ganador2 ){
		ganador2 = tiempo_insertion_sort2;
	}
	if(ganador2 < 0 || tiempo_bubble_sort2 < ganador2 ){
		ganador2 = tiempo_bubble_sort2;
	}
	if(ganador2 < 0 || tiempo_selection_sort2 < ganador2 ){
		ganador2 = tiempo_selection_sort2;
	}
	if(ganador2 < 0 || tiempo_shell_sort2 < ganador2 ){
		ganador2 = tiempo_shell_sort2;
	}
	if(ganador2 < 0 || tiempo_merge_sort2 < ganador2 ){
		ganador2 = tiempo_merge_sort2;
	}
	if(ganador2 < 0 || tiempo_heap_sort2 < ganador2 ){
		ganador2 = tiempo_heap_sort2;
	}
	
	cout<<"Insertion sort "<<tiempo_insertion_sort2<<"\n"<<"Bubble sort "<<tiempo_bubble_sort2<<endl;
	cout<<"Selection sort "<<tiempo_selection_sort2<<"\n"<<"Shell  sort "<<tiempo_shell_sort2<<endl;
	cout<<"Merge sort "<<tiempo_merge_sort2<<"\n"<<"Quick sort "<<tiempo_quick_sort2<<endl;
	cout<<"Heap Sort "<<tiempo_heap_sort2<<endl;
	cout<<"Ganador: "<<ganador2<<endl;

// -------------->------------> inverso <---------<--------------<-------------------<-----------
ganador3 = -1;
cout<<"\ninverso"<<endl;
double tiempo_selection_sort3 = 0;
	double tiempo_insertion_sort3 = 0;
	double tiempo_bubble_sort3 = 0;
	double tiempo_shell_sort3 = 0;
	double tiempo_merge_sort3 = 0;
	double tiempo_quick_sort3 = 0;
	double tiempo_heap_sort3 = 0;
	
	start_time = high_resolution_clock::now();
	insertion_sort(ivdef2,cont3);
	end_time = high_resolution_clock::now();
	duration = duration_cast<milliseconds>(end_time - start_time);
	tiempo_insertion_sort3 = duration.count();
	
	start_time = high_resolution_clock::now();
	bubble_sort(ivdef2,cont3);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_bubble_sort3 = duration.count();
	
	start_time = high_resolution_clock::now();
	selection_sort(ivdef2,cont3);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_selection_sort3 = duration.count();
	
	start_time = high_resolution_clock::now();
	shell_sort(ivdef2,cont3);
	end_time = high_resolution_clock::now();
	duration = duration_cast<milliseconds>(end_time - start_time);
	tiempo_shell_sort3  = duration.count();
	//----------------------------------------------------------
	start_time = high_resolution_clock::now();	
	mergeSort(ivdef2,0,limiteIntervalo2-1);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_merge_sort3 = duration.count();
	
	start_time = high_resolution_clock::now();	
//	quick_sort(ivdef2,0,limiteIntervalo2-1);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_quick_sort3 = duration.count();
//------------------------------------------------------------------------
//	--------------->----------->heap_sort<----------<--------------------
	start_time = high_resolution_clock::now();	
	heapSort(ivdef2,limiteIntervalo2);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_heap_sort3 = duration.count();	
	
	if(ganador3 < 0 || tiempo_insertion_sort3 < ganador3 ){
		ganador3 = tiempo_insertion_sort3;
	}
	if(ganador3 < 0 || tiempo_bubble_sort3 < ganador3 ){
		ganador3 = tiempo_bubble_sort3;
	}
	if(ganador3 < 0 || tiempo_selection_sort3 < ganador3 ){       //      aca se verifica quien se demoro menos si una se demoro 0 esta sera la que menos tiempo tardo
		ganador3 = tiempo_selection_sort3;
	}
	if(ganador3 < 0 || tiempo_shell_sort3 < ganador3 ){
		ganador3 = tiempo_shell_sort3;
	}
	if(ganador3 < 0 || tiempo_merge_sort3 < ganador3 ){
		ganador3 = tiempo_merge_sort3;
	}
	if(ganador3 < 0 || tiempo_heap_sort3 < ganador3 ){
		ganador3 = tiempo_heap_sort3;
	}
	
	cout<<"Insertion sort "<<tiempo_insertion_sort3<<"\n"<<"Bubble sort "<<tiempo_bubble_sort3<<endl;
	cout<<"Selection sort "<<tiempo_selection_sort3<<"\n"<<"Shell  sort "<<tiempo_shell_sort3<<endl;
	cout<<"Merge sort "<<tiempo_merge_sort3<<"\n"<<"Quick sort "<<tiempo_quick_sort3<<endl;
	cout<<"Heap Sort "<<tiempo_heap_sort3<<endl;
	cout<<"Ganador: "<<ganador3<<endl;

// -------------->------------> desorden con repeticion <---------<--------------<-------------------<-----------
cout<<"\ndesorden con repetir"<<endl;
ganador4 = -1;
double tiempo_selection_sort4 = 0;
	double tiempo_insertion_sort4 = 0;
	double tiempo_bubble_sort4 = 0;
	double tiempo_shell_sort4 = 0;
	double tiempo_merge_sort4 = 0;
	double tiempo_quick_sort4 = 0;
	double tiempo_heap_sort4 = 0;
	
	start_time = high_resolution_clock::now();
	insertion_sort(deso2,cont4);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_insertion_sort4 = duration.count();
	
	start_time = high_resolution_clock::now();
	bubble_sort(deso2,cont4);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_bubble_sort4 = duration.count();
	
	start_time = high_resolution_clock::now();
	selection_sort(deso2,cont4);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_selection_sort4 = duration.count();
	
	start_time = high_resolution_clock::now();
	shell_sort(deso2,cont4);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_shell_sort4  = duration.count();
	//----------------------------------------------------------
	start_time = high_resolution_clock::now();	
	mergeSort(deso2,0,limiteIntervalo2-1);
	end_time = high_resolution_clock::now();
	duration = duration_cast<milliseconds>(end_time - start_time);
	tiempo_merge_sort4 = duration.count();
	
	start_time = high_resolution_clock::now();	
//	quick_sort(deso2,0,limiteIntervalo2-1);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_quick_sort4 = duration.count();
//------------------------------------------------------------------------
//	--------------->----------->heap_sort<----------<---------------------
	start_time = high_resolution_clock::now();	
	heapSort(deso2,limiteIntervalo2);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_heap_sort4 = duration.count();	
	
	if(ganador4 < 0 || tiempo_insertion_sort4 < ganador4 ){
		ganador4 = tiempo_insertion_sort4;
	}
	if(ganador4 < 0 || tiempo_bubble_sort4 < ganador4 ){
		ganador4 = tiempo_bubble_sort4;
	}
	if(ganador4 < 0 || tiempo_selection_sort4 < ganador4 ){
		ganador4 = tiempo_selection_sort4;
	}
	if(ganador4 < 0 || tiempo_shell_sort4 < ganador4 ){
		ganador4 = tiempo_shell_sort4;
	}
	if(ganador4 < 0 || tiempo_merge_sort4 < ganador4 ){
		ganador4 = tiempo_merge_sort4;
	}
	if(ganador4 < 0 || tiempo_heap_sort4 < ganador4 ){
		ganador4 = tiempo_heap_sort4;
	}
	
	cout<<"Insertion sort "<<tiempo_insertion_sort4<<"\n"<<"Bubble sort "<<tiempo_bubble_sort4<<endl;
	cout<<"Selection sort "<<tiempo_selection_sort4<<"\n"<<"Shell  sort "<<tiempo_shell_sort4<<endl;
	cout<<"Merge sort "<<tiempo_merge_sort4<<"\n"<<"Quick sort "<<tiempo_quick_sort4<<endl;
	cout<<"Heap Sort "<<tiempo_heap_sort4<<endl;
	cout<<"Ganador: "<<ganador4<<endl;

	cout<<"\n\nLos ganadores fueron :"<<ganador<<"  2:  "<<ganador2<<"   3:  "<<ganador3<<"  4:  "<<ganador4<<endl;

	
}
int Evento_Escenario(){
	float ganador = -1,ganador2 = -1,ganador3 =-1,ganador4 = -1;
	int actualim = 0,cont1=0,cont2= 0,cont3 = 0,cont4 = 0;
	//ordenado
   int limiteIntervalo3 = rand()%(80000 - 60000 + 1) + 60000;
   int orden3[limiteIntervalo3];
	 for (int i = 1; i <= limiteIntervalo3; i++) {
	 	actualim++;
	 	cont1++;
        orden3[i]= i;
    }
     if(actualim >= EventoMin){
    	cout<<"C3 lista"<<endl;
	}else{
		return -1;
	}
	
	
	//desordenado sin repeticion
	actualim = 0;
	int desorden3[limiteIntervalo3];
	for (int i = 0; i < limiteIntervalo3; ++i) {
		actualim++;
		cont2++;
        desorden3[i] = i + 1;
    }
    random_device rd3;
    mt19937 gen3(rd3());
    shuffle(desorden3, desorden3 + limiteIntervalo3, gen3);	
	if(actualim >= EventoMin){
    	cout<<"C3 lista"<<endl;
	}else{
		return -1;
	}
	
	// inverso
	
 	int ivdef3[limiteIntervalo3];
	for(int i = limiteIntervalo3; i >= 1 ; i--){
		cont3++;
		actualim++;                                 // se supone que este for debe tomar el valor maximo permitido e ir decreciendo hasta el 1 y cada posicion se ira agregando 
		ivdef3[i] = i;
	}
	
	//desordenado con repeticion posible
	actualim = 0;
    int deso3[limiteIntervalo3];
    for(int i = 0; i < limiteIntervalo3; ++i){
        cont4++;
        actualim ++;
        deso3[i] = rand()% limiteIntervalo3 + 1;  // Generar número aleatorio entre 1 y EventoMax
    }
	if(actualim >= EventoMin){
    	cout<<"C3 lista"<<endl;
	}else{
		return -1;
	}
	
	
	//medicion de tiempo <-----------<-------------<---------------<---------------<------------
	
	//ahora se debe tomar el timepo y se tomara el tiempo de cada funcion
	cout<<"ORDEN:  "<<endl;
	double tiempo_selection_sort = 0;
	double tiempo_insertion_sort = 0;
	double tiempo_bubble_sort = 0;
	double tiempo_shell_sort = 0;
	double tiempo_merge_sort = 0;
	double tiempo_quick_sort = 0;
	double tiempo_heap_sort = 0;

	auto start_time = high_resolution_clock::now();
	insertion_sort(orden3,cont1);
	auto end_time = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_selection_sort = duration.count();
	
	start_time = high_resolution_clock::now();
	bubble_sort(orden3,cont1);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_bubble_sort = duration.count();
	
	start_time = high_resolution_clock::now();	
	selection_sort(orden3,cont1);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_selection_sort = duration.count();
	
	start_time = high_resolution_clock::now();	
	shell_sort(orden3,cont1);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_shell_sort = duration.count();
	//----------------------------------------------------------
	start_time = high_resolution_clock::now();	
	mergeSort(orden3,0,limiteIntervalo3-1);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_merge_sort = duration.count();
	
	start_time = high_resolution_clock::now();	
//	quick_sort(orden3,0,limiteIntervalo3-1);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_quick_sort = duration.count();
//------------------------------------------------------------------------
//	--------------->_------------->--------->heap_sort<----------<-------------
	start_time = high_resolution_clock::now();	
	heapSort(orden3,limiteIntervalo3);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_heap_sort = duration.count();

	if(ganador < 0 || tiempo_insertion_sort < ganador ){
		ganador = tiempo_insertion_sort;
	}
	if(ganador < 0 || tiempo_bubble_sort < ganador ){
		ganador = tiempo_bubble_sort;
	}
	if(ganador < 0 || tiempo_selection_sort < ganador ){
		ganador = tiempo_selection_sort;
	}
	if(ganador < 0 || tiempo_shell_sort < ganador ){
		ganador = tiempo_shell_sort;
	}
	if(ganador < 0 || tiempo_merge_sort < ganador ){
		ganador = tiempo_merge_sort;
	}
	if(ganador < 0 || tiempo_heap_sort < ganador ){
		ganador = tiempo_heap_sort;
	}
	

	cout<<"TIEMPO"<<endl;
	cout<<setprecision(10)<<"Insertion sort "<<tiempo_insertion_sort<<"\n"<<"Bubble sort "<<tiempo_bubble_sort<<endl;
	cout<<"Selection sort "<<tiempo_selection_sort<<"\n"<<"Shell  sort "<<tiempo_shell_sort<<endl;
	cout<<"Merge sort "<<tiempo_merge_sort<<"\n"/*<<"Quick sort "<<tiempo_quick_sort*/<<endl;
	cout<<"Heap Sort "<<tiempo_heap_sort<<endl;
	cout<<"Ganador:"<<ganador<<endl;
	
	// -------------->------------> desorden <---------<--------------<-------------------<-----------
	ganador2 = -1;
	cout<<" \ndesordenado"<<endl;
	double tiempo_selection_sort2 = 0;
	double tiempo_insertion_sort2 = 0;
	double tiempo_bubble_sort2 = 0;
	double tiempo_shell_sort2 = 0;
	double tiempo_merge_sort2 = 0;
	double tiempo_quick_sort2 = 0;
	double tiempo_heap_sort2 = 0;
	
	
	start_time = high_resolution_clock::now();
	insertion_sort(desorden3,cont2);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_insertion_sort2 = duration.count();
	
	start_time = high_resolution_clock::now();
	bubble_sort(desorden3,cont2);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_bubble_sort2 = duration.count();
	
	start_time = high_resolution_clock::now();
	selection_sort(desorden3,cont2);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_selection_sort2 = duration.count();
	
	start_time = high_resolution_clock::now();
	shell_sort(desorden3,cont2);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_shell_sort2 = duration.count();
	//----------------------------------------------------------
	start_time = high_resolution_clock::now();	
	mergeSort(desorden3,0,limiteIntervalo3-1);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_merge_sort2 = duration.count();
	
	start_time = high_resolution_clock::now();	
//	quick_sort(desorden3,0,limiteIntervalo3-1);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_quick_sort2 = duration.count();
//------------------------------------------------------------------------
//	--------------->_------------->--------->heap_sort<----------<------<-<-<-<--------<------------
	start_time = high_resolution_clock::now();	
	heapSort(desorden3,limiteIntervalo3);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_heap_sort2 = duration.count();
		
	if(ganador2 < 0 || tiempo_insertion_sort2 < ganador2 ){
		ganador2 = tiempo_insertion_sort2;
	}
	if(ganador2 < 0 || tiempo_bubble_sort2 < ganador2){
		ganador2 = tiempo_bubble_sort2;
	}
	if(ganador2 < 0 || tiempo_selection_sort2 < ganador2 ){
		ganador2 = tiempo_selection_sort2;
	}
	if(ganador2 < 0 || tiempo_shell_sort2 < ganador2 ){
		ganador2 = tiempo_shell_sort2;
	}
	if(ganador2 < 0 || tiempo_merge_sort2 < ganador2 ){
		ganador2 = tiempo_merge_sort2;
	}
	if(ganador2 < 0 || tiempo_heap_sort2 < ganador2 ){
		ganador2 = tiempo_heap_sort2;
	}		
		
	cout<<"Insertion sort "<<tiempo_insertion_sort2<<"\n"<<"Bubble sort "<<tiempo_bubble_sort2<<endl;
	cout<<"Selection sort "<<tiempo_selection_sort2<<"\n"<<"Shell  sort "<<tiempo_shell_sort2<<endl;
	cout<<"Merge sort "<<tiempo_merge_sort2<<"\n"<</*"Quick sort "<<tiempo_quick_sort2<<*/endl;
	cout<<"Heap Sort "<<tiempo_heap_sort2<<endl;
	cout<<"Ganador: "<<ganador2<<endl;
	
// -------------->------------> inverso <---------<--------------<-------------------<-----------
ganador3 = -1;
cout<<"\ninverso"<<endl;
	double tiempo_selection_sort3 = 0;
	double tiempo_insertion_sort3 = 0;
	double tiempo_bubble_sort3 = 0;
	double tiempo_shell_sort3 = 0;
	double tiempo_merge_sort3 = 0;
	double tiempo_quick_sort3 = 0;
	double tiempo_heap_sort3 = 0;
	
	start_time = high_resolution_clock::now();
	insertion_sort(ivdef3,cont3);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_insertion_sort3 = duration.count();
	
	start_time = high_resolution_clock::now();
	bubble_sort(ivdef3,cont3);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_bubble_sort3 = duration.count();
	
	start_time = high_resolution_clock::now();
	selection_sort(ivdef3,cont3);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_selection_sort3 = duration.count();
	
	start_time = high_resolution_clock::now();
	shell_sort(ivdef3,cont3);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_shell_sort3  = duration.count();
	//----------------------------------------------------------
	start_time = high_resolution_clock::now();	
	mergeSort(ivdef3,0,limiteIntervalo3-1);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_merge_sort3 = duration.count();
	
	start_time = high_resolution_clock::now();	
//	quick_sort(ivdef3,0,limiteIntervalo3-1);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_quick_sort3 = duration.count();
//------------------------------------------------------------------------
//	--------------->_------------->--------->heap_sort<----------<------<-<-<-<--------<------------
	start_time = high_resolution_clock::now();	
	heapSort(ivdef3,limiteIntervalo3);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_heap_sort3 = duration.count();	
	
	if(ganador3 < 0 || tiempo_insertion_sort3 < ganador3 ){
		ganador3 = tiempo_insertion_sort3;
	}
	if(ganador3 < 0 || tiempo_bubble_sort3 < ganador3 ){
		ganador3 = tiempo_bubble_sort3;
	}
	if(ganador3 < 0 || tiempo_selection_sort3 < ganador3 ){
		ganador3 = tiempo_selection_sort3;
	}
	if(ganador3 < 0 || tiempo_shell_sort3 < ganador3 ){
		ganador3 = tiempo_shell_sort3;
	}
	if(ganador3 < 0 || tiempo_merge_sort3 < ganador3 ){
		ganador3 = tiempo_merge_sort3;
	}
	if(ganador3 < 0 || tiempo_heap_sort3 < ganador3 ){
		ganador3 = tiempo_heap_sort3;
	}	
	
	cout<<"Insertion sort "<<tiempo_insertion_sort3<<"\n"<<"Bubble sort "<<tiempo_bubble_sort3<<endl;
	cout<<"Selection sort "<<tiempo_selection_sort3<<"\n"<<"Shell  sort "<<tiempo_shell_sort3<<endl;
	cout<<"Merge sort "<<tiempo_merge_sort3<<"\n"/*<<"Quick sort "<<tiempo_quick_sort3*/<<endl;
	cout<<"Heap Sort "<<tiempo_heap_sort3<<endl;
	cout<<"Ganador: "<<ganador3<<endl;		

// -------------->------------> desorden con repeticion <---------<--------------<-------------------<-----------
	ganador4 = -1;
	cout<<"\ndesorden con repetir"<<endl;
	double tiempo_selection_sort4 = 0;
	double tiempo_insertion_sort4 = 0;
	double tiempo_bubble_sort4 = 0;
	double tiempo_shell_sort4 = 0;
	double tiempo_merge_sort4 = 0;
	double tiempo_quick_sort4 = 0;
	double tiempo_heap_sort4 = 0;
	
	start_time = high_resolution_clock::now();
	insertion_sort(deso3,cont4);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_insertion_sort4 = duration.count();
	
	start_time = high_resolution_clock::now();
	bubble_sort(deso3,cont4);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_bubble_sort4 = duration.count();
	
	start_time = high_resolution_clock::now();
	selection_sort(deso3,cont4);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_selection_sort4 = duration.count();
	
	start_time = high_resolution_clock::now();
	shell_sort(deso3,cont4);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_shell_sort4  = duration.count();
	//----------------------------------------------------------
	start_time = high_resolution_clock::now();	
	mergeSort(deso3,0,limiteIntervalo3-1);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_merge_sort2 = duration.count();
	
	start_time = high_resolution_clock::now();	
//	quick_sort(deso3,0,limiteIntervalo3-1);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_quick_sort2 = duration.count();
//------------------------------------------------------------------------
//--------------->--------------->heap_sort<-----------------<------------
	start_time = high_resolution_clock::now();	
	heapSort(deso3,limiteIntervalo3);
	end_time = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end_time - start_time);
	tiempo_heap_sort3 = duration.count();
	
	if(ganador4 < 0 || tiempo_insertion_sort4 < ganador4 ){
		ganador4 = tiempo_insertion_sort4;
	}
	if(ganador4 < 0 || tiempo_bubble_sort4 < ganador4 ){
		ganador4 = tiempo_bubble_sort4;
	}
	if(ganador4 < 0 || tiempo_selection_sort4 < ganador4 ){
		ganador4 = tiempo_selection_sort4;
	}
	if(ganador4 < 0 || tiempo_shell_sort4 < ganador4 ){
		ganador4 = tiempo_shell_sort4;
	}
	if(ganador4 < 0 || tiempo_merge_sort4 < ganador4 ){
		ganador4 = tiempo_merge_sort4;
	}
	if(ganador4 < 0 || tiempo_heap_sort4 < ganador4 ){
		ganador4 = tiempo_heap_sort4;
	}
	
	cout<<"Insertion sort "<<tiempo_insertion_sort4<<"\n"<<"Bubble sort "<<tiempo_bubble_sort4<<endl;
	cout<<"Selection sort "<<tiempo_selection_sort4<<"\n"<<"Shell  sort "<<tiempo_shell_sort4<<endl;
	cout<<"Merge sort "<<tiempo_merge_sort4<<"\n"/*<<"Quick sort "<<tiempo_quick_sort4*/<<endl;
	cout<<"Heap Sort "<<tiempo_heap_sort4<<endl;
	cout<<"Ganador: "<<ganador<<endl;
	
	cout<<"\n\nLos ganadores fueron :"<<ganador<<"  2:  "<<ganador2<<"   3:  "<<ganador3<<"  4:  "<<ganador4<<endl;

	
}


int main(){
int wh1 = 0;
srand(time(NULL));	
	
cout<<"____________________________________________________________________________________"<<endl;
cout<<"________________________________Carrera  del  orden_________________________________"<<endl;
Sleep(1000);
cout<<"                      deberas elegir con cual de ls 4 opciones                      "<<endl;
cout<<"  crees que se ordenara mas rapido los numeros y de la forma en la que se entregaran    \n                        para ser de los mejores guardianes del reino"<<endl;
cout<<"____________________________________________________________________________________"<<endl;
Sleep(1000);
cout<<"."<<endl;
Sleep(1000);
cout<<"."<<endl;
Sleep(700);
cout<<"."<<endl;
Sleep(700);
cout<<"."<<endl;
Sleep(800);
cout<<"."<<endl;
Sleep(1000);
system("cls");


int question = 0;
while(wh1== 0){
	wh1 = 0;
	cout<<"___________________Que opcion desea elegir____________________"<<endl;
	cout<<"           Opcion_________cola de espera________1             "<<endl;  //acas edaran las opciones de que deben elegirr suceptible a cambio
	cout<<"           Opcion____trazabilidad de objetos____2             "<<endl;
	cout<<"           Opcion___evento de cada escenario____3             "<<endl;
	cout<<"           Opcion_____________salir_____________4             "<<endl;
	cout<<"______________________________________________________________"<<std::endl;
	cin>> question;
	switch(question){
		case 1:
			if(colaDEspera() == -1){
				cerr<<"el proceso esta incorrecto"<<endl;
				break;
			}
			break;
		case 2:
			if(TrazaObjetos() == -1){
				cerr<<"el proceso esta incorrecto"<<endl;
				break;
			}
			break;
		case 3:
			//formacion3();
			if(Evento_Escenario() == -1){
				cerr<<"el proceso esta incorrecto"<<endl;
				break;
			}
			break;
		
		case 4:	
			wh1= 1;
			break;
		default: cout<<"incorrecto vuelva a ingresar"<<endl;
	}
}
	
	
	//fin
	cout<<"Gracias pro asistir a las carreras"<<endl;
	Sleep(800);
	return 0;
}
