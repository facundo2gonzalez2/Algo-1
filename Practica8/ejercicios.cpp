#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;


// ejercicios práctica 8

//ejercicio 5
//calcular el tiempo de ejercucion de HacerAlgo con respecto a |v|

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
