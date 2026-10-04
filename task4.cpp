#include <iostream>
using namespace std;

class Boardingqueue {
private:
    int arr[6];
    int front;
    int back;
    const int MAX_SIZE = 6;

public:
    Boardingqueue() {
        front=-1;
        back=-1;
    }
     void enqeue(int passenger) {
        if((back+1)%MAX_SIZE==front){
            cout<<"Queue is full";
            return;
        }
        if (front==-1){
            front=0;
            back=0;
        }
        else{
            back=(back+1)%MAX_SIZE;    
        }
        arr[back]=passenger;

     }

     int deqeue() {
        if (front==-1){
            cout<<"queue is empty";
            return -1;
        }
        int temp=arr[front];
            if(front==back){
                front=-1;
                back=-1;
            }
            else{
                front=(front+1)%MAX_SIZE;
        }
        return temp;
     }

     void display() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return;
        }
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == back) {
                break;
            }
            i = (i + 1) % MAX_SIZE;
        }
        cout << endl;
    }

};

int main(){
    Boardingqueue Q;
    Q.enqeue(101);
    Q.enqeue(102);
    Q.enqeue(103);
    Q.enqeue(104);
    Q.enqeue(105);
    Q.enqeue(106);
    Q.deqeue();
    Q.deqeue();
    Q.deqeue();
    Q.enqeue(107);
    Q.enqeue(108);
    Q.enqeue(109);
    Q.deqeue();
    Q.deqeue();
    Q.enqeue(110);
    Q.deqeue();
    Q.enqeue(111);
    Q.enqeue(112);
    Q.display();

    
}