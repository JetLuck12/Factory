#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>
#include <string.h>
#include "Parser.h"
#include "Circle.h"
#include "Point.h"
#include "Class.h"
#include "Line.h"
#include "Figure.h"
#include "Rect.h"
#include "Dyn_arr.h"

int main(int argc, char** argv)
{
    FILE* fp;
    fopen_s(&fp, "data.txt", "r");
    if (fp == NULL)
    {
        printf("file open error\n");
        return 1;
    }
    void* figure_arrays = darray_create();
	get_figures(figure_arrays, fp);
    fclose(fp);

    draw_figures(figure_arrays);
    darray_destroy(figure_arrays, delete);
    return 0;
}
//разделить разделение строки и вызов конструктора, реализовать дин массив для колва аргументов, 