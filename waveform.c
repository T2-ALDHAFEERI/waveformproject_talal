//
// Created by hp on 13/04/2026.
//

#include "waveform.h"
#include <math.h>
double getRmsA ( struct waveformsample *power_data , int rows  )
{
    double rms =0;
    double totalVoltages=0;
    for ( int i =0 ; i < rows ; i++)
    {
        double square=(power_data+i)->phase_A_voltage * (power_data+i)->phase_A_voltage ;
        totalVoltages = totalVoltages + square;
    }
    double meanValue = totalVoltages /rows ;
    rms=sqrt(meanValue);
    return rms;
}

double getRmsB ( struct waveformsample *power_data , int rows  )
{
    double rms =0;
    double totalVoltages=0;
    for ( int i =0 ; i < rows ; i++)
    {
        double square=(power_data+i)->phase_B_voltage * (power_data+i)->phase_B_voltage ;
        totalVoltages = totalVoltages + square;
    }
    double meanValue = totalVoltages /rows ;
    rms=sqrt(meanValue);
    return rms;
}

double getRmsC ( struct waveformsample *power_data , int rows  )
{
    double rms =0;
    double totalVoltages=0;
    for ( int i =0 ; i < rows ; i++)
    {
        double square=(power_data+i)->phase_C_voltage * (power_data+i)->phase_C_voltage ;
        totalVoltages = totalVoltages + square;
    }
    double meanValue = totalVoltages /rows ;
    rms=sqrt(meanValue);
    return rms;
}