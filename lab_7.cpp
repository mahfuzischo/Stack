///Stack
#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *prev, *next;
    Node(int x)   /// constructor
    {
        data = x;
    }
};
struct DL_List
{
    Node *top;
    DL_List(); /// constructor
    ~DL_List(); /// destructor
    void insertAtEnd(int data);
    int deleteFromEnd();
    int getTopData();
};
struct Stack
{


    DL_List S;
    Stack() {};

    void push(int data); /// to insert an element into the stack
    int pop(); /// to delete an element from the stack
    int readTop(); /// to read an element from the top of the stack
    bool isEmpty(); /// checking for Underflow
};
DL_List::DL_List()
{
    top=NULL;
}

  DL_List :: ~DL_List()
{
    Node *temp;

    while(top != NULL)
    {
        temp = top->next;
        delete top;
        top = temp;
    }
}


void DL_List :: insertAtEnd(int data)
{
    Node *n = new Node(data);

   if(top == NULL)
    {

        n->data = data;
        n->next = NULL;
        n->prev = NULL;
        top = n;
    }
    else
    {
        n -> data = data;
        n -> prev = top;
        top -> next = n;
        top = n;
    }
}

int DL_List :: deleteFromEnd()
{
    Node *n=top;
    top = n->prev;
    return n->data;
    delete n;


}
int  DL_List ::  getTopData()
{
    Node *n;
    n=top;
    return n->data;
}

void Stack :: push(int data)
{
    S.insertAtEnd(data);

    cout << data << " is pushed in the stack." << endl;
}

int Stack :: pop()
{
    if(isEmpty())
    {
        cout<<" Stack is empty."<<endl;
        return -1;
    }
    else
    {
        int data = S.deleteFromEnd();
        cout << data << " is popped from the stack." << endl;
    }

}

bool Stack :: isEmpty()
{
    if(S.top==NULL)
        return true;
    else
        return false;
}

int Stack :: readTop()
{
    if(isEmpty())
    {
        cout<<" Stack is empty."<<endl;
        return -1;
    }
    else
        {
        int data = S.getTopData();
        cout<<data<<" Is at the top of the stack"<<endl;
        }

}

int main()
{
    Stack S;

    S.push(10);
    S.push(20);
    cout << " Top of stack: " << S.readTop() << endl;
    S.pop();
    S.pop();
    S.pop();

    return 0;
}


