#pragma once
#include "Figure.h"
#include <stdbool.h>
#include <stddef.h>

typedef struct
{
	size_t capacity;
	size_t size;
	void** array;
} Darray;

void* darray_create();
void darray_destroy(Darray* darray, void (*destroy)(void*));
bool darray_pushback(Darray* darray,  struct Figure* element);	
