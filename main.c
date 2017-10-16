#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    int temp; double Cel,Kel,Far;
    printf("Argument count: %i\n",argc);
    if(argc == 2){
        temp = atoi(argv[1]);
        Cel = (temp - 32)/1.8;
        Kel =(temp + 459.67) *5/9;
        printf("%i F:\n%2f C\n%2f K\n",temp,Cel,Kel);
        Far = temp *1.8+32;
        Kel = temp + 273.15;
        printf("%i C:\n%2f F\n%2f K\n",temp,Far,Kel);
        Cel = temp - 273.15;
        Far = temp *1,8 - 459.67;
        printf("%i K:\n%2f C\n%2f F\n",temp,Cel,Far);
    }
     if(argc == 3){
         temp = atoi(argv[1]);
        if (argv[2][0]== 'C' || argv[2][0]=='c'){
            Far = temp *1.8+32;
            Kel = temp + 273.15;
            printf("%i C:\n%2f F\n%2f K\n",temp,Far,Kel);
        }
         if(argv[2][0]=='K' || argv[2][0]=='k'){
             Cel = temp - 273.15;
             Far = (temp -273.15)*1.8+32;
             printf("%i K:\n%2f C\n%2f F\n",temp,Cel,Far);
         }
         if(argv[2][0]=='F' || argv[2][0]=='f'){
             Cel = (temp - 32)/1.8;
             Kel =(temp -32)*5/9 + 273.15;
             printf("%i F:\n%2f C\n%2f K\n",temp,Cel,Kel);
         }
     }
    return 0;
}