#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "lqueue.h"

void RadixSort(char* A[],int n,int k){
     char*** B;
     int pocB[10];
     int x;
     int y;
     int i;
     int j;
     B=(char***)malloc(10*sizeof(char**));
     if(!B)return;
     for(i=0;i<10;i++){
         B[i]=(char**)malloc((size_t)n*sizeof(char*));
         if(!B[i]){
             while(i>0){
                 free(B[--i]);
             }
             free(B);
             return;
         }
     }
     for(i=0;i<10;i++)pocB[i]=0;
     for(j=k-1;j>=0;j--){
          for(i=0;i<n;i++){
             x=A[i][j]-'0';
             if(x<0||x>9)x=0;
             B[x][pocB[x]++]=A[i];
             }
          for(y=0,x=0;x<10;x++){
              for(i=0;i<pocB[x];i++)
                  A[y++]=B[x][i];
              pocB[x]=0;
              }
     }
     for(i=0;i<10;i++)free(B[i]);
     free(B);
}

void RadixSortQueue(char* A[],int n,int k){
    int x;
    int i,j;
    LQueue q;
    LQueue B[10];
    TElem temp;
    q=CreateQueue();
    for(i=0;i<10;i++)B[i]=CreateQueue();
    for(i=0;i<n;i++) Enqueue(A[i],q);

    for(j=k-1;j>=0;j--){
        while(!IsEmptyQueue(q)){
            temp=FrontAndDequeue(q);
            x=temp[j]-'0';
            if(x<0||x>9) x=0;
            Enqueue(temp,B[x]);
        }
        for(x=0;x<10;x++){
            while(!IsEmptyQueue(B[x])){
                temp=FrontAndDequeue(B[x]);
                Enqueue(temp,q);
            }
        }
    }

    i=0;
    while(!IsEmptyQueue(q)){
        temp=FrontAndDequeue(q);
        A[i++]=temp;
    }
    for(i=0;i<10;i++)RemoveQueue(&B[i]);
    RemoveQueue(&q);
}

void MyPrintf(const char *format,...){
    va_list ap;
    va_start(ap,format);
    vprintf(format,ap);
    va_end(ap);
}
