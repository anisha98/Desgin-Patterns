#include <iostream>
using namespace std; // To not have to type out std:: for everything

class DynamicArray{
    private:
        int max_size;
        int curr_size;
        int * array;

    public:
        DynamicArray(){
            this->max_size = 5;
            this->curr_size = 0;
            array = new int[this->max_size];
            cout << "Dynamic Array has been created of size: " << this->max_size << endl;
        }

        ~DynamicArray(){
            delete [] array;
            cout << "Dynamic Array has been deleted" << endl;
        }

        int getArraySize(){
            return this->curr_size;
        }

        void add(int new_ele){
            if(this->max_size < this->curr_size + 1){
                cout << "We need to double the size of the array" << endl;
                this->max_size *= 2;
                int *tempArray = new int[this->max_size];
                for(int i = 0 ; i < this->curr_size; i++){
                    tempArray[i] = array[i];
                }
                delete []array;
                array = tempArray;
            }
            array[this->curr_size] = new_ele;
            this->curr_size += 1;
            cout << "We have added a new element to our array: " << array[this->curr_size - 1] << endl;
        }

        int getValue(int pos){
            if(pos - 1 >= 0 && (pos -1)  < this->curr_size){
                return array[pos - 1];
            }
        }
};

int main(){
    //Creating an object of dynamic array class.
    DynamicArray obj;
    for(int i = 0; i < 15; i++){
        obj.add(i);
    }

    cout << "Get the value at 5th position of the array: " << obj.getValue(5) << endl;

    return 0;
}