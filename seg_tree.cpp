/*short and int: -32,767 to 32,767
**unsigned short int and unsigned int: 0 to 65,535
**long int: -2,147,483,647 to 2,147,483,647
**unsigned long int: 0 to 4,294,967,295
**long long int: -9,223,372,036,854,775,807 to 9,223,372,036,854,775,807
**unsigned long long int: 0 to 18,446,744,073,709,551,615.*/

#pragma optimize('O3')
#include <bits/stdc++.h>
#define lli long long int
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define pf push_front
#define MOD 1000000007
#define F first
#define S second
#define inf INT_MAX
#define gcd(x,y) __gcd(x,y)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define i_am_iron_man ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MAXN 200010

using namespace std;

int n, t[4*MAXN];

template <class T>
void view(vector<T> v)
{
    for(auto i: v)
        cout << i << " ";
    cout << endl;
}
template <class T>
void view(T arr[], lli start, lli finish)
{
    for(lli i = start; i <= finish; i++)
        cout << arr[i] << " ";
    cout << endl;
}
template <class T>
void view(T arr[], lli n)
{
    for(lli i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

//**********************************************************************//

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}
int sum(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm))
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}
int main()
{
    i_am_iron_man
    cout << "Let an array A be: " << endl;
    int A[10] = {1,2,3,4,5,6,7,8,9,10};
    cout << "A[10] = {1,2,3,4,5,6,7,8,9,10} " << endl;
    build(A, 1, 0, 9);
    cout << "Quering the sum range from index 3 to 7: " << endl;
    cout << sum(1, 0, 9, 2, 6) << endl;
    cout << "After updating say, the 6th term to 12" << endl;
    update(1, 0, 9, 5, 12);
    cout << "Quering the sum range from index 3 to 7: " << endl;
    cout << sum(1, 0, 9, 2, 6) << endl;
    cout << "Thank You" << endl;
    return 0;
}

