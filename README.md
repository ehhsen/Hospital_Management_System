# Hospital Management System (C++)

A simple console-based Hospital Management System implemented in C++ using `std::queue` to represent wards. The program allows adding and removing patients from multiple wards (queues). It is intended as a learning / demonstration project for basic data structures, CLI arguments, and simple I/O.

---

## Features

* Create N wards (queues) via a command-line argument
* Enter ward names at startup
* Add patient records (Name, ID, Disease) to any ward
* Serve (remove) the next patient from any ward
* Simple text menu to interact with the system

---

## Requirements

* A C++ compiler that supports C++11 or later (example uses `g++`).

---

## Build

Compile the program (assuming file is `source.cpp`):

```bash
g++ -std=c++17 -Wall -Wextra -o source.exe source.cpp
```

---

## Usage

Run the program with one integer argument specifying how many wards (queues) you want to create:

```bash
./source.exe <num_wards>
# Example: create 3 wards
./source.exe 3
```

The program also accepts `--help` as the first argument to show the built-in help text:

```bash
./source.exe --help
```

After starting the program with a numeric argument you will be prompted to enter the name for each ward (one per line). Then the interactive menu will show available wards and allow the following options:

* `A` — Add patient to a ward
* `B` — Remove (serve) patient from a ward
* `C` — Quit

When adding a patient you'll be prompted for:

* Name (string)
* ID (integer)
* Disease (string)

When removing a patient, the program displays the patient who was served and the next patient in line (if any).

---

## Example session (short)

1. Start program: `./source.exe 2`
2. Enter ward names: `Emergency` (press Enter), `General` (press Enter)
3. Menu appears showing ward indices `0 Emergency` and `1 General`.
4. Type `A` to add; when prompted enter ward index e.g. `0`, then patient details.
5. Type `B` to remove; when prompted enter ward index e.g. `0`.
6. Type `C` to quit.

---

## Code structure (high-level)

* `struct patient` — simple struct with `ID`, `NAME`, and `DISEASE` fields.
* `interface(...)` — prints the user menu and ward list.
* `add_patient(...)` — prompts for patient info and pushes it into the selected queue.
* `remove_patient(...)` — pops the front patient of the selected queue and prints the served patient and the next patient.
* `display_help()` — built-in usage/help message.
* `main(...)` — validates CLI args, allocates dynamic arrays for ward names and queues, and runs the interactive loop.

---

## Known issues & suggested fixes

The program works as a basic demo but has a few correctness and robustness issues that you may want to fix or improve:

1. **Bounds checks for ward indices:**

   * The code checks `if (WARD > SIZE)` which is incorrect. It should check `if (WARD < 0 || WARD >= SIZE)` (or `if (WARD < 0 || WARD >= NUMBER_OF_QUEUES`) to correctly validate indices.

2. **Order of validation in `remove_patient`:**

   * The function checks bounds and emptiness separately, but still proceeds to access `QUEUES[WARD]` without ensuring the ward index was valid. Reorder checks and return early when invalid.

3. **Accessing `front()` after `pop()`:**

   * After removing the served patient with `pop()`, the code calls `QUEUES[WARD].front()` without checking whether the queue became empty. This causes undefined behavior when the queue is empty. Check `empty()` before calling `front()`.

4. **User input robustness:**

   * The program uses `std::getline` mixed with `operator>>` — consider using consistent line-based input handling and clear `std::cin` state after failed reads.

5. **Memory management and modern C++:**

   * The program uses `new[]` / `delete[]` for arrays. Prefer `std::vector<std::string>` and `std::vector<std::queue<patient>>` to avoid manual memory management and improve safety.

6. **Error messages & return codes:**

   * Improve CLI argument validation and return distinct exit codes for different error situations.

7. **Help behavior:**

   * When `--help` is passed the program prints help and returns `1`. Consider returning `0` for successful help display.

8. **Input validation for ID:**

   * Validate that the user entered an integer for `ID` and handle non-integer input gracefully.

---

## Improvements & TODOs

* Replace raw arrays with `std::vector`.
* Add persistence (save/load patient queues to a file).
* Add timestamps or arrival order metadata for patients.
* Allow viewing the full queue for any ward (list all patients waiting).
* Add priority queues or triage levels for emergency wards.
* Add unit tests for functions (where applicable) and make the program modular.

---

## License

use as you like.

---

## ehhsen
