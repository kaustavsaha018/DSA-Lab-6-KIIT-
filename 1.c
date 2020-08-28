//single linked list all delete operations
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

static int count=0;

void create();
void delete_begin();
void delete_end();
void delete_atPos();
void display();

struct node *head,*newnode,*temp;

void main(){
	
	create();
	int i;
	
	printf("\nCHOICES:\n1 for displaying the list\n2 for delete at begin\n"
	"3 for delete at end\n4 for delete at given position\n5 for exit\n\n");
	
	int again=1;
	do{
		printf("\nEnter your choice: ");
		scanf("%d",&i);
		
		switch(i){
			case 1:
				display();
				break;	
			case 2:
				delete_begin();
				break;
			case 3:
				delete_end();
				break;
			case 4:
				delete_atPos();
				break;
			case 5:
				again=0;
				break;
			default:
				printf("\nWrong Input!");
		}
	}while(again==1);	
		
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
	printf("\nThe List is Diplaying...\n");
	temp=head;
	while(temp!=0){
		printf(" %d ", temp->data);
		temp=temp->next;
	}
	printf("\n");	
}


void delete_begin(){
	temp=head;
	head=temp->next;
	count--;
}

void delete_end(){
	temp=head;
	while(temp->next->next!=NULL){
		temp=temp->next;
	}
	temp->next=NULL;
	count--;
}

void delete_atPos(){
	temp=head;
	int pos,curr=1;
	printf("\nEnter the position at which you want to delete an element: ");
	scanf("%d", &pos);
	int flag=0;
	while(flag==0){
		if(pos==1){
		delete_begin();
		flag=1;
		}
		else if(pos==count){
			delete_end();
			flag=1;
		}
		else if(pos>1 && pos <count){
			struct node *prev;
			while(curr<pos && temp!=NULL){
				curr++;
				prev=temp;
				temp=temp->next;
			}
			
		prev->next=temp->next;
		free(temp);
		flag=1;
		count--;
		}
		else if(pos<1 || pos>count){
		printf("Wrong Position! Please Enter a correct position: ");
		scanf("%d", &pos);
		flag=0;
		}
	}	
}


