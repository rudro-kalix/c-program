#include <stdio.h>
#include <stdlib.h>

struct node {

    int data;
    struct node* next;

};

int main (){

    struct node *head=NULL, *temp, *newnode;

    int values [] = {201, 202, 203 };

    for ( int i= 0 ; i <3 ; i ++){
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = values[i]; 
        
        newnode->next = NULL;

        if ( head == NULL) {
            head = newnode;
        }
            else {
               temp = head;
               while ( temp->next !=NULL){
                temp = temp->next;
               }
               temp->next = newnode;   
            }

        }

    newnode = (struct node*)malloc(sizeof(struct node)); 
    newnode->data = 204;
    newnode->next = NULL;



    temp = head;
    while ( temp->next != NULL){
        temp = temp ->next;
    }
temp->next = newnode;

temp= head;
head = head->next;
free(temp);

temp = head;
printf("final linked list : ");

     while( temp != NULL ) {
        printf("%d ", temp->data);
        if (temp->next !=NULL )
            printf("-> ");
            temp = temp->next;
        
     }




    return 0;
}