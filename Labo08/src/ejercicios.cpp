#include "ejercicios.h"

#include <utility>
#include <algorithm>

/* Para compilar */ 

using namespace std;

vector<string> split(string s, char delim){
	vector<string> v;
//	int i=0;
//    while (i<s.size()){
//        if (s[i]==delim){
//            int indice=i;
//        }
//        int j=0;
//
//
//    }

    return v;
}

string darVueltaPalabra(string s){
	string res;
	return res;
}

// Decidir si s1 es substring o subsecuencia de s2
bool subsecuencia(string s1, string s2) {
    int cont=0;
    int i=0;
    int j=0;
    while (i<s1.size()){
        while  (j<s2.size()){
            if (s1[i]==s2[j]){
                cont++;
                j++;
                break;
            }
            j++;
        }
        i++;
    }
    return (cont>=s1.size());
}

// Mismo orden relativo de conjunto de anagramas y dentro de cada vector y con repetidos
vector<vector<string> > agruparAnagramas(vector<string> v){
	vector<vector<string> > res;
	return res;
}

bool esPalindromo(string s){
	bool cumple = true;
	return cumple;
}

bool tieneRepetidos(string s){
	bool distinto = true;
	return !distinto;
}

string rotar(string s, int j){
    string res(s);
    if (j>=s.size()){
        j= j % s.size();
    }
        int k = j;
        while (j > 0) {
            res[j - 1] = s[s.size() - 1];
            s.pop_back();
            j--;
        }
        int h = 0;
        while (k < res.size()) {
            res[k] = s[h];
            h++;
            k++;
        }
    return res;
}

// no se puede usar substring
string darVueltaK(string s, int k){
	string res(s);
	return res;
}

string abueloLaino(string s){
    string res;
    return res;
}

int cantidadDeFelicitaciones(vector<string> v){
    int res;
    return res;
}

bool tienenMismasLetras(string s, string t){
    bool res = true;
    int i=0;
    while (i<s.size()){
        int j=0;
        while (j<t.size()){
            if (s[i]!=s[j]){

            }

        }
    }
    return ((s.size()==t.size()) & res);
}
void ordenar(vector<int>& v) {
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v.size();j++){
            if(v[i]<=v[j]){
                int aux = v[j];
                v[j]=v[i];
                v[i]=aux;
            }
        }
    }
}
int contadorMovimientosDeSaT(vector<int> s, vector<int>t){
    int contador=0;
    for(int i=0;i<s.size();i++){
        for(int j=0;j<s.size();j++){
            if(s[i]<=s[j]){
                int aux = s[j];
                s[j]=s[i];
                s[i]=aux;
                contador++;
            }
        }
    }
    return contador;
}


int middleOut(string s, string t){
    int movimientos=-1;
    vector<int> posicionesDeT(t.size());
    vector<int> posicionesDeS(s.size());
    int k=0;
    while (k<t.size()){
        posicionesDeT[k]=k;
        k++;
    }
    if (s.size()!=t.size()){
        return movimientos;
    }
 //   if (!tienenMismasLetras(s,t)){
 //       return movimientos;
 //   }
    int i=0;
    while (i<s.size()){
        int j=0;
        while (j<t.size()){
            if (s[i]==t[j]){
                posicionesDeS[i]=j;
            }
            j++;
        }
        i++;
    }
    movimientos = contadorMovimientosDeSaT(posicionesDeS,posicionesDeT);
    return movimientos;
}






