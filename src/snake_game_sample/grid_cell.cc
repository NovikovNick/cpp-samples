#include "../util/log.h"
#include "game_state.h"

namespace {

uint8_t dir_msk = 0b11000000;
uint8_t dir_top = (3 << 6);  // 0b11000000;
uint8_t dir_rht = (2 << 6);  // 0b10000000;
uint8_t dir_lft = (1 << 6);  // 0b01000000;
uint8_t dir_btm = (0 << 6);  // 0b00000000;

uint8_t plr_msk = 0b00001000;

uint8_t prev_mask = 0b00110000;
uint8_t prev_top = (3 << 4);  // 0b00110000;
uint8_t rev_rht = (2 << 4);   // 0b00100000;
uint8_t rev_lft = (1 << 4);   // 0b00010000;
uint8_t rev_btm = (0 << 4);   // 0b00000000;

uint8_t apple_mask = 0b00000110;
uint8_t curr_apple = (3 << 1);  // 0b00000110;
uint8_t prev_apple = (2 << 1);  // 0b00000100;
uint8_t next_apple = (1 << 1);  // 0b00000010;

int empty_b = 0b00000001;

}  // namespace

namespace ggpo {

GridCell::GridCell(const int data) : data(data){};

GridCell::GridCell() : GridCell(0){};

bool GridCell::isEmpty() { return data & empty_b; }
void GridCell::setEmpty(const bool flag) {
  data = flag ? data | empty_b : data ^ empty_b;
};

}  // namespace ggpo