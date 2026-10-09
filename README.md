# Zoo Wars

A terminal-based, turn-based C++ combat game: create an animal, choose your abilities, and battle your way to becoming king of the zoo.

**C++ · Object-oriented design · CMake · Google Test · Git/GitHub**

## Gameplay

- Customize your animal's name, species, attack, special attack, and defense names.
- Face six opponents: an armadillo, bobcat, crocodile, diamondback rattlesnake, elephant, and lion.
- Choose regular attacks, limited-use special attacks, or defense against randomly selected opponent actions.
- Increase attack and defense strength after victories, with health and ability uses restored between fights.
- Follow combat actions and health updates through a text-based interface.

## My contribution — Gonzalo Mercado

Developed the **Screen class**, which presents welcome messages, gameplay instructions, health statistics, action menus, and win/loss messages. Its output methods accept an `std::ostream`, allowing the same interface to write to the terminal or an in-memory stream for testing. The project includes Google Test checks for these screen outputs.

This was a four-person CS100 team project at the University of California, Riverside. The original project notes identify Wendy with Animal, Attack, Defend, and Health; Gonzalo with Screen; and Unnati with PlayGame. All original contributors are credited below.

## Build and run

Requirements: **CMake 3.20+**, a **C++14-compatible compiler**, and **Git**. The default test-enabled build downloads Google Test v1.14.0 on its first configuration, so it needs internet access.

```sh
git clone https://github.com/Gmercado05/Zoo-Wars.git
cd Zoo-Wars
cmake -S . -B build
cmake --build build
./build/bin/runProgram
```

For a game-only build without downloading test dependencies:

```sh
cmake -S . -B build-game -DBUILD_TESTING=OFF
cmake --build build-game
./build-game/bin/runProgram
```

With a multi-configuration generator such as Visual Studio, add `--config Debug` to the build command; executables are under `build/bin/Debug/` and have an `.exe` suffix on Windows.

## Controls

| Stage | Input | Action |
| --- | --- | --- |
| Welcome | `x` | Start |
| Main menu | `r` / `c` / `q` | Read description / create character / quit |
| Character confirmation | `y` / `n` | Confirm / recreate |
| Combat | `a` / `s` / `d` | Attack / special attack / defend |

Use single-word character and ability names; the current input handling reads whitespace-delimited values.

## Tests

```sh
ctest --test-dir build --output-on-failure
```

For Visual Studio or another multi-configuration generator, add `-C Debug`.

The existing unit suite covers Animal, Attack, Defend, Health, and Screen. It does not provide full gameplay or replay coverage.

## Architecture and repository layout

| Path / class | Responsibility |
| --- | --- |
| `Headers/` | C++ class declarations |
| `src/` | Game implementation and entry point |
| `test/` | Project-specific Google Test cases |
| `Animal` | Character identity and composed combat components |
| `Attack`, `Defend`, `Health` | Combat strengths, ability uses, and health state |
| `PlayGame` | Character creation, opponents, and combat flow |
| `Screen` | Terminal messages and health output |
| `docs/original-project-notes.md` | Preserved course write-up and design links |

CMake builds shared game code once as a library and links it into the game and test executables. Google Test is fetched into the build directory rather than stored among project sources.

## Screenshots

Original gameplay captures from the team project:

![Zoo Wars gameplay screenshot 1](https://github.com/user-attachments/assets/bc9ca34a-4458-46fd-8b73-3ab7fccce0a2)
![Zoo Wars gameplay screenshot 2](https://github.com/user-attachments/assets/e250ee12-9fae-40a0-863f-7b022962f8c8)

<details>
<summary>More gameplay screenshots</summary>

![Zoo Wars gameplay screenshot 3](https://github.com/user-attachments/assets/106b3353-0c46-4f6a-bb24-7d5ab32f30de)
![Zoo Wars gameplay screenshot 4](https://github.com/user-attachments/assets/1547b986-7d1f-4ac6-8185-06c682ff30db)
![Zoo Wars gameplay screenshot 5](https://github.com/user-attachments/assets/e09009e1-4a76-4e2f-8f77-197cda8a199c)

</details>

## Project status

This repository preserves a student team project. Known areas for improvement include replay/reset behavior, end-of-input handling, and some defense damage calculations. Unit tests alone do not establish that all combat paths are correct.

## Team

- [Wendy Vargas](https://github.com/wendyyvargas)
- [Gonzalo Mercado](https://github.com/Gmercado05)
- [Unnati Italia](https://github.com/unnatiitalia)
- [Naima Cano](https://github.com/naimacano)

Original course repository: [cs100/final-project-code-blooded](https://github.com/cs100/final-project-code-blooded) (access may be restricted).
