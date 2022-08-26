#include<bits/stdc++.h>
using namespace std;


template<typename N>class Node
{
public:
    N value;
    Node *next;
    Node *prev;
    Node(N val)
    {
        value = val;
        next = NULL;
        prev = NULL;
    }
};

template<typename S>class Stack{
    Node <S> *head;
    Node <S> *top;
    Node <S> *mid;
    int count = 0;
public:
    Stack()
    {
        head = NULL;
        top = NULL;
        mid = NULL;
    }
    //PUSH()
    void push(S val)
    {
        Node <S> *newNode = new Node <S>(val);
        if(head == NULL)
        {
            head = top = mid = newNode;
            count++;
            return ;
        }
        top->next = newNode;
        newNode->prev = top;
        top = newNode;
        count++;
    }
    //POP
    S pop()
    {
        Node <S> *delNode ;
        delNode = top;
        S chk;
        if(head == NULL)
        {
            cout<<"Stack is UNDERFLOW !!"<<endl;
            return chk;
        }

        if(top == head)
        {
            head = top =NULL;
        }
        else
        {
            top = delNode->prev;
            top->next = NULL;
        }
        chk = delNode->value;
        delete delNode;
        count--;
        return chk;
    }

    bool Empty()
    {

        if(head ==NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    //SIZE
    int Size()
    {
        return count;
    }
    //Top
    S Top()
    {
        S chk;
        if(top == NULL)
        {
            cout<<"Stack UnderFlow "<<endl;
        }
        else
        {
            chk = top->value;

        }
        return chk;
    }
    S Mid()
    {
        S chk ;
        int i=1;
        if(mid==NULL){
            cout<<"Stack Underflow"<<endl;
        }
        while(i<=Size()/2)
        {
            mid = mid->next;
            i++;
        }

        return mid->value;
    }

};
