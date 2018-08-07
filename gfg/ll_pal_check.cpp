#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};
void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node;
    new_node->data  = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)
       *head_ref = new_node;
    else
       (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}
bool isPalindrome(Node *head, Node *rev_head);
/* Driver program to test above function*/
int main()
{
  int T,i,n,l;
    cin>>T;
    while(T--){
    struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
   	cout<<isPalindrome(head, head)<<endl;
    }
    return 0;
}


/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*The structure of the Node is
struct Node
{
    int data;
    struct Node* next;
};*/
/*You are required to complete this method */
bool isPalindrome(Node *head, Node *rev_head)
{
    /*stack <Node *> stack;
    struct Node *t = head;
    while(t){
        stack.push(t);
        t = t->next;
    }
    t = head;
    while(t){
        struct Node *ptr = stack.pop();
        if(ptr -> data != t -> data){
            return false;
        }
        t = t->next;
    }
    return true;*/
    if(!rev_head)
        return true;
    bool temp = isPalindrome(head, rev_head -> next);
    if(!temp)
        return false;
    bool t1 = (head -> data == rev_head -> data);
    head = head -> next;
    return t1;
}