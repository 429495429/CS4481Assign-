#include "./read_huffman_encoded_data.h"
unsigned char *read_huffman_encoded_data(char *compressed_file_name_ptr, int *image_width, 
                        int *image_height, int *max_gray_value, int *number_of_nodes, 
                        struct node **huffman_node, long int *length_of_encoded_image_array){
    FILE *compressed_photo = fopen(compressed_file_name_ptr,"r+");
    if (compressed_photo == NULL) {
        printf("failed to open the file \n");
        exit(1);
    }

    struct node aaa;
    printf(" %d %d \n",aaa.first_value, aaa.second_value);
    fread(image_height,sizeof(int),1,compressed_photo);//save the height
    printf("height: %d \n", *image_height);
    fread(image_width,sizeof(int),1,compressed_photo);//save the width
    printf("width: %d \n", *image_width);
    fread(max_gray_value,sizeof(int),1,compressed_photo);//save the max gray value
    printf("mg: %d \n", *max_gray_value);
    fread(number_of_nodes,sizeof(int),1,compressed_photo);//save the number of nodes
    *huffman_node = malloc((*number_of_nodes)* sizeof(struct node));
    for (int i=0; i<*number_of_nodes; i++){
        // struct node aaa;
        fread(&aaa,sizeof(struct node),1,compressed_photo);
        
        (*huffman_node)[i] = aaa;
        printf("%d %d %d \n",i,(*huffman_node)[i].first_value, (*huffman_node)[i] .second_value);
    }
    printf("success read the nodes: %ld \n", *number_of_nodes);
    printf("lenghth of code: %ld \n", (*length_of_encoded_image_array));
    fread(length_of_encoded_image_array, sizeof(long int), 1, compressed_photo);//save the length of encoded data
    printf("lenghth of code: %ld \n", (*length_of_encoded_image_array));

    unsigned char *encoded_image = (unsigned char *)calloc((*length_of_encoded_image_array), sizeof(unsigned char));
    fread(encoded_image,sizeof(unsigned char),(*length_of_encoded_image_array),compressed_photo);//save the encoded data
    printf("success read the code array with %ld\n", *length_of_encoded_image_array);

    fclose(compressed_photo);
    return encoded_image;
}