#include <stdlib.h>
#include <stdio.h>

#define MALLOC(type) (type*)malloc(sizeof(type))

typedef struct _elem {
	int value;
	struct _elem* next;
} Element;

int base[21] = {1, 19, 4, 4, 7, 23, 5, 9, 12, 22, 11, 13, 19, 19, 19, 19, 56, 33, 1, 2, 4};

void print_list(Element* l, int size){
	int i = 0;
	Element* e = l;
	while (e != NULL && i < size){
		printf("%d, ", e->value);
		e = e->next;
		i += 1;
	}
	printf("-\n");
}

/*void _quicksort(Element* l, int size){
	if (l == NULL) return;
	if (l->next == NULL) return;
	if (size <= 1) return;

	int pivot = l->value;
	Element* e = l;
	Element* previous = l;
	int i = 0;
	while (e->next != NULL && e->next->value < pivot && i < size){
		e->value = e->next->value;
		previous = e;
		e = e->next;
		i += 1;
	}
	e->value = pivot;
	print_list(l);

	Element* pivotprev = previous;
	Element* pivotpos = e;
	int leftsize = i;
	previous = e;
	e = e->next;
	i += 1;
	Element* next = NULL;
	while (i < size){
		next = e->next;
		if (e->value < pivot){
			pivotprev->next = e;
			previous->next = e->next;
			e->next = pivotpos;
			leftsize += 1;
		}
		i += 1;
		e = next;
	}
	printf("%d >>> ", pivot);
	print_list(l);

	quicksort(l, leftsize);
	quicksort(pivotpos->next, size - leftsize);
}*/

Element* get(Element* l, int index){
	if (l == NULL) return NULL;
	int i = 0;
	while (l->next != NULL && i < index){
		l = l->next;
		i += 1;
	}
	return l;
}

Element* quicksort(Element* l, int size){
	if (l == NULL || size == 0) return NULL;
	if (l->next == NULL || size == 1) return l;
	
	print_list(l, size);

	int leftsize = 0, i = 0;
	Element* pivot = l;
	Element* e = l->next;
	Element* previous = l;
	Element* next = NULL;
	while (i < size - 1 && e != NULL){
		next = e->next;
		if (e->value < pivot->value){
			previous->next = next;
			e->next = l;
			l = e;
			leftsize += 1;
		} else {
			previous = e;
		}
		e = next;
		i += 1;
	}
	//printf("%d >>> ", pivot->value);
	//print_list(l, size);
	l = quicksort(l, leftsize);
	if (l == NULL) {
		l = pivot;
	} else {
		get(l, leftsize - 1)->next = pivot;
	}
	pivot->next = quicksort(pivot->next, size - leftsize - 1);
	return l;
}

int main(){
	Element* l = MALLOC(Element);
	l->value = 8;
	l->next = NULL;
	Element* p = l;
	for (int i = 0; i < 21; i++){
		Element* e = MALLOC(Element);
		e->value = base[i];
		e->next = NULL;
		p->next = e;
		p = e;
	}
	
	print_list(l, 22);
	l = quicksort(l, 22);
	print_list(l, 22);
	return 0;
}

