#include <iostream>
#include <new>
using namespace std;

class Node{
public:
    int data;
    Node *next;
};

class Queue{
private:
    Node *front;
    Node *back;
    int count;

public:
    Queue(){
        front = NULL;
        back = NULL;
        count = 0;
    }

    void enqueue(int value){
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if (isEmpty()){
            front = newNode;
        }
        else{
            back->next = newNode;
        }

        back = newNode;
        count++;
    }

    void dequeue(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
        }
        else{
            Node *temp = front;
            front = front->next;
            cout<<"Dequeued element: "<<temp->data<<endl;
            delete temp;
            count--;
        }
    }
    int top(){
        if (isEmpty()){
            cout<<"Queue is empty"<<endl;
        }
        else{
            int topValue = front->data;
            return topValue;
        }
    }
    bool isEmpty(){
        return count == 0;
    }
    int size(){
        return count;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    cout<<"Queue size: "<<q.size()<<endl;
    cout<<"Top element: "<<q.top()<<endl;

    q.dequeue();
    q.dequeue();

    cout<<"Top element: "<<q.top()<<endl;
    cout<<"Queue size: "<<q.size()<<endl;

    q.dequeue();
    q.dequeue();
    q.dequeue();

    cout<<"Is queue empty? "<<q.isEmpty()<<endl;

    return 0;
}
