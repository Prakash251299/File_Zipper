## File Zipper using Huffman Encoding

## Overview

This project implements a file compression and decompression tool using Huffman Encoding. Huffman Encoding is a lossless data compression algorithm that efficiently encodes data by assigning shorter codes to more frequent characters.

## Features

Compresses files using Huffman Encoding.

Decompresses compressed files to restore original data.

Supports text-based files.

Efficient storage and retrieval using a binary tree-based encoding scheme.

## How It Works

Frequency Analysis: The algorithm scans the input file to determine character frequencies.

Huffman Tree Construction: A min-heap is used to build a Huffman Tree based on character frequencies.

Encoding Generation: Unique binary codes are assigned to each character.

Compression: The input file is converted into a binary representation using Huffman codes.

Decompression: The compressed binary file is decoded using the Huffman tree to restore the original data.

## Installation

To use this project, follow these steps:

- Clone this repository:

```git clone https://github.com/yourusername/file-zipper.git``` \
```cd file-zipper```

Ensure you have a C/C++ compiler installed (e.g., GCC for Linux/macOS, MinGW for Windows).

- Compile the project:

```g++ -o filezipper filezipper.cpp```

## Usage

Compress a File

```./filezipper -c input.txt output.bin```

input.txt is the file to be compressed.

output.bin is the output compressed file.

## Decompress a File

```./filezipper -d compressed.bin output.txt```

output.bin is the file to be decompressed.

output.txt is the restored file.

## File Format

The compressed file consists of a header storing the Huffman tree structure followed by the encoded data.

## Dependencies

Standard C libraries (stdio, fstream, stdlib, string, bitset).

## Future Enhancements

Support for binary files.

GUI-based interface.

Multi-threaded compression for large files.

## License

This project is licensed under the MIT License.

## Contributing

Feel free to fork this repository and submit pull requests with improvements!

## Author

Prakash Pratap Singh
