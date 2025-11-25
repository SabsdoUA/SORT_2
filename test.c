#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "radix.h"

#define N  16
char *a[N];
void GenRnd(){
  int i;
  char txt[32];
  for(i=0;i<N;i++){
      sprintf(txt,"%03d",rand()%1000);
      a[i]=strdup(txt);
      }
}

int main(int argc, char *argv[])
{
  int i;
  printf("\nRADIX_SORT - ARRAY\n");
  GenRnd();
  RadixSort(a,N,3);
  printf("\n");
  for(i=0;i<N;i++)printf("%s ",a[i]);
  printf("\n");

  printf("\nRADIX_SORT - QUEUE\n");
  GenRnd();
  RadixSortQueue(a,N,3);
  printf("\n");
  for(i=0;i<N;i++)printf("%s ",a[i]);
  printf("\n");

  return 0;
}
