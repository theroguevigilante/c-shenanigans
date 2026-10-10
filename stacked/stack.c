#include <stdio.h>
#define MAX 100

typedef enum {
    false,
    true
} bool;

int st[MAX], top = -1;

bool is_empty(){
    return top == -1;
}

bool is_full(){
    return top == MAX - 1;
}

bool push(int key){
    if (!is_full()){
        st[++top] = key;
        return true;
    }
    else {
        return false;
    }
}

// To retrieve the value, use with peek
bool pop(){
    if (!is_empty()){
        --top;
        return true;
    }
    else {
        return false;
    }
}

// Check is_empty before calling
int peek(){
    return st[top];
}

int main(void){}
