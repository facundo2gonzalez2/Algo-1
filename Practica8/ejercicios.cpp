#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


// ejercicios práctica 8

//ejercicio 5
//calcular el tiempo de ejercucion de HacerAlgo con respecto a |v|

vector<int> construir_vector(int n, string disposicion){

    vector<int> res;
    srand (time(NULL));
    int numero;

    if (disposicion == "asc"){
        for(int i=0; i < n; i++){
            res.push_back(i);
        }
    }else if(disposicion == "desc"){
        for(int i=n-1; i >= 0; i--){
            res.push_back(i);
        }

    }else if(disposicion == "azar"){
        for(int i=0; i < n; i++){
            numero = rand() % 100;
            res.push_back(numero);
        }
    }else if(disposicion == "iguales"){
        numero = rand() % 100;
        for(int i=0; i < n; i++){
            res.push_back(numero);
        }
    }else{
        cout << "Dispocisión no válida" << endl;
    }

    return res;
}

int contarApariciones(vector<int> &v, int elem) {
    int cantAp = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == elem) {
            cantAp++;
        }
    }
    return cantAp;
}
vector<int> hacerAlgo(vector<int> &v) {
    vector<int> res;
    for (int i = 0; i < 100; i++) {
        res.push_back(contarApariciones(v, i + 1));
    }
    return res;
}
