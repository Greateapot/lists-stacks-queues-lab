#pragma once

#include <iostream>

using namespace std;

struct QueueElement
{
    string key;
    QueueElement *next;

    QueueElement(string key, QueueElement *next = nullptr)
        : key(key), next(next){};

    ~QueueElement()
    {
        if (next != nullptr)
            delete next;
    }
};

struct Queue
{
    size_t size;
    QueueElement *first;
    QueueElement *last;

    Queue(size_t size = 0, QueueElement *first = nullptr, QueueElement *last = nullptr)
        : size(size), first(first), last(last){};

    ~Queue()
    {
        if (first != nullptr)
            delete first;
    }
};

void queue_print(Queue *queue);

void queue_push(Queue *queue, QueueElement *element);

QueueElement *queue_pop(Queue *queue);

QueueElement *queue_recursive_remove(Queue *queue, const string key);

QueueElement *queue_queue_remove(Queue *queue, const string key);

bool queue_recursive_insert(Queue *queue, QueueElement *element, const string key);

bool queue_queue_insert(Queue *queue, QueueElement *element, const string key);

bool queue_recursive_insert(Queue *queue, Queue *elements, const string key);

bool queue_queue_insert(Queue *queue, Queue *elements, const string key);

bool queue_save(Queue *queue, const string filename);

bool queue_load(Queue *queue, const string filename);
