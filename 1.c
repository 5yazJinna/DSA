#include<stdio.h>
#define size 5
int hashfunction(int key){
    return key%size;
}
void main(){
    int arr[size],key,hash,op;
    for (int i = 0; i < size; i++){
        arr[i] = -1;
    }
    while (1){
            printf("\nEnter the key to be inserted : ");
            scanf("%d",&key);
            hash = hashfunction(key);
            if (arr[hash] == -1){
                arr[hash] = key;
                for (int i = 0; i < size; i++){
                printf(" %d ",arr[i]);
            }
                continue;
            }
            printf("\nCollision occured in %d ",hash);
            for (int i = hash+1; i < size; i++){
                if (arr[i] == -1){
                    arr[i] = key;
                    for (int i = 0; i < size; i++){
                printf(" %d ",arr[i]);
            }
                    break;
                }
                printf("\nCollision occurs in %d",i);
                if (i == size - 1){
                    i = -1;
                }
            }
    }
}