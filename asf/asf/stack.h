//
//  stack.h
//  asf
//
//  Created by GrooshBene on 2015. 9. 1..
//  Copyright (c) 2015년 GrooshBene. All rights reserved.
//

typedef struct _node{
    int value;
    struct _node* next;
}node;

typedef node* nptr;

typedef struct _stack{
    int count;
    nptr top;
}stack;

void init(stack* sptr);
void push(stack* sptr, int value);
int pop(stack* stpr);
int getTop(stack* sptr);
int getCount(stack* sptr);
void free_stack(stack* sptr);