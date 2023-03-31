#include <iostream>
#include "queue.hpp"
#include "queue_test.hpp"

using namespace std;

void queue_test()
{
     cout << "QUEUE TEST: " << endl
          << endl;

     cout << "Test queue_save_load: " << endl;
     test_queue_save_load();
     cout << endl;

     cout << "Test queue_recursive_insert: " << endl;
     test_queue_recursive_insert();
     cout << endl;

     cout << "Test queue_queue_insert: " << endl;
     test_queue_queue_insert();
     cout << endl;

     cout << "Test queue_recursive_insert with K elements: " << endl;
     test_queue_recursive_insert_K();
     cout << endl;

     cout << "Test queue_queue_insert with K elements: " << endl;
     test_queue_queue_insert_K();
     cout << endl;

     cout << "Test queue_recursive_remove: " << endl;
     test_queue_recursive_remove();
     cout << endl;

     cout << "Test queue_queue_remove: " << endl;
     test_queue_queue_remove();
     cout << endl;

     cout << "QUEUE TEST END." << endl
          << endl;
}

void test_queue_save_load()
{
     const string filename = "bin/queue.bin";

     QueueElement *A_e1 = new QueueElement("A_e11");
     QueueElement *A_e2 = new QueueElement("A_e22");
     QueueElement *A_e3 = new QueueElement("A_e33");
     Queue *A = new Queue();
     Queue *B = new Queue();

     queue_push(A, A_e1);
     queue_push(A, A_e2);
     queue_push(A, A_e3);

     cout << "Queue A with " << A->size << " elements: ";
     queue_print(A);
     cout << endl;

     cout << "Empty queue B: ";
     queue_print(B);
     cout << endl;

     cout << "Save queue A to file (\"" << filename << "\"): " << queue_save(A, filename) << endl;

     delete A;

     cout << "Load queue B from file (\"" << filename << "\"): " << queue_load(B, filename) << endl;

     cout << "Queue B with " << B->size << " elements: ";
     queue_print(B);
     cout << endl;

     delete B;
}

void test_queue_recursive_insert()
{
     QueueElement *e1 = new QueueElement("e11");
     QueueElement *e2 = new QueueElement("e22");
     QueueElement *e3 = new QueueElement("e33");
     QueueElement *e4 = new QueueElement("e44");
     Queue *queue = new Queue();

     cout << "Empty queue: ";
     queue_print(queue);
     cout << endl;

     cout << "Insert element to empty queue with invalid (\"invalid key\") key: "
          << queue_recursive_insert(queue, e1, "invalid key") << endl;

     cout << "Empty queue: ";
     queue_print(queue);
     cout << endl;

     cout << "Add 1 element after queue.";
     queue_push(queue, e1);
     cout << endl;

     cout << "Queue with 1 element: ";
     queue_print(queue);
     cout << endl;

     cout << "Insert element to queue with invalid (\"invalid key\") key: "
          << queue_recursive_insert(queue, e2, "invalid key") << endl;
     cout << "Insert element to queue with valid (\"" << e1->key << "\") key: "
          << queue_recursive_insert(queue, e2, e1->key) << endl;

     cout << "Queue with " << queue->size <<" elements: ";
     queue_print(queue);
     cout << endl;

     cout << "Add 1 element after queue.";
     queue_push(queue, e3);
     cout << endl;

     cout << "Queue with " << queue->size <<" elements: ";
     queue_print(queue);
     cout << endl;

     cout << "Insert element to queue with valid (\"" << e3->key << "\") key: "
          << queue_recursive_insert(queue, e4, e3->key) << endl;

     cout << "Queue with " << queue->size <<" elements: ";
     queue_print(queue);
     cout << endl;

     delete queue;
}

