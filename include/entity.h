typedef struct entity_s {
    Vector2 size;
    Vector2 position;
    Vector2 velocity;
    Vector2 acceleration;
} Entity;

Entity *createPlayer();
void drawPlayer(Entity *p);

void applyForce(Entity *e, float ax, float ay, float deltatime);
void updateVelocity(Entity *e, float deltatime);
void updatePosition(Entity *e, float deltatime);
