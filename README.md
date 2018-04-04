# HuffmanCoding

This is huffman code implementation

It will only work for text files.

Here I have provided words.txt, which contains around 479k words and its size is 5.3 MB

Let's apply compression to words.txt

To compress:

- g++ -std=c++17 -o Encoding Encoding.cpp
- ./Encoding words.txt

Two files, words.txt_freqability and words.txt_compressed will be generated.
words.txt_compressed file is compressed file which is size of 3 MB.

To uncompress:

- g++ -std=c++17 -o Decoding Decoding.cpp
- ./Decoding words.txt_frequability words.txt_compressed

words.txt_uncompressed file will be generated.


This implementation is also limited to unix based system.
But you can modify the code for other system.

At implementation side,

- HuffmanCoding.hpp file contains common set of components required for Encoding.cpp and Decoding.cpp
  mainly, It will build huffman tree based upon freuquencies provided.
  
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

