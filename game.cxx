/// @file   main.cxx
/// @author Gael Zarco
/// @date   02-10-2026
/// @brief  Idk what game this is yet.

#include <print>
#include <cstdlib>

// =============================================================================
// ADT(S)
// =============================================================================
/// @brief Game state (0 = fail, 1 = win)
class Game {
public:
    /// @brief Represents game state explicitly
    enum class State {
        Menu,
        Play,
        Pause,
        Win,
        Fail
    };

    /// @brief Default parameterized constructor
    explicit Game(State s = State::Menu) : state(s) {}

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

    std::print("[LOG] Game state: ");

    switch (game.get_state()) {
        case Game::State::Menu:
            std::println("Menu");
        case Game::State::Play:
            std::println("Play");
        case Game::State::Pause:
            std::println("Pause");
        case Game::State::Win:
            std::println("Win");
        case Game::State::Fail:
            std::println("Fail");
    }

    return EXIT_SUCCESS;
}

// =============================================================================
// ADT IMPLEMENTATION(S)
// =============================================================================
// ...

// EOF main.cxx
