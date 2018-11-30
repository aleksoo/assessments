#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


struct node{ //tworze wskazniki na to
	size_t size;
	void *pointer;
	
	//struct node *last;
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

void delete_node(struct node nodeToDelete){

}


void *mem_alloc(size_t size){
	struct node *newNode = malloc(sizeof(struct node));
	newNode->size = size;
	add_node(newNode);

	// add_node
	// return memoryLocation;
}

void *mem_free(struct node nodeToDelete){
	.free(nodeToDelete)
	// usunac node, przestawic wstazniki
}

void *get_currently_allocated_size(void){

}

void test_cases(){

}

int main(int argc, char *argv[])
{
	test_cases();
	return 0;
}
