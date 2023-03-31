#include <iostream>
#include "bilist.hpp"
#include "bilist_test.hpp"

using namespace std;

void bilist_test()
{
     cout << "BILIST TEST: " << endl
          << endl;

     cout << "Test bilist_save_load: " << endl;
     test_bilist_save_load();
     cout << endl;

     cout << "Test bilist_recursive_insert: " << endl;
     test_bilist_recursive_insert();
     cout << endl;

     cout << "Test bilist_queue_insert: " << endl;
     test_bilist_queue_insert();
     cout << endl;

     cout << "Test bilist_recursive_insert with K elements: " << endl;
     test_bilist_recursive_insert_K();
     cout << endl;

     cout << "Test bilist_queue_insert with K elements: " << endl;
     test_bilist_queue_insert_K();
     cout << endl;

     cout << "Test bilist_recursive_remove: " << endl;
     test_bilist_recursive_remove();
     cout << endl;

     cout << "Test bilist_queue_remove: " << endl;
     test_bilist_queue_remove();
     cout << endl;

     cout << "BILIST TEST END." << endl
          << endl;
}

void test_bilist_save_load()
{
     const string filename = "bin/bilist.bin";

     BidirectionalElement *A_e1 = new BidirectionalElement("A_e11");
     BidirectionalElement *A_e2 = new BidirectionalElement("A_e22");
     BidirectionalElement *A_e3 = new BidirectionalElement("A_e33");
     BidirectionalList *A = new BidirectionalList();
     BidirectionalList *B = new BidirectionalList();

     bilist_add_after(A, A_e1);
     bilist_add_after(A, A_e2);
     bilist_add_after(A, A_e3);

     cout << "Bilist A with " << A->size << " elements: ";
     bilist_print(A);
     cout << endl;

     cout << "Empty bilist B: ";
     bilist_print(B);
     cout << endl;

     cout << "Save bilist A to file (\"" << filename << "\"): " << bilist_save(A, filename) << endl;

     delete A;

     cout << "Load bilist B from file (\"" << filename << "\"): " << bilist_load(B, filename) << endl;

     cout << "Bilist B with " << B->size << " elements: ";
     bilist_print(B);
     cout << endl;

     delete B;
}

void test_bilist_recursive_insert()
{
     BidirectionalElement *e1 = new BidirectionalElement("e11");
     BidirectionalElement *e2 = new BidirectionalElement("e22");
     BidirectionalElement *e3 = new BidirectionalElement("e33");
     BidirectionalElement *e4 = new BidirectionalElement("e44");
     BidirectionalElement *e5 = new BidirectionalElement("e55");
     BidirectionalElement *e6 = new BidirectionalElement("e66");
     BidirectionalList *list = new BidirectionalList();

     cout << "Empty bilist: ";
     bilist_print(list);
     cout << endl;

     cout << "Insert element to empty bilist with invalid (\"invalid key\") key: "
          << bilist_recursive_insert(list, e1, "invalid key") << endl;

     cout << "Empty bilist: ";
     bilist_print(list);
     cout << endl;

     cout << "Add 1 element after list.";
     bilist_add_after(list, e1);
     cout << endl;

     cout << "Bilist with 1 element: ";
     bilist_print(list);
     cout << endl;

     cout << "Insert element to bilist with invalid (\"invalid key\") key: "
          << bilist_recursive_insert(list, e2, "invalid key") << endl;
     cout << "Insert element to bilist with valid (\"" << e1->key << "\") key: "
          << bilist_recursive_insert(list, e2, e1->key) << endl;

     cout << "Bilist with 2 elements: ";
     bilist_print(list);
     cout << endl;

     cout << "Add 1 element after list.";
     bilist_add_after(list, e3);
     cout << endl;

     cout << "Bilist with 3 elements: ";
     bilist_print(list);
     cout << endl;

     cout << "Add 1 element before list.";
     bilist_add_before(list, e4);
     cout << endl;

     cout << "Bilist with 4 elements: ";
     bilist_print(list);
     cout << endl;

     cout << "Insert element to bilist with valid (\"" << e3->key << "\") key: "
          << bilist_recursive_insert(list, e5, e3->key) << endl;

     cout << "Bilist with 5 elements: ";
     bilist_print(list);
     cout << endl;

     cout << "Insert element to bilist with valid (\"" << e4->key << "\") key: "
          << bilist_recursive_insert(list, e6, e4->key) << endl;

     cout << "Bilist with 6 elements: ";
     bilist_print(list);
     cout << endl;

     delete list;
}

