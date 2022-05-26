#include <iostream>

using namespace std;

// Funcion de fibonacci que calcula n-esimo termino
int fibonacci(int n){
    if (n==0 || n==1){
        return n;
    } else {
    int a = 0;
    int b = 1;
    int res;
    for(int i=2;i<=n;i=i+1){
        res = a + b;
        a = b;
        b = res;
    }
    return res;
        
    }
    

}
int main() 
{
    int n;
    cin >> n;
    cout << fibonacci(n) << endl;    
    return 0;
}