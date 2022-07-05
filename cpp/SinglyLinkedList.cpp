#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
	
		Node(int data){
			this->data=data;
			next=NULL;
		}
};

//--------linked list----------//
void insertAtHead(Node * &head,int data){
	if(head==NULL){
		head = new Node(data);
		return;
	}
	
	Node * n= new Node(data);
	n->next=head;
	head=n;
	
}

//insert at middle
void insertAtMiddle(Node * &head,int data, int pos){
	if(pos==0){
		insertAtHead(head,data);
	}else{
		Node * temp = head;
		for(int jump=1;jump<=pos-1;jump++){
			temp=temp->next;
		}
		
		Node * n = new Node(data);
		n->next=temp->next;
		temp->next=n;
	}
	
	
}

//reverse a LL recursively
Node* recReverse(Node *head){
	
	//base case
	if(head==NULL or head->next==NULL){
		return head;
	}
	
	//otherwise
	Node* sHead=recReverse(head->next);
	head->next->next=head;
	head->next=NULL;
	
	return sHead;
}

//reverse a linked list
void reverse(Node *&head){
	Node* prev=NULL;
	Node* current=head;
	Node * temp;
	
	while(current!=NULL){
		//store next
		temp=current->next;
		current->next=prev;
		
		//prev and current
		prev=current;
		current=temp;
	}
	
	head=prev;
	return;
}

//given a LL, reverse every k nodes
//to it recursively
Node* kReverse(Node *head,int k){
	//base case
	if(head==NULL){
		return NULL;
	}
	
	//reverse the first k nodes	
	Node* prev=NULL;
	Node* curr=head;
	Node* temp;
	int cnt=1;
	
	while(curr!=NULL and cnt<=k){
		temp=curr->next;
		curr->next=prev;
		
		prev=curr;
		curr=temp;
		cnt++;
	}
	
	//for nodes left
	if(temp!=NULL){
		head->next=kReverse(temp,k);
	}
	
	return prev;
}

//merge two sorted linked lists
Node* merge(Node *a, Node *b){
	//base case
	if(a==NULL){
		return b;
	}
	if(b==NULL){
		return a;
	}
	
	//rec case
	Node *c;
	
	if(a->data< b->data){
		c=a;
		c->next=merge(a->next,b);
	}else{
		c=b;
		c->next=merge(a,b->next);
	}
	return c;
}

//LL midpoint
Node *midPoint(Node *head){
	Node *slow=head;
	Node *fast=head->next;
	
	while(fast!=NULL and fast->next!=NULL){
		slow=slow->next;
		fast=fast->next->next;
	}
	return slow;
}

//merge sort LL
Node* mergeSort(Node* head){

	//base case
	if(head==NULL or head->next==NULL){
		return head;
	}
	
	//rec case
	Node *mid=midPoint(head);
	
	Node *a=head;
	Node *b=mid->next;
	mid->next=NULL;
	
	//recursive sort
	a=mergeSort(a);
	b=mergeSort(b);
	
	//merge
	return merge(a,b);

	
}




//print LL
void printLL(Node * head){
	while(head!=NULL){
		cout<<head->data<<"-->";
		head=head->next;
	}
	cout<<endl;
}

int main(){
	Node* head=NULL;
	//insertAtHead(head,4);
	//insertAtHead(head,3);
	//insertAtHead(head,2);
	//insertAtMiddle(head,6,3);
	
	//printLL(head);
	
	//head=recReverse(head);
	//reverse(head);
	//printLL(head);
	
	//head = kReverse(head,3);
	//printLL(head);
	
	Node *a=NULL;
	insertAtHead(a,10);
	insertAtHead(a,7);
	insertAtHead(a,5);
	insertAtHead(a,1);
	insertAtHead(a,17);
	insertAtHead(a,2);
	insertAtHead(a,14);
	
	printLL(a);
	
	a=mergeSort(a);
	printLL(a);
	
	/*Node *b=NULL;
	insertAtHead(b,6);
	insertAtHead(b,3);
	insertAtHead(b,2);
	
	head=merge(a,b);
	printLL(head);*/
	
	return 0;
}
