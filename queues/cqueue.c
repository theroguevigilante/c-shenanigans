#include <stdio.h>
#define MAX 100

typedef enum {
    false,
    true
} bool;

int q[MAX], front = -1, rear = -1;
bool is_empty() {
    if (front == -1 && rear == -1) {
        return true;
    }
    else {
        return false;
    }
}

bool is_full() {
    if ((rear + 1) % MAX == front) {
        return true;
    }
    else {
        return false;
    }
}

bool enqueue(int key) {
    if (is_empty()) {
        front = 0;
        rear = 0;
        q[rear] = key;
        return true;
    }

    else if (!is_full()) {
        rear = (rear + 1) % MAX;
        q[rear] = key;
        return true;
    }

    else {
        return false;
    }
}

bool dequeue() {
    if (is_empty()) {
        return false;
    }
    else if (front == rear) {
        front = rear = -1;
        return true;
    }
    else {
        front = (front + 1) % MAX;
        return true;
    }
}

// Helper use in tandem with is_empty()
int peek() { 
    return q[front]; 
}

int main(void){}
