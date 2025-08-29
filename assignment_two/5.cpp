#include <iostream>
using namespace std;

struct Diagonal{
    int n; int *d;
    Diagonal(int n_=0): n(n_) { d = new int[n]; for(int i=0;i<n;++i) d[i]=0; }
    ~Diagonal(){ delete[] d; }
    void set(int i,int j,int val){ if(i==j) d[i-1]=val; }
    int get(int i,int j) const { return (i==j)? d[i-1]:0; }
};

struct TriDiagonal{
    int n; int *a;
    TriDiagonal(int n_=0): n(n_) { int sz = (n>0)?(3*n-2):0; a = new int[sz]; for(int i=0;i<sz;++i) a[i]=0; }
    ~TriDiagonal(){ if(n>0) delete[] a; }
    void set(int i,int j,int val){
        if(i-j==1) a[i-2]=val;
        else if(i==j) a[n-1 + i-1]=val;
        else if(j-i==1) a[2*n-1 + i-1]=val;
    }
    int get(int i,int j) const{
        if(i-j==1) return a[i-2];
        else if(i==j) return a[n-1 + i-1];
        else if(j-i==1) return a[2*n-1 + i-1];
        return 0;
    }
};

struct LowerTri{
    int n; int *a;
    LowerTri(int n_=0): n(n_) { int sz = n*(n+1)/2; a = new int[sz]; for(int i=0;i<sz;++i) a[i]=0; }
    ~LowerTri(){ delete[] a; }
    int idx(int i,int j) const { return (i*(i-1))/2 + (j-1); }
    void set(int i,int j,int val){ if(i>=j) a[idx(i,j)] = val; }
    int get(int i,int j) const { return (i>=j)? a[idx(i,j)]:0; }
};

struct UpperTri{
    int n; int *a;
    UpperTri(int n_=0): n(n_) { int sz = n*(n+1)/2; a = new int[sz]; for(int i=0;i<sz;++i) a[i]=0; }
    ~UpperTri(){ delete[] a; }
    int idx(int i,int j) const { return (j*(j-1))/2 + (i-1); }
    void set(int i,int j,int val){ if(i<=j) a[idx(i,j)] = val; }
    int get(int i,int j) const { return (i<=j)? a[idx(i,j)]:0; }
};

struct Symmetric{
    int n; int *a;
    Symmetric(int n_=0): n(n_) { int sz = n*(n+1)/2; a = new int[sz]; for(int i=0;i<sz;++i) a[i]=0; }
    ~Symmetric(){ delete[] a; }
    int idx(int i,int j) const { if(i>j){ int t=i; i=j; j=t; } return (j*(j-1))/2 + (i-1); }
    void set(int i,int j,int val){ a[idx(i,j)] = val; }
    int get(int i,int j) const { return a[idx(i,j)]; }
};

int main(){
    Diagonal D(4);
    D.set(1,1,5); D.set(2,2,6); D.set(3,3,7); D.set(4,4,8);
    cout << "Diagonal D(3,3)=" << D.get(3,3) << " D(1,2)=" << D.get(1,2) << '\n';

    TriDiagonal T(4);
    T.set(1,1,10); T.set(2,1,3); T.set(2,2,20); T.set(2,3,4);
    cout << "TriDiag T(2,1)=" << T.get(2,1) << " T(2,3)=" << T.get(2,3) << '\n';

    LowerTri L(3);
    L.set(3,1,9); L.set(2,1,4); cout << "Lower L(3,1)=" << L.get(3,1) << '\n';

    UpperTri U(3);
    U.set(1,3,11); U.set(2,2,5); cout << "Upper U(1,3)=" << U.get(1,3) << '\n';

    Symmetric S(3);
    S.set(1,2,7); cout << "Sym S(2,1)=" << S.get(2,1) << '\n';

    return 0;
}
