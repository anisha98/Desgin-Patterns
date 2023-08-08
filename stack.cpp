#include<iostream>
using namespace std;
#define n 10
class Stack{
    int * arr;
    int top;
    public:
        Stack(){
            arr = new int[n];
            top = -1;
        }

        void add(int x){
            if(top + 1 >= n){
                cout<< "Stack overflowed" << endl;
            }
            else{
                top++;
                arr[top] = x;
            }
        }

        void pop(){
            if(top == -1){
                cout << "Stack contains no elements" << endl;
            }
            else{
                top--;
            }
        }

        void pop_at_position(int pos){
            if(top == -1){
                cout << "Stack is empty" << endl;
                return;
            }
            else if(pos > top){
                cout << "Invalid Position" << endl;
                return;
            }
            for(int i = pos; i < top; i++){
                arr[i] = arr[i+1];
            }
            top--;
        }

        void add_at_position(int val, int pos){
            if(top + 1 > n){
                cout << "Stack Overflow" << endl;
                return;
            }
            else if((pos > top) || (pos < 0)){
                cout << "Invalid Position" << endl;
                return;
            }
            for(int i = top + 1; i > pos; i--){
                arr[i] = arr[i - 1];
            }
            arr[pos] = val;
            top++;
        }

        void display(){
            for(int i =0; i <= top;i++){
                cout << arr[i] << "|";
            }
            cout << endl;
        }
};

int main(){
    Stack stk;
    for(int i = 0 ; i< 14; i++){
        stk.add(i);
    }
    stk.display();

    for(int i = 0; i < 4; i++){
        stk.pop();
    }
    stk.display();

    stk.add_at_position(123,2);
    stk.display();

    stk.pop_at_position(5);
    stk.display();

    return 0;
}


