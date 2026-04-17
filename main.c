#include <stdio.h>
#include "io.h"
#include "waveform.h"
int main() {
    char * file_name = "power_quality_log.csv"; //pointer char to store file name

    int rows_count=0; // we will count how many row ( except the header ) in this file
    struct waveformsample *power_data = readData(file_name , &rows_count);
    if(power_data == NULL)
    {
        printf("error reading the data");
    }

    double Rms_phaseA= getRmsA(power_data , rows_count);
    double Rms_phaseB= getRmsB(power_data , rows_count);
    double Rms_phaseC= getRmsC(power_data , rows_count);
    printf("Rms for phase A is %lf \n Rms for phase B is %lf \n Rms for phase C is %lf \n" ,
           Rms_phaseA , Rms_phaseB ,Rms_phaseC);

    return 0;


}

