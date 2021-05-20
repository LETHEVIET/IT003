#include <bits/stdc++.h>
#define MAXN 2187+1
using namespace std;
int A[MAXN][MAXN];
int F[MAXN][MAXN];
int res[3];

int getSum(int a, int b, int u, int v){
    return F[u][v] - F[u][b-1] - F[a-1][v] + F[a-1][b-1];
}

bool check(int a, int b, int u, int v)
{
    int l = u-a+1;
    if(a==u && b==v){
        if (A[a][b] == 13) res[2]++;
        else res[A[a][b]]++; 
        return true;
    }
    if (A[a][b] == 0 && getSum(a,b,u,v) == 0){
        res[0] ++;
        return true;
    }
    if (A[a][b] == 1 && getSum(a,b,u,v) == l*l){
        res[1] ++;
        return true;
    }
    if (A[a][b] == 13 && getSum(a,b,u,v) == 13*l*l){
        //cout<<"eyyy it here" ;
        res[2] ++;
        return true;
    }
    return false;
    /*
    if(a==u && b==v){
        res[A[a][b]]++; 
        return true;
    }
    for (int i = a; i <= u; i ++)
        for (int j = b; j <= v; j++)
            if (A[i][j] != A[a][b]) return false;

    res[A[a][b]]++; 
    */
    return true;
}

void print(int a, int b, int u, int v){
    cout<< "---" <<endl;
    for (int i = a; i <= u; i ++){
        for (int j = b; j <= v; j++)
            cout << A[i][j] << " ";
        cout<< endl;
    }
    cout<<getSum(a,b,u,v) << endl;
}


void process(int a, int b, int u, int v)
{
    //print(a,b,u,v);
    if (check(a,b,u,v)) return ;

    int l = (u-a+1)/3;
    int res = 0;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            int x,y;
            x = a + l * i;
            y = b + l * j;
            process(x, y, x+l-1, y+l-1);
        }
    }
}

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++){
            cin >> A[i][j];
            if (A[i][j] == 2) A[i][j] = 13;
        }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++){
            F[i][j] = F[i-1][j] + F[i][j-1] - F[i-1][j-1] + A[i][j];
        }   
    /*
    cout<<"----";
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n; j++)
            cout << F[i][j] << " ";
        cout<< endl;
    }
    */
    process(1,1,n,n);
    cout<< res[0] << endl << res[1] << endl << res[2];
    return 0;
}