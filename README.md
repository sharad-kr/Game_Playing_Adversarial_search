# Rollerball Chess

Welcome to the repository for our Rollerball Chess AI project.

## Overview

This project is an AI-based implementation of the game Rollerball Chess. The AI features adversarial search algorithms, including minimax and alpha-beta pruning, to play Rollerball Chess, a chess variant. The AI evaluates positions and makes optimal moves to outplay opponents.

## Game Rules

- Rollerball Chess is played on a 7x7 board with a 3x3 section in the middle cut out.
- Each player has six pieces: two pawns, two rooks, one bishop, and one king.
- Pieces move similarly to chess with the ability to move clockwise for most steps and one step counterclockwise.
- Pieces may reflect off the corners or edges of the board at most once.

## Implementation

We, in collaboration with Sharad Kumar and Bedanta Bhaumik, implemented the game logic and adversarial search algorithms, including minimax and alpha-beta pruning, to create a strategic AI player for Rollerball Chess. The AI evaluates positions and makes optimal moves to outplay opponents.

## Collaborators

- Sharad Kumar
- Bedanta Bhaumik

## Repository Structure

- `src/`: Contains the source code for the Rollerball Chess AI.
- `web/`: Houses the GUI for the Rollerball Chess game.
- `starter_code/`: Original starter code provided for the assignment.

## How to Run

To run the Rollerball Chess AI, follow these steps:

1. Clone this repository to your local machine.
2. Navigate to the `web` directory and launch a local web server.
   ```shell
   cd web
   python3 -m http.server 8080
   ```
3. Open a web browser and access `localhost:8080` to play Rollerball Chess against the AI.

## AI Performance

The AI has been tested against various AI opponents, and its performance has been evaluated based on scoring metrics. It demonstrates strategic gameplay and strong decision-making abilities.

Feel free to explore this repository and enjoy a game of Rollerball Chess against our AI opponent!
