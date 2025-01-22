#include <stdio.h>
#include <stdarg.h>
#include "Figure.h"
#include "Point.h"
#include "Class.h"

#define x(p) (((const struct PPoint *)(p)) -> x)
#define y(p) (((const struct PPoint *)(p)) -> y)

static void* point_ctor(void* _self, va_list* app)
{
    struct Point* self = ((const struct Class*)Figure)->ctor(_self, app);
    self->x = va_arg(*app, int);
    self->y = va_arg(*app, int);

    return self;
}

static void point_draw(const void* _self)
{
    const struct Point* self = _self;
    printf("point at %d,%d \n", self->x, self->y);
}

static const struct Class _Point = {
    sizeof(struct Point),
    point_ctor,
    0,
    point_draw
};

const void * PPoint = &_Point;