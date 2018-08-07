Node* deleteNode(Node *head,int x)
{
    struct Node *prev, *t = head;
	--x;
	while(t -> next && x){
		--x;
		prev = t;
		t = t -> next;
	}
	if(prev){
		prev -> next = t -> next;
	} else {
		head = head -> next;
	}
	free(t);
	return head;
}
