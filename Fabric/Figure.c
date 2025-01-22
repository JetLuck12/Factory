#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "Figure.h"
#include "Class.h"

static void* figure_ctor(void* _self, va_list* app)
{
    struct Figure* self = _self;

    return self;
}

static const struct Class _Figure = {
    sizeof(struct Figure),
    figure_ctor,
    0,
    0
};

const void* Figure = &_Figure;