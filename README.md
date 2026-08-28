# so_long 🎮

**so_long** is a 42 School project where I created a small 2D game using **MiniLibX**.

The player must collect all the items on the map and then reach the exit, while avoiding walls.

## 🎯 Goal

* Create a 2D game
* Parse and validate the map
* Handle player movement
* Collect all items
* Open the exit after collecting everything
* Count the player's movements

## 🎮 Controls

| Key       | Action     |
| --------- | ---------- |
| `W` / `↑` | Move up    |
| `A` / `←` | Move left  |
| `S` / `↓` | Move down  |
| `D` / `→` | Move right |
| `ESC`     | Exit       |

## 🗺️ Map

The map uses these characters:

```text
1 → Wall
0 → Empty space
P → Player
C → Collectible
E → Exit
```

Example:

```text
111111
100001
10C0P1
1000E1
111111
```

## 🛠️ Technologies

* C
* MiniLibX
* Makefile
* 2D Graphics
* Map Parsing

## 🚀 Usage

Compile:

```bash
make
```

Run:

```bash
./so_long maps/map.ber
```

Clean:

```bash
make clean
make fclean
make re
```

## 📚 What I Learned

* 2D game development
* Graphics with MiniLibX
* Map parsing and validation
* Event handling
* Player movement
* Collision detection
* Memory management

42 School
