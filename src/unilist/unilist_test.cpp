#include <iostream>
#include "unilist.hpp"
#include "unilist_test.hpp"

using namespace std;

void unilist_test()
{
     cout << "UNILIST TEST: " << endl
          << endl;

     cout << "Test unilist_save_load: " << endl;
     test_unilist_save_load();
     cout << endl;

     cout << "Test unilist_recursive_insert: " << endl;
     test_unilist_recursive_insert();
     cout << endl;

     cout << "Test unilist_queue_insert: " << endl;
     test_unilist_queue_insert();
     cout << endl;

     cout << "Test unilist_recursive_insert with K elements: " << endl;
     test_unilist_recursive_insert_K();
     cout << endl;

     cout << "Test unilist_queue_insert with K elements: " << endl;
     test_unilist_queue_insert_K();
     cout << endl;

     cout << "Test unilist_recursive_remove: " << endl;
     test_unilist_recursive_remove();
     cout << endl;

     cout << "Test unilist_queue_remove: " << endl;
     test_unilist_queue_remove();
     cout << endl;

     cout << "UNILIST TEST END." << endl
          << endl;
}

void test_unilist_save_load()
{
     const string filename = "bin/unilist.bin";

     UnidirectionalElement *A_e1 = new UnidirectionalElement("A_e11");
     UnidirectionalElement *A_e2 = new UnidirectionalElement("A_e22");
     UnidirectionalElement *A_e3 = new UnidirectionalElement("A_e33");
     UnidirectionalList *A = new UnidirectionalList();
     UnidirectionalList *B = new UnidirectionalList();

     unilist_add_after(A, A_e1);
     unilist_add_after(A, A_e2);
     unilist_add_after(A, A_e3);

     cout << "Unilist A with " << A->size << " elements: ";
     unilist_print(A);
     cout << endl;

     cout << "Empty unilist B: ";
     unilist_print(B);
     cout << endl;

     cout << "Save unilist A to file (\"" << filename << "\"): " << unilist_save(A, filename) << endl;

     delete A;

     cout << "Load unilist B from file (\"" << filename << "\"): " << unilist_load(B, filename) << endl;

     cout << "Unilist B with " << B->size << " elements: ";
     unilist_print(B);
     cout << endl;

     delete B;
}

void test_unilist_recursive_insert()
{
     UnidirectionalElement *e1 = new UnidirectionalElement("e11");
     UnidirectionalElement *e2 = new UnidirectionalElement("e22");
     UnidirectionalElement *e3 = new UnidirectionalElement("e33");
     UnidirectionalElement *e4 = new UnidirectionalElement("e44");
     UnidirectionalElement *e5 = new UnidirectionalElement("e55");
     UnidirectionalElement *e6 = new UnidirectionalElement("e66");
     UnidirectionalList *list = new UnidirectionalList();

     cout << "Empty unilist: ";
     unilist_print(list);
     cout << endl;

     cout << "Insert element to empty unilist with invalid (\"invalid key\") key: "
          << unilist_recursive_insert(list, e1, "invalid key") << endl;

     cout << "Empty unilist: ";
     unilist_print(list);
     cout << endl;

     cout << "Add 1 element after list.";
     unilist_add_after(list, e1);
     cout << endl;

     cout << "Unilist with 1 element: ";
     unilist_print(list);
     cout << endl;

     cout << "Insert element to unilist with invalid (\"invalid key\") key: "
          << unilist_recursive_insert(list, e2, "invalid key") << endl;
     cout << "Insert element to unilist with valid (\"" << e1->key << "\") key: "
          << unilist_recursive_insert(list, e2, e1->key) << endl;

     cout << "Unilist with 2 elements: ";
     unilist_print(list);
     cout << endl;

     cout << "Add 1 element after list.";
     unilist_add_after(list, e3);
     cout << endl;

     cout << "Unilist with 3 elements: ";
     unilist_print(list);
     cout << endl;

     cout << "Add 1 element before list.";
     unilist_add_before(list, e4);
     cout << endl;

     cout << "Unilist with 4 elements: ";
     unilist_print(list);
     cout << endl;

     cout << "Insert element to unilist with valid (\"" << e3->key << "\") key: "
          << unilist_recursive_insert(list, e5, e3->key) << endl;

     cout << "Unilist with 5 elements: ";
     unilist_print(list);
     cout << endl;

     cout << "Insert element to unilist with valid (\"" << e4->key << "\") key: "
          << unilist_recursive_insert(list, e6, e4->key) << endl;

     cout << "Unilist with 6 elements: ";
     unilist_print(list);
     cout << endl;

     delete list;
}

