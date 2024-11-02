#ifndef HUFFMAN_DECODED_IMAGE_H
#define HUFFMAN_DECODED_IMAGE_H

#include "read_huffman_encoded_data.h"

struct PGM_Image *huffman_decode_image( int image_width, int image_height, int max_gray_value, 
                            int number_of_nodes, struct node *huffman_node, 
                            long int length_of_encoded_image_array, unsigned char *encoded_image);

#endif