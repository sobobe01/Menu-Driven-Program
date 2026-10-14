# Menu-Driven Program

A small C++ console program that calculates health club membership charges.
Pick a membership type, enter the number of months, and it prints the total.

```
    Health Club Membership Menu

  1. Standard Adult  $40.00 / month
  2. Child           $20.00 / month
  3. Senior Citizen  $30.00 / month
  4. Quit
```

## Build and run

```bash
make run
```

Or without `make`:

```bash
c++ -std=c++17 -Wall -Wextra -o membership main.cpp && ./membership
```

## How it is put together

- **`MEMBERSHIPS`** — one table holds every membership type and its monthly rate.
  The menu, the valid choices and the Quit number all come from it, so adding a
  type is a one-line change.
- **`readInt`** — reads a whole line and accepts it only if it is a whole number
  in range. Letters, blank lines and out-of-range numbers get a message and a
  re-prompt; end of input (Ctrl-D) exits cleanly.
- **`formatCents`** — prices are stored in whole cents, so totals are exact.
- **`displayMenu`** / **`showFees`** — print the menu and the result.

## Test

```bash
make test
```

Feeds a scripted session (including bad input) through the program and compares
the output with `tests/expected.txt`.
