# HuffmanCoding

This is huffman code implementation

It will only work for text files.
 

To compress:

- compile Encoding.cpp.
-  ./Encoding <your text file>

Here two files will be generated <your text file>_frequalibility, <your text file>_compressed

To uncompress:

- compile Decoding.cpp
- ./Decoding <your text file>_frequalibility, <your text file>_compressed.

Example:

To compress:

- g++ -std=c++17 -o Encoding Encoding.cpp
- ./Encoding words.txt

Two files, words.txt_freqability and words.txt_compressed will be generated.

To uncompress:

- g++ -std=c++17 -o Decoding Decoding.cpp
- ./Decoding words.txt_frequability words.txt_compressed

words.txt_uncompressed file will be generated.



This implementation is also limited to unix based system.
But you can modify the code for other system.

At implementation side,

- HuffmanCoding.hpp contains common set of components required for Encoding.cpp and Decoding.cpp
  mainly, It builds huffman tree structure based upon freuquencies provided.
  
  It provides Huffman Tree via configure() call.
  configure() call return pointer to root of huffman tree.

  Every huffman tree node is defined via "node" strucutre which contains

  l      -    letter symbol
  is_l   -    is there letter symbol (only external nodes will have letter symbol)
  height -    height of the node
  freq   -    frequency of the letter in file
  left   -    pointer to left subtree
  right  -    pointer to right subtree


- Any imporvement in the code is highly appreciated.  

