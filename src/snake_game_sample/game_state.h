#ifndef SNAKE_GAME_STATE_H_
#define SNAKE_GAME_STATE_H_
#include <iostream>

namespace ggpo {

struct Player final {
  uint8_t x, y, score;
  Player() : Player(0, 0, 0){};
  Player(const uint8_t x, const uint8_t y, const uint8_t score)
      : x(x), y(y), score(score){};
};

struct GridCell final {
  uint8_t data;

  GridCell();
  GridCell(const int data);
  bool isEmpty();
  void setEmpty(const bool flag);
 
};

struct GameState final {
  GridCell grid[400];
  Player p1;
  Player p2;
  uint8_t status;

  /*void Init(HWND hwnd, int num_players);
  void GetShipAI(int i, double *heading, double *thrust, int *fire);
  void ParseShipInputs(int inputs, int i, double *heading, double *thrust,
                       int *fire);
  void MoveShip(int i, double heading, double thrust, int fire);*/
  void Update(int inputs[], int disconnect_flags);
};

}  // namespace ggpo
#endif  // SNAKE_GAME_STATE_H_
