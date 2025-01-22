#include <stdio.h>
#include "Line.h"
#include "Class.h"

#define x(p) (((const struct Point*)(p))->x)
#define y(p) (((const struct Point*)(p))->y)

static void* line_ctor(void* _self, va_list* app) {

    struct Line* self = ((const struct Class*)Figure)->ctor((struct Line*)_self, app);
    (const struct Point*)(((const struct Class*)PPoint)->ctor(&(self->point1), app));
    (const struct Point*)(((const struct Class*)PPoint)->ctor(&(self->point2), app));

    return self;
}

static void line_draw(const void* _self)
{
    const struct Line* self = _self;

    printf("Line at %d,%d and %d,%d\n", x(&self->point1), y(&self->point1), x(&self->point2), y(&self->point2));
}

static const struct Class _Line = {
    sizeof(struct Line),
    line_ctor,
    0,
    line_draw
};

const void* Line = &_Line;