void test_unilist_queue_insert()
{
     UnidirectionalElement *e1 = new UnidirectionalElement("e11");
     UnidirectionalElement *e2 = new UnidirectionalElement("e22");
     UnidirectionalElement *e3 = new UnidirectionalElement("e33");
     UnidirectionalElement *e4 = new UnidirectionalElement("e44");
     UnidirectionalElement *e5 = new UnidirectionalElement("e55");
     UnidirectionalElement *e6 = new UnidirectionalElement("e66");
     UnidirectionalList *list = new UnidirectionalList();

     cout << "Empty unilist: ";
     unilist_print(list);
     cout << endl;

     cout << "Insert element to empty unilist with invalid (\"invalid key\") key: "
          << unilist_recursive_insert(list, e1, "invalid key") << endl;

     cout << "Empty unilist: ";
     unilist_print(list);
     cout << endl;

     cout << "Add 1 element after list.";
     unilist_add_after(list, e1);
     cout << endl;

     cout << "Unilist with 1 element: ";
     unilist_print(list);
     cout << endl;

     cout << "Insert element to unilist with invalid (\"invalid key\") key: "
          << unilist_recursive_insert(list, e2, "invalid key") << endl;
     cout << "Insert element to unilist with valid (\"" << e1->key << "\") key: "
          << unilist_recursive_insert(list, e2, e1->key) << endl;

     cout << "Unilist with 2 elements: ";
     unilist_print(list);
     cout << endl;

     cout << "Add 1 element after list.";
     unilist_add_after(list, e3);
     cout << endl;

     cout << "Unilist with 3 elements: ";
     unilist_print(list);
     cout << endl;

     cout << "Add 1 element before list.";
     unilist_add_before(list, e4);
     cout << endl;

     cout << "Unilist with 4 elements: ";
     unilist_print(list);
     cout << endl;

     cout << "Insert element to unilist with valid (\"" << e3->key << "\") key: "
          << unilist_recursive_insert(list, e5, e3->key) << endl;

     cout << "Unilist with 5 elements: ";
     unilist_print(list);
     cout << endl;

     cout << "Insert element to unilist with valid (\"" << e4->key << "\") key: "
          << unilist_recursive_insert(list, e6, e4->key) << endl;

     cout << "Unilist with 6 elements: ";
     unilist_print(list);
     cout << endl;

     delete list;
}

