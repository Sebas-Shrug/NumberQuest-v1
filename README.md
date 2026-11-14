# NumberQuest v1.4 — Statistics & Bug Fixes

This update introduces a new statistics tracker to NumberQuest, allowing players to monitor their performance across multiple games!

## New Features

- **Statistics Tracker:** Displays overall player statistics after each completed game.
- **Game History Tracking:** Records the score and number of turns taken in every completed game.
- **Performance Tracking:** Keeps track of best score, average score, average turns, and the fewest turns taken in a game.
- **Lifetime Guess Counter:** Tracks the total number of valid guesses made across games.
- **Option Statistics:** Tracks total uses and win percentages for the CutHalf and Gambling categories.

## Bug Fixes & Improvements

- Fixed array loop boundaries to prevent accessing invalid indexes.
- Fixed total guess tracking to prevent invalid inputs from being counted.
- Improved accuracy of statistics calculations.
- Refined game testing and verification across multiple consecutive games.

**Thank you for playing NumberQuest!**

---

# NumberQuest v1.3 — Update Notes

## New Features
- **Reworked the Gambling System:** Modified the gambling mechanics and introduced new features to make each gamble more interesting.
- **Progressive Number Pools:** Successfully getting close to the dice roll rewards the player with a pool of possible numbers. Repeated successes make the pool progressively smaller (10 → 5 → 3).
- **Array-Based Number Tracking:** Implemented an array system to keep track of the remaining possible numbers throughout the game.
- **Repeated Guess Prevention:** Added validation that prevents players from guessing numbers that have already been excluded.

## Improvements
- Improved number validation to ensure guesses are consistent with the remaining possible answers.
- Refined the game's number-tracking logic to support the updated gambling mechanics.
- Fixed some issues with the restar-tability feature

---

# NumberQuest v1.2 — Update Notes

## New Features
- Added a **Check Valid Numbers** option, allowing players to view all remaining possible numbers during gameplay.
- Added a live score display, making score deductions and the current score transparent throughout the game.

## Bug Fixes
- Fixed a restart validation bug where the game would fail to exit properly after receiving an invalid response followed by `N`.
- Fixed a replay bug that caused the game to malfunction after the first retry due to inconsistent variable values.

---

# NumberQuest v1.1

## What's New
- Added an optional scoring guide before starting.
- Introduced score-based ending dialogues.
- Improved the gambling mechanic with randomized number placement.
- Fixed several bugs and refined gameplay.
- Added a restartability feature, allowing players to start a new round without relaunching the program.
- 
---

# NumberQuest v1.0

**Date:** October 30, 2026  
**Status:** Initial Release

## About the Project

A number guessing game written in C. The objective is to guess a randomly generated number between 1 and 100, with a few additional mechanics to make things more interesting!

## Features

1. **Turn Mechanic** – Keeps track of the player's turns.
2. **Scoring System** – Deducts points based on the number of turns taken and certain gameplay decisions.
3. **Cut-in-Half Mechanic** – Allows players to find out whether the secret number is higher or lower than 50.
4. **Odd-or-Even Mechanic** – Reveals whether the secret number is odd or even.
5. **Gambling Mechanic** – WOOOOOOO! Test your luck with a dice roll for a chance to receive additional clues or hit the jackpot.

## Objective

Guess the randomly generated number to finish the game and see your final score.

---

*Version 1.0 – Initial upload.*

---

Thanks for playing NumberQuest!
