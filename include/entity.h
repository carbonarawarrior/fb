typedef struct entity_s {
    Vector2 size;
    Vector2 position;
    Vector2 velocity;
    Vector2 acceleration;
} Entity;
Entity *createPlayer();
void drawPlayer(Entity *p);
