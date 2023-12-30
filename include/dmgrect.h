typedef struct {
	int32_t offset[2];
	uint32_t size[2];
} Dmgrect();

void dmgrect(intersection)(Dmgrect() *dmg, Dmgrect() *other);
void dmgrect(union)(Dmgrect() *dmg, Dmgrect() *other);
void dmgrect(debug)(Dmgrect() *dmg);
void dmgrect(rd)(Dmgrect() *dmg, int32_t rd[2]);
void dmgrect(from_2point)(Dmgrect() *dmg,
int32_t x1, int32_t y1, int32_t x2, int32_t y2);
void dmgrect(include)(Dmgrect() *dmg, int32_t x, int32_t y);
bool dmgrect(is_empty)(Dmgrect() *dmg);
void dmgrect(init)(Dmgrect() *dmg);
