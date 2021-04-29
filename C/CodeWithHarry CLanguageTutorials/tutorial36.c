#include <stdio.h>

void arrayRev(int * ptr, int size){
    /* reverses an array*/
    for (int i = 0; i < size/2; i++ ){
        int aux = *(ptr+i);
        *(ptr+i) = *(ptr+size-i-1);
        *(ptr+size-i-1) = aux;
    }
    return ;
}

int main(){

    int arr[] = {1,2,3,4,5,6,67};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    arrayRev(arr,size);

    for(int j = 0; j < size; j++){
        //prints the array elements
        printf("%d ",arr[j]);
    }
    return 0 ;
}