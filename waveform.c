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