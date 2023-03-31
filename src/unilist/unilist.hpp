#pragma once

#include <iostream>

using namespace std;

struct UnidirectionalElement
{
    string key;
    UnidirectionalElement *next;

    UnidirectionalElement(string key, UnidirectionalElement *next = nullptr)
        : key(key), next(next){};

    ~UnidirectionalElement()
    {
        if (next != nullptr)
            delete next;
    }
};

struct UnidirectionalList
{
    size_t size;
    UnidirectionalElement *first;
    UnidirectionalElement *last;

    UnidirectionalList(size_t size = 0, UnidirectionalElement *first = nullptr, UnidirectionalElement *last = nullptr)
        : size(size), first(first), last(last){};

    ~UnidirectionalList()
    {
        if (first != nullptr)
            delete first;
    }
};

void unilist_print(UnidirectionalList *list);

void unilist_add_before(UnidirectionalList *list, UnidirectionalElement *element);

void unilist_add_after(UnidirectionalList *list, UnidirectionalElement *element);

UnidirectionalElement *unilist_pop_first(UnidirectionalList *list);

UnidirectionalElement *unilist_pop_last(UnidirectionalList *list);

UnidirectionalElement *unilist_recursive_remove(UnidirectionalList *list, const string key);

UnidirectionalElement *unilist_queue_remove(UnidirectionalList *list, const string key);

bool unilist_recursive_insert(UnidirectionalList *list, UnidirectionalElement *element, const string key);

bool unilist_queue_insert(UnidirectionalList *list, UnidirectionalElement *element, const string key);

bool unilist_recursive_insert(UnidirectionalList *list, UnidirectionalList *elements, const string key);

bool unilist_queue_insert(UnidirectionalList *list, UnidirectionalList *elements, const string key);

bool unilist_save(UnidirectionalList *list, const string filename);

bool unilist_load(UnidirectionalList *list, const string filename);
