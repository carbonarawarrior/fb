#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "../include/raylib.h"
#include "../include/main.h"
#include "../include/entity.h"
#include "../include/winmanager.h"

int main() {
    srand(time(0));
    InitWindow(screen_width, screen_height, "gd");
    SetTargetFPS(target_fps);


    Entity *player = createPlayer();
    size_t obj_count = 10;
    Entity *objects[obj_count];

    if (createObjects(objects, obj_count)) {
	printf("Error: couldn't create objects\n");
	exit(1);
    }

gamestart:
    float deltatime;
    while (!WindowShouldClose()) {
	while (loseCheck(player, objects, obj_count) && !WindowShouldClose()){
	    deltatime = GetFrameTime();

	    jump(player);

	    updateVelocity(player, deltatime);
	    for (size_t i = 0; i < obj_count; ++i) {
		updateVelocity(objects[i], deltatime);
	    }

	    BeginDrawing();
	    if (loseCheck(player, objects, obj_count)) {
		ClearBackground(WHITE);
		drawPlayer(player);
		drawObjects(objects, obj_count);
	    } else {
		break;
	    }
	    EndDrawing();
	}
	while (!WindowShouldClose()) {
	    BeginDrawing();	
		ClearBackground(RED);
	    EndDrawing();
	    if (IsKeyPressed(KEY_SPACE)) {
		resetPlayer(player);
		for (size_t i = 0; i < obj_count; ++i) {
		    resetObject(objects[i]);
		}
		goto gamestart;
	    }
	}
    }
    free(player);
    for (size_t i = 0; i < obj_count; ++i) {
	free(objects[i]);
    }
    CloseWindow();
    return 0;
}
