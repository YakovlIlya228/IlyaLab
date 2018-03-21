#include "CandC.h"

Cities :: Cities() = default;

void Cities ::add_city(int crossings) {
    CandC[city_i]=crossings;
    printf("City number %i with %i crossings was added!\n",city_i,crossings);
    city_i++;
}
void Cities ::delete_city(){
    city_i--;
    CandC[city_i]=0;
    printf("City number %i was deleted!\n",city_i);
}
void Operation ::check() {
    Cities C;
    int n,num;
    for(n=1;n<city_i;n++){
        if(CandC[n]>MAX_CROSSINGS){
            MAX_CROSSINGS=CandC[n];
            num=n;
        }
    }
    printf("City with the most crossings is number %i with %i crossings!\n",num,MAX_CROSSINGS);
}
void Operation ::show() {
    int n;
    if(city_i!=1){
        for(n=1;n<city_i;n++){
            printf("City number %i: %i crossings\n",n,CandC[n]);
        }

    }

}
int main() {
    Cities c; Operation o;int tmp;bool check= true;
    printf("Type in number to choose action!\n1 - Add city\n2 - Delete previous city\n3 - Check for the city with most crossings among added\n4 - Show all cities\n5 - Exit\n:");
    while(check){
        cin >> tmp;
        switch(tmp){
            case 1:
                printf("Enter number of crossings in city, u want to add:\n");
                cin >> tmp;
                c.add_city(tmp);
                continue;
            case 2:
                c.delete_city();
                continue;
            case 3:
                o.check();
                continue;
            case 4:
                o.show();
            case 5:
                exit(0);
            default:
                check = false;
        }

    }

    return 0;
}
