#include <stdio.h>
#include <stdlib.h>


int count = 0, top , size = 20;
int stack[20];


void Push(){
    if(size==count){
        printf("Stack is full!\n");
    }
    else{
        printf("Enter the value u want to add to stack:\n");
        scanf("%i",&(top));
        stack[count] = top;
        printf("You added:%i to stack\n",stack[count]);
        count++;
    }
}

void Pop(){
    if(count==0){
        printf("Stack is empty!");
    }
    else{
        stack[count-1] = 0;
        count--;
    }
}

void Resize(){
    int add;
    printf("Type in amount of items u want to add to stack:\n");
    scanf("%i",&add);
    size *= add;
}

void Check_Top(){
    printf("%i",stack[count-1]);
}

void Check_Size(){
    printf("%i",size);
}
void Check_Stack(){
    if(count!=0){
        int counter = 0;
        for(counter;counter<count;counter++){
            printf("Item %i:%i\n",counter,stack[counter]);
        }
    }
    else{
        printf("Stack is empty!\n");
    }
}

int main(){
    int act;
    while(act!=7){
        printf("\n\n\nActions to do with stack:\n1-Push\n2-Pop\n4-See top\n6-See all items of stack\n7-Exit\n:");
        scanf("%i",&act);
        if(act==1){
            Push();
        }
        if(act==2){
            Pop();
        }
//        if(act==3){
//            Resize();
//        }
        if(act==4){
            Check_Top();
        }
//        if(act==5){
//            Check_Size();
//        }
        if(act==6){
            Check_Stack();
        }
    }
    exit(0);

}

