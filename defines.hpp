#ifndef DEFINES_HPP
#define DEFINES_HPP
#include <string>
class Spaceship;
const int BOARD_EXTENSION = 120;
enum State
{
    DEAD,
    ALIVE
};
enum Model
{
    STATIC,
    MOVING
};
const int PLAYER_BULLET_SPEED = 10;
const int ENEMY_BULLET_SPEED = 8;
const int ENEMY_SHOOT_DURATION = 110;
const int ENEMY_SPEED = 5;
const int PLAYER_SPEED = 8;
const std::string PLAYER_FILENAME = "player.png";
const int SPACESHIP_HEIGTH = 90;
const int SPACESHIP_WIDTH = 90;
const int NOT_SHOT = -1;
const int BULLET_HEIGTH = 30;
const int BULLET_WIDTH = 30;
const int UPDATE_DELAY = 15;
const int END_GAME_MESSAGE = 3000;
const std::string PLAYER_BULLEET_FILENAME = "player_bullet.png";
const std::string ENEMY_BULLEET_FILENAME = "enemy_bullet.png";
const std::string WIN_IMAGE = "win.jpg";
const std::string LOSE_IMAGE = "lose.jpg";
const std::string HOSTAGE_FILENAME = "hostage.png";
const std::string WINDOW_FILENAME = "board.jpg";
const std::string STATIC_ENEMY_FILENAME = "enemy.png";
const std::string MOVING_ENEMY_FILENAME = "enemy.png";
#endif