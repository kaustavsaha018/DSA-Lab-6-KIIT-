//single linked list reverse
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

static int count=0;

void create();
void reverse_list();
void display();

struct node *head,*newnode,*temp;

void main(){	
	create();
	reverse_list();
	display();		
}

void create(){
	char flag;
	printf("Enter the elements of the Linked List:\n\n");
	do{
		newnode = (struct node *)malloc(sizeof(struct node));
		if(count==0){
			printf("Enter data: ");	
			scanf("%d", &newnode->data);
			head=newnode;
			temp=newnode;
			temp->next=0;
			count++;
		}
		else{	
			printf("Enter data: ");	
			scanf("%d", &newnode->data);
			temp->next=newnode;
			temp=newnode;
			temp->next=0;
			count++;	
		}
		printf("Do you want to continue(y/n)? ");
		scanf(" %c",&flag);
		getchar();
		
	}while(flag='y' && flag!='n');
}

void display(){
	printf("\nThe List is Diplaying in Reverse Order...\n");
	temp=head;
	while(temp!=0){
		printf(" %d ", temp->data);
		temp=temp->next;
	}	
}

void reverse_list(){
	struct node*prevnode;
	if(head!=NULL){
		prevnode=head;
		temp=head->next;
		head=head->next;
		prevnode->next=NULL;
		while(head!=NULL){
			head=head->next;
			temp->next=prevnode;
			prevnode=temp;
			temp=head;
		}
		head=prevnode;
	}	
}
