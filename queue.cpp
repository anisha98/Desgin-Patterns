#include<iostream>
using namespace std;
#define n 10

class Queue{
    int * arr;
    int front;
    int back;
    public:
        Queue(){
            arr = new int[n];
            front = -1;
            back = -1;
        }

        void add(int val){
            if(back == n - 1){
                cout<<"Queue is full"<<endl;
                return;
            }
            back++;
            arr[back] = val;

            if(front == -1){
                front++; // first element is added to the queue
            }

        }

        void pop(){
            if(front == -1){
                cout << "Queue is empty" << endl;
                return;
            }
            front++;
        }

        void display(){
            for(int i =front; i <= back;i++){
                cout << arr[i] << "|";
            }
            cout << endl;
        }
};

int main(){
    Queue q;
    for(int i = 0 ; i< 14; i++){
        q.add(i);
    }
    q.display();

    for(int i = 0; i < 4; i++){
        q.pop();
    }
    q.display();

    for(int i = 0 ; i< 14; i++){
        q.add(i);
    }
    q.display();


    return 0;
}
