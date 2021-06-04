#include <iostream>
#include <bits/stdc++.h>

/* 
Design your implementation of the linked list. You can choose to use a singly or doubly linked list.
A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node.
If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

Implement the MyLinkedList class:

MyLinkedList() Initializes the MyLinkedList object.
int get(int index) Get the value of the indexth node in the linked list. If the index is invalid, return -1.
void addAtHead(int val) Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
void addAtTail(int val) Append a node of value val as the last element of the linked list.
void addAtIndex(int index, int val) Add a node of value val before the indexth node in the linked list. If index equals the length of the linked list, the node will be appended to the end of the linked list. If index is greater than the length, the node will not be inserted.
void deleteAtIndex(int index) Delete the indexth node in the linked list, if the index is valid.
*/

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    struct linkedList {
        int val;
        linkedList *next;
        //linkedList(int x): val(x), next(NULL) {}
    };
    linkedList *head;
    MyLinkedList() {
        head = NULL;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        int count = 0;
        linkedList* temp = head;
        while (temp != NULL && count != index) {
            temp = temp->next;
            count++;
        }
        if (count == index && temp != NULL) {
            return temp->val;
        }
        else {
            return -1;
        }
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        linkedList* newNode = (linkedList*)malloc(sizeof(linkedList));
        newNode->val = val;
        newNode->next = head;
        head = newNode;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        linkedList* temp = head;
        linkedList* newNode = (linkedList*)malloc(sizeof(linkedList));
        newNode->val = val;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            return;
        }
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        linkedList *temp = head;
        linkedList *prev = NULL;
        int count = 0;
        linkedList* newNode = (linkedList*)malloc(sizeof(linkedList));
        newNode->val = val;
        while (count != index && temp != NULL) {
            prev = temp;
            temp = temp->next;
            count++;
        }
        if (count == index && temp == NULL) {
            if (prev == NULL) {
                head = newNode;
                head->next = NULL;
            }
            else {
                newNode->next = NULL;
                prev->next = newNode;
            }
        }
        else if (count == index) {
            if (prev == NULL) {
                newNode->next = head;
                head = newNode;
            }
            else {
                newNode->next = temp;
                prev->next = newNode;
            }
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        int count = 0;
        linkedList* temp = head;
        linkedList* prev = NULL;
        if (index == 0 && head != 0) {
            temp = head->next;
            free(head);
            head = temp;
            return;
        }
        while (count != index && temp != NULL) {
            prev = temp;
            temp = temp->next;
            count++;
        }
        if (prev == NULL || temp == NULL) {
            return;
        }
        else {
            prev->next = temp->next;
            free(temp);
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */