#include <bits/stdc++.h>
using namespace std;
int A[2187][2187];
int res[3];
//kiem tra o vuong do co 
bool check(int a, int b, int u, int v)
{
    if(a==u && b==v){ 
        res[A[a][b]]++; 
        return true;
    }
    for (int i = a; i <= u; i ++)
        for (int j = b; j <= v; j++)
            if (A[i][j] != A[a][b]) return false;

    res[A[a][b]]++; 
    return true;
}

void print(int a, int b, int u, int v){
    for (int i = a; i <= u; i ++){
        for (int j = b; j <= v; j++)
            cout << A[i][j] << " ";
        cout<< endl;
    }
}

//xu ly o vuong tu (a,b) den (u,v)
void process(int a, int b, int u, int v)
{
    //print(a,b,u,v);
    if (check(a,b,u,v)) return ;

    //chia nho o vuong ra 9 o vuong
    int l = (u-a+1)/3;
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
    ios_base::sync_with_stdio(0); // insert
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];
    process(0,0,n-1,n-1);
    cout<< res[0] << endl << res[1] << endl << res[2];
    return 0;
}