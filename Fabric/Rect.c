#include <stdio.h>
#include "Rect.h"
#include "Class.h"

#define x(p) ((((const struct Point*)(p)))->x)
#define y(p) ((((const struct Point*)(p)))->y)

static void* rect_ctor(void* _self, va_list* app) {

    struct Rect* self = ((const struct Class*)Figure)->ctor(_self, app);

    (const struct Point*)((const struct Class*)PPoint)->ctor(&(self->point1), app);
    (const struct Point*)((const struct Class*)PPoint)->ctor(&(self->point2), app);

    return self;
}

static void rect_draw(const void* _self)
{
    const struct Rect* self = _self;

    printf("Rect at %d,%d and %d,%d\n", x(&self->point1), y(&self->point1), x(&self->point2), y(&self->point2));
}

static const struct Class _Rect = {
    sizeof(struct Rect),
    rect_ctor,
    0,
    rect_draw
};

const void* Rect = &_Rect;