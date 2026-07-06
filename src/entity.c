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

void applyForce(Entity *e, float ax, float ay, float deltatime) {
    e->acceleration.x = ax;
    e->acceleration.y = ay;
    updateVelocity(e, deltatime);
}

void updateVelocity(Entity *e, float deltatime) {
    e->velocity.x += e->acceleration.x * deltatime;
    e->velocity.y += e->acceleration.y * deltatime;
    updatePosition(e, deltatime);
}


void updatePosition(Entity *e, float deltatime) {
    e->position.x += e->velocity.x * deltatime;
    e->position.y += e->velocity.y * deltatime;
}
