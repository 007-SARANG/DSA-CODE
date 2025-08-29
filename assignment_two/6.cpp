#include <iostream>
using namespace std;

struct Triplet{ int r,c,val; };

struct Sparse{
    int rows, cols;
    Triplet *data;
    int cap, sz;
    Sparse(int r=0,int c=0): rows(r), cols(c), data(nullptr), cap(0), sz(0){}
    ~Sparse(){ if(data) delete[] data; }
    void add(int i,int j,int v){ if(v==0) return; if(sz==cap){ int ncap = cap?cap*2:4; Triplet* nd=new Triplet[ncap]; for(int k=0;k<sz;++k) nd[k]=data[k]; if(data) delete[] data; data=nd; cap=ncap; } data[sz++] = {i,j,v}; }
    void sort_data(){ if(sz>1) for(int p=0;p<sz-1;++p) for(int q=0;q<sz-1-p;++q) if(data[q].r>data[q+1].r || (data[q].r==data[q+1].r && data[q].c>data[q+1].c)){ Triplet t=data[q]; data[q]=data[q+1]; data[q+1]=t; } }
    Sparse transpose() const{
        Sparse t(cols, rows);
        for(int i=0;i<sz;++i) t.add(data[i].c, data[i].r, data[i].val);
        t.sort_data();
        return t;
    }
    Sparse add(const Sparse &other) const{
        Sparse Acopy = *this; Sparse Bcopy = other;
        Acopy.sort_data(); Bcopy.sort_data();
        Sparse res(rows, cols);
        int i=0,j=0;
        while(i<Acopy.sz && j<Bcopy.sz){
            if(Acopy.data[i].r==Bcopy.data[j].r && Acopy.data[i].c==Bcopy.data[j].c){
                int s = Acopy.data[i].val + Bcopy.data[j].val;
                if(s!=0) res.add(Acopy.data[i].r, Acopy.data[i].c, s);
                i++; j++;
            } else if(Acopy.data[i].r < Bcopy.data[j].r || (Acopy.data[i].r==Bcopy.data[j].r && Acopy.data[i].c < Bcopy.data[j].c)){
                res.add(Acopy.data[i].r, Acopy.data[i].c, Acopy.data[i].val); i++;
            } else { res.add(Bcopy.data[j].r, Bcopy.data[j].c, Bcopy.data[j].val); j++; }
        }
        while(i<Acopy.sz) res.add(Acopy.data[i].r, Acopy.data[i].c, Acopy.data[i].val), i++;
        while(j<Bcopy.sz) res.add(Bcopy.data[j].r, Bcopy.data[j].c, Bcopy.data[j].val), j++;
        return res;
    }
    Sparse multiply(const Sparse &other) const{
        if(cols != other.rows) return Sparse();
        Sparse Bcopy = other; Bcopy.sort_data();
        int *rowStart = new int[Bcopy.rows+2]; for(int i=0;i<=Bcopy.rows+1;++i) rowStart[i]=-1;
        for(int i=0;i<Bcopy.sz;++i){ int r = Bcopy.data[i].r; if(rowStart[r]==-1) rowStart[r]=i; }
        Sparse res(rows, other.cols);
        for(int ia=0; ia<sz; ++ia){
            int i = data[ia].r; int k = data[ia].c; int aval = data[ia].val;
            int start = (k<=Bcopy.rows && rowStart[k]!=-1)? rowStart[k] : -1;
            if(start==-1) continue;
            for(int ib = start; ib < Bcopy.sz && Bcopy.data[ib].r == k; ++ib){
                int j = Bcopy.data[ib].c; int bval = Bcopy.data[ib].val;
                bool found=false;
                for(int t=0;t<res.sz;++t){ if(res.data[t].r==i && res.data[t].c==j){ res.data[t].val += aval*bval; found=true; break; } }
                if(!found) res.add(i,j,aval*bval);
            }
        }
        delete[] rowStart;
        return res;
    }
    void print() const{
        cout << "Triplets (r,c,val):\n";
        for(int i=0;i<sz;++i) cout << data[i].r << " " << data[i].c << " " << data[i].val << "\n";
    }
};

int main(){
    Sparse A(3,3);
    A.add(1,1,1); A.add(1,3,2); A.add(3,2,3);
    cout << "A:\n"; A.print();

    Sparse At = A.transpose();
    cout << "Transpose:\n"; At.print();

    Sparse B(3,3); B.add(1,1,4); B.add(2,3,5);
    cout << "B:\n"; B.print();
    Sparse Sum = A.add(B);
    cout << "A+B:\n"; Sum.print();

    Sparse Prod = A.multiply(B);
    cout << "A*B:\n"; Prod.print();
    return 0;
}
