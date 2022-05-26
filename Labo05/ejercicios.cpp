#include "ejercicios.h"


// Ejercicio 1
bool existePico(vector<int> v){
    int i = 0;
    bool res = false;
    while (i < (v.size()-1)) {
        if ((v[i]>v[i-1])&&(v[i]>v[i+1])){
            res = true;
        }
        i++;
    }
    return res;
}

// Ejercicio 2
int mcd(int m, int n){
    int res;
    int a = max(n,m);
    int b = min(n,m);
    while (b != 0){
        res = b;
        b = a % b;
        a = res;
    }
	return res;
}

// Ejercicio 3
int indiceMinSubsec(vector<int> v, int l, int r){
    int res = l;
    int i = l+1;
    while (i <= r){
        if (v[res]<=v[i]){
        } else{
            res = i;
        }
        i++;
    }
	return res;
}

// Ejercicio 4
void ordenar1(vector<int>& v){
    for(int m=0;m<v.size();m++){
        for(int n=0;((n<v.size())&&(n!=m));n++){
            if(v[m]<=v[n]){
                int aux = v[n];
                v[n]=v[m];
                v[m]=aux;
            }
        }

    }
}

// Ejercicio 5
void ordenar2(vector<int>& v){
	return;
}

// Ejercicio 6
tuple<int,int> division(int n, int d){
	return make_tuple(0,0);
}
