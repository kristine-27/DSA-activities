#include <iostream>

using namespace std;

typedef struct Node{
    string songName;
    Node  *link;
}Node;

Node *createNode(string data){
    Node *newNode = new Node;
    newNode->songName = data;
    newNode->link = NULL;

    return newNode;
}

void traverse(Node *head){
    Node *temp = new Node;
    temp = head;
    
    cout << "My Playlist" <<endl;
    while(temp != NULL){
        cout << temp->songName<< "->"<<endl;
        if(temp->link == NULL){
            cout << "NULL"<<endl;
        }
        
        temp = temp->link;
    }
}

Node *insertAtEnd(string data, Node *head){
    if(head == NULL){
        Node *newNode = createNode(data);
        head = newNode;
        cout << "A new node has been inserted at the end \n" << endl;
        return head;
    }
    Node *temp = new Node;
    temp = head;
    
    while(temp->link != NULL){
        temp = temp->link;
    }
    
    Node *newNode = createNode(data);
    temp->link = newNode;
    
    cout << "A new node has been inserted at the end \n" << endl;
    return head;
}

Node *insertAtBeginning(string data, Node *head){
    Node *newNode = createNode(data);
    newNode->link = head;
    
    head = newNode;
    
    cout << "A new node has been inserted at the beginning \n" <<endl;
    
    return head;
}

string insertAfter(string after, string data, Node *head){
    Node *temp = new Node;
    temp = head;
    
    while(temp->songName.compare(after) != 0){
        if(temp == NULL){
            return "No such exist, please try again later.";
        }
        
        temp = temp->link;
    }
    Node *newNode = createNode(data);
    newNode->link = temp->link;
    temp->link = newNode;
    
    return "An new node has been inserted after " + after + "\n";
}

int main(){
    Node *head = createNode("My Valentine by McBride");
    
    head = insertAtEnd("Lover by Taylor Swift", head);
    head = insertAtEnd("Strawberries&cigarettes by TYrone Sivan", head);
    head = insertAtEnd("The Only Exception by Paramore", head);
    head = insertAtEnd("Heather by Conan Gray", head);
    
    head = insertAtBeginning("You'll Be Safe Here by Rico Blanco", head);
    head = insertAtBeginning("The Man Who Can't Be Moved by The Script", head);
    head = insertAtBeginning("Die With A Smile by Bruno Mars,Lady Gaga", head);
    head = insertAtBeginning("Dream by LISA", head);
    traverse(head);
    
    insertAfter ("Pano by Zack Tabudlo", "Dream by LISA", head);
    insertAfter ("Imahe by Magnus Heaven", "The Man Who Can't Be Moved by The Script", head);
    insertAfter ("Kathang Isip by Ben&Ben", "Die With A Smile by Bruno Mars,Lady Gaga", head);
    traverse(head);
    
    

    return 0;
}