#include "ejercicios.h"

vector<vector<int> > productoVectorial(vector<int> u, vector<int> v){
    vector<vector<int>> res(u.size(), vector<int>(v.size()));
    int i=0;
    while (i<u.size()){
        int j=0;
        while(j<v.size()){
            res[i][j] = u[i] * v[j];
            j=j+1;
        }
        i=i+1;
    }
	return res;
}







void trasponer(vector<vector<int> > &m) {
    vector<vector<int>> aux=m;
    int i=0;
    while (i<m.size()){
        int j=0;
        while (j<m.size()){
            m[i][j]=aux[j][i];
            j++;
        }
        i++;
    }
	return;
}










int sumatoria (int i, int j, vector<vector<int>> m1,  vector<vector<int>> m2){
    int k=0;
    int cuenta=0;
    while (k<m2.size()){
        cuenta=cuenta+ m1[i][k] * m2[k][j];
        k++;
    }
    return cuenta;
}
vector<vector<int> > multiplicar(vector<vector<int> > m1, vector<vector<int> > m2){
	vector<vector<int>> res(m1.size(), vector<int>(m2[0].size()));
    int i=0;
    while (i<m1.size()){
        int j=0;
        while (j<m2[0].size()){
            res[i][j]= sumatoria(i,j,m1,m2);
            j++;
        }
        i++;
    }
    return res;
}










int sumatoria2(int i, int j, vector<vector<int>> m){
    int count=0;
    int k=i-1;
    while (k<i+2){
        if (k<m.size()){
            int h=j-1;
            while (h<j+2){
                if (h<m[0].size()) {
                    count = count + m[k][h];
                }
                h++;
            }
        }
        k++;
    }
    return count;
}
int cantidad(int i, int j, vector<vector<int>> m){
    int count2=0;
    int k=i-1;
    while (k<i+2){
        if (k<m.size()){
            int h=j-1;
            while (h<j+2){
                if (h<m[0].size()){
                    count2 = count2 + 1;
                }
                h++;
            }
        }
        k++;
    }
    return count2;
}
int promedio(int i, int j, vector<vector<int>> m){
    return (sumatoria2(i,j,m) / cantidad(i,j,m));
}
vector<vector<int>> promediar(vector<vector<int>> m){
    vector<vector<int>> res(m.size(),vector<int>(m[0].size()));
    int i=0;
    while (i<m.size()){
        int j=0;
        while (j<m[0].size()){
            res[i][j] = promedio(i,j,m);
            j++;
        }
        i++;
    }
    return res;
}










bool espico(int i, int j, vector<vector<int>> m){
    int a = i-1;
    bool res = true;
    while (a<i+2){
        if (a<m.size()){
            int b=j-1;
            while (b<j+2){
                if (b<m[0].size() && (a!=i || b!=j)){
                    if (m[i][j]>m[a][b]) {
                    } else{
                        res = false;
                    }
                }
                b=b+1;
            }
        }
        a=a+1;
    }
    return res;
}
int contarPicos(vector<vector<int> > m){
	int picos = 0;
    int i=0;
    while (i<m.size()){
        int j = 0;
        while (j<m[0].size()){
            if (espico(i,j,m)){
                picos++;
            }
            j++;
        }
        i++;
    }
	return picos;
}













bool esTriangular(vector<vector<int> > m){
	bool inferior=true;
    bool superior=true;
    int i=0;
    while (i<m.size()){
        int j=0;
        while (j<m[0].size()){
            if (j>i){
                if (m[i][j]!=0){
                    superior= false;
                }
            }
            if  (i>j){
                if (m[i][j]!=0){
                    inferior=false;
                }
            }
            j++;
        }
        i++;
    }
	return (superior || inferior);
}











bool seAmenazan(int i1, int j1, int i2, int j2){
    return (i1!=i2 || j1!=j2) && ((i1==i2) || (j1==j2) || (abs(i1-i2)==abs(j1-j2)));
}
bool hayAmenaza(vector<vector<int> > m){
	bool amenaza = false;
    int i1=0;
    while (i1<m.size()){
        int j1=0;
        while (j1<m[0].size()){
            if (m[i1][j1]==1) {
                int i2 = 0;
                while (i2 < m.size()) {
                    int j2 = 0;
                    while (j2 < m[0].size()) {
                        if (m[i2][j2]==1 && seAmenazan(i1, j1, i2, j2)) {
                            amenaza = true;
                        }
                        j2++;
                    }
                    i2++;
                }
            }
            j1++;
        }
        i1++;
    }
	return amenaza;
}















int diferenciaDiagonales(vector<vector<int> > m) {
    int diagonal1=0;
    int diagonal2=0;
    int i=0;
    while (i<m.size()){
        int j=0;
        while (j<m.size()){
            if (i==j){
                diagonal1=diagonal1+m[i][j];
            }
            j++;
        }
        i++;
    }
    int i2=0;
    while (i2<m.size()){
        int j2=0;
        while (j2<m.size()){
            if (i2==m.size()-1-j2){
                diagonal2=diagonal2+m[i2][j2];
            }
            j2++;
        }
        i2++;
    }
    return abs(diagonal1-diagonal2);
}


















