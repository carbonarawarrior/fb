#include <stdlib.h>
#include "../include/raylib.h"
#include "../include/entity.h"
#include "../include/main.h"


void resetPlayer(Entity *p) {
    p->size = (Vector2){ 50, 50 };
    p->position = (Vector2){ 25, screen_height/2 };
    p->velocity = (Vector2){ 0, 0 };
    p->acceleration = (Vector2){ 0, 0 };
    applyForce(p, 0.0, acc_gravity);

}
int giveHeight() {
    return rand() % (screen_height/2 - 100 + 1) + 100;
}
void resetObject(Entity *objs) {
    int randHeight = giveHeight();

    objs->size = (Vector2){ 100, randHeight };
    objs->position.x = ((rand() % 100) * 100 + screen_width);
    objs->position.y = rand() % (2) ? 0 : screen_height - objs->size.y;
    objs->velocity = (Vector2){ 0, 0 };
    objs->acceleration = (Vector2){ 0, 0 };
    applyForce(objs, +50, 0);
    applyForce(objs, -50, 0);
}


Entity *createPlayer() {
    Entity *p = malloc(sizeof(Entity));
    if (p == NULL) {
	return NULL;
    }
    
    resetPlayer(p);
    return p;
}

int createObjects(Entity **objs, size_t count) {
    for (size_t i = 0; i < count; ++i) {
	objs[i] = malloc(sizeof(Entity));
	if (objs[i] == NULL) {
	    return 1;
	}
	resetObject(objs[i]);
    }

    return 0;
}

void drawWithColor(Entity *e, Color COLOR) {
    DrawRectangleV(e->position, e->size, COLOR);
}

void drawPlayer(Entity *p) {
    drawWithColor(p, BLUE);
}

void drawObjects(Entity **o, size_t count) {
    for (size_t i = 0; i < count; ++i) {
	drawWithColor(o[i], RED);
    }
}

void applyForce(Entity *e, float ax, float ay) {
    e->acceleration.x = ax;
    e->acceleration.y = ay;
}

void updateVelocity(Entity *e, float deltatime) {
    e->velocity.x += e->acceleration.x * deltatime * 0.5f;
    e->velocity.y += e->acceleration.y * deltatime * 0.5f;
    updatePosition(e, deltatime);
    e->velocity.x += e->acceleration.x * deltatime * 0.5f;
    e->velocity.y += e->acceleration.y * deltatime * 0.5f;
}


void updatePosition(Entity *e, float deltatime) {
    e->position.x += e->velocity.x * deltatime;
    if (e->position.x + e->size.x < 0) {
	e->size.y = giveHeight();
	e->position.x = ((rand() % 100) * 100 + screen_width);
	e->position.y = rand() % (2) ? 0 : screen_height - e->size.y;
    }
    e->position.y += e->velocity.y * deltatime;
}


void jump(Entity *e) {
    const float pushForce = 1000;
    if (IsKeyDown(KEY_SPACE)) {
	applyForce(e, 0.0, -pushForce);
    } else if (IsKeyReleased(KEY_SPACE)){
	applyForce(e, 0.0, +pushForce);
    }
}
