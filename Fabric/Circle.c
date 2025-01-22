#include <stdio.h>
#include "Circle.h"
#include "Class.h"

#define x(p) (((const struct Point*)(p))->x)
#define y(p) (((const struct Point*)(p))->y)

static void* circle_ctor(void* _self, va_list* app) {

    struct Circle* self = ((const struct Class*)Figure)->ctor(_self, app);
	((const struct Class*)PPoint)->ctor(&(self->point), app);
    self->rad = va_arg(*app, int);

    return self;
}

static void circle_draw(const void* _self)
{
    const struct Circle* self = _self;

    printf("circle at %d,%d rad %d\n", x(&self->point), y(&self->point), self->rad);
}

static const struct Class _Circle = {
    sizeof(struct Circle),
    circle_ctor,
    0,
    circle_draw
};

const void* Circle = &_Circle;