void test_unilist_recursive_remove()
{
     UnidirectionalElement *e1 = new UnidirectionalElement("e11");
     UnidirectionalElement *e2 = new UnidirectionalElement("e22");
     UnidirectionalElement *e3 = new UnidirectionalElement("e33");
     UnidirectionalList *list = new UnidirectionalList();

     cout << "Empty unilist: ";
     unilist_print(list);
     cout << endl;

     cout << "Remove element of empty unilist wiht valid (\"" << e2->key << "\") key (result == nullptr): "
          << (unilist_recursive_remove(list, e2->key) == nullptr) << endl;

     cout << "Add 3 elements to empty unilist.";
     unilist_add_after(list, e1);
     unilist_add_after(list, e2);
     unilist_add_after(list, e3);
     cout << endl;

     cout << "Unilist with 3 elements: ";
     unilist_print(list);
     cout << endl;

     cout << "Remove element of empty unilist wiht valid (\"" << e2->key << "\") key (key): "
          << unilist_recursive_remove(list, e2->key)->key << endl;

     cout << "Unilist with 2 elements: ";
     unilist_print(list);
     cout << endl;

     cout << "Remove element of empty unilist wiht valid (\"" << e1->key << "\") key (key): "
          << unilist_recursive_remove(list, e1->key)->key << endl;

     cout << "Unilist with 1 element: ";
     unilist_print(list);
     cout << endl;

     cout << "Remove element of empty unilist wiht valid (\"" << e3->key << "\") key (key): "
          << unilist_recursive_remove(list, e3->key)->key << endl;

     cout << "Empty unilist: ";
     unilist_print(list);
     cout << endl;

     delete list, e1, e2, e3;
}

void test_unilist_queue_remove()
{

     UnidirectionalElement *e1 = new UnidirectionalElement("e11");
     UnidirectionalElement *e2 = new UnidirectionalElement("e22");
     UnidirectionalElement *e3 = new UnidirectionalElement("e33");
     UnidirectionalList *list = new UnidirectionalList();

     cout << "Remove element of empty unilist with valid (\"" << e1->key << "\") key (result == nullptr): "
          << (unilist_queue_remove(list, e1->key) == nullptr) << endl;

     cout << "Add 3 elements to empty unilist.";
     unilist_add_after(list, e1);
     unilist_add_after(list, e2);
     unilist_add_after(list, e3);
     cout << endl;

     cout << "Unilist with 3 elements: ";
     unilist_print(list);
     cout << endl;

     cout << "Remove element of empty unilist with valid (\"" << e2->key << "\") key (key): "
          << unilist_queue_remove(list, e2->key)->key << endl;

     cout << "Unilist with 2 elements: ";
     unilist_print(list);
     cout << endl;

     cout << "Remove element of empty unilist with valid (\"" << e1->key << "\") key (key): "
          << unilist_queue_remove(list, e1->key)->key << endl;

     cout << "Unilist with 1 element: ";
     unilist_print(list);
     cout << endl;

     cout << "Remove element of empty unilist with valid (\"" << e3->key << "\") key (key): "
          << unilist_queue_remove(list, e3->key)->key << endl;

     cout << "Empty unilist: ";
     unilist_print(list);
     cout << endl;

     delete list, e1, e2, e3;
}

void test_unilist_recursive_insert_K()
{

     UnidirectionalElement *A_e1 = new UnidirectionalElement("A_e11");
     UnidirectionalElement *A_e2 = new UnidirectionalElement("A_e22");
     UnidirectionalElement *A_e3 = new UnidirectionalElement("A_e33");
     UnidirectionalList *A = new UnidirectionalList();
     unilist_add_after(A, A_e1);
     unilist_add_after(A, A_e2);
     unilist_add_after(A, A_e3);

     cout << "Unilist A with 3 elements: ";
     unilist_print(A);
     cout << endl;

     UnidirectionalElement *B_e1 = new UnidirectionalElement("B_e11");
     UnidirectionalElement *B_e2 = new UnidirectionalElement("B_e22");
     UnidirectionalElement *B_e3 = new UnidirectionalElement("B_e33");
     UnidirectionalElement *B_e4 = new UnidirectionalElement("B_e44");
     UnidirectionalList *B = new UnidirectionalList();
     unilist_add_after(B, B_e1);
     unilist_add_after(B, B_e2);
     unilist_add_after(B, B_e3);
     unilist_add_after(B, B_e4);

     cout << "Unilist B with 4 elements: ";
     unilist_print(B);
     cout << endl;

     UnidirectionalElement *C_e1 = new UnidirectionalElement("C_e11");
     UnidirectionalList *C = new UnidirectionalList();

     cout << "Empty unilist C: ";
     unilist_print(C);
     cout << endl;

     cout << "Insert " << A->size << " elements to empty unilist with invalid (\"invalid key\") key: "
          << unilist_recursive_insert(C, A, "invalid key") << endl;

     cout << "Empty unilist C: ";
     unilist_print(C);
     cout << endl;

     cout << "Add 1 element after list.";
     unilist_add_after(C, C_e1);
     cout << endl;

     cout << "Unilist C with 1 element: ";
     unilist_print(C);
     cout << endl;

     cout << "Insert " << A->size << " element to unilist with invalid (\"invalid key\") key: "
          << unilist_recursive_insert(C, A, "invalid key") << endl;

     cout << "Insert " << A->size << " element to unilist with valid (\"" << C_e1->key << "\") key: "
          << unilist_recursive_insert(C, A, C_e1->key) << endl;

     cout << "Unilist C with " << C->size << " elements: ";
     unilist_print(C);
     cout << endl;

     cout << "Insert " << B->size << " element to unilist with valid (\"" << C_e1->key << "\") key: "
          << unilist_recursive_insert(C, B, C_e1->key) << endl;

     cout << "Unilist C with " << C->size << " elements: ";
     unilist_print(C);
     cout << endl;

     delete A, B, C;
}

