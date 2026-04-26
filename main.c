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


    double vpp_A= getVPP_A(power_data,rows_count);
    double vpp_B= getVPP_B(power_data,rows_count);
    double vpp_C= getVPP_C(power_data,rows_count);
    printf("VPP for phase A is %lf \n VPP for phase B is %lf \n VPP for phase C is %lf \n" ,
           vpp_A , vpp_B ,vpp_C);

    double offset_A= getDC_Offset_phaseA(power_data,rows_count);
    double offset_B= getDC_Offset_phaseB(power_data,rows_count);
    double offset_C= getDC_Offset_phaseC(power_data,rows_count);
    printf("Dc offset for phase A is %lf \n Dc offset for phase B is %lf \n Dc offset for phase C is %lf \n" ,
           offset_A , offset_B ,offset_C);

    int Clipping_number_phaseA=getClipping_number_phaseA(power_data,rows_count);
    int Clipping_number_phaseB=getClipping_number_phaseB(power_data,rows_count);
    int Clipping_number_phaseC=getClipping_number_phaseC(power_data,rows_count);

    printf("Clipping for phase A is %d \n Clipping for phase B is %d \n Clipping for phase C is %d \n" ,
           Clipping_number_phaseA , Clipping_number_phaseB ,Clipping_number_phaseC);
    return 0;


}

