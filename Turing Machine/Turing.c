#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define DEFAUlT_SIZE 10
#define RESIZING_COEFFICIENT 1.5

char *Cmovl = "movl";
char *Cmovr = "movr";
char *Cinc = "inc";
char *Cdec = "dec";
char *Cprint = "print";
char *Cget = "get";
char *Cprintc = "printc";
char *Cbegin = "begin";
char *Cend = "end";
int i;


typedef struct turing_tape_s {
    unsigned char *pos_array;
    unsigned char *neg_array;
    unsigned long int pos_size;
    unsigned long int neg_size;
    int sign;
    unsigned long int current_element;
} turing_tape;

void init_turing_tape(turing_tape *tape) {
    tape->pos_array = (unsigned char *) calloc(DEFAUlT_SIZE, sizeof(unsigned char));
    tape->neg_array = (unsigned char *) calloc(DEFAUlT_SIZE, sizeof(unsigned char));
    tape->sign = 1;
    tape->pos_size = DEFAUlT_SIZE;
    tape->neg_size = DEFAUlT_SIZE;
    tape->current_element = 0;
}
turing_tape *create_turing_tape() {
    turing_tape *tape = (turing_tape *) malloc(sizeof(turing_tape));
    init_turing_tape(tape);
    return tape;
}
void free_turing_tape(turing_tape *tape) {
    if(tape->pos_array)
        free(tape->pos_array);
    if(tape->neg_array)
        free(tape->neg_array);
    if(tape)
        free(tape);
}
void resize_turing_tape(turing_tape *tape, int tape_type) {
    if(tape_type == 1) {
        unsigned char *tmp_array = (unsigned char *) calloc(tape->pos_size*RESIZING_COEFFICIENT, sizeof(unsigned char));
        memcpy(tmp_array, tape->pos_array, tape->pos_size);
        free(tape->pos_array); tape->pos_array = tmp_array;
        tape->pos_size = tape->pos_size*RESIZING_COEFFICIENT;
    } else if(tape_type == -1) {
        unsigned char *tmp_array = (unsigned char *) calloc(tape->neg_size*RESIZING_COEFFICIENT, sizeof(unsigned char));
        memcpy(tmp_array, tape->neg_array, tape->neg_size);
        free(tape->neg_array); tape->neg_array = tmp_array;
        tape->neg_size = tape->neg_size*RESIZING_COEFFICIENT;
    }
}
void print_turing_tape(turing_tape *tape) {
    unsigned long int i;
    for(i = tape->neg_size; i > 0; i--) {
        printf("%3ld: %d\t", -i, tape->neg_array[i-1]);
    }
    printf("\n");
    for(i = 0; i < tape->pos_size; i++) {
        printf("%3ld: %d\t", i, tape->pos_array[i]);
    }
    printf("\n\n");
}
void movl(turing_tape *tape) {
    if(tape->sign == 1) {
        if(tape->current_element == 0) {
            tape->sign = -1;
        } else {
            tape->current_element--;
        }
    } else if(tape->sign == -1) {
        if(tape->current_element == tape->neg_size-1) {
            resize_turing_tape(tape, tape->sign);
            tape->current_element++;
        } else {
            tape->current_element++;
        }
    }
}
void movr(turing_tape *tape) {
    if(tape->sign == 1) {
        if(tape->current_element == tape->pos_size-1) {
            resize_turing_tape(tape, tape->sign);
            tape->current_element++;
        } else {
            tape->current_element++;
        }
    } else if(tape->sign == -1) {
        if(tape->current_element == 0) {
            tape->sign = 1;
        } else {
            tape->current_element--;
        }
    }
}
void inc(turing_tape *tape) {
    if(tape->sign == 1) {
        tape->pos_array[tape->current_element]++;
    } else if(tape->sign == -1) {
        tape->neg_array[tape->current_element]++;
    }
}
void dec(turing_tape *tape) {
    if(tape->sign == 1) {
        tape->pos_array[tape->current_element]--;
    } else if(tape->sign == -1) {
        tape->neg_array[tape->current_element]--;
    }
}
void print(turing_tape *tape) {
    if(tape->sign == 1) {
        printf("%u\n", tape->pos_array[tape->current_element]);
    } else if(tape->sign == -1) {
        printf("%u\n",tape->neg_array[tape->current_element]);
    }
}
void get(turing_tape *tape) {
    if(tape->sign == 1) {
        tape->pos_array[tape->current_element] = getchar();
    } else if(tape->sign == -1) {
        tape->neg_array[tape->current_element] = getchar();
    }
}
char cur(turing_tape *tape) {
    if(tape->sign == 1) {
        return tape->pos_array[tape->current_element];
    } else if(tape->sign == -1) {
        return tape->neg_array[tape->current_element];
    }
    return 0;
}
void printc(turing_tape *tape) {
    if(tape->sign == 1) {
        printf("%c\n", tape->pos_array[tape->current_element]);
    } else if(tape->sign == -1) {
        printf("%c\n",tape->neg_array[tape->current_element]);
    }
}

int string_array_length(char **string_array) {
    if(!string_array)
        return 0;
    
    int length = 0;
    while(*string_array++) {
        length++;
    }
    return length;
}
char **read_all_commands(const char *filename) {
    FILE *file = fopen(filename, "r");
    if(file == NULL) {
        return NULL;
    }
    const double mult = 1.5;
    int index = 0;
    int array_size = 10;
    char **array = (char **) calloc(array_size, sizeof(char *));
    char *line;
    size_t size;
    while(!feof(file)) {
        line = NULL;
        size = 0;
        getline(&line, &size, file);
        array[index++] = line;
        if(index == array_size) {
            array_size = (int) (array_size*mult);
            array = (char **) realloc(array, sizeof(char *)*array_size);
        }
    }
    array[index] = NULL;
    return array;
}
void check(char** t, turing_tape *pointer, int start, int end){
    int cycle;
    for(i = cycle = start; i< end; i++) {
    if (strstr(t[i], Cmovl)){
        movl(pointer);
    }
    if (strstr(t[i], Cmovr)){
        movr(pointer);
    }
    if (strstr(t[i], Cinc)){
        inc(pointer);
    }
    if (strstr(t[i], Cdec)){
        dec(pointer);
    }
    if (strstr(t[i], Cprint)){
        print(pointer);
       
    }
    if (strstr(t[i], Cget)){
        get(pointer);
    }
    if (strstr(t[i], Cprintc)){
        printc(pointer);
    }
    if (strstr(t[i], Cbegin)){
        cycle = i+1;
        
        }
    if (strstr(t[i], Cend)){
        while(cur(pointer)){
            check(t, pointer, cycle, i);
         }
      }
   }
}

int main(int argc, char *argv[]) {
    char **t = read_all_commands(argv[1]);
    turing_tape tape;
    turing_tape *point = &tape;
    tape = *create_turing_tape();
    check(t, point, 0,string_array_length(t));
    return 0;
}
