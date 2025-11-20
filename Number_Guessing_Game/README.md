# 🎯 [Number Guessing Game](main.cpp) (C++)

A simple but engaging console-based number guessing game built in C++.  
The computer generates a random number based on the difficulty level you choose, and your goal is to guess it within the allowed number of attempts.

This is my first complete C++ project where I used functions, classes, and modular design to build a playable mini-game.

---

## 🚀 Features

- 🎮 **Multiple difficulty levels**
  - Easy: 1–100  
  - Medium: 1–200  
  - Hard: 1–500  
  - Extreme: 1–1000  
  - Impossible: 1–1500  

- 🎯 **Different number of tries per difficulty**
- 🔁 **Instant replay support without reselecting difficulty**
- 🎲 **Random number generation using `rand()` with dynamic seeding**
- 📏 **Higher / Lower hints after each guess**
- ❌ **Loss when tries run out**
- 🏆 **Victory message when guessed correctly**
- 🧩 **Clean, modular code (functions + class)**

---

## 🧠 Logic Overview (How the Game Works)

1. The player selects a difficulty level.
2. The program generates a random number within that level's range.
3. The player has a limited number of tries based on difficulty.
4. For each guess:
   - If guess > secret → “You're higher”
   - If guess < secret → “You're lower”
   - If guess == secret → player wins
5. After the round ends, the player can replay instantly.

---

## 🛠️ Technical Concepts Used

- **Classes**  
  Used for generating random numbers (`Generator` class).

- **Functions**  
  - `generateRandom()` → Returns random number within a level  
  - `givenTries()` → Decides attempts based on difficulty  
  - `playGame()` → Controls the entire guessing flow  

- **Modular design**  
  Code is split into readable, reusable components.

- **Random number generation**  
  Using `rand()` and `srand(time(0))`.

---

## 🧠 Output Example

```
========================================================================================
 WELCOME TO NUMBER GUESSING GAME 

About Game:
        This is a very simple game.
        The computer generates a number from 1 to 100 every second
        You have to guess the correct number to win this game
        If you fail to guess correctly within 10 tries, you lose
        You also lose if you guessed a number that is beyond the level you specified
        You get more tries depending on your level


        THAT'S ALL. ENJOY!
========================================================================================

Choose the level:
1. Easy - 1 to 100
2. Medium - 1 to 200
3. Hard - 1 to 500
4. Extreme - 1 to 1000
5. Impossible - 1 to 1500
6. Exit
2
Try 1: Guess number:--->   100
You're lower

Try 2: Guess number:--->   150
You're lower

Try 3: Guess number:--->   190
You're higher

Try 4: Guess number:--->   170
You're higher

Try 5: Guess number:--->   163
You're lower

Try 6: Guess number:--->   169
You're higher

Try 7: Guess number:--->   167
CONGRATULATIONS!! YOU WON IN 7 TRIES! ^_^
Replay? (y/n): n
```