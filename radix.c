#include <stdio.h>
#include "lqueue.h"

void RadixSort(char* A[],int n,int k){
     char* B[10][n];
     int pocB[10];
     int x,y;
     int i,j;
     for(i=0;i<10;i++)pocB[i]=0;
     for(j=k-1;j>=0;j--){
          for(i=0;i<n;i++){
             x=A[i][j]-'0';
             B[x][pocB[x]++]=A[i];
             }
          for(y=0,x=0;x<10;x++){
              for(i=0;i<pocB[x];i++)
                  A[y++]=B[x][i];
              pocB[x]=0;
              }
     }
}

void RadixSortQueue(char* A[],int n,int k){
    int x,y;
    int i,j;
    LQueue q;
    LQueue B[10];
    TElem temp;
    q=CreateQueue();
    for(i=0;i<10;i++)B[i]=CreateQueue();
    for(i=0;i<n;i++) Enqueue(A[i],q);

    /* DOPLNIT UTRIEDENIE */

    i=0;    
    while(!IsEmptyQueue(q)){
        temp=FrontAndDequeue(q);
        A[i++]=temp;
    }
}
