#include "ejercicios.h"

using namespace std;

int main() {
    int n=1;
    int hasta = 100000;
    int paso = 100;
    ofstream fout;
    fout.open("datos_ejercicio5g.csv");
    fout << "n\t" << "tiempo" <<endl;
    while (n<hasta){
        vector<int> v= construir_vector(n,"asc");

        double t0=clock();
        v.clear();
        double t1=clock();

        double tiempo = (double (t1-t0) / CLOCKS_PER_SEC);

        fout << n << "\t" << tiempo << endl;

        n += paso;
    }
    fout.close();



    return 0;
}

//python graficar.py -i cmake-build-debug\datos.csv -o lineal.png