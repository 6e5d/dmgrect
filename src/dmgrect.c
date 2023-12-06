#include <math.h>

#include "../include/dmgrect.h"

static inline int32_t max(int32_t x, int32_t y) {
	if (x >= y) { return x; } else { return y; }
}

static inline int32_t min(int32_t x, int32_t y) {
	if (x <= y) { return x; } else { return y; }
}

void dmgrect_intersection(Dmgrect *dmg, Dmgrect *other) {
	int32_t x1 = max(dmg->offset[0], other->offset[0]);
	int32_t y1 = max(dmg->offset[1], other->offset[1]);
	int32_t rd1[2];
	int32_t rd2[2];
	dmgrect_rd(dmg, rd1);
	dmgrect_rd(other, rd2);
	int32_t x2 = min(rd1[0], rd2[0]);
	int32_t y2 = min(rd1[1], rd2[1]);
	if (x2 <= x1 || y2 <= y1) {
		dmgrect_init(dmg);
		return;
	}
	dmgrect_from_2point(dmg, x1, y1, x2, y2);
}

void dmgrect_union(Dmgrect *dmg, Dmgrect *other) {
	dmgrect_include(dmg, other->offset[0], other->offset[1]);
	int32_t rd[2];
	dmgrect_rd(other, rd);
	dmgrect_include(dmg, rd[0], rd[1]);
}

void dmgrect_rd(Dmgrect *dmg, int32_t rd[2]) {
	rd[0] = dmg->offset[0] + (int32_t)dmg->size[0];
	rd[1] = dmg->offset[1] + (int32_t)dmg->size[1];
}

void dmgrect_from_2point(Dmgrect *dmg,
	int32_t x1, int32_t y1, int32_t x2, int32_t y2) {
	dmg->offset[0] = x1;
	dmg->offset[1] = y1;
	assert(x2 >= x1);
	dmg->size[0] = (uint32_t)(x2 - x1);
	assert(y2 >= y1);
	dmg->size[1] = (uint32_t)(y2 - y1);
}

bool dmgrect_is_empty(Dmgrect *dmg) {
	return dmg->size[0] == 0 || dmg->size[1] == 0;
}

void dmgrect_include(Dmgrect *dmg, int32_t x, int32_t y) {
	if (dmgrect_is_empty(dmg)) {
		dmg->offset[0] = x;
		dmg->offset[1] = y;
		dmg->size[0] = 1;
		dmg->size[1] = 1;
	}
	int32_t x1 = dmg->offset[0];
	int32_t y1 = dmg->offset[1];
	int32_t x2 = dmg->offset[0] + (int32_t)dmg->size[0];
	int32_t y2 = dmg->offset[1] + (int32_t)dmg->size[1];
	if (x > x2) { x2 = x; }
	if (x < x1) { x1 = x; }
	if (y > y2) { y2 = y; }
	if (y < y1) { y1 = y; }
	dmgrect_from_2point(dmg, x1, y1, x2, y2);
}

void dmgrect_init(Dmgrect *dmg) {
	dmg->size[0] = 0;
	dmg->size[1] = 0;
}
