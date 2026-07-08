#ifndef ENTITY_HEADER
#define ENTITY_HEADER

#include <stddef.h>
#include "raylib.h"
typedef struct entity_s {
    Vector2 size;
    Vector2 position;
    Vector2 velocity;
    Vector2 acceleration;
} Entity;

Entity *createPlayer();
int createObjects(Entity **objs, size_t count);

void resetPlayer(Entity *p);
void resetObject(Entity *objs);

void drawPlayer(Entity *p);
void drawObjects(Entity **o, size_t count);

void applyForce(Entity *e, float ax, float ay);
void updateVelocity(Entity *e, float deltatime);
void updatePosition(Entity *e, float deltatime);


void jump(Entity *e);
#endif
