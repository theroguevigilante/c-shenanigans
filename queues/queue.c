#include <stdio.h>
#define MAX 100

typedef enum {
    false,
    true
} bool;

int q[MAX], front = -1, rear = -1;

bool is_empty(){
    return front == -1 && rear == -1;
}

bool is_full(){
    return rear == MAX - 1;
}

bool enqueue(int key){
    if(front == -1 && rear == -1){
        front = 0;
        rear = 0;
        q[rear] = key;
        return true;
    }
    
    if (!is_full()){
        q[++rear] = key;
        return true;
    }
    else{
        return false;
    }
}

bool dequeue(){
    if(front == -1 && rear == -1){
        return false;
    }
    else if (front == rear){
        front = rear = -1;
        return true;
    }
    else{
        ++front;
        return true;
    }
}

// Check for is_empty before calling
int peek(){
    return q[front];
} int main(void){}
