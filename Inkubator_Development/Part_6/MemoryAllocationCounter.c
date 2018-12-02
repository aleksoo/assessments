#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


struct node{ //tworze wskazniki na to
	size_t size;
	void *pointer;	
	void *address;
	struct node *next;
}*firstNode = NULL, *lastNode = NULL;

void add_node(struct node *newNode){ //referencja, musze tworzyc wskaznik na to
	if(firstNode == NULL && lastNode == NULL){ // pierwszy node
		newNode->pointer = malloc(newNode->size);
		firstNode = newNode;
		lastNode = newNode;
	} else {
		newNode->pointer = malloc(newNode->size);
		lastNode->next = newNode;
		lastNode = newNode;
	}
}

void *mem_alloc(size_t size){
	struct node *newNode = malloc(sizeof(struct node));
	newNode->address = newNode;
	newNode->size = size;
	add_node(newNode);
	return newNode;
}

void mem_free(void *toDelete){
	struct node *tempNode = firstNode;

	if(tempNode->address == toDelete){
		if(tempNode->next != NULL)
			firstNode = tempNode->next;
		free(tempNode->pointer);		
		free(tempNode);
		return;
	}

	while(tempNode){
		if(tempNode->next->address == toDelete){			
			free(tempNode->next->pointer);
			free(tempNode->next);
			if(tempNode->next->next != NULL){
				tempNode->next = tempNode->next->next;
			} else {
				tempNode->next = NULL;
				lastNode = tempNode;
			}			
			return;

		}
		tempNode = tempNode->next;
	}

	// struct node *tempNode = &toDelete;
	// free(tempNode->pointer);
	// free(&toDelete);
}

long get_currently_allocated_size(){
	int allocatedMemory = 0;
	struct node *tempNode = firstNode;
	while(tempNode != NULL){
		printf("Size: %ld\n", tempNode->size);
		allocatedMemory += tempNode->size;
		tempNode = tempNode->next;
	}
	return allocatedMemory;
}

void test_cases(){
	void *first = mem_alloc(sizeof(char));
	//printf("Sizeof char: %ld , firstNode->size: %ld , lastNode->size: %ld , Address first and last: %ld %ld\n", sizeof(char), firstNode->size, lastNode->size, &first, &firstNode);
	void *second = mem_alloc(sizeof(char) * 2);
	//printf("Sizeof char: %ld , firstNode->size: %ld , lastNode->size: %ld\n", sizeof(int) * 5, firstNode->size, lastNode->size);
	void *third = mem_alloc(sizeof(char) * 3);
	//printf("Sizeof char: %ld , firstNode->size: %ld , lastNode->size: %ld\n", sizeof(char) * 5, firstNode->size, lastNode->size);
	
	mem_free(second);
	printf("Allocated memory: %ld\n", get_currently_allocated_size());
	void *forth = mem_alloc(sizeof(char) * 4); // ON ZACZYNA WSKAZYWAC NA TEN PRZEDOSTATNI ELEMENT I SIE ZAPETLA
	printf("Allocated memory: %ld\n", get_currently_allocated_size());

}

int main(int argc, char *argv[])
{
	test_cases();
	return 0;
}
