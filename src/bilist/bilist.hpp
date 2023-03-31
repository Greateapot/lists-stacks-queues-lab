#pragma once

#include <iostream>

using namespace std;

struct BidirectionalElement
{
    string key;
    BidirectionalElement *next;
    BidirectionalElement *previous;

    BidirectionalElement(string key, BidirectionalElement *next = nullptr, BidirectionalElement *previous = nullptr)
        : key(key), next(next), previous(previous){};

    ~BidirectionalElement()
    {
        if (next != nullptr)
            delete next;
    }
};

struct BidirectionalList
{
    size_t size;
    BidirectionalElement *first;
    BidirectionalElement *last;

    BidirectionalList(size_t size = 0, BidirectionalElement *first = nullptr, BidirectionalElement *last = nullptr)
        : size(size), first(first), last(last){};

    ~BidirectionalList()
    {
        if (first != nullptr)
            delete first;
    }
};

void bilist_print(BidirectionalList *list);

void bilist_add_before(BidirectionalList *list, BidirectionalElement *element);

void bilist_add_after(BidirectionalList *list, BidirectionalElement *element);

BidirectionalElement *bilist_pop_first(BidirectionalList *list);

BidirectionalElement *bilist_pop_last(BidirectionalList *list);

BidirectionalElement *bilist_recursive_remove(BidirectionalList *list, const string key);

BidirectionalElement *bilist_queue_remove(BidirectionalList *list, const string key);

bool bilist_recursive_insert(BidirectionalList *list, BidirectionalElement *element, const string key);

bool bilist_queue_insert(BidirectionalList *list, BidirectionalElement *element, const string key);

bool bilist_recursive_insert(BidirectionalList *list, BidirectionalList *elements, const string key);

bool bilist_queue_insert(BidirectionalList *list, BidirectionalList *elements, const string key);

bool bilist_save(BidirectionalList *list, const string filename);

bool bilist_load(BidirectionalList *list, const string filename);
