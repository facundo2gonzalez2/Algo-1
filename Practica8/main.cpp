#include <iostream>
#include "ejercicios.h"
using namespace std;


int main() {
    vector<int> v(1000000,10);
    double t0 = clock();
    vector<int> nuevovector = hacerAlgo(v);
    double t1 = clock();

    double tiempo = (double(t1-t0)/CLOCKS_PER_SEC);

    cout << "El tiempo fue de " << tiempo << "segundos" << endl;

    return 0;
}
