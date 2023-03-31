/* Tree creator for encoding */

#include<stdio.h>
#include<malloc.h>

struct node{
	int data;
	struct node *next, *left, *right, *value;
}*start = NULL,*q,*r;

int ins(int n){
	int i = 0;
	start = (struct node*)malloc(sizeof(struct node));
	start->data = 1; // For smaller values, giving error
	start->next = NULL;
	start->left = NULL;
	start->right = NULL;
	q = start;
	for(i=0;i<n-1;i++){
		q->next = (struct node*)malloc(sizeof(struct node));
		q->next->data = i+2;
		q = q->next;
		q->left = NULL;
		q->right = NULL;
		q->next = NULL;
	}
	return 0;
}

int display(){
	if(start==NULL){
		return 0;
	}
	q = start;
	while(q!=NULL){
		printf("%d ",q->data);
		q = q->next;
	}
	return 0;
}
int insertionSort(node *q){ // just for sorting first element [ Time complexity: O(n) ]
	if(q==NULL || q->next==NULL){
		return 0;
	}
	while(1){
		if(start->data > q->next->data){
			if(q->next->next==NULL){
				q->next->next = start;
				start = start->next;
				q->next->next->next = NULL; // For more than 2 elements it is must
				return 0;
			}
			else{
				q = q->next;continue;
			}
		}
		else{
			r = q->next;
			q->next = start;
			start = start->next;
			q->next->next = r;
			return 0;
		}
	}
}

int addArrange(){
	int sum = 0;
	q = start;
	r = NULL;
	sum = q->data + q->next->data;
	r = (struct node*)malloc(sizeof(struct node));
	r->data = sum;
	r->left = q;
	r->right = q->next;
	r->next = q->next->next;
	start = r;
	printf("\nsum: %d ",sum);
	return 0;
}

void inorderTraverse(struct node *q){
	if(q==NULL){
//		printf("Yes");
		return;
	}
	inorderTraverse(q->left);
//	printf("%d ",q->left->data);
	printf("%d ",q->data);
	inorderTraverse(q->right);
//	printf("%d ",q->right->data);
	return;
}

int main(){
	int n = 0;
	printf("Enter length: ");
	scanf("%d",&n);
	if(n==0){
		printf("No element in the list");
		return 0;
	}
	if(n==1){
		start = (struct node*)malloc(sizeof(struct node));
		start->data = 0; // Fill here any value with scanf
		start->next = NULL;
		start->left = NULL;
		start->right = NULL;
//		printf("\nstart: %d ",start->data);
		return 0;
	}
	ins(n);
	while(1){
		display();
		addArrange();
		printf("\n");
		if(start->next == NULL){
			break;
		}
		insertionSort(start);
	}
//	printf("%d",start->left->data);
	/* Now here the start contains the required tree*/
	inorderTraverse(start); // For displaying the tree
	return 0;
}