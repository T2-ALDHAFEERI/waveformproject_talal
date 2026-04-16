//
// Created by hp on 13/04/2026.
//

#include <stdio.h>
#include "io.h"
#include <stdlib.h>
#include "waveform.h"

struct waveformsample * readData (char *file_name , int *rows)
{
    FILE * power_data_file = fopen (file_name , "r"); // open fine in read mode


    char row_size[200] ; //maximum number of character in each row
    int number_rows=0;
    // skip header
    fgets (row_size, sizeof(row_size) ,power_data_file ); // to read one row ( header)

    //- count how many rows we have
    while (fgets (row_size, sizeof(row_size) ,power_data_file ))
    {
        number_rows++; // we added * before pointer name to increase its value
    }

    // until here we know how many rows we have in power_quality_log.csv stored in rows pointer

    // we need to allocate (reserve ) memory to store those rows
    struct waveformsample * power_data = malloc( number_rows * sizeof( struct waveformsample));



    // we can start storing data inside power_data

    //we should reset the cursor to the end of the file using rewind
    rewind(power_data_file);
    // skip header again
    fgets (row_size, sizeof(row_size) ,power_data_file ); // to read one row ( header

    //start storing/reading
    int index = 0 ;
    while (fgets (row_size, sizeof(row_size) ,power_data_file ))
    {
       //start storing
       sscanf(row_size , "%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf",
              &power_data[index].time_stamp,
              &power_data[index].phase_A_voltage,
              &power_data[index].phase_B_voltage,
              &power_data[index].phase_C_voltage,
              &power_data[index].line_current,
              &power_data[index].frequency,
              &power_data[index].power_factor,
              &power_data[index].the_percent);
            index++;
    }

    fclose(power_data_file);
    *rows = number_rows;
    return power_data;

}
