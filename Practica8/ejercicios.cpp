#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


// ejercicios práctica 8


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

//ejercicio 2
// Ejercicio 2a
void f(vector<int> &v) { // |v| = n
    int i = v.size() / 2; // 3
    while (i >= 0) { // 2, n/2 iteraciones
        v[v.size() / 2 - i] = i; // 6
        v[v.size() / 2 + i] = i; // 6
        i--; // 1
    } // t(n) = 2 + 15(n/2)
} // t(n) = 5 + 15(n/2) -> O(n)


// Ejercicio 2b
// PRE: e pertenece a v1
int f(vector<int> &v1, int e) {
    int i = 0; // 1
    while (v1[i] != e) { // 4, n iteraciones
        i++; // 1
    } // t(n) = 4 + 5n
    return i; // 1
} // t(n) = 6 + 5n


// Ejercicio 2c
vector<int> f(vector<int> &v1, vector<int> &v2) { // |v1| = n, |v2| = m
    vector<int> res; // 1
    for (int i = 0; i < v1.size(); i++) { // init: 1, guarda: 3, incremento: 1, n iteraciones
        res.push_back(v1[i]); // 3
    } // t(n) = 4 + 7n
    for (int i = 0; i < v2.size(); i++) { // init: 1, guarda: 3, incremento: 1, m iteraciones
        res.push_back(v2[i]); // 3
    } // t(m) = 4 + 7m
    return res; // 1
} // t(n,m) = 10 + 7n + 7m -> O(n + m)


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


// ejercicio 8
int detTriangular(vector<vector<int> > M) { // |M| = n
    int i = 0; // 1
    int res = 1; // 1
    while (i<M.size()) { // 3, n iteraciones
        res = res * M[i][i]; // 6
    } // t(n) = 3 + 9n
    return res; // 1
} // t(n) = 6 + 9n -> O(n)
// En función de la cantidad de filas: n = sqrt(|M|)
// t(n) -> O(n) = O(sqrt(|M|))
bool esTriangular(vector<vector<int> > M) {// |M| = n
    bool res = true; // 1
    for (int i=0; i<M.size(); i++) { // init: 1, guarda: 3, incremento: 1, n iteraciones
        for (int j=0; j < i; j++) { // init: 1, guarda: 3, incremento: 1, (i-1) iteraciones
            res = res && M[i][j] == 0; // 7
        } // t(i) = 4 + 11i
    } // t(n) = 4 + suma(i=0,n-1)(4 + 11i)
    return res; // 1
} // t(n) = 4 + 4n + 11*(n*(n-1)/2) (suma de gauss 0...n-1)
// = 4 + 4n + (11n²-11n)/2 -> O(n²)
// En función de la cantidad de filas: n = sqrt(|M|)
// t(n) -> O(n²) = O(sqrt(|M|)²) = O(|M|)


//ejercicio 9
// Pre: m1 y m2 son matrices, y |m1[0]| = |m2|
vector<vector<int> > multiplicar(vector<vector<int> > m1, vector<vector<int> > m2) {
//|m1|=n, |m1[0]|=|m2|=m, |m2[0]|=r
    vector<vector<int> > res; // 1
    for (int i=0; i < m1.size(); i++) { // init: 1, guarda: 3, incremento: 1, n iteraciones
        vector<int> fila; // 1
        for (int j=0; j<m2[0].size(); j++) { // init: 1, guarda: 3, incremento: 1, r iteraciones
            int v=0; // 1
            for (int k=0; k<m2.size(); k++) { // init: 1, guarda: 3, incremento: 1, m iteraciones
                v += m1[i][k]*m2[k][j]; // 9
            } // t(m) = 4 + 13m
            fila.push_back(v); // 2
        } // t(r,m) = 4 + r*(4 + 13m)
        res.push_back(fila); // 2
    } // t(n,r,m) = 4 + n*(4 + r*(4 + 13m))
    return res; // 1
} // t(n,r,m) = 6 + n*(4 + r*(4 + 13m)) = 6 + 4n + 4nr+ 13nrm// -> O(n*r*m)
// item 3.2) n=m=r
// t(n,r,m) = 6 + 4n + 4n² + 13n³ -> O(n³)



//Ejercicio 12 parecido (video de la practica)
vector<int> restarLosPares(vector<int> S, int x) { // |s| = n
     vector<int> res; // 1
     int i = 0; // 1
     int suma = 0; // 1
     while (i<S.size()) { // 3, n iteraciones
         if (S[i] % 2 == 0) { // 4
             suma += S[i]; // 5
             res.push_back(x - suma);// 1
         }
     } // t(n) = 3 + 13n
             return res; // 1
} // t(n) = 7 + 13n -> O(n)















