#include <stdio.h>
#include <stdlib.h>
#define OVERFLOW -101
#define UNDERFLOW -102
#define OUT_OF_MEMORY -103
#define INIT_SIZE 20
#define MULTIPLIER 2
typedef int T;

struct stack{
   T *data;
   int size, top;
};

void init(struct stack *st){
    st ->top = NULL;
    st = malloc(sizeof(st)); //выделение памяти
    if(st == NULL){
        exit(OUT_OF_MEMORY);
    }
    st->size = INIT_SIZE;
    st->data = malloc(st-> size * sizeof(T)); // выделение паямти под элементы стека
    if (st->data = NULL){
        free(st);
        exit(OUT_OF_MEMORY);
    }
    st->top = 0;
}

void delete_stack(struct stack **st){
    free((*st)->data); // освобождение памяти элементов стека
    free(*st); // освобождение памяти
    *st = NULL;
}

void resize(struct stack *st){
    st->size *= MULTIPLIER; //увеличение кол-ва элментов стека в N раз
    st->data = realloc(st->data, st->size * sizeof(T));
    if (st->data == NULL){
        exit(OVERFLOW);
    }
}

void push(struct stack *st, T value){

}

int main() {

    return 0;
}
