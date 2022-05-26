#include <iostream>

using namespace std;

int maximo(int x, int y){
  if(x<0)
    x=-x;
  if(y<0)
    y=-y;
  if(x>y)
    return x;
  else
    return y;
}

int minimo(int x, int y){
  if(x<0)
    x=-x;
  if(y<0)
    y=-y;
  if(x<y)
    return x;
  else
    return y;
}

int maximoComunDivisor(int x, int y){
    int a = maximo(x,y);
    int b = minimo(x,y);
    int resto;
    if(x==0 && y==0){
        resto=0;
    } else{
        while(b!=0){
            resto = b;
            b = a % b;
            a = resto;
        }
    }
    return resto;
 }

int main() {
    /* No hace falta modificar el main */
    int a,b;
    //Leo a
    cin >> a >> b;
    
    int res = maximoComunDivisor(a,b);
    
    //Devuelvo el maximo comun divisor
    cout << res;
    return 0;
}
