#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;
const int n = 10;
class Arr {
public:
    int arr[n], tmp;
    void Sort() {
        for(int i=1; i<n-1;i++)
            for(int j=i; j>0 && arr[j-1]>arr[j];j--){
                tmp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = tmp;
            }
    }
};
int main() {
    Arr ar;int i,j,x;
    srand(time(NULL));
    printf("Not sorted:\n");
    for(i=0; i<n-1;i++){
        ar.arr[i]=rand();
        printf("%i: %i\n",i+1,ar.arr[i]);
    }
    ar.Sort();
    printf("Sorted:\n");
    for(i=0; i<n-1;i++){
        printf("%i: %i\n",i+1,ar.arr[i]);
    }
    return 0;
}
