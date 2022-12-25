#include<stdio.h>
#define size 7
int hashfunction(int key){
    int sum;
    while (key > 0){
        sum += key % 10;
        key /= 10;
    }
    return sum%size;
}
int dp(int key,int i){
    return ((key%7)+(i*(1+(key%5))))%size;
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
                int d = dp(key,i);
                if (arr[d] == -1){
                    arr[d] = key;
                    for (int i = 0; i < size; i++){
                        printf(" %d ",arr[i]);
                    }
                    break;
                }
                printf("\nCollision occurs in %d",i);
            }
    }
}