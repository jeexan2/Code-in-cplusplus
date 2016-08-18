#include <bits/stdc++.h>
using namespace std;
typedef struct node{int data;struct node *nxt;}node;
void sortedInsert(node** head_ref, node* new_node){
    node* cur;
    if(*head_ref == NULL || (*head_ref)->data >= new_node->data){
        new_node->nxt = *head_ref;
        *head_ref = new_node;
    }
    else {
        cur = *head_ref;
        while(cur->nxt != NULL || cur->nxt->data < new_node->data){
            cur = cur->nxt;
        }
        new_node->nxt = cur->nxt;
        cur->nxt = new_node;
    }
}
node* newNode(int n){

    node *new_node = (node*) malloc(sizeof(node));
    new_node->data = n;
    new_node->nxt = NULL;

    return new_node;
}
void printList(node *head) {
    node *cur = head;
    while(cur != NULL){
        printf("%d ",cur->data);
        cur = cur->nxt;
        }
}
int main()
{
     node* head = NULL;
     node *new_node = newNode(5);
    sortedInsert(&head, new_node);
    new_node = newNode(10);
    sortedInsert(&head, new_node);
    new_node = newNode(7);
    sortedInsert(&head, new_node);
    new_node = newNode(3);
    sortedInsert(&head, new_node);
    new_node = newNode(1);
    sortedInsert(&head, new_node);
    new_node = newNode(9);
    sortedInsert(&head, new_node);
    printf("\n Created Linked List\n");
    printList(head);
    return 0;
}
