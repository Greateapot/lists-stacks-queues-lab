#include <iostream>
#include "stack.hpp"
#include "stack_test.hpp"

using namespace std;

void stack_test()
{
     cout << "STACK TEST: " << endl
          << endl;

     cout << "Test stack_save_load: " << endl;
     test_stack_save_load();
     cout << endl;

     cout << "Test stack_recursive_insert: " << endl;
     test_stack_recursive_insert();
     cout << endl;

     cout << "Test stack_queue_insert: " << endl;
     test_stack_queue_insert();
     cout << endl;

     cout << "Test stack_recursive_insert with K elements: " << endl;
     test_stack_recursive_insert_K();
     cout << endl;

     cout << "Test stack_queue_insert with K elements: " << endl;
     test_stack_queue_insert_K();
     cout << endl;

     cout << "Test stack_recursive_remove: " << endl;
     test_stack_recursive_remove();
     cout << endl;

     cout << "Test stack_queue_remove: " << endl;
     test_stack_queue_remove();
     cout << endl;

     cout << "STACK TEST END." << endl
          << endl;
}

void test_stack_save_load()
{
     const string filename = "bin/stack.bin";

     StackElement *A_e1 = new StackElement("A_e11");
     StackElement *A_e2 = new StackElement("A_e22");
     StackElement *A_e3 = new StackElement("A_e33");
     Stack *A = new Stack();
     Stack *B = new Stack();

     stack_push(A, A_e1);
     stack_push(A, A_e2);
     stack_push(A, A_e3);

     cout << "Stack A with " << A->size << " elements: ";
     stack_print(A);
     cout << endl;

     cout << "Empty stack B: ";
     stack_print(B);
     cout << endl;

     cout << "Save stack A to file (\"" << filename << "\"): " << stack_save(A, filename) << endl;

     delete A;

     cout << "Load stack B from file (\"" << filename << "\"): " << stack_load(B, filename) << endl;

     cout << "Stack B with " << B->size << " elements: ";
     stack_print(B);
     cout << endl;

     delete B;
}

void test_stack_recursive_insert()
{
     StackElement *e1 = new StackElement("e11");
     StackElement *e2 = new StackElement("e22");
     StackElement *e3 = new StackElement("e33");
     StackElement *e4 = new StackElement("e44");
     Stack *stack = new Stack();

     cout << "Empty stack: ";
     stack_print(stack);
     cout << endl;

     cout << "Insert element to empty stack with invalid (\"invalid key\") key: "
          << stack_recursive_insert(stack, e1, "invalid key") << endl;

     cout << "Empty stack: ";
     stack_print(stack);
     cout << endl;

     cout << "Add 1 element after stack.";
     stack_push(stack, e1);
     cout << endl;

     cout << "Stack with 1 element: ";
     stack_print(stack);
     cout << endl;

     cout << "Insert element to stack with invalid (\"invalid key\") key: "
          << stack_recursive_insert(stack, e2, "invalid key") << endl;
     cout << "Insert element to stack with valid (\"" << e1->key << "\") key: "
          << stack_recursive_insert(stack, e2, e1->key) << endl;

     cout << "Stack with " << stack->size <<" elements: ";
     stack_print(stack);
     cout << endl;

     cout << "Add 1 element after stack.";
     stack_push(stack, e3);
     cout << endl;

     cout << "Stack with " << stack->size <<" elements: ";
     stack_print(stack);
     cout << endl;

     cout << "Insert element to stack with valid (\"" << e3->key << "\") key: "
          << stack_recursive_insert(stack, e4, e3->key) << endl;

     cout << "Stack with " << stack->size <<" elements: ";
     stack_print(stack);
     cout << endl;

     delete stack;
}

