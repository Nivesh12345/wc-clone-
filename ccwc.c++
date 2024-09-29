#include <iostream>   // For input/output operations (e.g., cout, cerr)
#include <fstream>    // For file handling (e.g., ifstream to read files)
#include <string>     // For string manipulation (e.g., std::string)
#include <sstream>    // For handling string streams (used in countWords to split lines into words)
#include <vector>     // For using dynamic arrays (used in countChar to store file content)


using namespace std;

// Function to count the number of bytes in a file
void countBytes(const string& filename) {
    // Open the file in binary mode
    ifstream file(filename, ios::binary);

    // Check if file was successfully opened
    if(!file.is_open()) {
        cerr << "Error opening file" << endl;
        return;
    }

    // Move the file pointer to the end to get file size
    file.seekg(0, ios::end);

    // Get the position of the file pointer (file size)
    streampos fileSize = file.tellg();

    // Output the file size (in bytes) and the filename
    cout << fileSize << " " << filename << endl;

    // Close the file
    file.close();
}

// Function to count the number of lines in a file
void countLines(const string& filename) {
    // Open the file in text mode
    ifstream file(filename);

    // Check if file was successfully opened
    if(!file.is_open()) {
        cerr << "Error opening file" << endl;
        return;
    }

    string line;
    int lineCount = 0;

    // Count lines by reading the file line by line
    while(getline(file, line)) {
        lineCount++;
    }

    // Output the number of lines and the filename
    cout << lineCount << " " << filename << endl;

    // Close the file
    file.close();
}

// Function to count the number of words in a file
void countWords(const string& filename) {
    // Open the file in text mode
    ifstream file(filename);

    // Check if file was successfully opened
    if(!file.is_open()) {
        cerr << "Error opening file" << endl;
        return;
    }

    string line;
    int wordCount = 0;

    // Read the file line by line
    while(getline(file, line)) {
        // Use a string stream to extract words from each line
        istringstream iss(line);
        string word;

        // Count words in the current line
        while(iss >> word) {
            wordCount++;
        }
    }

    // Output the number of words and the filename
    cout << wordCount << " " << filename << endl;

    // Close the file
    file.close();
}

// Function to count the number of characters in a file (handling multi-byte characters)
void countChar(const string& filename) {
    // Open the file in binary mode to handle any character encoding
    ifstream file(filename, ios::binary);  
    if (!file.is_open()) {
        cerr << "Error opening file" << endl;
        return;
    }
    
    // Get the file size
    file.seekg(0, ios::end);
    streampos fileSize = file.tellg();
    file.seekg(0, ios::beg);

    // Read the entire file into a buffer
    vector<char> buffer(fileSize);
    file.read(buffer.data(), fileSize);

    int charCount = 0;

    // Count characters, ignoring continuation bytes in multi-byte characters (UTF-8 handling)
    for (char c : buffer) {
        if ((c & 0xC0) != 0x80) {  // Only count non-continuation bytes
            charCount++;
        }
    }

    // Output the number of characters and the filename
    cout << charCount << " " << filename << endl;

    // Close the file
    file.close();
}

// Main function to handle command line arguments and call respective counting functions
int main(int argc, char* argv[]) {
    // Check if the correct number of arguments is passed and call the appropriate function
    if (argc == 3 && string(argv[1]) == "-c") {
        countBytes(argv[2]);  // Call function to count bytes
    } else if (argc == 3 && string(argv[1]) == "-l") {
        countLines(argv[2]);  // Call function to count lines
    } else if (argc == 3 && string(argv[1]) == "-w") {
        countWords(argv[2]);  // Call function to count words
    } else if (argc == 3 && string(argv[1]) == "-m") {
        countChar(argv[2]);   // Call function to count characters
    } else {
        // If incorrect arguments are provided, print usage instructions
        cout << "Usage: ccwc -[c, l, w, m] <filename>" << endl;
    }

    return 0;
}
