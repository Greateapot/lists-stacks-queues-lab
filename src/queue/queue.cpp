#include <iostream>
#include <fstream>

#include "queue.hpp"

using namespace std;

void queue_print(Queue *queue)
{
    if (queue->first == nullptr) // список пуст
        return;
    QueueElement *element = queue->first;
    for (int i = 2; i <= queue->size; i++)
    {
        cout << element->key << ", ";
        element = element->next;
    }
    cout << element->key;
}

void queue_push(Queue *queue, QueueElement *element)
{
    if (queue->size == 0)       // список пуст
        queue->first = element; // новый элемент и первый и последний
    else
        queue->last->next = element;
    queue->last = element;
    queue->size++;
}

QueueElement *queue_pop(Queue *queue)
{
    if (queue->first == nullptr) // список пуст
        return nullptr;
    QueueElement *element = queue->first;
    if (queue->first == queue->last) // элемент и первый и последний
        queue->last = nullptr;
    queue->first = element->next;
    element->next = nullptr;
    queue->size--;
    return element;
}

QueueElement *_queue_recursive_remove(Queue *queue, const string key, const size_t size)
{
    if (size == 0)
        return nullptr;
    if (queue->first->key == key)
    {
        QueueElement *element = queue_pop(queue);
        _queue_recursive_remove(queue, key, size - 1);
        return element;
    }
    queue_push(queue, queue_pop(queue));
    return _queue_recursive_remove(queue, key, size - 1);
}

QueueElement *queue_recursive_remove(Queue *queue, const string key)
{
    return _queue_recursive_remove(queue, key, queue->size);
}

QueueElement *queue_queue_remove(Queue *queue, const string key)
{
    int size = queue->size; // храним, иначе забудем сделать один оборот при наличии элемента с заданным ключом
    QueueElement *element = nullptr;
    for (int i = 1; i <= size; i++)
        if (queue->first->key == key)
            element = queue_pop(queue);
        else
            queue_push(queue, queue_pop(queue));
    return element;
}

bool _queue_recursive_insert(Queue *queue, QueueElement *element, const string key, const size_t size)
{
    if (size == 0)
        return false;
    if (queue->first->key == key)
    {
        if (element->next == nullptr)
            queue_push(queue, element);
        queue_push(queue, queue_pop(queue));
        _queue_recursive_insert(queue, element, key, size - 1);
        return true;
    }
    queue_push(queue, queue_pop(queue));
    return _queue_recursive_insert(queue, element, key, size - 1);
}

bool queue_recursive_insert(Queue *queue, QueueElement *element, const string key)
{
    return _queue_recursive_insert(queue, element, key, queue->size);
}

bool queue_queue_insert(Queue *queue, QueueElement *element, const string key)
{
    if (queue->first == nullptr) // список пуст
        return false;
    int size = queue->size; // храним, иначе сделаем лишний оборот при наличии элемента с заданным ключом
    for (int i = 1; i <= size; i++)
    {
        QueueElement *temp = queue_pop(queue);
        if (queue->first->key == key)
            queue_push(queue, element);
        queue_push(queue, temp);
    }
    return (queue->size > size);
}

bool _queue_recursive_insert(Queue *queue, Queue *elements, const string key, const size_t size)
{
    if (size == 0)
        return false;
    if (queue->first->key == key)
    {
        for (int i = 1, size = elements->size; i <= size; i++)
            queue_push(queue, queue_pop(elements));
        queue_push(queue, queue_pop(queue));
        _queue_recursive_insert(queue, elements, key, size - 1);
        return true;
    }
    queue_push(queue, queue_pop(queue));
    return _queue_recursive_insert(queue, elements, key, size - 1);
}

bool queue_recursive_insert(Queue *queue, Queue *elements, const string key)
{
    return _queue_recursive_insert(queue, elements, key, queue->size);
}

bool queue_queue_insert(Queue *queue, Queue *elements, const string key)
{
    if (queue->first == nullptr) // список пуст
        return false;
    const int size = queue->size; // храним, иначе сделаем лишний оборот при наличии элемента с заданным ключом
    for (int i = 1; i <= size; i++)
    {
        QueueElement *element = queue_pop(queue);
        if (element->key == key)
            for (int i = 1, _size = elements->size; i <= _size; i++)
                queue_push(queue, queue_pop(elements));
        queue_push(queue, element);
    }
    return (queue->size > size);
}

bool queue_save(Queue *queue, const string filename)
{
    ofstream file(filename, ios::binary);
    if (!file)
    {
        file.close();
        return false;
    }
    QueueElement *element = queue->first;
    for (int i = 1; i <= queue->size; i++, element = element->next)
        file << element->key << '\0';
    file.close();
    return true;
}

bool queue_load(Queue *queue, const string filename)
{
    ifstream file(filename, ios::binary);
    if (!file)
    {
        file.close();
        return false;
    }
    string key;
    while (getline(file, key, '\0'))
        queue_push(queue, new QueueElement(key));
    file.close();
    return true;
}