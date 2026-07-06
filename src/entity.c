#include <stdlib.h>
#include "../include/raylib.h"
#include "../include/entity.h"




Entity *createPlayer() {
    Entity *p = malloc(sizeof(Entity));
    if (p == NULL) {
	return NULL;
    }
    
    p->size = (Vector2){ 50, 50 };
    p->position = (Vector2){ 5, 5 };
    p->velocity = (Vector2){ 0, 0 };
    p->acceleration = (Vector2){ 0, 0 };

    
    return p;
}

void drawPlayer(Entity *p) {
    DrawRectangleV(p->position, p->size, BLUE);
}
