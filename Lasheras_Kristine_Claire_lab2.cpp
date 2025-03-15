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
    traverse(head);
    
    head = insertAtEnd("Lover by Tylor Swift", head);
    traverse(head);
    head = insertAtEnd("Strawberries&cigarettes by Tyrone Sivan", head);
    traverse(head);
    head = insertAtEnd("The Only Exeption by Paramore", head);
    traverse(head);
    
    head = insertAtBeginning("Dream by LISA", head);
    traverse(head);
    head = insertAtBeginning("The Man Who Can't Be Moved by The Script", head);
    traverse(head);
    head = insertAtBeginning("Crybaby by SZA", head);
    traverse(head);
    head = insertAtBeginning("Iris by Goo Goo Dolls", head);
    traverse(head);
    
    insertAfter ("Strawberries&cigarettes by Tyrone Sivan", "Love Hangover by JENNIE & Dominic Fike", head);
    traverse(head);
    insertAfter ("The Only Exeption by Paramore", "Die With A Smile by Lady Gaga & Bruno Mars", head);
    traverse(head);
    insertAfter ("The Man Who Can't Be Moved by The Script", "Bawat Daan by Ebe Dancel" , head);
    traverse(head);
    
    cout << deleteAtEnd(head);
    traverse(head);
    head = deleteFromBeginning(head);
    traverse(head);
    head = deleteFromGivenNode("Bawat Daan by Ebe Dancel",head);
    traverse(head);

    return 0;
}
