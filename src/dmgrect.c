#include <assert.h>
#include <math.h>
#include <stdint.h>

#include "../include/dmgrect.h"

void dmgrect_union(Dmgrect dmg, Dmgrect other) {
	dmgrect_include(dmg, other.offset[0], other.offset[1]);
	int32_t rd[2];
	dmgrect_rd(other, rd);
	dmgrect_include(dmg, rd[0], rd[1]);
}

void dmgrect_rd(Dmgrect dmg, int32_t rd[2]) {
	rd[0] = dmg.offset[0] + (int32_t)dmg.size[0];
	rd[1] = dmg.offset[1] + (int32_t)dmg.size[1];
}

void dmgrect_from_2point(Dmgrect dmg,
	int32_t x1, int32_t y1, int32_t x2, int32_t y2) {
	dmg.offset[0] = x1;
	dmg.offset[1] = y1;
	assert(x2 >= x1);
	dmg.size[0] = (uint32_t)(x2 - x1);
	assert(y2 >= y1);
	dmg.size[1] = (uint32_t)(y2 - y1);
}

void dmgrect_includef(Dmgrect dmg, float x, float y) {
	int32_t x1 = (int32_t)floorf(x);
	int32_t x2 = (int32_t)ceilf(x);
	int32_t y1 = (int32_t)floorf(y);
	int32_t y2 = (int32_t)ceilf(y);
	dmgrect_include(dmg, x1, y1);
	dmgrect_include(dmg, x2, y2);
}

void dmgrect_include(Dmgrect dmg, int32_t x, int32_t y) {
	int32_t x1 = dmg.offset[0];
	int32_t y1 = dmg.offset[1];
	int32_t x2 = dmg.offset[0] + (int32_t)dmg.size[0];
	int32_t y2 = dmg.offset[1] + (int32_t)dmg.size[1];
	if (x > x2) { x2 = x; }
	if (x < x1) { x1 = x; }
	if (y > y2) { y2 = y; }
	if (y < y1) { y1 = y; }
	dmgrect_from_2point(dmg, x1, y1, x2, y2);
}
