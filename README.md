# Custom `wc` Tool in C++

This project is a custom implementation of the Unix `wc` (word count) command-line tool, built in C++. It supports counting the number of lines, words, bytes, and characters in a file.

## Features
- **Count lines (`-l`)**
- **Count words (`-w`)**
- **Count bytes (`-c`)**
- **Count characters (`-m`)**

## Table of Contents
- [Installation](#installation)
- [Usage](#usage)
- [Example](#example)
- [Testing Your Tool](#testing-your-tool)
- [How It Works](#how-it-works)

## Installation

1. Clone the repository:
    ```bash
    git clone https://github.com/Nivesh12345/wc-clone-.git
    ```
2. Navigate to the project directory:
    ```bash
    cd wc-clone-
    ```
3. Compile the code using a C++ compiler:
    ```bash
    g++ -o ccwc ccwc.cpp
    ```

## Usage

To use the tool, run the following command in your terminal:

```bash
./ccwc -[option] <filename>
```

### Available Options
- `-c`: Count the number of **bytes**.
- `-l`: Count the number of **lines**.
- `-w`: Count the number of **words**.
- `-m`: Count the number of **characters**.

## Example

To count the number of words in a file named `sample.txt`:

```bash
./ccwc -w sample.txt
```

Output:
```
42 sample.txt
```

## Testing Your Tool

To verify the correctness of your custom `wc` tool, you can use the provided test file named `test.txt`. You can download or create this file with known values. Here’s how you can check the values:

1. Count lines:
    ```bash
    ./ccwc -l test.txt
    ```
   
2. Count words:
    ```bash
    ./ccwc -w test.txt
    ```

3. Count bytes:
    ```bash
    ./ccwc -c test.txt
    ```

4. Count characters:
    ```bash
    ./ccwc -m test.txt
    ```

Make sure to compare the output with the expected results to confirm that your tool is working correctly.

## How It Works

- **File Handling:** The program reads files using standard C++ file streams.
- **Command-Line Arguments:** The user provides options (`-c`, `-l`, `-w`, `-m`) and a file name as command-line arguments.
- **Counting Logic:** Depending on the option, the program processes the file and outputs the corresponding count.
