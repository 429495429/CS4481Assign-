#include "./store_huffman_encoded_data.h"

void store_huffman_encoded_data(char *compressed_file_name_ptr, int image_width, 
                        int image_height, int max_gray_value, int number_of_nodes, 
                        struct node *huffman_node, long int length_of_encoded_image_array, 
                        unsigned char *encoded_image){
    FILE *compressed_photo = fopen(compressed_file_name_ptr, "w+");
    if (compressed_photo == NULL) {
        printf("failed to open the file \n");
        exit(1);
    }
    // struct node aaa;
    // unsigned char c;
    fwrite(&image_height,sizeof(int),1,compressed_photo);//save the height
    printf("height: %d \n", image_height);
    fwrite(&image_width,sizeof(int),1,compressed_photo);//save the width
    printf("width: %d \n", image_width);
    fwrite(&max_gray_value,sizeof(int),1,compressed_photo);//save the max gray value
    printf("mg: %d \n", max_gray_value);
    fwrite(&number_of_nodes,sizeof(int),1,compressed_photo);//save the number of nodes
    printf("number of nodes: %d \n", number_of_nodes);
    for (int i=0; i<number_of_nodes; i++){
        struct node aaa;
        aaa.first_value=huffman_node[i].first_value;
        aaa.second_value=huffman_node[i].second_value;
        fwrite(&aaa,sizeof(struct node),1,compressed_photo);

        printf("%d %d %d \n",i,aaa.first_value, aaa .second_value);
    }
    // fwrite(huffman_node,sizeof(struct node),number_of_nodes,compressed_photo);//save the nodes array for decoding
    printf("success save nodes: %d \n", number_of_nodes);
    fwrite(&length_of_encoded_image_array,sizeof(long int),1,compressed_photo);//save the length of encoded data
    printf("lenghth of code: %d \n", length_of_encoded_image_array);
    // for (long int i=0; i<length_of_encoded_image_array; i++){
    //     c = encoded_image[i];
    //     fwrite(&c,sizeof(unsigned char),1,compressed_photo);
    //     // printf("%d %d %d \n",i,aaa.first_value, aaa .second_value);
    // }
    fwrite(encoded_image,sizeof(unsigned char),length_of_encoded_image_array,compressed_photo);//save the encoded data
    printf("success save codes %d \n", length_of_encoded_image_array);

    fclose(compressed_photo);
    return;
}