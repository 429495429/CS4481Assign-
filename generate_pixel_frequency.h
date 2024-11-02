#ifndef GENERATE_PIXEL_FREQUENCY_H
#define GENERATE_PIXEL_FREQUENCY_H

#include "pnm_library_01_2022/libpnm.h" 

long int *generate_pixel_frequency(struct PGM_Image *input_pgm_image, int *number_of_non_zero_values_in_the_frequency_array);

#endif