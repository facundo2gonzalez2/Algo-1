#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
void swap(vector<int> &v,int i, int j){
    int aux = v[i];// O(1)
    v[i] = v[j];// O(1)
    v[j] = aux;// O(1)
}
void insert(vector<int> &v, int i){
    for(int j = i; j > 0 && v[j] > v[j-1]; j--){
        swap(v, j, j-1);// O(1)
    }
}
void insertionSort(vector< int > &arr){
    for(int i = 0; i<arr.size(); i++){// O(n*n)
        insert(arr, i);// O(n)
    }
}
void ordenar(vector<int> &items){
    insertionSort(items);
    // Poner aca una implementación de ordenar
    
    // Atencion: no todas las implementaciones son
    // suficientemente rápidas para resolver en el
    // tiempo máximo permitido de la prueba automatizada.
    // Elegir entre las implementaciones vistas en
    // clase.
    //
    // Observación:
    // No vale usar std::sort()
}


int bestFit(int W, vector<int> &items){
    multiset<int> restos;
    for(int i=0; i<(int)items.size(); ++i){
        restos.insert(W);
    }
    int res = 0;
    for(int i=0; i<(int)items.size(); ++i){
        multiset<int>::iterator it = restos.lower_bound(items[i]);
        int restoAct = *it;
        if(restoAct==W){
            res++;
        }
        restoAct -= items[i];
        restos.erase(it);
        restos.insert(restoAct);
    }
    return res;
}

int main(){
    int N, W, aux;

    //Se levantan los items y la capacidad del contenedor
    cin >> N >> W;
    vector<int> items;
    for(int i=0; i<N; ++i){
        cin >> aux;
        items.push_back(aux);
    }
    //Se corre best-fit
    int cant1 = bestFit(W, items);
    cout << "Con la idea bestFit, se consigue una asignacion con " << cant1 << " contenedores" << endl;

    //Se ordenan los items
    ordenar(items);
    //Se corre best-fit-decreasing
    int cant2 = bestFit(W, items);
    cout << "Con la idea bestFitDecreasing, se consigue una asignacion con " << cant2 << " contenedores" << endl;

    return 0;
}