void test_queue_queue_insert()
{
     QueueElement *e1 = new QueueElement("e11");
     QueueElement *e2 = new QueueElement("e22");
     QueueElement *e3 = new QueueElement("e33");
     QueueElement *e4 = new QueueElement("e44");
     Queue *queue = new Queue();

     cout << "Empty queue: ";
     queue_print(queue);
     cout << endl;

     cout << "Insert element to empty queue with invalid (\"invalid key\") key: "
          << queue_recursive_insert(queue, e1, "invalid key") << endl;

     cout << "Empty queue: ";
     queue_print(queue);
     cout << endl;

     cout << "Add 1 element after queue.";
     queue_push(queue, e1);
     cout << endl;

     cout << "Queue with 1 element: ";
     queue_print(queue);
     cout << endl;

     cout << "Insert element to queue with invalid (\"invalid key\") key: "
          << queue_recursive_insert(queue, e2, "invalid key") << endl;
     cout << "Insert element to queue with valid (\"" << e1->key << "\") key: "
          << queue_recursive_insert(queue, e2, e1->key) << endl;

     cout << "Queue with " << queue->size <<" elements: ";
     queue_print(queue);
     cout << endl;

     cout << "Add 1 element after queue.";
     queue_push(queue, e3);
     cout << endl;

     cout << "Queue with " << queue->size <<" elements: ";
     queue_print(queue);
     cout << endl;

     cout << "Insert element to queue with valid (\"" << e3->key << "\") key: "
          << queue_recursive_insert(queue, e4, e3->key) << endl;

     cout << "Queue with " << queue->size <<" elements: ";
     queue_print(queue);
     cout << endl;

     delete queue;
}

void test_queue_recursive_remove()
{
     QueueElement *e1 = new QueueElement("e11");
     QueueElement *e2 = new QueueElement("e22");
     QueueElement *e3 = new QueueElement("e33");
     Queue *queue = new Queue();

     cout << "Empty queue: ";
     queue_print(queue);
     cout << endl;

     cout << "Remove element of empty queue wiht valid (\"" << e2->key << "\") key (result == nullptr): "
          << (queue_recursive_remove(queue, e2->key) == nullptr) << endl;

     cout << "Add 3 elements to empty queue.";
     queue_push(queue, e1);
     queue_push(queue, e2);
     queue_push(queue, e3);
     cout << endl;

     cout << "Queue with 3 elements: ";
     queue_print(queue);
     cout << endl;

     cout << "Remove element of empty queue wiht valid (\"" << e2->key << "\") key (key): "
          << queue_recursive_remove(queue, e2->key)->key << endl;

     cout << "Queue with 2 elements: ";
     queue_print(queue);
     cout << endl;

     cout << "Remove element of empty queue wiht valid (\"" << e1->key << "\") key (key): "
          << queue_recursive_remove(queue, e1->key)->key << endl;

     cout << "Queue with 1 element: ";
     queue_print(queue);
     cout << endl;

     cout << "Remove element of empty queue wiht valid (\"" << e3->key << "\") key (key): "
          << queue_recursive_remove(queue, e3->key)->key << endl;

     cout << "Empty queue: ";
     queue_print(queue);
     cout << endl;

     delete queue, e1, e2, e3;
}

void test_queue_queue_remove()
{

     QueueElement *e1 = new QueueElement("e11");
     QueueElement *e2 = new QueueElement("e22");
     QueueElement *e3 = new QueueElement("e33");
     Queue *queue = new Queue();

     cout << "Remove element of empty queue with valid (\"" << e1->key << "\") key (result == nullptr): "
          << (queue_queue_remove(queue, e1->key) == nullptr) << endl;

     cout << "Add 3 elements to empty queue.";
     queue_push(queue, e1);
     queue_push(queue, e2);
     queue_push(queue, e3);
     cout << endl;

     cout << "Queue with 3 elements: ";
     queue_print(queue);
     cout << endl;

     cout << "Remove element of empty queue with valid (\"" << e2->key << "\") key (key): "
          << queue_queue_remove(queue, e2->key)->key << endl;

     cout << "Queue with 2 elements: ";
     queue_print(queue);
     cout << endl;

     cout << "Remove element of empty queue with valid (\"" << e1->key << "\") key (key): "
          << queue_queue_remove(queue, e1->key)->key << endl;

     cout << "Queue with 1 element: ";
     queue_print(queue);
     cout << endl;

     cout << "Remove element of empty queue with valid (\"" << e3->key << "\") key (key): "
          << queue_queue_remove(queue, e3->key)->key << endl;

     cout << "Empty queue: ";
     queue_print(queue);
     cout << endl;

     delete queue, e1, e2, e3;
}

