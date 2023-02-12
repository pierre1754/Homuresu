/*
** EPITECH PROJECT, 2022
** kidiot.h
** File description:
** kidiot
*/

#ifndef CLIENT_H_
#define CLIENT_H_

#define _GNU_SOURCE
#include "raylib.h"
#include "raymath.h"
#include <ctype.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>

#include "list.h"

#define OBS_NBR 10
#define WALL_NBR 4
#define MAP_SIZE 32.0f

typedef enum
{
  CROSSHAIR = 0,
} spriteName_t;

typedef struct
{
  Texture2D texture;
  Vector2 position;
  Vector2 origin;
  float scale;
  Color tint;
  char *name;
} sprite_t;

typedef enum
{
  SOUND_WALK,
  SOUND_SHOOT,
} sound_e;

typedef struct
{
  sound_e type;
  Sound sound;
} sound_t;

typedef enum
{
  MODEL_BATARANG,
  MODEL_DORION,
  MODEL_DORION2,
} model_e;

typedef struct
{
  model_e type;
  Model model;
} model_t;

typedef struct
{
  int score;
  int life;
  int ammo;
  int cooldownShoot;
  int lastShoot;
} stat_t;

typedef struct {
  int id;
  Vector3 position;
  Vector3 direction;
  model_t model;
  stat_t stat;
  bool isAlive;
} player_t;

typedef struct bullet_s
{
  Vector3 position;
  Vector3 direction;
  Model model;
  float speed;
  float size;
  bool isAlive;
} bullet_t;

typedef struct
{
  Vector3 position;
  float width;
  float height;
  float length;
  Texture2D texture;
} cube_t;

typedef struct
{
  Vector3 position;
  float width;
  float height;
  float length;
  Texture2D texture;
  char *name;
  bool isAlive;
} item_t;

typedef struct selection_menu_s
{
  list_t *elements;

  Texture2D right_button;
  Rectangle right_sourceRec;
  Rectangle right_btnBounds;

  Texture2D left_button;
  Rectangle left_sourceRec;
  Rectangle left_btnBounds;

  Texture2D validate_button;
  Rectangle validate_sourceRec;
  Rectangle validate_btnBounds;
} selection_menu_t;

typedef struct menu_s
{
  Camera camera;
  Vector2 mousePoint;

  Texture2D button;

  Rectangle sourceRec;
  Rectangle btnBounds;

  Texture2D quit_button;
  Rectangle quit_sourceRec;
  Rectangle quit_btnBounds;
  Vector2 quit_position;

  Texture2D title;

  int is_menu;
  Vector2 windowSize;
} menu_t;

typedef struct
{
  Camera camera;
  Vector3 cameraLastPosition;

  Vector2 windowSize;
  int id;

  list_t *cube;
  list_t *sound;
  list_t *model;
  list_t *bullet;
  list_t *sprite;
  list_t *item;
  list_t *player;
  stat_t *stat;
  menu_t *menu;
} game_t;

/**
 * @brief
 *
 * @param screenWidth
 * @param screenHeight
 */
void initWindow(const int screenWidth, const int screenHeight);

/**
 * @brief
 *
 * @param game
 */
void initWall(game_t *game);

/**
 * @brief
 *
 * @param game
 */
void initCube(game_t *game);

/**
 * @brief
 *
 * @param game
 */
void initCamera(game_t *game);

/**
 * @brief
 *
 * @param speed
 * @param size
 * @param camera
 * @return bullet_t*
 */
void initBullet(game_t *game);

/**
 * @brief
 *
 * @param game
 */
void initSounds(game_t *game);

/**
 * @brief
 *
 * @param game
 */
void initModels(game_t *game);

/**
 * @brief
 *
 * @param game
 */
void initGame(game_t *game);

// MANAGE
/**
 * @brief
 *
 * @param game
 */
void initSprite(game_t *game);

/**
 * @brief
 *
 * @param game
 */
void initStat(game_t *game);

/**
 * @brief
 *
 * @param game
 */
void initItem(game_t *game);

/**
 * @brief
 *
 * @param game
 */
void initPlayer(game_t *game);

/**
 * @brief
 *
 * @param game
 */
void addInfoPlayerToGame(game_t *game, char *msg);

// CREATE

/**
 * @brief Create a Bullet object
 *
 * @param game
 * @param speed
 * @param size
 */
void createBullet(game_t *game, float speed, float size);

/**
 * @brief Get the Sound object
 *
 * @param game
 * @param type
 * @return Sound*
 */
Sound *getSound(game_t *game, sound_e type);

/**
 * @brief Get the Sound object
 *
 * @param game
 * @param type
 * @return Model*
 */
Model *getModel(game_t *game, model_e type);

/**
 * @brief
 *
 * @param game
 * @param type
 */
void playSound(game_t *game, sound_e type);

void createAmmoBox(game_t *game);

// UPDATE

/**
 * @brief
 *
 * @param game
 */
void setupSprite(game_t *game, spriteName_t name, Vector2 position, Vector2 size, float scale, Color tint);

/**
 * @brief
 *
 * @param game
 */
void updateEnter(game_t *game);

/**
 * @brief
 *
 * @param game
 */
void updateWalk(game_t *game);
void updateR(game_t *game);

/**
 * @brief
 *
 * @param game
 */
void updateEvent(game_t *game);

/**
 * @brief
 *
 * @param game
 */
void checkCollision(game_t *game);

/**
 * @brief
 *
 * @param game
 */
void updateCollision(game_t *game);

/**
 * @brief
 *
 * @param game
 */
void updateDeadBullet(game_t *game);

/**
 * @brief
 *
 * @param game
 */
void updateDeadItem(game_t *game);

/**
 * @brief
 *
 * @param game
 */
void updateGame(game_t *game);

// DRAW

/**
 * @brief
 *
 * @param game
 */
void drawGame(game_t *game);

/**
 * @brief
 *
 * @param game
 */
void drawCube(game_t *game);

/**
 * @brief
 *
 * @param game
 */
void drawBullet(game_t *game);

/**
 * @brief
 *
 * @param game
 */
void drawPlayer(game_t *game);

/**
 * @brief
 *
 * @param game
 */
void drawItem(game_t *game);

/**
 * @brief
 *
 * @param game
 */
void drawSpriteTwoD(game_t *game);

/**
 * @brief
 *
 * @param game
 */
void drawTextTwoD(game_t *game);

// MAIN

/**
 * @brief
 *
 * @param game
 */
void mainLoop(game_t *game);

/**
 * @brief
 *
 * @param menu_st
 */
void initMenu(game_t *game);

/**
 * @brief
 *
 * @param menu_st
 * @return int
 */
int menu(menu_t *menu_st, float *x);

#endif /* !CLIENT_H_ */
