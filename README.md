# monopoly

## ABOUT

Fun project that aims to create a monoboly-like turn-based game.

Features are being iteratively added as developement progresses further.

### Iteration 1 - basic features
1. 2-8 players support
2. 40 fields board (fields: start, penalty, reward)
3. Game simulation (until: "all players but one go bankrupt" or "x rounds have passed")
4. Rolling 2 dice

### Iteration 2
1. Deposit field (when passing-through leave $, when standing on field collect all $)
2. Prison (If you step onto it, you have to wait 2 turns!)
3. Different dice (D4, D6, D12...), boards
4. Polimorphic field

### Iteration 3
1. Property field
2. AI players (greedy...) + human players

### Iteration 4 - twists
1. Black hole field (every second time you step onto this field, nothing happens, can be applied by player)
2. Random field (random field action happens)


## SETUP & USAGE

Note: start each step from project dir

1. Add external lib - [googletest](https://github.com/google/googletest)
    ```
    mkdir ext
    cd ext
    git clone https://github.com/google/googletest.git
    cd googletest
    mkdir build
    cd build
    cmake ..
    ```

2. Create a project build dir and setup using cmake
    ```
    mkdir build
    cd build
    cmake ..
    make
    ```

3. Run compiled project binary or tests binary
    project:
    ```
    ./monopoly
    ```

    tests:
    ```
    ./monopoly_test
    ```
