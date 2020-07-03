#include<stdio.h>

int search(int f[], int i, int n, int k){
    for(i;i<n;i++){
        if(f[i]==k){
            return i+1;
        }
    }
    return n+1;
}

int min(int f[],int n){
    int mi=0;
    for (int i=1; i<n; i++){
        if (f[i]>f[mi]){
            mi=i;
        }
    }
    return mi;
}

void display(int f[], int n){
    for(int i=0;i<n;i++){
        if (f[i]!=-1){
            printf("%d ",f[i]);
        }
    }printf("\n");
}

int main(){
    
    int p[10], f[3], fn, pn, i, pf=0, s, t[3], m, j;
    printf("Enter no. of pages: ");
    scanf("%d",&pn);
    printf("Enter reference string: ");
    for (i=0;i<pn;i++){
        scanf("%d",&p[i]);
    }
    printf("Enter no of frames: ");
    scanf("%d",&fn);
    for (i=0;i<fn;i++){
        f[i]=-1;
    }
    for (i=0;i<fn;i++){
        if(search(f,0,fn,p[i])==fn+1){
            f[i]=p[i];
            pf+=1;
            display(f,fn);
        }
    }
    for (i;i<pn;i++){
        s=search(f,0,fn,p[i]);
        if(s==fn+1){
            for (j=0;j<fn;j++){
                t[j]=search(p,i,pn,f[j])-1;
            }
            m=min(t,fn);
            f[m]=p[i];
            pf+=1;
        }
        display(f,fn);
    }
    printf("No of page faults: %d\n",pf);
}
