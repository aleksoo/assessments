#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


struct node{ 
	size_t size;
	void *pointer;	
	void *address;
	struct node *next;
}*firstNode = NULL, *lastNode = NULL;

void add_node(struct node *newNode){ 
	if(firstNode == NULL && lastNode == NULL){
		newNode->pointer = malloc(newNode->size);
		firstNode = newNode;
		lastNode = newNode;
	} else {
		newNode->pointer = malloc(newNode->size);
		lastNode->next = newNode->address;
		lastNode = newNode;
	}
}

void *mem_alloc(size_t size){
	struct node *newNode = malloc(sizeof(struct node));
	newNode->address = newNode;
	newNode->size = size;
	newNode->next = NULL;
	add_node(newNode);
	return newNode;
}

void mem_free(void *toDelete){
	struct node *tempNode = firstNode;

	if(firstNode == NULL)
		return;

	if(tempNode->address == toDelete){		
		if(tempNode->next != NULL)
			firstNode = tempNode->next;
		else {
			firstNode = NULL;
			lastNode = NULL;
		}
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

}

long get_currently_allocated_size(){
	int allocatedMemory = 0;
	struct node *tempNode = firstNode;
	while(tempNode != NULL){
		allocatedMemory += tempNode->size;
		tempNode = tempNode->next;
	}
	return allocatedMemory;
}

void test_cases(){
	void *first = mem_alloc(sizeof(char));
	void *second = mem_alloc(sizeof(char) * 2);
	void *third = mem_alloc(sizeof(char) * 3);
	printf("Allocated memory: %ld\n", get_currently_allocated_size());
	
	mem_free(first);
	printf("Allocated memory: %ld\n", get_currently_allocated_size());

	void *forth = mem_alloc(sizeof(char) * 4); 
	printf("Allocated memory: %ld\n", get_currently_allocated_size());

	mem_free(third);
	printf("Allocated memory: %ld\n", get_currently_allocated_size());

	mem_free(second);
	mem_free(forth);
	printf("Allocated memory: %ld\n", get_currently_allocated_size());

}

int main(int argc, char *argv[])
{
	test_cases();
	return 0;
}
