#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "anagramas.h"
using namespace std;

int main(){
    string palabra, palabra2;
    cout << "Ingrese una palabra en ingles con letras en minuscula:" << endl;
    cin >> palabra;

    ifstream dicci ("ingles.dic");
    vector<string> listaPalabras;
    string word;
    while(getline(dicci, word)){
        listaPalabras.push_back(word);
    }
    int cantidadAnagrama = 0;
    for (int i = 0; i < listaPalabras.size(); ++i)
    {
        if (esAnagrama(listaPalabras[i], palabra)) {
            cout << "Son anagramas: " << listaPalabras[i] << " y " << palabra << endl;
            cantidadAnagrama++;
        }
    }
    cout << "La cantidad de anagramas es: " << cantidadAnagrama << endl;
    return 0;
}


bool esAnagrama(string p1, string p2){
    // CAMBIAR AQUI QUE IMPLEMENTACION USAR
    //return esAnagrama1(p1,p2);
    return esAnagrama2(p1,p2);
}







bool esAnagrama1(string p1, string p2){
    //devuelve true sii p1 es anagrama de p2
    //esta versión usa ordenar
    ordenarString(p1);
    ordenarString(p2);
    return p1 == p2;
}
void swap(string &v,int i, int j){
    char aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}
void insert(string &v, int i){
    for(int j = i; j > 0 && v[j] < v[j-1]; j--){
        swap(v, j, j-1);
    }
}
void ordenarString(string &palabra){
    //COMPLETAR
    //Asumir que palabra solo contiene letras minusculas de a-z (sin enie). Implementar cualquier algoritmo
    for(int i = 0; i<palabra.size(); i++){
        insert(palabra, i);
    }
}











bool esAnagrama2(string p1, string p2){
    //COMPLETAR
    //devuelve true sii p1 es anagrama de p2
    //esta versión usa el mapeo de letras a números primos. Utilizar charToPrimo()

    vector<int> primosDep1(p1.size());
    for(int i=0;i<p1.size();i++){
        primosDep1[i]= charToPrimo(p1[i]);
    }
    int productoDep1=1;
    for(int i=0;i<primosDep1.size();i++){
        productoDep1=productoDep1*primosDep1[i];
    }


    vector<int> primosDep2(p2.size());
    for(int i=0;i<p2.size();i++){
        primosDep2[i]= charToPrimo(p2[i]);
    }
    int productoDep2=1;
    for(int i=0;i<primosDep2.size();i++){
        productoDep2=productoDep2*primosDep2[i];
    }
    return productoDep1==productoDep2;
}
bool esPrimo(int n){
    if(n==0||n==1){
        return false;
    }
    if(n==2){
        return true;
    }
    for (int x = 2; x < n; x++) {
        if (n % x == 0) {
            return false;
        }
    }
    return true;
}
int enesimoPrimo(int n){
    if(n<0){
        return -1;
    }
    if(n==0){
        return 2;
    }
    if(esPrimo(n)){
        return enesimoPrimo(n-1)+n;
    }else{
        return enesimoPrimo(n-1);
    }
}
int charToPrimo(char c){
    int pos = posicionEnAlfabeto(c);
	return enesimoPrimo(pos);
}
int posicionEnAlfabeto(char c){
    return c - 'a';
}