//
// Created by hp on 13/04/2026.
//

#ifndef TALALPOWERWAVE_PROJECT_IO_H
#define TALALPOWERWAVE_PROJECT_IO_H

struct waveformsample * readData (char *file_name , int * rows); //header

void write_results(char *file_name , int rows  );

#endif //TALALPOWERWAVE_PROJECT_IO_H
