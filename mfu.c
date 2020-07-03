#include<stdio.h>

struct pag{
    int pno,fre,t;    
};

int max(struct pag f[],int n){
    int mi=0,m=f[mi].fre,ti;
    for (int i=1; i<n;i++){
        ti=f[mi].t;
        if (f[i].fre>m){
            m=f[i].fre;
            mi=i;
        }else if(f[i].fre==m){
            if(f[i].t<ti){
                mi=i;
            }
        }
    }
    return mi;
}

int search(struct pag f[],int n,int k){
    for(int i=0;i<n;i++){
        if (f[i].pno==k){
            return i+1;
        }
    }
    return 0;
}

void display(struct pag f[],int n){
    for(int i =0;i<n;i++){
        if (f[i].pno!=-1){
            printf("%d ",f[i].pno);
        }
    }printf("\n");
}

int main(){
    struct pag p[10],f[10];
    int pn,i,fn,fault=0,s,mi,at=0;
    printf("Enter no. of pages:");
    scanf("%d",&pn);
    printf("Enter reference string:");
    for (i=0;i<pn;i++){
        scanf("%d",&p[i].pno);
        p[i].fre=0;
    }
    printf("Enter no. of frames:");
    scanf("%d",&fn);
    for (i=0;i<fn;i++){
        f[i].pno=-1;
        f[i].fre=0;
        f[i].t=0;
    }
    for (i=0;i<fn;i++){
        if (search(f,fn,p[i].pno)==0){
            f[i].pno=p[i].pno;
            f[i].t=at;
            f[i].fre+=1;
            fault+=1;
        }
        at+=1;
        display(f,fn);
    }
    for (i;i<pn;i++){
        at+=1;
        s=search(f,fn,p[i].pno);
        p[i].t=at;
        if (s==0){
            mi=max(f,fn);
            f[mi]=p[i];
            f[mi].fre+=1;
            fault+=1;
        }else{
            f[s-1].fre+=1;
        }
        display(f,fn);
    }
    printf("page faults: %d\n",fault);
    
}
