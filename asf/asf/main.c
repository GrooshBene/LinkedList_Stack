
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
struct KT{
    int age;
    struct KT *next;
};
int main(){
    stack* myStack = (stack*)malloc(sizeof(stack));
    init(myStack);
    printf ("***********************\n");
    printf ("STACK 프로그램 1학년 5반 박지수\n");
    printf ("***********************\n");
    int menuChk;
    int a;
    int chk=1 ;
    while(chk == 1){
    printf ("1.Input\n2.Output\n3.Clear All\n4.Stack Length\n5.exit\n");
        printf ("Menu Input:");
    scanf ("%d", &menuChk);
    switch(menuChk){
        case 1:
            chk = 0;
            printf ("PLZ INPUT, WANT EXIT, PLZ Input 0: ");
            scanf ("%d", &a);
            if(a==0) {
                chk = 1;
                break;
            }
            else{
            push(myStack, a);
                chk = 1;
                break;
            }
        case 2:
            chk = 0;
            if(pop(myStack) ==-1){
                pop(myStack);
                printf ("\n");
                chk=1;
            }
            else{
            printf ("Stack Value: %d\n", pop(myStack));
            chk = 1;
            }
            break;
        case 3:
            chk = 0;
            free_stack(myStack);
            chk = 1;
            break;
        case 4:
            chk =0;
            printf ("Stack Length: %d\n", getCount(myStack));
            chk = 1;
            break;
        case 5:
            return 0;
            break;
        default:
            printf ("Wrong Number!!\n");
            break;
    }
    }
    
}

void init(stack *sptr){
    sptr->count = 0;
    sptr->top = NULL;
}
void push(stack *sptr, int value){
    nptr new_nptr = (nptr)malloc(sizeof(node));
    new_nptr->value=value;
    new_nptr->next=sptr->top;
    sptr->top = new_nptr;
    sptr->count++;
}
int pop(stack* sptr){
    if(sptr->count>0){
        nptr tmp = sptr->top;
        sptr->top = tmp->next;
        int pop_value = tmp->value;
        free(tmp);
        sptr->count--;
        return pop_value;
    }
    else{
        printf ("No Item exists in this stack!");
        return -1;
    }
}

int getTop(stack* sptr) {
    if(sptr->count>0){
        return sptr->top->value;
    }
    else{
        printf ("No Item exists in this stack!");
        return -1;
    }
}

int getCount(stack* sptr){
    return sptr->count;
}

void free_stack(stack* sptr){
    while(sptr->top!=NULL) {
        pop(sptr);
    }
    free(sptr);
}