void test_unilist_queue_insert_K()
{

     UnidirectionalElement *A_e1 = new UnidirectionalElement("A_e11");
     UnidirectionalElement *A_e2 = new UnidirectionalElement("A_e22");
     UnidirectionalElement *A_e3 = new UnidirectionalElement("A_e33");
     UnidirectionalList *A = new UnidirectionalList();
     unilist_add_after(A, A_e1);
     unilist_add_after(A, A_e2);
     unilist_add_after(A, A_e3);

     cout << "Unilist A with 3 elements: ";
     unilist_print(A);
     cout << endl;

     UnidirectionalElement *B_e1 = new UnidirectionalElement("B_e11");
     UnidirectionalElement *B_e2 = new UnidirectionalElement("B_e22");
     UnidirectionalElement *B_e3 = new UnidirectionalElement("B_e33");
     UnidirectionalElement *B_e4 = new UnidirectionalElement("B_e44");
     UnidirectionalList *B = new UnidirectionalList();
     unilist_add_after(B, B_e1);
     unilist_add_after(B, B_e2);
     unilist_add_after(B, B_e3);
     unilist_add_after(B, B_e4);

     cout << "Unilist B with 4 elements: ";
     unilist_print(B);
     cout << endl;

     UnidirectionalElement *C_e1 = new UnidirectionalElement("C_e11");
     UnidirectionalList *C = new UnidirectionalList();

     cout << "Empty unilist C: ";
     unilist_print(C);
     cout << endl;

     cout << "Insert " << A->size << " elements to empty unilist with invalid (\"invalid key\") key: "
          << unilist_recursive_insert(C, A, "invalid key") << endl;

     cout << "Empty unilist C: ";
     unilist_print(C);
     cout << endl;

     cout << "Add 1 element after list.";
     unilist_add_after(C, C_e1);
     cout << endl;

     cout << "Unilist C with 1 element: ";
     unilist_print(C);
     cout << endl;

     cout << "Insert " << A->size << " element to unilist with invalid (\"invalid key\") key: "
          << unilist_recursive_insert(C, A, "invalid key") << endl;

     cout << "Insert " << A->size << " element to unilist with valid (\"" << C_e1->key << "\") key: "
          << unilist_recursive_insert(C, A, C_e1->key) << endl;

     cout << "Unilist C with " << C->size << " elements: ";
     unilist_print(C);
     cout << endl;

     cout << "Insert " << B->size << " element to unilist with valid (\"" << C_e1->key << "\") key: "
          << unilist_recursive_insert(C, B, C_e1->key) << endl;

     cout << "Unilist C with " << C->size << " elements: ";
     unilist_print(C);
     cout << endl;

     delete A, B, C;
}
