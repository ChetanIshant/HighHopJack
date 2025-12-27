# Jumping Boy (C / DOS Console Game)

A small retro-style console game written in C for the Turbo C / DOS-style environment. The game renders ASCII characters using `gotoxy()` and animates movement with `delay()`. Your goal is to keep the player(s) moving and avoid collisions with the obstacle.

## Preview (ASCII)

- Player: `>O>` (3 characters wide)
- Obstacle parts:
  - Top: `(00)`
  - Middle: `/()\` (or `\()/` during animation)
  - Bottom: `||`
- Border: `*` frame around the play area

## Gameplay

- The player moves horizontally across the screen.
- Press **J** to jump (the obstacle shifts vertically during the jump animation).
- Collision is detected when the player overlaps the obstacle at the same row.
- Score increases when the player reaches a certain position while moving.

## Controls

- `S` → Start / continue movement
- `J` → Jump
- `E` → Exit

## How collision works

The game checks overlap between the player sprite and each obstacle section:

- Player width is 3 columns (`left` to `left + 2`)
- Obstacle widths:
  - `(00)` is 4 columns
  - `/()\` is 4 columns
  - `||` is 2 columns

A collision happens if the player and any obstacle part share the same `top` row and their horizontal ranges overlap.

## Requirements

This project uses old DOS/TC headers and APIs:

- `conio.h` (for `clrscr()`, `gotoxy()`, `kbhit()`, `getch()`, cursor control)
- `dos.h` (for `delay()`)

Because of this, it is intended to be compiled and run in one of these environments:

- Turbo C / Turbo C++
- DOSBox with Turbo C
- Compatible Borland compilers that support `conio.h` + `dos.h`

> Note: This will **not** compile directly on most modern compilers (GCC/Clang/MSVC) without porting/replacing these DOS-specific functions.

## How to run (Turbo C / DOSBox)

1. Open Turbo C / Turbo C++ (or run it inside DOSBox).
2. Create/open a project (or just open the `.c` file).
3. Compile and run:
   - Compile: `Alt + F9`
   - Run: `Ctrl + F9`

## Files

- `main.c` (or your source file name): Contains the complete game logic, rendering, input handling, scoring, and collision detection.

## Project notes / limitations

- The game is designed for an 80x25 text screen layout.
- Uses blocking-style console drawing with frequent erase/redraw.
- Depends on Turbo C style console functions.
- Contains multiple moving player sprites (additional `>O>` characters) once certain conditions are met.

## Author

Made by: Chetan Urf Ishant.

If you fork or improve it, feel free to open a PR!