void test_queue_recursive_insert_K()
{

     QueueElement *A_e1 = new QueueElement("A_e11");
     QueueElement *A_e2 = new QueueElement("A_e22");
     QueueElement *A_e3 = new QueueElement("A_e33");
     Queue *A = new Queue();
     queue_push(A, A_e1);
     queue_push(A, A_e2);
     queue_push(A, A_e3);

     cout << "Queue A with 3 elements: ";
     queue_print(A);
     cout << endl;

     QueueElement *B_e1 = new QueueElement("B_e11");
     QueueElement *B_e2 = new QueueElement("B_e22");
     QueueElement *B_e3 = new QueueElement("B_e33");
     QueueElement *B_e4 = new QueueElement("B_e44");
     Queue *B = new Queue();
     queue_push(B, B_e1);
     queue_push(B, B_e2);
     queue_push(B, B_e3);
     queue_push(B, B_e4);

     cout << "Queue B with 4 elements: ";
     queue_print(B);
     cout << endl;

     QueueElement *C_e1 = new QueueElement("C_e11");
     Queue *C = new Queue();

     cout << "Empty queue C: ";
     queue_print(C);
     cout << endl;

     cout << "Insert " << A->size << " elements to empty queue with invalid (\"invalid key\") key: "
          << queue_recursive_insert(C, A, "invalid key") << endl;

     cout << "Empty queue C: ";
     queue_print(C);
     cout << endl;

     cout << "Add 1 element after queue.";
     queue_push(C, C_e1);
     cout << endl;

     cout << "Queue C with 1 element: ";
     queue_print(C);
     cout << endl;

     cout << "Insert " << A->size << " element to queue with invalid (\"invalid key\") key: "
          << queue_recursive_insert(C, A, "invalid key") << endl;

     cout << "Insert " << A->size << " element to queue with valid (\"" << C_e1->key << "\") key: "
          << queue_recursive_insert(C, A, C_e1->key) << endl;

     cout << "Queue C with " << C->size << " elements: ";
     queue_print(C);
     cout << endl;

     cout << "Insert " << B->size << " element to queue with valid (\"" << C_e1->key << "\") key: "
          << queue_recursive_insert(C, B, C_e1->key) << endl;

     cout << "Queue C with " << C->size << " elements: ";
     queue_print(C);
     cout << endl;

     delete A, B, C;
}

void test_queue_queue_insert_K()
{

     QueueElement *A_e1 = new QueueElement("A_e11");
     QueueElement *A_e2 = new QueueElement("A_e22");
     QueueElement *A_e3 = new QueueElement("A_e33");
     Queue *A = new Queue();
     queue_push(A, A_e1);
     queue_push(A, A_e2);
     queue_push(A, A_e3);

     cout << "Queue A with 3 elements: ";
     queue_print(A);
     cout << endl;

     QueueElement *B_e1 = new QueueElement("B_e11");
     QueueElement *B_e2 = new QueueElement("B_e22");
     QueueElement *B_e3 = new QueueElement("B_e33");
     QueueElement *B_e4 = new QueueElement("B_e44");
     Queue *B = new Queue();
     queue_push(B, B_e1);
     queue_push(B, B_e2);
     queue_push(B, B_e3);
     queue_push(B, B_e4);

     cout << "Queue B with 4 elements: ";
     queue_print(B);
     cout << endl;

     QueueElement *C_e1 = new QueueElement("C_e11");
     Queue *C = new Queue();

     cout << "Empty queue C: ";
     queue_print(C);
     cout << endl;

     cout << "Insert " << A->size << " elements to empty queue with invalid (\"invalid key\") key: "
          << queue_recursive_insert(C, A, "invalid key") << endl;

     cout << "Empty queue C: ";
     queue_print(C);
     cout << endl;

     cout << "Add 1 element after queue.";
     queue_push(C, C_e1);
     cout << endl;

     cout << "Queue C with 1 element: ";
     queue_print(C);
     cout << endl;

     cout << "Insert " << A->size << " element to queue with invalid (\"invalid key\") key: "
          << queue_recursive_insert(C, A, "invalid key") << endl;

     cout << "Insert " << A->size << " element to queue with valid (\"" << C_e1->key << "\") key: "
          << queue_recursive_insert(C, A, C_e1->key) << endl;

     cout << "Queue C with " << C->size << " elements: ";
     queue_print(C);
     cout << endl;

     cout << "Insert " << B->size << " element to queue with valid (\"" << C_e1->key << "\") key: "
          << queue_recursive_insert(C, B, C_e1->key) << endl;

     cout << "Queue C with " << C->size << " elements: ";
     queue_print(C);
     cout << endl;

     delete A, B, C;
}
