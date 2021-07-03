# GameOfLife

**Conway's Game of Life** is a **0 player** game created in 1970 by a British mathematicion in 1970.

This is my own implementation written in **C++**.
With a given initial state, the game requires no player input in order to evolve and create interesting patterns.

![](R-Pentomino-Example.gif)

^ Example of a pattern called the **R-Pentomino**.

The game only has 4 rules:
1. Any live cell with fewer than 2 live neighbors dies, as if caused by under-population.
2. Any live cell with 2 or 3 neighbours on to the next generation.
3. Any live cell with more than 3 neighbors dies, as if caused by over-population.
4. Any dead cell with exactly 3 live neighbors becomes a live cell, as if caused by reproduction.

Controls:
- Click any cell with either mouse button to toggle its state.
- Hit the spacebar to pause the simulation.

To Do:
- Make board infinite.

Known Bugs:
- Game gets weird / doesn't work in the bottom right cell of the board.
