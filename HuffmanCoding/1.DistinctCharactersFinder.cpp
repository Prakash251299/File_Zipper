/* Distinc characters finder */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Address{
	int count;
	char data;
	struct Address *next;
}*ad=NULL,*d,*q,*r;

//struct Sort{
//	int count;
//	char data;
//	struct Sort *next,*prev;
//}*start=NULL,*q,*r;

/* In '**q', q is a pointer that contains address of another pointer, *q is the address that is contained by q and **q is the data
   that is at the address *q
 */
void midFinder(struct Address *head, struct Address **q, struct Address **r){ // **q is address pointer
	struct Address *fast = head;
	struct Address *slow = head;
	while(1){
		if(fast->next==NULL || fast->next->next==NULL){
			break;
		}
		fast = fast->next->next;
		slow = slow->next;
	}
	*q = head; 
	*r = slow->next;
	slow->next = NULL;
}

struct Address *sortedMerge(struct Address *q, struct Address *r){
	struct Address *result = NULL; // It is a container for the merged list
	if(q==NULL){
		return r;
	}else{
		if(r==NULL){
			return q;
		}
	}
	if(q->count>r->count){
		result = r;
		result->next = sortedMerge(q,r->next);
	}else{
		result = q;
		result->next = sortedMerge(q->next,r);
	}
	
	return result;
}

void mergeSort(struct Address **q){  // Here **q holds address of pointer (initially address of start)
	struct Address *head = *q; // *q is pointer ( initially start)
	struct Address *front;
	struct Address *back;
	if(head==NULL || head->next==NULL){
		return;
	}
	midFinder(head,&front,&back);
	mergeSort(&front);
	mergeSort(&back);
	*q = sortedMerge(front,back);
}

int main(){
	int small[26],capital[26];
	for(int i = 0; i<26; i++){
		small[i] = 0;
		capital[i] = 0;
	}
	FILE *p = NULL;
	p = fopen("file1.txt","r");
	char c;
	while(1){
		c = fgetc(p);
		if(c==EOF){
			break;
		}
		if(int(c)>=65 && int(c)<=91){
			capital[int(c)-65]++;
		}
		if(int(c)>=97 && int(c)<=121){
			small[int(c)-97]++;
		}
	}
	for(int i = 0; i<26; i++){
		printf("%c:%d %c:%d\n",i+97,small[i],i+65,capital[i]);
	}
	for(int i = 0; i<26; i++){
		if(small[i]!=0){
			if(ad==NULL){
				ad = (struct Address*)malloc(sizeof(struct Address));
				ad->data = i+97;
				ad->count = small[i];
				ad->next = NULL;
				d = ad;
			}
			else{
				d->next = (struct Address*)malloc(sizeof(struct Address));
				d = d->next;
				d->data = i+97;
				d->count = small[i];
				d->next = NULL;
			}
		}
	}
	for(int i = 0; i<26; i++){
		if(capital[i]!=0){
			if(ad==NULL){
				ad = (struct Address*)malloc(sizeof(struct Address));
				ad->data = i+65;
				ad->count = capital[i];
				ad->next = NULL;
				d = ad;
			}
			else{
				d->next = (struct Address*)malloc(sizeof(struct Address));
				d = d->next;
				d->data = i+65;
				d->count = capital[i];
				d->next = NULL;
			}
		}
	}
	d = ad;
	mergeSort(&ad);
	printf("\nFinal\n");
	while(1){
		if(d==NULL){
			return 0;
		}
		printf("%c: %d\n",d->data,d->count);
		d = d->next;
	}
	
	return 0;
}