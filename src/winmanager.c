#include "../include/winmanager.h"
#include "../include/raylib.h"
#include "../include/main.h"
#include "../include/entity.h"
bool objectCheck(Entity *p, Entity *objs[], size_t obj_size) {
    for (size_t i = 0; i < obj_size; ++i) {

	if (p->position.x < objs[i]->position.x + objs[i]->size.x &&
	    p->position.x + p->size.x > objs[i]->position.x &&
	    p->position.y < objs[i]->position.y + objs[i]->size.y &&
	    p->position.y + p->size.y > objs[i]->position.y)
	{
	    return false;
	}

    }

    return true;
}
bool outOfBoundsCheck(Entity *p) {
    if (p->position.y + p->size.y < 0) {
	return false;
    }

    if (p->position.y - p->size.y > screen_height) {
	return false;
    }

    return true;

}

bool loseCheck(Entity *p, Entity *objs[], size_t count) {

    return objectCheck(p, objs, count) && outOfBoundsCheck(p);
}

