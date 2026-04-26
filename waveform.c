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
double getVPP_A( struct waveformsample *power_data , int rows  ) {
    double maximumVoltage = power_data->phase_A_voltage;
    double minimumVoltage = power_data->phase_A_voltage;

    for (int i = 1; i < rows; i++) {
        double voltage = (power_data + i)->phase_A_voltage;

        if (voltage > maximumVoltage)
            maximumVoltage = voltage;
        if (voltage < minimumVoltage)
            minimumVoltage = voltage;
    }
    double vpp = maximumVoltage - minimumVoltage;
    return vpp;
}
double getVPP_B( struct waveformsample *power_data , int rows  ) {
    double maximumVoltage = power_data->phase_B_voltage;
    double minimumVoltage = power_data->phase_B_voltage;

    for (int i = 1; i < rows; i++) {
        double voltage = (power_data + i)->phase_B_voltage;

        if (voltage > maximumVoltage)
            maximumVoltage = voltage;
        if (voltage < minimumVoltage)
            minimumVoltage = voltage;
    }
    double vpp = maximumVoltage - minimumVoltage;
    return vpp;
}
double getVPP_C( struct waveformsample *power_data , int rows  ) {
    double maximumVoltage = power_data->phase_C_voltage;
    double minimumVoltage = power_data->phase_C_voltage;

    for (int i = 1; i < rows; i++) {
        double voltage = (power_data + i)->phase_C_voltage;

        if (voltage > maximumVoltage)
            maximumVoltage = voltage;
        if (voltage < minimumVoltage)
            minimumVoltage = voltage;
    }
    double vpp = maximumVoltage - minimumVoltage;
    return vpp;
}

double getDC_Offset_phaseA( struct waveformsample *power_data , int rows  )
{
    //dc offest  ( mean values ) sum of all voltages /count
    double sum_value = 0; //to store total values of voltages in phase A
    for (int i = 1; i < rows; i++) {
        double voltage = (power_data + i)->phase_A_voltage;
        sum_value += voltage;  // sum_value = sum_value + voltage
    }
    return sum_value/rows;
}


double getDC_Offset_phaseB( struct waveformsample *power_data , int rows  )
{
    //dc offest  ( mean values ) sum of all voltages /count
    double sum_value = 0; //to store total values of voltages in phase B
    for (int i = 1; i < rows; i++) {
        double voltage = (power_data + i)->phase_B_voltage;
        sum_value += voltage;  // sum_value = sum_value + voltage
    }
    return sum_value/rows;
}

double getDC_Offset_phaseC( struct waveformsample *power_data , int rows  )
{
    //dc offest  ( mean values ) sum of all voltages /count
    double sum_value = 0; //to store total values of voltages in phase C
    for (int i = 1; i < rows; i++) {
        double voltage = (power_data + i)->phase_C_voltage;
        sum_value += voltage;  // sum_value = sum_value + voltage
    }
    return sum_value/rows;
}

int getClipping_number_phaseA( struct waveformsample *power_data , int rows  )
{
    int count=0; // store how many clipping in phase A
    for (int i = 1; i < rows; i++) {
        double voltage = (power_data + i)->phase_A_voltage;
        if  ( fabs (voltage) >= 324.9)
            count++;
    }
    return count;
}

int getClipping_number_phaseB( struct waveformsample *power_data , int rows  )
{
    int count=0; // store how many clipping in phase B
    for (int i = 1; i < rows; i++) {
        double voltage = (power_data + i)->phase_B_voltage;
        if  ( fabs (voltage) >= 324.9)
            count++;
    }
    return count;
}
int getClipping_number_phaseC( struct waveformsample *power_data , int rows  )
{
    int count=0; // store how many clipping in phase C
    for (int i = 1; i < rows; i++) {
        double voltage = (power_data + i)->phase_C_voltage;
        if  ( fabs (voltage) >= 324.9)
            count++;
    }
    return count;
}
