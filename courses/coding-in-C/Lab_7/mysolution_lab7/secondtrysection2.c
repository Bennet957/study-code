#include <stdio.h>
#include <stdlib.h>
typedef struct{
    double value;
    struct Node* next;
}Node;

int main (){
    Node *head=NULL;
    Node *current=NULL;
    for(int c=0;c<50;c++){
        Node *newNode=create_node(5.6);
        if (newNode==NULL){
            printf("Stop programm.");
            return 1;
        }
        else {
            current->next=newNode;
            current=newNode;
        }
    }
}
Node *create_node (double value){
    Node *newNode= malloc(sizeof(Node));
    if (newNode==NULL){
        return NULL;
    }
    else{
        newNode->value=value;
        newNode->next=NULL;
    }

}
