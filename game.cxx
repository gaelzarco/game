/// @file   main.cxx
/// @author Gael Zarco
/// @date   02-10-2026
/// @brief  Idk what game this is yet.

#include <print>
#include <raylib.h>
#include <cstdlib>

// =============================================================================
// ADT(S)
// =============================================================================
/// @brief Game state (0 = fail, 1 = win)
class Game {
public:
    /// @brief Represents game state explicitly
    enum class State {
        Win,
        Fail
    };

    /// @brief Default parameterized constructor
    explicit Game(State s = State::Fail) : state(s) {}

    /// @brief  State getter
    /// @return Game state
    State get_state(void) noexcept { return state; }
    /// @brief State setter
    void set_state(State s) { state = s; }

private:
    State state;
};

/// @brief Network related methods
class Network {
public:
private:
};

// =============================================================================
// ENTRY-POINT
// =============================================================================
int main(void) {
    Game game{};

    std::println("[LOG] Game state: {}", 
        game.get_state() == Game::State::Win ? "Win!" : "Fail!"
    );

    return EXIT_SUCCESS;
}

// =============================================================================
// ADT IMPLEMENTATION(S)
// =============================================================================
// ...

// EOF main.cxx
