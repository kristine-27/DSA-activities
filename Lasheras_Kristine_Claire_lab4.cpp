#include <iostream>

using namespace std;

string karaoke_queue[100];

int front = 0;
int rear = -1;
int max_queue =10;

bool isFull(){
    if(rear == max_queue -1){
        return true;
    }
    return false;
    
}
bool isEmpty(){
    if(rear == -1){
        
    }
    return false;
}
string enqueue(string song){
    if(isFull()){
        return "The queue is full. Try again later";
        
    }
    karaoke_queue[++rear] = song;
    return "A new song has been added in the queue";
}
string dequeue() {
    if(isEmpty()) {
        return "There is no song is in the queue. Try adding first";
        
    }
    string song = karaoke_queue[front];
    
    for(int i = 1; i <= rear; i++){
        karaoke_queue[i-1] = karaoke_queue[i];
    }
    
    rear--;
    return song + "has been delete the queue";
}
int main(){
    cout << enqueue ("Iris") <<endl;
    cout << enqueue ("Right Where You Belong") << endl;
    cout << enqueue ("I Need You More Today") << endl;
    
    cout << dequeue() <<endl;
    cout << dequeue() <<endl;
    cout << dequeue() <<endl;
    return 0;
}
