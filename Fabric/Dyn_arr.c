#include <stdlib.h>
#include "Dyn_arr.h"
#include "Class.h"

static bool darray_resize(Darray* darray);

void* darray_create()
{
	Darray* darray = malloc(sizeof(Darray));
	if (darray == NULL)
	{
		return NULL;
	}
	darray->array = NULL;
	darray->capacity = 0;
	darray->size = 0;
	return darray;
}

void darray_destroy(Darray* darray)
{
	for (size_t i = 0; i < darray->size; i++)
	{
			delete(darray->array[i]);
	}
	darray->size = 0;
	darray->capacity = 0;
	free(darray->array);
	free(darray);
}
bool darray_pushback(Darray* darray, struct Figure* element)
{
	if (element == NULL)
	{
		return false;
	}
	if (darray->size + 1 > darray->capacity)
	{
		if (darray_resize(darray) == false)
		{
			return false;
		}
	}

	darray->array[darray->size] = element;
	darray->size++;
	return true;

}

bool darray_resize(Darray* darray)
{
	size_t new_capacity = darray->capacity < 2 ? 2 : 1.5 * darray->capacity;
	void* temp_array = realloc(darray->array, new_capacity * sizeof(struct Figure*));
	if (temp_array == NULL)
	{
		return false;
	}
	darray->array = temp_array;
	darray->capacity = new_capacity;
	return true;
}