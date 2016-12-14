#include <iostream>
using namespace std;

class llist;
class Node
{
    private:

    int data;
    Node*next;

    public:
    Node(int x): data(x) ,next(nullptr)
    {


    }

    int getdata()
    {
        return this->data;

    }

    void setdata(int x)
    {
        this->data=x;

    }


    friend class llist;

};

class llist
{
    private:

        Node*root;

    public:
        llist(): root(nullptr)
        {

        }
        Node* get_root(){return this->root;};
        void  set_root(Node*head){root=head;}
        void  insert_node(Node* data_node);
        void  delete_node(Node* data_node);
        void  print_list();
        void  delete_complete_list();
        Node*  reverse_list(Node*head);
        virtual ~llist()
        {
            //delete_complete_list();
        }

};

Node* llist::reverse_list(Node*head)
{
    if(head->next==nullptr)
    {
        set_root(head);
        return head;

    }
    Node *previous=reverse_list(head->next);

    previous->next=head;
    head->next=nullptr;
    return head;

}
void llist::print_list()
{
    Node* head=get_root();
    while(head)
    {
        cout<<head->data;
        cout<<"->";
        head=head->next;
    }
    cout<<"NULL";
    cout<<endl;
}
void llist::insert_node(Node* data_node)
{

    Node* head=get_root();

    if(head==nullptr)
    {

        set_root(data_node);

    }

    else
    {
        Node*current=head;

        while(current->next)
        {
            current=current->next;
        }
        current->next=data_node;

    }

}

int main()
{
    llist mylist;
    mylist.insert_node(new Node(10));
    mylist.insert_node(new Node(40));
    mylist.insert_node(new Node(50));
    mylist.insert_node(new Node(60));
    mylist.insert_node(new Node(70));
    mylist.insert_node(new Node(80));
    mylist.print_list();
    mylist.reverse_list(mylist.get_root());
    mylist.print_list();
    return 0;
}


//for reference taken from

#if 0
#include <iostream>
#include "Node.cpp"
using namespace std;
int main ()
{
  Node<char> *p,*q,*r;
  // Link the nodes with each other
  q = new Node<char>('B'); // here nxtptr is passed by a nullptr by default
  p = new Node<char>('A',q);
  r = new Node<char>('C');

  // modify the list
  q->InsertAfter(r);
  /*
  Call the InsertAfter method that belongs to the object pointed by q, as
  paramater, pass to it the address contained in r.
  */

  cout << "p:" << p->data << endl;                 // "A" will be printed out
  cout << "p_next:" << p->NextNode()->data << endl;  // "B" will be printed out
  cout << "q:" << q->data << endl;                 // "B" will be printed out
  cout << "q_next:" << q->NextNode()->data << endl;  // "C" will be printed out
  cout << "r:" << r->data << endl;                 // "C" will be printed out

  p = p->NextNode(); // p now points to the node coming after the node it was
                     // previously pointing to.
  cout << endl;
  cout << "p:" << p->data << endl;                 // "B" will be printed out

  r = q->DeleteAfter();        // copy to r the address of the node pointed by
  //the node pointed by the node pointed by q, and remove that node from the list

  Node<char> *head;
  head = GetNode('A',GetNode('B',GetNode('C')));
  /*
  Here above method, creates a list which has nodes having data A,B,C and each
  node pointing to the next one respectively.
  */
  delete q;
  delete p;
  delete r;
  return 0;
}

// Node.h
// Author: Ali Selcuk AKYUZ
// Mail: selcuk@retinarobotics.com || e174043@metu.edu.tr
// Electrical and Electronics Engineering Department
// Middle East Technical University - ANKARA
// If any questions please send me an email

#ifndef NODE_H
#define NODE_H
#include <iostream>

using namespace std;

template<class T>
class Node
{
    public:
        Node();
        Node(const T& item, Node<T>* ptrnext = NULL);
        T data;
        // access to the next node
        Node<T>* NextNode();
        // list modification methods
        void InsertAfter(Node<T>* p);
        Node<T>* DeleteAfter();
        Node<T> * GetNode(const T& item, Node<T>* nextptr = NULL);
    private:

        Node<T> * next;
};

#endif // NODE_H


// implementation of Node class
// Author: Ali Selcuk AKYUZ
// Mail: selcuk@retinarobotics.com || e174043@metu.edu.tr
// Electrical and Electronics Engineering Department
// Middle East Technical University - ANKARA
// If any questions please send me an email

#include "Node.h"

template<class T>
Node<T>::Node()
{
    // default constructor
    // this is to allow us to create an object without any initialization

}


//  This constructor is just to set next pointer of a node and the data contained.
template<class T>
Node<T>::Node(const T& item,Node<T>* ptrnext)
{
    this->data = item;
    this->next = ptrnext;
}

template<class T>
Node<T>*Node<T>::NextNode()
{
    return this->next;
}

//  This methods inserts a node just after the node that the method belongs to
//  TO-DO: Consider a better implementation
template<class T>
void Node<T>::InsertAfter(Node<T> *p)
{
    // not to lose the rest of the list, we ought to link the rest of the
    // list to the Node<T>* p first
    p->next = this->next;

    // now we should link the previous Node to Node<T> *p , i.e the Node that we are
    //inserting after,
    this->next = p;
}

// Deletes the node from the list and returns the deleted node
template<class T>
Node<T>* Node<T>::DeleteAfter()
{
    // store the next Node in a temporary Node
    Node<T>* tempNode = next;
    // check if there is a next node
    if(next != NULL)
        next = next->next;

    return tempNode;
}
template<class T>
Node<T> * GetNode(const T& item, Node<T>* nextptr = NULL)
{
    Node<T>* newnode; // Local ptr for new node
    newnode = new Node<T>(item,nextptr);
    if ( newnode == NULL)
    {
        cerr << "Memory allocation failed." << endl;
        exit(1);
    }
    return newnode;
}

#endif // 0






