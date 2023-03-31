#include <iostream>
#include <fstream>

#include "unilist.hpp"

using namespace std;

void unilist_print(UnidirectionalList *list)
{
    if (list->first == nullptr) // список пуст
        return;
    UnidirectionalElement *element = list->first;
    for (int i = 2; i <= list->size; i++)
    {
        cout << element->key << ", ";
        element = element->next;
    }
    cout << element->key;
}

void unilist_add_before(UnidirectionalList *list, UnidirectionalElement *element)
{
    element->next = list->first;
    list->first = element;
    if (list->size == 0)      // список пуст
        list->last = element; // новый элемент и первый и последний
    list->size++;
}

void unilist_add_after(UnidirectionalList *list, UnidirectionalElement *element)
{
    if (list->last == nullptr) // список пуст
        unilist_add_before(list, element);
    else
    {
        list->last->next = element;
        list->last = element;
        list->size++;
    }
}

UnidirectionalElement *unilist_pop_first(UnidirectionalList *list)
{
    if (list->first == nullptr) // список пуст
        return nullptr;
    UnidirectionalElement *element = list->first;
    list->first = element->next;
    if (list->first == nullptr) // Это был единственный элемент
        list->last = nullptr;
    else // если бы он был последним, то ему не пришлось бы ставить nullptr
        element->next = nullptr;
    list->size--;
    return element;
}

UnidirectionalElement *unilist_pop_last(UnidirectionalList *list)
{
    if (list->last == nullptr) // список пуст
        return nullptr;
    UnidirectionalElement *temp = list->first;
    if (list->first == list->last) // это был единственный элемент
    {
        list->first = nullptr;
        list->last = nullptr;
        list->size--;
        return temp;
    }
    for (; temp->next != list->last; temp = temp->next) // ищем предпоследний элемент
        ;                                               // странная у форматтера логика
    UnidirectionalElement *element = temp->next;        // последний элемент
    list->last = temp;
    temp->next = nullptr;
    list->size--;
    return element;
}

UnidirectionalElement *_unilist_recursive_search(UnidirectionalElement *element, const string key)
{
    if (element->next == nullptr)
        return nullptr;
    if (element->next->key == key)
        return element;
    return _unilist_recursive_search(element->next, key);
}

UnidirectionalElement *unilist_recursive_remove(UnidirectionalList *list, const string key)
{
    if (list->first == nullptr) // список пуст
        return nullptr;
    if (list->first->key == key)        // первый элемент подходит
        return unilist_pop_first(list); // значит его и удаляем
    if (list->first == list->last)      // он не подошел и оказался единственным
        return nullptr;
    // он не подошел, но он не единственный
    UnidirectionalElement *temp = _unilist_recursive_search(list->first, key);
    if (temp == nullptr) // не нашлось элемента с таким ключом
        return nullptr;
    UnidirectionalElement *element = temp->next;
    temp->next = element->next;
    if (list->last == element)
        list->last = temp;
    element->next = nullptr;
    list->size--;
    return element;
}

UnidirectionalElement *unilist_queue_remove(UnidirectionalList *list, const string key)
{
    if (list->first == nullptr) // список пуст
        return nullptr;
    int _size = list->size; // храним, иначе забудем сделать один оборот при наличии элемента с заданным ключом
    UnidirectionalElement *element = nullptr;
    for (int i = 1; i <= _size; i++)
    {
        UnidirectionalElement *temp = unilist_pop_first(list);
        if (temp->key == key)
            element = temp;
        else
            unilist_add_after(list, temp);
    }
    return element;
}

bool unilist_recursive_insert(UnidirectionalList *list, UnidirectionalElement *element, const string key)
{
    if (list->first == nullptr) // список пуст
        return false;
    if (list->first->key == key) // первый элемент подходит
    {
        unilist_add_before(list, element); // значит добавляем в начало
        return true;
    }
    if (list->first == list->last) // он не подошел и оказался единственным
        return false;
    // он не подошел, но он не единственный
    UnidirectionalElement *temp = _unilist_recursive_search(list->first, key);
    if (temp == nullptr) // не нашлось элемента с таким ключом
        return false;
    element->next = temp->next;
    temp->next = element;
    list->size++;
    return true;
}

bool unilist_queue_insert(UnidirectionalList *list, UnidirectionalElement *element, const string key)
{
    if (list->first == nullptr) // список пуст
        return false;
    int _size = list->size; // храним, иначе сделаем лишний оборот при наличии элемента с заданным ключом
    for (int i = 1; i <= _size; i++)
    {
        UnidirectionalElement *temp = unilist_pop_first(list);
        if (temp->key == key)
            unilist_add_after(list, element);
        unilist_add_after(list, temp);
    }
    return (list->size > _size);
}

bool unilist_recursive_insert(UnidirectionalList *list, UnidirectionalList *elements, const string key)
{
    if (list->first == nullptr) // список пуст
        return false;
    if (list->first->key == key) // первый элемент подходит
    {
        int _size = elements->size;
        for (int i = 1; i <= _size; i++)
            unilist_add_before(list, unilist_pop_last(elements));
        return true;
    }
    if (list->first == list->last) // он не подошел и оказался единственным
        return false;
    // он не подошел, но он не единственный
    UnidirectionalElement *temp = _unilist_recursive_search(list->first, key);
    if (temp == nullptr) // не нашлось элемента с таким ключом
        return false;
    elements->last->next = temp->next;
    temp->next = elements->first;
    list->size += elements->size;
    elements->first = nullptr;
    elements->last = nullptr;
    elements->size = 0;
    return true;
}

bool unilist_queue_insert(UnidirectionalList *list, UnidirectionalList *elements, const string key)
{
    if (list->first == nullptr) // список пуст
        return false;
    int _size = list->size; // храним, иначе сделаем лишний оборот при наличии элемента с заданным ключом
    for (int i = 1; i <= _size; i++)
    {
        UnidirectionalElement *element = unilist_pop_first(list);
        if (element->key == key)
        {
            int __size = elements->size;
            for (int i = 1; i <= __size; i++)
                unilist_add_after(list, unilist_pop_first(elements));
        }
        unilist_add_after(list, element);
    }
    return (list->size > _size);
}

bool unilist_save(UnidirectionalList *list, const string filename)
{
    ofstream file(filename, ios::binary);
    if (!file)
    {
        file.close();
        return false;
    }
    UnidirectionalElement *element = list->first;
    for (int i = 1; i <= list->size; i++, element = element->next)
        file << element->key << '\0';
    file.close();
    return true;
}

bool unilist_load(UnidirectionalList *list, const string filename)
{
    ifstream file(filename, ios::binary);
    if (!file)
    {
        file.close();
        return false;
    }
    string key;
    while (getline(file, key, '\0'))
        unilist_add_after(list, new UnidirectionalElement(key));
    file.close();
    return true;
}