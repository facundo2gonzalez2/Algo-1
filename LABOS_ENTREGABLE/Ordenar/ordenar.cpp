#include <vector>
#include <iostream>

using namespace std;


void ordenar1(vector<int>& v) {
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

void ordenar2(vector<int> &v){
    int i=0;
    while (i<v.size()){
        if((v[i]<=v[i+1]) & (i<v.size()-1)){
            int aux = v[i];
            v[i+1]=v[i];
            v[i]=aux;
        }
        int k=0;
        while((k<v.size()-1)&(i>0)&(k>=i)){
            if (v[k]<v[i-1]){
                int aux2 = v[i-1];
                v[i-1]=v[k];
                v[k]=aux2;
            }
        }
        k++;
        i++;
    }


}

int main() {
    /* No hace falta modificar el main */
    
    // Leo las entradas
    int n; //Longitud del vector
    cin >> n;
    int i = 0;
    int x;
    vector<int> v;// En v leo el vector
    while (i<n){
        cin >> x;
        v.push_back(x);
        i++;
    }

    // Hago el ordenamiento
    ordenar1(v);
    
    // Imprimo el vector resultado
    i = 0;
    while (i < v.size()){
        cout << v[i] << " ";
        i++;
    }
    
    return 0;
}
