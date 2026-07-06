#include <stdio.h>

#include "../include/raylib.h"
#include "../include/main.h"
#include "../include/entity.h"

int main() {
    InitWindow(screen_width, screen_height, "gd");
    SetTargetFPS(target_fps);

    Entity *player = createPlayer();
    applyForce(player, 0.0, acc_gravity, 1);

    float deltatime;
    while (!WindowShouldClose()) {
	deltatime = GetFrameTime();
	updateVelocity(player, deltatime);
	BeginDrawing();
	    ClearBackground(WHITE);
	    drawPlayer(player);

	EndDrawing();
    }
    return 0;
}
