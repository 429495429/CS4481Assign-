#include <stdio.h>
#include <stdlib.h>
// #include "./generate_pixel_frequency.h"
// #include "./generate_huffman_node.h"
// #include "./huffman_encode_image.h"
#include "pnm_library_01_2022/libpnm.h"
#include "./store_huffman_encoded_data.h"

int main(int argc, char *argv[]){
    printf("A ha! \n");
    if (argc != 3) {
        printf("Please input in format: %s <imagename> <filename>\n", argv[0]);
        return 1;
    }
    char *imagename = argv[1];
    char *filename = argv[2];

    printf("imagename %s \n",imagename);
    printf("export file %s \n",filename);

    struct PGM_Image pic;
    load_PGM_Image(&pic,imagename);
    int width = pic.width;
    int height = pic.height;
    int maxGrayValue = pic.maxGrayValue;
    printf("success loading picture \n");

    int non_zero_values_in_frequency_array = 0;
    long int *pixel_frequency_array = generate_pixel_frequency(&pic,&non_zero_values_in_frequency_array);
    printf("success generate frequency array %d \n", non_zero_values_in_frequency_array);
    struct node *huffman_node_array = generate_huffman_nodes(pixel_frequency_array,maxGrayValue
    ,non_zero_values_in_frequency_array);
    int number_of_nodes = non_zero_values_in_frequency_array-1;
    printf("success generate node array %d \n", number_of_nodes);
    long int length_of_encode_image_array = 0;
    
    unsigned char *huffman_encode_image_array = huffman_encode_image(&pic,huffman_node_array,number_of_nodes,&length_of_encode_image_array);
    printf("success code array with %d length\n", length_of_encode_image_array);
    store_huffman_encoded_data(filename,width,height,maxGrayValue,number_of_nodes,huffman_node_array,length_of_encode_image_array,huffman_encode_image_array);
    printf("success save codes in file %s \n", filename);

    return 0;
}