void test_stack_queue_insert()
{
     StackElement *e1 = new StackElement("e11");
     StackElement *e2 = new StackElement("e22");
     StackElement *e3 = new StackElement("e33");
     StackElement *e4 = new StackElement("e44");
     Stack *stack = new Stack();

     cout << "Empty stack: ";
     stack_print(stack);
     cout << endl;

     cout << "Insert element to empty stack with invalid (\"invalid key\") key: "
          << stack_recursive_insert(stack, e1, "invalid key") << endl;

     cout << "Empty stack: ";
     stack_print(stack);
     cout << endl;

     cout << "Add 1 element after stack.";
     stack_push(stack, e1);
     cout << endl;

     cout << "Stack with 1 element: ";
     stack_print(stack);
     cout << endl;

     cout << "Insert element to stack with invalid (\"invalid key\") key: "
          << stack_recursive_insert(stack, e2, "invalid key") << endl;
     cout << "Insert element to stack with valid (\"" << e1->key << "\") key: "
          << stack_recursive_insert(stack, e2, e1->key) << endl;

     cout << "Stack with " << stack->size <<" elements: ";
     stack_print(stack);
     cout << endl;

     cout << "Add 1 element after stack.";
     stack_push(stack, e3);
     cout << endl;

     cout << "Stack with " << stack->size <<" elements: ";
     stack_print(stack);
     cout << endl;

     cout << "Insert element to stack with valid (\"" << e3->key << "\") key: "
          << stack_recursive_insert(stack, e4, e3->key) << endl;

     cout << "Stack with " << stack->size <<" elements: ";
     stack_print(stack);
     cout << endl;

     delete stack;
}

void test_stack_recursive_remove()
{
     StackElement *e1 = new StackElement("e11");
     StackElement *e2 = new StackElement("e22");
     StackElement *e3 = new StackElement("e33");
     Stack *stack = new Stack();

     cout << "Empty stack: ";
     stack_print(stack);
     cout << endl;

     cout << "Remove element of empty stack wiht valid (\"" << e2->key << "\") key (result == nullptr): "
          << (stack_recursive_remove(stack, e2->key) == nullptr) << endl;

     cout << "Add 3 elements to empty stack.";
     stack_push(stack, e1);
     stack_push(stack, e2);
     stack_push(stack, e3);
     cout << endl;

     cout << "Stack with " << stack->size <<" elements: ";
     stack_print(stack);
     cout << endl;

     cout << "Remove element of empty stack wiht valid (\"" << e2->key << "\") key (key): "
          << stack_recursive_remove(stack, e2->key)->key << endl;

     cout << "Stack with " << stack->size <<" elements: ";
     stack_print(stack);
     cout << endl;

     cout << "Remove element of empty stack wiht valid (\"" << e1->key << "\") key (key): "
          << stack_recursive_remove(stack, e1->key)->key << endl;

     cout << "Stack with 1 element: ";
     stack_print(stack);
     cout << endl;

     cout << "Remove element of empty stack wiht valid (\"" << e3->key << "\") key (key): "
          << stack_recursive_remove(stack, e3->key)->key << endl;

     cout << "Empty stack: ";
     stack_print(stack);
     cout << endl;

     delete stack, e1, e2, e3;
}

void test_stack_queue_remove()
{

     StackElement *e1 = new StackElement("e11");
     StackElement *e2 = new StackElement("e22");
     StackElement *e3 = new StackElement("e33");
     Stack *stack = new Stack();

     cout << "Remove element of empty stack with valid (\"" << e1->key << "\") key (result == nullptr): "
          << (stack_queue_remove(stack, e1->key) == nullptr) << endl;

     cout << "Add 3 elements to empty stack.";
     stack_push(stack, e1);
     stack_push(stack, e2);
     stack_push(stack, e3);
     cout << endl;

     cout << "Stack with " << stack->size <<" elements: ";
     stack_print(stack);
     cout << endl;

     cout << "Remove element of empty stack with valid (\"" << e2->key << "\") key (key): "
          << stack_queue_remove(stack, e2->key)->key << endl;

     cout << "Stack with " << stack->size <<" elements: ";
     stack_print(stack);
     cout << endl;

     cout << "Remove element of empty stack with valid (\"" << e1->key << "\") key (key): "
          << stack_queue_remove(stack, e1->key)->key << endl;

     cout << "Stack with 1 element: ";
     stack_print(stack);
     cout << endl;

     cout << "Remove element of empty stack with valid (\"" << e3->key << "\") key (key): "
          << stack_queue_remove(stack, e3->key)->key << endl;

     cout << "Empty stack: ";
     stack_print(stack);
     cout << endl;

     delete stack, e1, e2, e3;
}

