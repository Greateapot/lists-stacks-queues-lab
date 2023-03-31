#include <iostream>
#include <fstream>

#include "bilist.hpp"

using namespace std;

void bilist_print(BidirectionalList *list)
{
    if (list->first == nullptr) // список пуст
        return;
    BidirectionalElement *element = list->first;
    for (int i = 2; i <= list->size; i++)
    {
        cout << element->key << ", ";
        element = element->next;
    }
    cout << element->key;
}

void bilist_add_before(BidirectionalList *list, BidirectionalElement *element)
{
    element->next = list->first;
    if (list->size == 0)      // список пуст
        list->last = element; // новый элемент и первый и последний
    else
        list->first->previous = element;
    list->first = element;
    list->size++;
}

void bilist_add_after(BidirectionalList *list, BidirectionalElement *element)
{
    if (list->last == nullptr) // список пуст
        bilist_add_before(list, element);
    else
    {
        list->last->next = element;
        element->previous = list->last;
        list->last = element;
        list->size++;
    }
}

BidirectionalElement *bilist_pop_first(BidirectionalList *list)
{
    if (list->first == nullptr) // список пуст
        return nullptr;
    BidirectionalElement *element = list->first;
    list->first = element->next;
    if (list->first == nullptr) // Это был единственный элемент
        list->last = nullptr;
    else // если бы он был последним, то ему не пришлось бы ставить nullptr
    {
        element->next->previous = nullptr;
        element->next = nullptr;
    }
    list->size--;
    return element;
}

BidirectionalElement *bilist_pop_last(BidirectionalList *list)
{
    if (list->last == nullptr) // список пуст
        return nullptr;
    BidirectionalElement *element = list->last;
    if (list->first == list->last) // это был единственный элемент
    {
        list->first = nullptr;
        list->last = nullptr;
    }
    else // это был не единственный элемент
    {
        element->previous->next = nullptr;
        list->last = element->previous;
        element->previous = nullptr;
    }
    list->size--;
    return element;
}

BidirectionalElement *_bilist_recursive_search(BidirectionalElement *element, const string key)
{
    if (element->key == key)
        return element;
    if (element->next == nullptr)
        return nullptr;
    return _bilist_recursive_search(element->next, key);
}

BidirectionalElement *bilist_recursive_remove(BidirectionalList *list, const string key)
{
    if (list->first == nullptr) // список пуст
        return nullptr;
    if (list->first->key == key)       // первый элемент подходит
        return bilist_pop_first(list); // значит его и удаляем
    if (list->first == list->last)     // он не подошел и оказался единственным
        return nullptr;
    // он не подошел, но он не единственный
    BidirectionalElement *element = _bilist_recursive_search(list->first, key);
    if (element != nullptr) // не нашлось элемента с таким ключом
    {
        element->previous->next = element->next;
        element->next->previous = element->previous;
        list->size--;
    }
    return element;
}

BidirectionalElement *bilist_queue_remove(BidirectionalList *list, const string key)
{
    if (list->first == nullptr) // список пуст
        return nullptr;
    int _size = list->size; // храним, иначе забудем сделать один оборот при наличии элемента с заданным ключом
    BidirectionalElement *element = nullptr;
    for (int i = 1; i <= _size; i++)
    {
        BidirectionalElement *temp = bilist_pop_first(list);
        if (temp->key == key)
            element = temp;
        else
            bilist_add_after(list, temp);
    }
    return element;
}

bool bilist_recursive_insert(BidirectionalList *list, BidirectionalElement *element, const string key)
{
    if (list->first == nullptr) // список пуст
        return false;
    if (list->first->key == key) // первый элемент подходит
    {
        bilist_add_before(list, element); // значит добавляем в начало
        return true;
    }
    if (list->first == list->last) // он не подошел и оказался единственным
        return false;
    // он не подошел, но он не единственный
    BidirectionalElement *temp = _bilist_recursive_search(list->first, key);
    if (temp == nullptr) // не нашлось элемента с таким ключом
        return false;
    temp->previous->next = element;
    element->next = temp;
    element->previous = temp->previous;
    temp->previous = element;
    list->size++;
    return true;
}

bool bilist_queue_insert(BidirectionalList *list, BidirectionalElement *element, const string key)
{
    if (list->first == nullptr) // список пуст
        return false;
    int _size = list->size; // храним, иначе сделаем лишний оборот при наличии элемента с заданным ключом
    for (int i = 1; i <= _size; i++)
    {
        BidirectionalElement *temp = bilist_pop_first(list);
        if (temp->key == key)
            bilist_add_after(list, element);
        bilist_add_after(list, temp);
    }
    return (list->size > _size);
}

bool bilist_recursive_insert(BidirectionalList *list, BidirectionalList *elements, const string key)
{
    if (list->first == nullptr) // список пуст
        return false;
    if (list->first->key == key) // первый элемент подходит
    {
        int _size = elements->size;
        for (int i = 1; i <= _size; i++)
            bilist_add_before(list, bilist_pop_last(elements));
        return true;
    }
    if (list->first == list->last) // он не подошел и оказался единственным
        return false;
    // он не подошел, но он не единственный
    BidirectionalElement *element = _bilist_recursive_search(list->first, key);
    if (element == nullptr) // не нашлось элемента с таким ключом
        return false;
    element->previous->next = elements->first;
    elements->first->previous = element->previous;
    element->previous = elements->last;
    elements->last->next = element;
    list->size += elements->size;
    elements->first = nullptr;
    elements->last = nullptr;
    elements->size = 0;
    return true;
}

bool bilist_queue_insert(BidirectionalList *list, BidirectionalList *elements, const string key)
{
    if (list->first == nullptr) // список пуст
        return false;
    int _size = list->size; // храним, иначе сделаем лишний оборот при наличии элемента с заданным ключом
    for (int i = 1; i <= _size; i++)
    {
        BidirectionalElement *element = bilist_pop_first(list);
        if (element->key == key)
        {
            int __size = elements->size;
            for (int i = 1; i <= __size; i++)
                bilist_add_after(list, bilist_pop_first(elements));
        }
        bilist_add_after(list, element);
    }
    return (list->size > _size);
}


bool bilist_save(BidirectionalList *list, const string filename)
{
    ofstream file(filename, ios::binary);
    if (!file)
    {
        file.close();
        return false;
    }
    BidirectionalElement *element = list->first;
    for (int i = 1; i <= list->size; i++, element = element->next)
        file << element->key << '\0';
    file.close();
    return true;
}

bool bilist_load(BidirectionalList *list, const string filename)
{
    ifstream file(filename, ios::binary);
    if (!file)
    {
        file.close();
        return false;
    }
    string key;
    while (getline(file, key, '\0'))
        bilist_add_after(list, new BidirectionalElement(key));
    file.close();
    return true;
}
