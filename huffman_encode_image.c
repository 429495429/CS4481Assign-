#include "./huffman_encode_image.h"

//helper funcion to convert node to charset
void convert_node_to_char (struct node *huffman_node, int number_of_nodes, int gray_value, unsigned char *huffman_codes_image_array, long int *length_of_encoded_image_array){
    
    int length_of_code = 0;
    unsigned char *code = (unsigned char *)calloc(8, sizeof(char));
    //iterate all nodes to get the code of the gray value
    for(int i=0; i<number_of_nodes; i++){
        int left = huffman_node[i].first_value;
        int right = huffman_node[i].second_value;
        if(gray_value == left){
            code[length_of_code] = 0;
            length_of_code++;
        }
        //swap the temp if the value combined to right in this node
        if(gray_value == right){
            code[length_of_code] = 1;
            length_of_code++;
            gray_value = left;
        }
    }
    for(int i=length_of_code-1; i>-1; i--){
        huffman_codes_image_array[(*length_of_encoded_image_array)] = code[i];

        (*length_of_encoded_image_array)++;
    }

    
}

unsigned char *huffman_encode_image(struct PGM_Image *input_pgm_image, struct node *huffman_node, int number_of_nodes, long int *length_of_encoded_image_array){
    int width = input_pgm_image->width;
    int height = input_pgm_image->height;
    int maxGrayValue = input_pgm_image->maxGrayValue;
    unsigned char *huffman_codes_image_array = (unsigned char *)calloc(width * height * 8, sizeof(char));
    *length_of_encoded_image_array = 0;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int pixel_value = input_pgm_image->image[i][j];
            // get the code
            convert_node_to_char(huffman_node,number_of_nodes,pixel_value,huffman_codes_image_array, length_of_encoded_image_array);
            
        }
    }
    printf("\n length_of_encoded_image_array: %d \n", *length_of_encoded_image_array);
    return huffman_codes_image_array;
}