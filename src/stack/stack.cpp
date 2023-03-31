#include <iostream>
#include <fstream>

#include "stack.hpp"

using namespace std;

void stack_print(Stack *stack)
{
    if (stack->first == nullptr) // список пуст
        return;
    StackElement *element = stack->first;
    for (int i = 2; i <= stack->size; i++)
    {
        cout << element->key << ", ";
        element = element->next;
    }
    cout << element->key;
}

void stack_push(Stack *stack, StackElement *element)
{
    element->next = stack->first;
    stack->first = element;
    stack->size++;
}

StackElement *stack_pop(Stack *stack)
{
    StackElement *element = stack->first;
    stack->first = element->next;
    stack->size--;
    return element;
}

StackElement *_stack_recursive_remove(Stack *from, Stack *to, const string key)
{
    if (from->first == nullptr)
        return nullptr;
    if (from->first->key == key)
    {
        StackElement *element = stack_pop(from);
        _stack_recursive_remove(from, to, key);
        return element;
    }
    stack_push(to, stack_pop(from));
    return _stack_recursive_remove(from, to, key);
}

StackElement *stack_recursive_remove(Stack *stack, const string key)
{
    Stack *temp = new Stack();
    StackElement *element = _stack_recursive_remove(stack, temp, key);
    for (int i = 1, size = temp->size; i <= size; i++)
        stack_push(stack, stack_pop(temp));
    delete temp;
    return element;
}

bool _stack_recursive_insert(Stack *from, Stack *to, StackElement *element, const string key)
{
    if (from->first == nullptr)
        return false;
    if (from->first->key == key)
    {
        if (element->next == nullptr) // Чтоб дважды не вставило
            stack_push(to, element);
        stack_push(to, stack_pop(from));
        _stack_recursive_insert(from, to, element, key);
        return true;
    }
    stack_push(to, stack_pop(from));
    return _stack_recursive_insert(from, to, element, key);
}

bool stack_recursive_insert(Stack *stack, StackElement *element, const string key)
{
    Stack *temp = new Stack();
    bool result = _stack_recursive_insert(stack, temp, element, key);
    for (int i = 1, size = temp->size; i <= size; i++)
        stack_push(stack, stack_pop(temp));
    delete temp;
    return result;
}

bool _stack_recursive_insert(Stack *from, Stack *to, Stack *elements, const string key)
{
    if (from->first == nullptr)
        return false;
    if (from->first->key == key)
    {
        {
            Stack *temp = new Stack();
            for (int i = 1, size = elements->size; i <= size; i++)
                stack_push(temp, stack_pop(elements));
            for (int i = 1, size = temp->size; i <= size; i++)
                stack_push(to, stack_pop(temp));
            delete temp;
        }
        stack_push(to, stack_pop(from));
        _stack_recursive_insert(from, to, elements, key);
        return true;
    }
    stack_push(to, stack_pop(from));
    return _stack_recursive_insert(from, to, elements, key);
}

bool stack_recursive_insert(Stack *stack, Stack *elements, const string key)
{
    Stack *temp = new Stack();
    bool result = _stack_recursive_insert(stack, temp, elements, key);
    for (int i = 1, size = temp->size; i <= size; i++)
        stack_push(stack, stack_pop(temp));
    delete temp;
    return result;
}

StackElement *stack_queue_remove(Stack *stack, const string key)
{
    Stack *temp = new Stack();
    StackElement *element = nullptr, *v;
    for (int i = 1, size = stack->size; i <= size; i++)
        if (stack->first->key == key)
            element = stack_pop(stack);
        else
            stack_push(temp, stack_pop(stack));
    for (int i = 1, size = temp->size; i <= size; i++)
        stack_push(stack, stack_pop(temp));
    delete temp;
    return element;
}

bool stack_queue_insert(Stack *stack, StackElement *element, const string key)
{
    Stack *temp = new Stack();
    const size_t size = stack->size;
    for (int i = 1; i <= size; i++)
    {
        StackElement *v = stack_pop(stack);
        stack_push(temp, v);
        if (v->key == key && element->next == nullptr)
            stack_push(temp, element);
    }
    for (int i = 1, size = temp->size; i <= size; i++)
        stack_push(stack, stack_pop(temp));
    delete temp;
    return (stack->size > size);
}

bool stack_queue_insert(Stack *stack, Stack *elements, const string key)
{
    Stack *temp = new Stack();
    const size_t size = stack->size;
    for (int i = 1; i <= size; i++)
    {
        StackElement *v = stack_pop(stack);
        stack_push(temp, v);
        if (v->key == key)
            for (int j = 1, _size = elements->size; j <= _size; j++)
                stack_push(temp, stack_pop(elements));
    }
    for (int i = 1, size = temp->size; i <= size; i++)
        stack_push(stack, stack_pop(temp));
    delete temp;
    return (stack->size > size);
}

bool stack_save(Stack *stack, const string filename)
{
    ofstream file(filename, ios::binary);
    if (!file)
    {
        file.close();
        return false;
    }
    StackElement *element = stack->first;
    for (int i = 1; i <= stack->size; i++, element = element->next)
        file << element->key << '\0';
    file.close();
    return true;
}

bool stack_load(Stack *stack, const string filename)
{
    Stack *temp = new Stack();
    ifstream file(filename, ios::binary);
    if (!file)
    {
        file.close();
        return false;
    }
    string key;
    while (getline(file, key, '\0'))
    {
        stack_push(temp, new StackElement(key));
    }
    file.close();
    for (int i = 1, size = temp->size; i <= size; i++)
        stack_push(stack, stack_pop(temp));
    delete temp;
    return true;
}