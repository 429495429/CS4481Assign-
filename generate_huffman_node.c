#include <stdio.h>
#include <stdlib.h>
#include "./generate_huffman_node.h"

// help function, find out the two grayvalue with smallest frequency
void find_two_smallest(long int *pixel_frequency, int size, int *first, int *second) {
    *first = -1;
    *second = -1;

    for (int i = 0; i < size; i++) {
        if (pixel_frequency[i] > 0) {
            if (*first == -1 || pixel_frequency[i] < pixel_frequency[*first]) {
                *second = *first;
                *first = i;
            } else if (*second == -1 || pixel_frequency[i] < pixel_frequency[*second]) {
                *second = i;
            }
        }
    }
}

struct node *generate_huffman_nodes (long int *pixel_frequency, int max_gray_value, int number_of_non_zero_values_in_the_frequency_array) {
    // Allocate the struct node array
    struct node *huffman_nodes = (struct node *)malloc((number_of_non_zero_values_in_the_frequency_array - 1) * sizeof(struct node));
    if (huffman_nodes == NULL) {
        fprintf(stderr, "Error: Memory allocation for huffman nodes failed\n");
        exit(1);
    }

    // make a temp copy of frequency array
    long int *temp = (long int *)malloc((max_gray_value + 1) * sizeof(long int));
    if (temp == NULL) {
        fprintf(stderr, "Error: Memory allocation for temp frequency array failed\n");
        exit(1);
    }
    for (int i = 0; i <= max_gray_value; i++) {
        temp[i] = pixel_frequency[i];
    }

    // construct huffman tree
    for (int i = 0; i < number_of_non_zero_values_in_the_frequency_array - 1; i++) {
        int first, second;
        find_two_smallest(temp, max_gray_value + 1, &first, &second);

        // combine the two smallest value
        huffman_nodes[i].first_value = first;
        huffman_nodes[i].second_value = second;
        // printf(" %d %d \n",huffman_nodes[i].first_value, huffman_nodes[i] .second_value);
        // add the combined value together and mark the second one be used
        temp[first] += temp[second];
        temp[second] = 0;  
    }

    // free the temp array
    free(temp);

    return huffman_nodes;
}