void test_bilist_queue_insert()
{
     BidirectionalElement *e1 = new BidirectionalElement("e11");
     BidirectionalElement *e2 = new BidirectionalElement("e22");
     BidirectionalElement *e3 = new BidirectionalElement("e33");
     BidirectionalElement *e4 = new BidirectionalElement("e44");
     BidirectionalElement *e5 = new BidirectionalElement("e55");
     BidirectionalElement *e6 = new BidirectionalElement("e66");
     BidirectionalList *list = new BidirectionalList();

     cout << "Empty bilist: ";
     bilist_print(list);
     cout << endl;

     cout << "Insert element to empty bilist with invalid (\"invalid key\") key: "
          << bilist_recursive_insert(list, e1, "invalid key") << endl;

     cout << "Empty bilist: ";
     bilist_print(list);
     cout << endl;

     cout << "Add 1 element after list.";
     bilist_add_after(list, e1);
     cout << endl;

     cout << "Bilist with 1 element: ";
     bilist_print(list);
     cout << endl;

     cout << "Insert element to bilist with invalid (\"invalid key\") key: "
          << bilist_recursive_insert(list, e2, "invalid key") << endl;
     cout << "Insert element to bilist with valid (\"" << e1->key << "\") key: "
          << bilist_recursive_insert(list, e2, e1->key) << endl;

     cout << "Bilist with 2 elements: ";
     bilist_print(list);
     cout << endl;

     cout << "Add 1 element after list.";
     bilist_add_after(list, e3);
     cout << endl;

     cout << "Bilist with 3 elements: ";
     bilist_print(list);
     cout << endl;

     cout << "Add 1 element before list.";
     bilist_add_before(list, e4);
     cout << endl;

     cout << "Bilist with 4 elements: ";
     bilist_print(list);
     cout << endl;

     cout << "Insert element to bilist with valid (\"" << e3->key << "\") key: "
          << bilist_recursive_insert(list, e5, e3->key) << endl;

     cout << "Bilist with 5 elements: ";
     bilist_print(list);
     cout << endl;

     cout << "Insert element to bilist with valid (\"" << e4->key << "\") key: "
          << bilist_recursive_insert(list, e6, e4->key) << endl;

     cout << "Bilist with 6 elements: ";
     bilist_print(list);
     cout << endl;

     delete list;
}

void test_bilist_recursive_remove()
{
     BidirectionalElement *e1 = new BidirectionalElement("e11");
     BidirectionalElement *e2 = new BidirectionalElement("e22");
     BidirectionalElement *e3 = new BidirectionalElement("e33");
     BidirectionalList *list = new BidirectionalList();

     cout << "Empty bilist: ";
     bilist_print(list);
     cout << endl;

     cout << "Remove element of empty bilist wiht valid (\"" << e2->key << "\") key (result == nullptr): "
          << (bilist_recursive_remove(list, e2->key) == nullptr) << endl;

     cout << "Add 3 elements to empty bilist.";
     bilist_add_after(list, e1);
     bilist_add_after(list, e2);
     bilist_add_after(list, e3);
     cout << endl;

     cout << "Bilist with 3 elements: ";
     bilist_print(list);
     cout << endl;

     cout << "Remove element of empty bilist wiht valid (\"" << e2->key << "\") key (key): "
          << bilist_recursive_remove(list, e2->key)->key << endl;

     cout << "Bilist with 2 elements: ";
     bilist_print(list);
     cout << endl;

     cout << "Remove element of empty bilist wiht valid (\"" << e1->key << "\") key (key): "
          << bilist_recursive_remove(list, e1->key)->key << endl;

     cout << "Bilist with 1 element: ";
     bilist_print(list);
     cout << endl;

     cout << "Remove element of empty bilist wiht valid (\"" << e3->key << "\") key (key): "
          << bilist_recursive_remove(list, e3->key)->key << endl;

     cout << "Empty bilist: ";
     bilist_print(list);
     cout << endl;

     delete list, e1, e2, e3;
}

void test_bilist_queue_remove()
{

     BidirectionalElement *e1 = new BidirectionalElement("e11");
     BidirectionalElement *e2 = new BidirectionalElement("e22");
     BidirectionalElement *e3 = new BidirectionalElement("e33");
     BidirectionalList *list = new BidirectionalList();

     cout << "Remove element of empty bilist with valid (\"" << e1->key << "\") key (result == nullptr): "
          << (bilist_queue_remove(list, e1->key) == nullptr) << endl;

     cout << "Add 3 elements to empty bilist.";
     bilist_add_after(list, e1);
     bilist_add_after(list, e2);
     bilist_add_after(list, e3);
     cout << endl;

     cout << "Bilist with 3 elements: ";
     bilist_print(list);
     cout << endl;

     cout << "Remove element of empty bilist with valid (\"" << e2->key << "\") key (key): "
          << bilist_queue_remove(list, e2->key)->key << endl;

     cout << "Bilist with 2 elements: ";
     bilist_print(list);
     cout << endl;

     cout << "Remove element of empty bilist with valid (\"" << e1->key << "\") key (key): "
          << bilist_queue_remove(list, e1->key)->key << endl;

     cout << "Bilist with 1 element: ";
     bilist_print(list);
     cout << endl;

     cout << "Remove element of empty bilist with valid (\"" << e3->key << "\") key (key): "
          << bilist_queue_remove(list, e3->key)->key << endl;

     cout << "Empty bilist: ";
     bilist_print(list);
     cout << endl;

     delete list, e1, e2, e3;
}

