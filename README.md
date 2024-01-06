# Objective
The goal of the frog game is to swap the X and O pieces completely. The only way to move a piece is by hopping over another piece or by moving into an empty space next to it.

This program allows a user to specify how many pieces to start the game and whether or not they play the game themselves or have the optimal algorithm solve it for them.

This program was created for a middle school math class learning about the Frog game to help them analyze and interact with the game in an intuitive way.

# How to use
clone the repo:
```console
git clone https://github.com/lpjones/Frog.git
```
Then compile the file within the repo:
```console
g++ Frog.cc
```
To run the program:
```console
./a.out
```
Then follow the prompts to play the Frog game

# Example
```console
lukejones@Lukes-MacBook-Pro-5 Frog % ./a.out 
Input number of Pairs of Frogs: 2
Computer or Player [c] or [p]: p
1 2 3 4 5 
X X   O O 
Moves: 0
Choose which frog to move: 2
1 2 3 4 5 
X   X O O 
Moves: 1
Choose which frog to move: 4
1 2 3 4 5 
X O X   O 
Moves: 2
Choose which frog to move: 3
1 2 3 4 5 
X O   X O 
Moves: 3
Choose which frog to move: 1
1 2 3 4 5 
  O X X O 
Moves: 4
Choose which frog to move: 2
1 2 3 4 5 
O   X X O 
Moves: 5
Choose which frog to move: 3
1 2 3 4 5 
O X   X O 
Moves: 6
Choose which frog to move: 5
1 2 3 4 5 
O X O X   
Moves: 7
Choose which frog to move: 4
1 2 3 4 5 
O X O   X 
Moves: 8
Choose which frog to move: 2
1 2 3 4 5 
O   O X X 
Moves: 9
Choose which frog to move: 3
1 2 3 4 5 
O O   X X 
You Won in 10 moves!!
```