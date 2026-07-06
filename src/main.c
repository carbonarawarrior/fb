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

	if (IsKeyDown(KEY_SPACE)) {
	    applyForce(player, 0.0, -500, deltatime);
	} else if (IsKeyReleased(KEY_SPACE)){
	    applyForce(player, 0.0, +500, deltatime);
	}

	updateVelocity(player, deltatime);
	BeginDrawing();
	    ClearBackground(WHITE);
	    drawPlayer(player);

	EndDrawing();
    }
    return 0;
}
