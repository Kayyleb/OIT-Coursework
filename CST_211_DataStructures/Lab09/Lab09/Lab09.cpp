// Lab09.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "Queue.h"

bool EnqueueTest();

int main()
{
    EnqueueTest();
}

bool EnqueueTest()
{
    Queue<int> enqueue;
    enqueue.Enqueue(5);
    enqueue.Enqueue(5);
    enqueue.Enqueue(5);
    enqueue.Enqueue(5);

    return true;
}