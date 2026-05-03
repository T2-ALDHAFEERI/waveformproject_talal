Three-Phase Power Quality Waveform Analyzer
Description
This program reads a CSV file with three-phase power quality measurements and calculates:

RMS voltage for each phase

Peak-to-peak voltage for each phase

DC offset for each phase

Number of clipping points

Checks if voltages are within 10% tolerance (230V ±10%)

Files
File	Purpose
main.c	Program entry point
io.h / io.c	File reading and writing
waveform.h / waveform.c	Waveform analysis calculations
Requirements
C compiler (GCC)

CLion IDE (or any C IDE)

CSV input file with 8 columns

How to Run in CLion
Open CLion

Click File → Open and select the project folder

Wait for CMake to load

Go to Run → Edit Configurations

In Program arguments box, type the CSV filename: power_quality_log.csv

Click Apply then OK

Click the green Run button (or press Shift+F10)

Input File Format
CSV file with header and 8 columns:

text
timestamp,phase_A_voltage,phase_B_voltage,phase_C_voltage,line_current,frequency,power_factor,percent
0.001,325.27,322.5,326.1,10.5,50.0,0.95,100
0.002,320.15,324.8,322.3,10.2,50.1,0.94,99
Output
Program creates result.txt file containing:

RMS voltages for all phases

Peak-to-peak voltages

DC offset values

Clipping counts

Tolerance check results (Pass/Fail)

Example Output
result.txt
Rms for phase A is 229.809704 
 Rms for phase B is 229.809704 
 Rms for phase C is 229.809704 
VPP for phase A is 650.000000 
 VPP for phase B is 649.857444 
 VPP for phase C is 649.857444 
Dc offset for phase A is -0.000000 
 Dc offset for phase B is -0.281458 
 Dc offset for phase C is 0.281458 
Clipping for phase A is 20 
 Clipping for phase B is 20 
 Clipping for phase C is 20 
Phase A is within 10 percent tolerance 
Phase B is within 10 percent tolerance 
Phase C is within 10 percent tolerance 
