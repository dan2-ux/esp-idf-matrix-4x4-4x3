# Matrix Keypad (4×4 and 4×3)

This repository demonstrates how to interface 4×4 and 4×3 matrix keypads using a row–column scanning method.

<img width="500" height="500" alt="image" src="https://github.com/user-attachments/assets/1f44bff0-a721-4c2b-82a2-dede5bc1b339" />

## What problem does this solve?
Ready to use components and clean API only require developers to define pin.

## How It Works

A matrix keypad is organized into rows and columns.
Each button connects one specific row to one specific column.
- A 4×4 keypad has 4 rows and 4 columns

- A 4×3 keypad has 4 rows and 3 columns

<img width="700" height="609" alt="image" src="https://github.com/user-attachments/assets/77f3d9e4-c0ae-423e-bbb7-180ec8b9fcd1" />

## GPIO Configuration

- Rows are configured as inputs

- Columns are configured as outputs

The columns are driven one at a time, while the rows are continuously read.

Scanning Process

1. Set all column pins to HIGH

2. Pull one column LOW

3. Read all row pins

4. If a row reads LOW, a key press is detected

5. The pressed key is identified by the current row and column index

6. The corresponding character is printed or sent to a queue

This scanning process runs continuously, allowing reliable detection of key presses.

## Features

Supports 4×4 and 4×3 matrix keypads

Modular design (component-based)

Compatible with ESP-IDF and FreeRTOS

Clean separation between GPIO setup and keypad logic
