//----------------------- Queue Implentation --------------------------//
#pragma once
#ifndef QUEUE_H
#define QUEUE_H

#define MAX 10
#define DATA_TYPE int

typedef struct {
	DATA_TYPE elements[MAX];
	int front;
	int rear;
}Queue;

void Init(Queue* ptr_queue) {
	ptr_queue->front = -1;
	ptr_queue->rear = -1;
}

int IsFull(Queue* ptr_queue) {
	if ((ptr_queue->rear + 1) % MAX == ptr_queue->front) {
		return 1;
	}
	else {
		return 0;
	}
}

int IsEmpty(Queue* ptr_queue) {
	if ((ptr_queue->front == -1) && (ptr_queue->rear == -1)) {
		return 1;
	}
	else {
		return 0;
	}
}

void ClearQueue(Queue* ptr_queue) {
	ptr_queue->front = -1;
	ptr_queue->rear = -1;
}

int Enqueue(DATA_TYPE element, Queue* ptr_queue) {
	if (IsFull(ptr_queue)) {
		return 0;
	}
	else if (IsEmpty(ptr_queue)) {
		ptr_queue->front = ptr_queue->rear = 0;
	}
	else {
		ptr_queue->rear = (ptr_queue->rear + 1) % MAX;
	}

	ptr_queue->elements[ptr_queue->rear] = element;

	return 1;
}

int Dequeue(DATA_TYPE* ptr_element, Queue* ptr_queue) {
	if (IsEmpty(ptr_queue)) {
		return 0;
	}
	*ptr_element = ptr_queue->elements[ptr_queue->front];

	if (ptr_queue->front == ptr_queue->rear) {
		ptr_queue->front = ptr_queue->rear = 1;
	}
	else {
		ptr_queue->front = (ptr_queue->front + 1) % MAX;
	}

	return 1;
}

int QueueSize(Queue* ptr_queue) {
	if (IsEmpty(ptr_queue)) {
		return 0;
	}
	else if (ptr_queue->front < ptr_queue->rear) {
		return (ptr_queue->rear - ptr_queue->front + 1);
	}
	else if (ptr_queue->rear < ptr_queue->front) {
		return ((MAX - ptr_queue->front) + (ptr_queue->rear + 1));
	}
	else {
		return 1;
	}
}

#endif
