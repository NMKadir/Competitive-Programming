#include<bits/stdc++.h>
using namespace std;
#define ll long long
double p[305][305][305], ev[305][305][305];
int main(){
    int n;
    scanf("%d", &n);
    vector<int>cnt(4);
    for(int i=0; i<n; i++){
        int p;
        scanf("%d", &p);
        ++cnt[p];
    }
    p[cnt[1]][cnt[2]][cnt[3]] = 1;
    for(int c=n; c>=0; --c){
        for(int b=n; b>=0; --b){
            for(int a=n; a>=0; --a){
                if(a==0 && b==0 && c==0)
                    continue;
                if(a+b+c>n)
                    continue;
                double p_waste = (double) (n-(a+b+c))/n;
                double ev_waste = p_waste/(1-p_waste) + 1;
                ev[a][b][c] += ev_waste * p[a][b][c];
                //remove 1
                if(a!=0){
                    double p_go = ((double)a/(a+b+c));
                    p[a-1][b][c] += p[a][b][c] * p_go;
                    ev[a-1][b][c] += ev[a][b][c] * p_go;
                }
                //remove 2
                if(b!=0){
                    double p_go = ((double)b/(a+b+c));
                    p[a+1][b-1][c] += p[a][b][c] * p_go;
                    ev[a+1][b-1][c] += ev[a][b][c] * p_go;
                }
                //remove 3
                if(c!=0){
                    double p_go = ((double)c/(a+b+c));
                    p[a][b+1][c-1] += p[a][b][c] * p_go;
                    ev[a][b+1][c-1] += ev[a][b][c] * p_go;
                }

            }
        }
    }
    printf("%.10lf\n", ev[0][0][0]);
    return 0;
}