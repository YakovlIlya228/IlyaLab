#include <stdio.h>
#include <cctype>
#include <locale>

#define N 1000
int main(){
    int n, i, j;
    int a[N];
    printf("Enter count of elements: \n");
    scanf("%d", &n);

    printf("Enter your elements: \n");
    for(i = 0 ; i < n; i++){
        scanf("%d", &a[i]);
        if(isdigit(a[i])){
            printf("You can't enter the letters or other symbols!\nChoose another value and enter it once more:\n");
            scanf("%d", &a[i]);
        }
    }
    for(i = 0 ; i < n - 1; i++){

        for(j = 0 ; j < n - i - 1 ; j++){
            if(a[j] > a[j+1]){

                int tmp = a[j];
                a[j] = a[j+1] ;
                a[j+1] = tmp;
            }
        }
    }
    for(i=0;i < n; i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}
