#pragma once
#include "Figure.h"
#include "Point.h"

struct Circle {
    const struct Figure _;
    const struct Point point;
    int rad;
};

extern const void* Circle;
