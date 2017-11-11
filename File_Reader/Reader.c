#include <stdio.h>
#include <string.h>
int main(int argc, char* argv[]) {
    char a[255],b[255]; int count = 0, lines = 0,i = 0;
    FILE *file;
    file = fopen(argv[1],"r");
    printf("Text in file:\n");
    while((a[i] = fgetc(file)) != EOF){
        count++;
        if(a[i] == '\n'){
            a[i]='\0';
            printf("%s\n",a);
            i = 0;
            lines++;
        }
        else i++;

    }
    a[i] = '\0';
    printf("%s\n",a);
    printf("There is:\n%i bytes in file,\n%i lines in file.\n",count,lines);
    return 0;
}
