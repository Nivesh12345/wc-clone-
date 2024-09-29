Custom wc Tool in C++
This project is a custom implementation of the Unix wc (word count) command-line tool, built in C++. It supports counting the number of lines, words, bytes, and characters in a file.

Features
Count lines (-l)
Count words (-w)
Count bytes (-c)
Count characters (-m)
Table of Contents
Installation
Usage
Example
How It Works
Installation
Clone the repository:
bash
Copy code
git clone https://github.com/[YourUsername]/[repository-name].git
Navigate to the project directory:
bash
Copy code
cd [repository-name]
Compile the code using a C++ compiler:
bash
Copy code
g++ -o ccwc ccwc.cpp
Usage
To use the tool, run the following command in your terminal:

bash
Copy code
./ccwc -[option] <filename>
Available Options
-c: Count the number of bytes.
-l: Count the number of lines.
-w: Count the number of words.
-m: Count the number of characters.
Example
To count the number of words in a file named sample.txt:

bash
Copy code
./ccwc -w sample.txt
Output:

Copy code
42 sample.txt
How It Works
File Handling: The program reads files using standard C++ file streams.
Command-Line Arguments: The user provides options (-c, -l, -w, -m) and a file name as command-line arguments.
Counting Logic: Depending on the option, the program processes the file and outputs the corresponding count.
