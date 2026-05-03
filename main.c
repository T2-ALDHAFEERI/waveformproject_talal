#include <stdio.h>
#include "io.h"
#include "waveform.h"
#include <stdlib.h>
int main(int arguments , char * arg[]) {
    char * file_name = arg[1]; //we read file name from program configuration arguemnt

    int rows_count=0; // we will count how many row ( except the header ) in this file
    struct waveformsample *power_data = readData(file_name , &rows_count);
    if(power_data == NULL)
    {
        printf("error reading the data");
        return 0;
    }

    write_result_file("result.txt",power_data,rows_count);

    free(power_data); // to free the data from memory
    return 0;


}

