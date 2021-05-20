#include <bits/stdc++.h>
#define MAXN 2187+1
using namespace std;
int A[MAXN][MAXN];
int anss[3];

void print(int a, int b, int u, int v){
    for (int i = a; i <= u; i ++){
        for (int j = b; j <= v; j++)
            cout << A[i][j] << " ";
        cout<< endl;
    }
}

int process(int a, int b, int l){
    //cout<< "l dayyy " << l << endl;
    if (l==1){
        return A[a][b];
    }
    int res = 0;
    int ans[3] = {0,0,0};
    bool flag = true;
    l /= 3;
    for (int i = 0; i < 3; i ++){
        for (int j = 0; j < 3; j++){
            int x, y;
            x = a + l*i;
            y = b + l*j;
            //cout<< "x voi y ne " << x << " " << y <<endl;
            int aa = process(x,y,l);
            if (aa >= 0){
                ans[aa] ++;
            }
            if (aa < 0 || (a >= 0 && A[a][b] != A[x][y]) || !flag){
                flag = false;
            }
        }
    }
    /*
    l *=3;
    cout<< a << " " << b <<" " << a+l-1 << " " << b+l-1  << endl;
    print(a,b,a+l-1,b+l-1);
    string ress = (flag) ? "true nha " :  "false roi thang lon" ;
    cout<< ress <<endl << ans[0] << " " << ans[1] << " " << ans[2] << endl;
    //cout<< anss[0] << " " << anss[1] << " " << anss[2] << endl;
    //cout<< " ---- " << endl;
    */
    if (flag) {
        //cout<< " ---- " << endl;
        return A[a][b];
    }else
    {
        anss[0]+= ans[0];
        anss[1]+= ans[1];
        anss[2]+= ans[2];
        //cout<< anss[0] << " " << anss[1] << " " << anss[2] << endl;
        //cout<< " ---- " << endl;    
        return -1;
    }
}

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++){
            cin >> A[i][j];
        }

    int aa = process(1,1,n);
    if (aa >= 0){
        anss[aa] ++;
    }else
    

    cout<< anss[0] << endl << anss[1] << endl << anss[2];

    return 0;
}