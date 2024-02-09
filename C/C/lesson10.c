#include <stdio.h>

struct Vector {
	int x;
	int y;
};

typedef struct Vector Vector; // enables us not to write "struct" everywhere

void add_vector(Vector* v) {
	v->x += 1; // (*v).x += 1;
	v->y += 1; // (*v).y += 1;
}

struct foo2 {
	char c;
	double d;
	short s;
};

int main() {
	printf("%d", sizeof(struct foo2));
	//Vector v = { 2, 1 };
	//add_vector(&v);
	//printf("%d %d", v.x, v.y);

	//drob res;
	//add(dr, dr2, &res);
	//print_drob(res);

	return 0;
}