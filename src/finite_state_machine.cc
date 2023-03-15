#include <numeric>
#include <sml.hpp>

#include "util/log.h"

namespace fsm {

namespace sml = boost::sml;

enum class PlayerState {
  IDLE = 0,
  RUN = 1,
  JUMP = 2,
  FALLING = 3,
  LANDING = 4,
  ATTACK_ON_GROUND = 5,
  DEATH = 6
};

struct Context {
  PlayerState state;
  uint64_t state_frame;
  bool on_ground, on_damage;
};

struct InputLeftMouseBtn {};
struct InputLeft {};
struct InputRight {};
struct InputUp {};
struct InputDown {};
struct InputNone {};

class idle;
class run;
class jump;
class falling;
class landing;
class attack_on_ground;
class death;

const auto onGround = [](const Context& ctx) { return ctx.on_ground; };
const auto inAir = [](const Context& ctx) { return !ctx.on_ground; };

struct FrameLessOrEqualThen {
  int frame;
  auto operator()(const Context& ctx) const { return ctx.state_frame <= frame; }
};
struct FrameGreatThen {
  int frame;
  auto operator()(const Context& ctx) const { return ctx.state_frame > frame; }
};

struct transition_table {
  // using idle_s = sml::state<idle>;

  auto operator()() const {
    using namespace sml;

    auto idle_s = state<idle>;
    auto run_s = state<run>;
    auto jump_s = state<jump>;
    auto falling_s = state<falling>;
    auto landing_s = state<landing>;
    auto attack_s = state<attack_on_ground>;
    auto death_s = state<death>;

    auto input_up = event<InputUp>;
    auto input_none = event<InputNone>;
    auto input_left = event<InputLeft>;
    auto input_right = event<InputRight>;
    auto input_attack = event<InputLeftMouseBtn>;
    /**
     * Initial state: *initial_state
     * Transition DSL: src_state + event [ guard ] / action = dst_state
     */
    return make_transition_table(
        *idle_s + input_none[onGround] = idle_s,
        idle_s + input_left[onGround] = run_s,
        idle_s + input_right[onGround] = run_s,
        idle_s + input_up[onGround] = jump_s,
        idle_s + input_attack[onGround] = attack_s,
        idle_s + input_none[inAir] = falling_s,

        landing_s + input_none[onGround && FrameLessOrEqualThen{2}] = idle_s,
        landing_s + input_none[onGround && FrameGreatThen{2}] = idle_s,
        landing_s + input_none[inAir] = falling_s,

        attack_s + input_none[onGround && FrameLessOrEqualThen{3}] = attack_s,
        attack_s + input_none[onGround && FrameGreatThen{3}] = idle_s,
        attack_s + input_none[inAir] = falling_s,

        run_s + input_none[onGround] = idle_s,
        run_s + input_left[onGround] = run_s,
        run_s + input_right[onGround] = run_s,
        run_s + input_none[inAir] = falling_s,

        jump_s + input_none[inAir && FrameLessOrEqualThen{6}] = jump_s,
        jump_s + input_none[inAir && FrameGreatThen{6}] = falling_s,
        jump_s + input_none[onGround] = landing_s,

        falling_s + input_none[onGround] = landing_s);
  }
};

PlayerState getState(const auto& sm) {
  if (sm.is(sml::state<idle>)) return PlayerState::IDLE;
  if (sm.is(sml::state<run>)) return PlayerState::RUN;
  if (sm.is(sml::state<jump>)) return PlayerState::JUMP;
  if (sm.is(sml::state<falling>)) return PlayerState::FALLING;
  if (sm.is(sml::state<landing>)) return PlayerState::LANDING;
  if (sm.is(sml::state<attack_on_ground>)) return PlayerState::ATTACK_ON_GROUND;
  return PlayerState::DEATH;
}

std::string toString(const PlayerState& state) {
  switch (state) {
    case PlayerState::IDLE:
      return "IDLE";
    case PlayerState::RUN:
      return "RUN";
    case PlayerState::JUMP:
      return "JUMP";
    case PlayerState::FALLING:
      return "FALLING";
    case PlayerState::LANDING:
      return "LANDING";
    case PlayerState::ATTACK_ON_GROUND:
      return "ATTACK_ON_GROUND";
    case PlayerState::DEATH:
      return "DEATH";
  }
}

struct my_logger {
  template <class SM, class TEvent>
  void log_process_event(const TEvent&) {
    printf("[%s][process_event] %s\n", sml::aux::get_type_name<SM>(),
           sml::aux::get_type_name<TEvent>());
  }

  template <class SM, class TGuard, class TEvent>
  void log_guard(const TGuard&, const TEvent&, bool result) {
    printf("[%s][guard] %s %s %s\n", sml::aux::get_type_name<SM>(),
           sml::aux::get_type_name<TGuard>(), sml::aux::get_type_name<TEvent>(),
           (result ? "[OK]" : "[Reject]"));
  }

  template <class SM, class TAction, class TEvent>
  void log_action(const TAction&, const TEvent&) {
    printf("[%s][action] %s %s\n", sml::aux::get_type_name<SM>(),
           sml::aux::get_type_name<TAction>(),
           sml::aux::get_type_name<TEvent>());
  }

  template <class SM, class TSrcState, class TDstState>
  void log_state_change(const TSrcState& src, const TDstState& dst) {
    printf("[%s][transition] %s -> %s\n", sml::aux::get_type_name<SM>(),
           src.c_str(), dst.c_str());
  }
};

void test() {
  using namespace sml;

  Context ctx{PlayerState::IDLE, 0, true, false};
  // sm<transition_table, logger<my_logger>> state_machine{ctx, my_logger{}};
  sm<transition_table> state_machine{ctx};

  for (int i = 0; i < 10; ++i) {
    ++ctx.state_frame;

    state_machine.process_event(InputNone{});
    // state_machine.process_event(input_left_mouse_btn{});
    // state_machine.process_event(input_left{});
    state_machine.process_event(InputUp{});

    auto player_state = getState(state_machine);
    if (ctx.state != player_state) {
      ctx.state = player_state;
      ctx.state_frame = 0;
    }
    if (i == 0) ctx.on_ground = false;
    util::debug("frame#{:3d}. {}\n", ctx.state_frame, toString(player_state));
  }
}
}  // namespace fsm
