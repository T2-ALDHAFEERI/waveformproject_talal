#include <stdio.h>
#include "io.h"
#include "waveform.h"
int main() {
    char * file_name = "power_quality_log.csv"; //pointer char to store file name

    int rows=0; // we will count how many row ( except the header ) in this file
    struct waveformsample *power_data = readData(file_name , &rows);
    if(power_data == NULL)
    {
        printf("error reading the data");
    }
    else
    {

        printf("time %.4f \n" , power_data[0].time_stamp);
        printf("phase a %.4f \n" , power_data[0].phase_A_voltage);
        printf("phase b %.4f \n" , power_data[0].phase_B_voltage);
        printf("number of read rows is %d \n" , rows);

    }
    return 0;


}

