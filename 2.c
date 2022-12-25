#include<stdio.h>
#define size 7
int hashfunction(int key){
    return ((key*key)/size)%size;
}
int qp(int key,int i){
    return ((key%size)+0*(i)+3*(i*i));
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
            for (int i = 0; i < size; i++){
                int p = qp(key,i);
                if (arr[p] == -1){
                    arr[p] = key;
                    for (int i = 0; i < size; i++){
                printf(" %d ",arr[i]);
                }
                    break;
                }
                printf("\nCollision occurs in %d",i);
            }
    }
}