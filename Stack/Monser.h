#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int value;
    Node *prev;
    Node *next;

    Node(int val)
    {
        value = val;
        prev = NULL;
        next = NULL;
    }
};

class Stack
{
    Node *head;
    Node *top;
    int sz = 0;

public:
    Stack(){
        head = NULL;
        top = NULL;
    }
    /// push operation
    void push(int val)
    {
        Node *newNode = new Node(val);
        if(head == NULL)
        {
            head = top = newNode;
            sz++;
            return;
        }
        top->next = newNode;
        newNode->prev = top;
        top = newNode;
        sz++;

    }
    /// Pop operation
    int pop()
    {
        Node *delNode = top;
        int chk = -1;

        if(top==NULL){    // there is no element in the list
            //cout<<"Stack Underflow"<<endl;
            return chk;
        }
        if(top==head)  // there is only one element
        {
            head = top = NULL;
        }
        else  // multiple element
        {
            top = delNode->prev;
            top->next = NULL;
        }
        chk = delNode->value;
        delete delNode;
        sz--;
        return chk;
    }

    /// Empty Operation
    bool Empty(){
        if(head==NULL) return true;
        else return false;
    }
    /// top operation
    int Top(){
        if(top==NULL){
            return -1;
        }
        else{
            return top->value;
        }
    }

    /// size t
    int Size(){
        return sz;
    }
};

