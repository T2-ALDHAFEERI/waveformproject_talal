//
// Created by hp on 13/04/2026.
//

#ifndef TALALPOWERWAVE_PROJECT_WAVEFORM_H
#define TALALPOWERWAVE_PROJECT_WAVEFORM_H
struct  waveformsample
{
    double time_stamp;
    double phase_A_voltage;
    double phase_B_voltage;
    double phase_C_voltage;
    double line_current;
    double frequency;
    double power_factor;
    double the_percent;

};

double getRmsA ( struct waveformsample *power_data , int rows  );
double getRmsB ( struct waveformsample *power_data , int rows  );
double getRmsC ( struct waveformsample *power_data , int rows  );

#endif //TALALPOWERWAVE_PROJECT_WAVEFORM_H
