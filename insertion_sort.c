#include<stdio.h>
int main(){
    int array[10] = {12,9,13,15,8,4,78,43,2,3};
    for (int i = 1;i < 10;i++){
        int temp = array[i];
        int j = i - 1;
        while(j >=0 ){
            if (temp < array[j]){
                array[j + 1] = array[j];
            }
            else {
                break;
            }
            j--;
        }
        array[j+1] = temp;
    }
    for (int i = 0;i < 10;i++){
        printf("%d\n",array[i]);
    }
    return 0;
}