void test_stack_recursive_insert_K()
{

     StackElement *A_e1 = new StackElement("A_e11");
     StackElement *A_e2 = new StackElement("A_e22");
     StackElement *A_e3 = new StackElement("A_e33");
     Stack *A = new Stack();
     stack_push(A, A_e1);
     stack_push(A, A_e2);
     stack_push(A, A_e3);

     cout << "Stack A with 3 elements: ";
     stack_print(A);
     cout << endl;

     StackElement *B_e1 = new StackElement("B_e11");
     StackElement *B_e2 = new StackElement("B_e22");
     StackElement *B_e3 = new StackElement("B_e33");
     StackElement *B_e4 = new StackElement("B_e44");
     Stack *B = new Stack();
     stack_push(B, B_e1);
     stack_push(B, B_e2);
     stack_push(B, B_e3);
     stack_push(B, B_e4);

     cout << "Stack B with 4 elements: ";
     stack_print(B);
     cout << endl;

     StackElement *C_e1 = new StackElement("C_e11");
     Stack *C = new Stack();

     cout << "Empty stack C: ";
     stack_print(C);
     cout << endl;

     cout << "Insert " << A->size << " elements to empty stack with invalid (\"invalid key\") key: "
          << stack_recursive_insert(C, A, "invalid key") << endl;

     cout << "Empty stack C: ";
     stack_print(C);
     cout << endl;

     cout << "Add 1 element after stack.";
     stack_push(C, C_e1);
     cout << endl;

     cout << "Stack C with 1 element: ";
     stack_print(C);
     cout << endl;

     cout << "Insert " << A->size << " element to stack with invalid (\"invalid key\") key: "
          << stack_recursive_insert(C, A, "invalid key") << endl;

     cout << "Insert " << A->size << " element to stack with valid (\"" << C_e1->key << "\") key: "
          << stack_recursive_insert(C, A, C_e1->key) << endl;

     cout << "Stack C with " << C->size << " elements: ";
     stack_print(C);
     cout << endl;

     cout << "Insert " << B->size << " element to stack with valid (\"" << C_e1->key << "\") key: "
          << stack_recursive_insert(C, B, C_e1->key) << endl;

     cout << "Stack C with " << C->size << " elements: ";
     stack_print(C);
     cout << endl;

     delete A, B, C;
}

void test_stack_queue_insert_K()
{

     StackElement *A_e1 = new StackElement("A_e11");
     StackElement *A_e2 = new StackElement("A_e22");
     StackElement *A_e3 = new StackElement("A_e33");
     Stack *A = new Stack();
     stack_push(A, A_e1);
     stack_push(A, A_e2);
     stack_push(A, A_e3);

     cout << "Stack A with 3 elements: ";
     stack_print(A);
     cout << endl;

     StackElement *B_e1 = new StackElement("B_e11");
     StackElement *B_e2 = new StackElement("B_e22");
     StackElement *B_e3 = new StackElement("B_e33");
     StackElement *B_e4 = new StackElement("B_e44");
     Stack *B = new Stack();
     stack_push(B, B_e1);
     stack_push(B, B_e2);
     stack_push(B, B_e3);
     stack_push(B, B_e4);

     cout << "Stack B with 4 elements: ";
     stack_print(B);
     cout << endl;

     StackElement *C_e1 = new StackElement("C_e11");
     Stack *C = new Stack();

     cout << "Empty stack C: ";
     stack_print(C);
     cout << endl;

     cout << "Insert " << A->size << " elements to empty stack with invalid (\"invalid key\") key: "
          << stack_recursive_insert(C, A, "invalid key") << endl;

     cout << "Empty stack C: ";
     stack_print(C);
     cout << endl;

     cout << "Add 1 element after stack.";
     stack_push(C, C_e1);
     cout << endl;

     cout << "Stack C with 1 element: ";
     stack_print(C);
     cout << endl;

     cout << "Insert " << A->size << " element to stack with invalid (\"invalid key\") key: "
          << stack_recursive_insert(C, A, "invalid key") << endl;

     cout << "Insert " << A->size << " element to stack with valid (\"" << C_e1->key << "\") key: "
          << stack_recursive_insert(C, A, C_e1->key) << endl;

     cout << "Stack C with " << C->size << " elements: ";
     stack_print(C);
     cout << endl;

     cout << "Insert " << B->size << " element to stack with valid (\"" << C_e1->key << "\") key: "
          << stack_recursive_insert(C, B, C_e1->key) << endl;

     cout << "Stack C with " << C->size << " elements: ";
     stack_print(C);
     cout << endl;

     delete A, B, C;
}
