#pragma once

#include <iostream>

using namespace std;

struct StackElement
{
    string key;
    StackElement *next;

    StackElement(string key, StackElement *next = nullptr)
        : key(key), next(next){};

    ~StackElement()
    {
        if (next != nullptr)
            delete next;
    }
};

struct Stack
{
    size_t size;
    StackElement *first;

    Stack(size_t size = 0, StackElement *first = nullptr)
        : size(size), first(first){};

    ~Stack()
    {
        if (first != nullptr)
            delete first;
    }
};

void stack_print(Stack *stack);

void stack_push(Stack *stack, StackElement *element);

StackElement *stack_pop(Stack *stack);

StackElement *stack_recursive_remove(Stack *stack, const string key);

StackElement *stack_queue_remove(Stack *stack, const string key);

bool stack_recursive_insert(Stack *stack, StackElement *element, const string key);

bool stack_queue_insert(Stack *stack, StackElement *element, const string key);

bool stack_recursive_insert(Stack *stack, Stack *elements, const string key);

bool stack_queue_insert(Stack *stack, Stack *elements, const string key);

bool stack_save(Stack *stack, const string filename);

bool stack_load(Stack *stack, const string filename);
