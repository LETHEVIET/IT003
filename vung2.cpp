#include<bits/stdc++.h>

using namespace std;

int64_t m_quick_pow(long a, long n, int c) {
	int64_t result = 1;
	while (n > 0) {// cho đến khi số mũ bằng 0. Tiếp tục vòng lặp
		if (n % 2 == 1){// nếu số mũ là số lẻ, ta nhân thêm a cho biến chứa kết quả
			result *= a;
            //result %= c;
        }
		a *= a;// cập nhật cơ số a, a(mới)= a(cũ)^2
		n /= 2;// cập nhật lại số mũ, n(mới)= n(cũ)/2
	}
	return result;
}
int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    cout<< m_quick_pow(a,b,c) % c ;
    return 0;
}
