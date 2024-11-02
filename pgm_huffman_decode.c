#include <stdio.h>
#include <stdlib.h>

#include "pnm_library_01_2022/libpnm.h"
#include "./huffman_decode_image.h"

int main(int argc, char *argv[]){
    printf("A ha! \n");
    if (argc != 3) {
        printf("Please input in format: %s <filename> <imagename> \n", argv[0]);
        return 1;
    }
    char *filename = argv[1];
    char *imagename = argv[2];

    printf("import file %s \n",filename);
    printf("imagename %s \n",imagename);

    int image_width =0;
    int image_height=0;
    int max_gray_value=0;
    int number_of_nodes;
    struct node *huffman_node; 
    long int length_of_encoded_image_array;
    unsigned char *encode_data = read_huffman_encoded_data(filename,&image_width,&image_height,&max_gray_value,&number_of_nodes,&huffman_node,&length_of_encoded_image_array);

    struct PGM_Image *PGMpc;
    PGMpc = huffman_decode_image(image_width,image_height,max_gray_value,number_of_nodes,huffman_node,length_of_encoded_image_array,encode_data);

    printf(" try save pic\n");

    //save the image
    save_PGM_Image(PGMpc, imagename, true);
    
    printf(" success save pic\n");

    //free the memory
    free_PGM_Image(PGMpc);
    printf(" free pic\n");
    return 0;
}