void test_bilist_recursive_insert_K()
{

     BidirectionalElement *A_e1 = new BidirectionalElement("A_e11");
     BidirectionalElement *A_e2 = new BidirectionalElement("A_e22");
     BidirectionalElement *A_e3 = new BidirectionalElement("A_e33");
     BidirectionalList *A = new BidirectionalList();
     bilist_add_after(A, A_e1);
     bilist_add_after(A, A_e2);
     bilist_add_after(A, A_e3);

     cout << "Bilist A with 3 elements: ";
     bilist_print(A);
     cout << endl;

     BidirectionalElement *B_e1 = new BidirectionalElement("B_e11");
     BidirectionalElement *B_e2 = new BidirectionalElement("B_e22");
     BidirectionalElement *B_e3 = new BidirectionalElement("B_e33");
     BidirectionalElement *B_e4 = new BidirectionalElement("B_e44");
     BidirectionalList *B = new BidirectionalList();
     bilist_add_after(B, B_e1);
     bilist_add_after(B, B_e2);
     bilist_add_after(B, B_e3);
     bilist_add_after(B, B_e4);

     cout << "Bilist B with 4 elements: ";
     bilist_print(B);
     cout << endl;

     BidirectionalElement *C_e1 = new BidirectionalElement("C_e11");
     BidirectionalList *C = new BidirectionalList();

     cout << "Empty bilist C: ";
     bilist_print(C);
     cout << endl;

     cout << "Insert " << A->size << " elements to empty bilist with invalid (\"invalid key\") key: "
          << bilist_recursive_insert(C, A, "invalid key") << endl;

     cout << "Empty bilist C: ";
     bilist_print(C);
     cout << endl;

     cout << "Add 1 element after list.";
     bilist_add_after(C, C_e1);
     cout << endl;

     cout << "Bilist C with 1 element: ";
     bilist_print(C);
     cout << endl;

     cout << "Insert " << A->size << " element to bilist with invalid (\"invalid key\") key: "
          << bilist_recursive_insert(C, A, "invalid key") << endl;

     cout << "Insert " << A->size << " element to bilist with valid (\"" << C_e1->key << "\") key: "
          << bilist_recursive_insert(C, A, C_e1->key) << endl;

     cout << "Bilist C with " << C->size << " elements: ";
     bilist_print(C);
     cout << endl;

     cout << "Insert " << B->size << " element to bilist with valid (\"" << C_e1->key << "\") key: "
          << bilist_recursive_insert(C, B, C_e1->key) << endl;

     cout << "Bilist C with " << C->size << " elements: ";
     bilist_print(C);
     cout << endl;

     delete A, B, C;
}

void test_bilist_queue_insert_K()
{

     BidirectionalElement *A_e1 = new BidirectionalElement("A_e11");
     BidirectionalElement *A_e2 = new BidirectionalElement("A_e22");
     BidirectionalElement *A_e3 = new BidirectionalElement("A_e33");
     BidirectionalList *A = new BidirectionalList();
     bilist_add_after(A, A_e1);
     bilist_add_after(A, A_e2);
     bilist_add_after(A, A_e3);

     cout << "Bilist A with 3 elements: ";
     bilist_print(A);
     cout << endl;

     BidirectionalElement *B_e1 = new BidirectionalElement("B_e11");
     BidirectionalElement *B_e2 = new BidirectionalElement("B_e22");
     BidirectionalElement *B_e3 = new BidirectionalElement("B_e33");
     BidirectionalElement *B_e4 = new BidirectionalElement("B_e44");
     BidirectionalList *B = new BidirectionalList();
     bilist_add_after(B, B_e1);
     bilist_add_after(B, B_e2);
     bilist_add_after(B, B_e3);
     bilist_add_after(B, B_e4);

     cout << "Bilist B with 4 elements: ";
     bilist_print(B);
     cout << endl;

     BidirectionalElement *C_e1 = new BidirectionalElement("C_e11");
     BidirectionalList *C = new BidirectionalList();

     cout << "Empty bilist C: ";
     bilist_print(C);
     cout << endl;

     cout << "Insert " << A->size << " elements to empty bilist with invalid (\"invalid key\") key: "
          << bilist_recursive_insert(C, A, "invalid key") << endl;

     cout << "Empty bilist C: ";
     bilist_print(C);
     cout << endl;

     cout << "Add 1 element after list.";
     bilist_add_after(C, C_e1);
     cout << endl;

     cout << "Bilist C with 1 element: ";
     bilist_print(C);
     cout << endl;

     cout << "Insert " << A->size << " element to bilist with invalid (\"invalid key\") key: "
          << bilist_recursive_insert(C, A, "invalid key") << endl;

     cout << "Insert " << A->size << " element to bilist with valid (\"" << C_e1->key << "\") key: "
          << bilist_recursive_insert(C, A, C_e1->key) << endl;

     cout << "Bilist C with " << C->size << " elements: ";
     bilist_print(C);
     cout << endl;

     cout << "Insert " << B->size << " element to bilist with valid (\"" << C_e1->key << "\") key: "
          << bilist_recursive_insert(C, B, C_e1->key) << endl;

     cout << "Bilist C with " << C->size << " elements: ";
     bilist_print(C);
     cout << endl;

     delete A, B, C;
}
