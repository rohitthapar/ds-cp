#include<climits>
#include<iostream>
using namespace std;
template <typename T>
class stackA{
    T *data;
    int nextIndex;
    int capacity;

    public:
    stackA(){
         data = new T[4];
         nextIndex=0;
         capacity=4;
    }
    int size(){
        return nextIndex;
    }
    bool isEmpty(){
    //     if(nextIndex == 0){
    //         return TRUE;
    //     } else return FALSE;
    // }
    return nextIndex == 0;
    }

    void push(T i){
        if(nextIndex == capacity){
            // cout<<"Stack Full"<<endl;
            int *newData = new T[2*capacity];
            for(int i=0;i<capacity;i++){
                newData[i] = data[i];
            }
            capacity*=2;
            delete [] data;
            data = newData;

        } 
        data[nextIndex] = i;
        nextIndex++;
    }

    T pop(){
        if(isEmpty()){
            cout<<"Stack Empty"<<endl;
            return 0;
        }
        nextIndex--;
        return data[nextIndex];
    }
    T top(){
         if(isEmpty()){
            cout<<"Stack Empty"<<endl;
            return T;
        }
        return data[nextIndex-1];
    }

     
};