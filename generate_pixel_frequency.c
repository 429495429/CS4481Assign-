#include "./generate_pixel_frequency.h"

long int *generate_pixel_frequency(struct PGM_Image *input_pgm_image, int *number_of_non_zero_values_in_the_frequency_array) {
    int width = input_pgm_image->width;
    int height = input_pgm_image->height;
    int maxGrayValue = input_pgm_image->maxGrayValue;
    
    // Allocate the long int array
    long int *frequency_array = (long int *)calloc(maxGrayValue + 1, sizeof(long int));
    if (frequency_array == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for frequency array\n");
        exit(1);
    }

    // Initialize the count of non-zero frequency values
    *number_of_non_zero_values_in_the_frequency_array = 0;

    // Iterate over all pixels
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int pixel_value = input_pgm_image->image[i][j];
            frequency_array[pixel_value]++;
        }
    }

    // Count the non-zero values in the frequency array
    for (int i = 0; i <= maxGrayValue; i++) {
        if (frequency_array[i] != 0) {
            (*number_of_non_zero_values_in_the_frequency_array)++;
        }
    }

    // Return the pointer to the frequency array
    return frequency_array;
}