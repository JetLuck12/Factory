#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Parser.h"
#include "Circle.h"
#include "Point.h"
#include "Class.h"
#include "Line.h"
#include "Rect.h"
#include "Dyn_arr.h"

typedef struct
{
    char* name;
    int args[8];
} TBO;

static size_t read_string(char* buffer, TBO* args);
static void* create_figure(TBO* args, size_t amount_of_args);

void get_figures(Darray* Figure_array, FILE* fp) {
    char buffer[21];
    while (fgets(buffer, 20, fp) != NULL) {
        TBO args;
    	const size_t amount_of_args = read_string(buffer, &args);

        if (!amount_of_args) {
            printf("invalid line: %s\n", buffer);
            continue;
        }
        void* figure = create_figure(&args, amount_of_args);
        if (!darray_pushback(Figure_array, figure))
        {
            delete(figure);
            printf("invalid line: %s\n", buffer);
        }
    }
}

static size_t read_string(char* buffer, TBO* args)
{
    size_t index = 0;
    args->name = strtok(buffer, " ");
    char* word = strtok(NULL, " ");
    while (word && index < 4)
    {
        args->args[index] = strtol(word,NULL,10);
        word = strtok(NULL, " ");
        index++;
    }
    
    return index;
}

static void* create_figure(TBO* args, size_t amount_of_args) {
        
    if (!strcmp(args->name, "point")) {
        if (amount_of_args == 2) {
            return new(PPoint, args->args[0], args->args[1]);
        }
    }
	else if (!strcmp(args->name, "circle")) {
        if (amount_of_args == 3) {
            return new(Circle, args->args[0], args->args[1], args->args[2]);
        }
    }
    else if (!strcmp(args->name, "line")) {
        if (amount_of_args == 4) {
            return new(Line, args->args[0], args->args[1], args->args[2], args->args[3]);
        }
    }
    else if (!strcmp(args->name, "rect")) {
        if (amount_of_args == 4) {
            return new(Rect, args->args[0], args->args[1], args->args[2], args->args[3]);
        }
    }
    return NULL;
}

void draw_figures(Darray* figure_array) {
    for (size_t index = 0; index < figure_array->size ; index++) {
        draw(figure_array->array[index]);
    }
}
