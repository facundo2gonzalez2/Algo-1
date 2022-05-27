#include "ejercicios.h"

using namespace std;

int main() {
    int n=0;
    int hasta = 1000;
    int paso = 10;
    ofstream fout;
    fout.open("datos.csv");
    fout << "n\t" << "tiempo" <<endl;
    while (n<hasta){
        vector<int> v = construir_vector(n , "asc");

        double t0=clock();
        bool busqueda = algunSubconjSuma(v, n/2);
        double t1=clock();

        double tiempo = (double (t1-t0) / CLOCKS_PER_SEC);

        fout << n << "\t" << tiempo << endl;

        n += paso;
    }
    fout.close();



    return 0;
}

//python graficar.py -i cmake-build-debug\datos.csv -o lineal.png