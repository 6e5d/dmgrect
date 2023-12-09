#ifndef INCLUDEGUARD_DMGRECT
#define INCLUDEGUARD_DMGRECT

typedef struct {
	int32_t offset[2];
	uint32_t size[2];
} Dmgrect;

void dmgrect_intersection(Dmgrect *dmg, Dmgrect *other);
void dmgrect_union(Dmgrect *dmg, Dmgrect *other);
void dmgrect_debug(Dmgrect *dmg);
void dmgrect_rd(Dmgrect *dmg, int32_t rd[2]);
void dmgrect_from_2point(Dmgrect *dmg,
int32_t x1, int32_t y1, int32_t x2, int32_t y2);
void dmgrect_include(Dmgrect *dmg, int32_t x, int32_t y);
bool dmgrect_is_empty(Dmgrect *dmg);
void dmgrect_init(Dmgrect *dmg);

#endif
