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
void write_result_file (char * filename , struct waveformsample *power_data , int rows_count  )
{
    FILE * result_file = fopen (filename,"w");

    double Rms_phaseA= getRmsA(power_data , rows_count);
    double Rms_phaseB= getRmsB(power_data , rows_count);
    double Rms_phaseC= getRmsC(power_data , rows_count);
    fprintf(result_file,"Rms for phase A is %lf \n Rms for phase B is %lf \n Rms for phase C is %lf \n" ,
           Rms_phaseA , Rms_phaseB ,Rms_phaseC);


    double vpp_A= getVPP_A(power_data,rows_count);
    double vpp_B= getVPP_B(power_data,rows_count);
    double vpp_C= getVPP_C(power_data,rows_count);
    fprintf(result_file,"VPP for phase A is %lf \n VPP for phase B is %lf \n VPP for phase C is %lf \n" ,
           vpp_A , vpp_B ,vpp_C);

    double offset_A= getDC_Offset_phaseA(power_data,rows_count);
    double offset_B= getDC_Offset_phaseB(power_data,rows_count);
    double offset_C= getDC_Offset_phaseC(power_data,rows_count);
    fprintf(result_file,"Dc offset for phase A is %lf \n Dc offset for phase B is %lf \n Dc offset for phase C is %lf \n" ,
           offset_A , offset_B ,offset_C);

    int Clipping_number_phaseA=getClipping_number_phaseA(power_data,rows_count);
    int Clipping_number_phaseB=getClipping_number_phaseB(power_data,rows_count);
    int Clipping_number_phaseC=getClipping_number_phaseC(power_data,rows_count);

    fprintf(result_file,"Clipping for phase A is %d \n Clipping for phase B is %d \n Clipping for phase C is %d \n" ,
           Clipping_number_phaseA , Clipping_number_phaseB ,Clipping_number_phaseC);
    printf("written successfully");

    if(Rms_phaseA >= 209 && Rms_phaseA <=253)
        fprintf(result_file,"Phase A is within 10 percent tolerance \n");
    else
        fprintf(result_file,"Phase A is NOT within 10 percent tolerance \n");

    if(Rms_phaseB >= 209 && Rms_phaseB <=253)
        fprintf(result_file,"Phase B is within 10 percent tolerance \n");
    else
        fprintf(result_file,"Phase B is NOT within 10 percent tolerance \n");

    if(Rms_phaseC >= 209 && Rms_phaseC <=253)
        fprintf(result_file,"Phase C is within 10 percent tolerance \n");
    else
        fprintf(result_file,"Phase C is NOT within 10 percent tolerance \n");
    fclose(result_file);
}
