#include <stdio.h>

void merge(int* A, int p, int q, int r){
    // Implementa merge di merge sort
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1], R[n2];
    int i, j, k;
    for(i = 0; i < n1; i++)
        L[i] = A[p + i];
    for(j = 0; j < n2; j++)
        R[j] = A[q + j + 1];
    i = 0;
    j = 0;
    k=p;
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }
        else{
            A[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1){
        A[k] = L[i];
        i++;
        k++;
    }
    while(j < n2){
        A[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int* A, int p, int r){
    if(p<r){
        int q = (p+r)/2;
        mergeSort(A,p,q);
        mergeSort(A,q+1,r);
        merge(A,p,q,r);
    }
}

int main(){
    int A[] = {-123,43,41,2,0,7,2,11};
    int dim= 8;
    mergeSort(A,0,dim-1);
    for(int i=0; i<dim; i++){
        printf("%d\t",A[i]);
    }
}