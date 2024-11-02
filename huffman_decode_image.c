#include "huffman_decode_image.h"

int convert_char_to_node (struct node *huffman_node, int number_of_nodes, unsigned char *huffman_codes_image_array, long int *index_of_code, long int length_of_encoded_image_array){
    
    //iterate all nodes
    int gray_value = -1;
    for(int i=number_of_nodes-1; i>-1; i--){
        int left = huffman_node[i].first_value;
        int right = huffman_node[i].second_value;
        unsigned char code = huffman_codes_image_array[(*index_of_code)];
        if(gray_value==-1){
            if(code == 0){
                gray_value = left;
                (*index_of_code)++;
                continue;
            }
            else if(code==1){
                gray_value = right;
                (*index_of_code)++;
                continue;
            }
        }
        if(gray_value == left||gray_value == right){
            if(code == 0){
                gray_value = left;
                (*index_of_code)++;
            }
            else if(code == 1){
                gray_value = right;
                (*index_of_code)++;
            }
        }
        
        

    }
    return gray_value;
}

struct PGM_Image *huffman_decode_image( int image_width, int image_height, int max_gray_value, 
                            int number_of_nodes, struct node *huffman_node, 
                            long int length_of_encoded_image_array, unsigned char *encoded_image){
    static struct PGM_Image PGMpc;
    if (create_PGM_Image(&PGMpc, image_width, image_height, max_gray_value) != 0) {
        printf("Failed creating\n");
        exit(1);
    }

    long int index = 0;
    int gray_value = 0;


    //set the whole image to black
    for (int row = 0; row < image_height; row++) {
        for (int col = 0; col < image_width; col++) {
            PGMpc.image[row][col] = convert_char_to_node(huffman_node,number_of_nodes,encoded_image,&index,length_of_encoded_image_array); // set the pixel to black
        }
    }

    printf(" success return pic\n");

    return &PGMpc;
}