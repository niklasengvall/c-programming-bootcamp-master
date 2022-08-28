#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <math.h>

#define LEN 10

typedef struct Sample
{
    double temperature;
    time_t timestamp;
} Sample;

int randRangeInt(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

double randRange(double min, double max, int decimalDigits)
{
    double scaleFactor = pow(10, decimalDigits);
    int scaledMin = round(min * scaleFactor);
    int scaledMax = round(max * scaleFactor);
    return randRangeInt(scaledMin, scaledMax) / scaleFactor;
}

double getTemperature()
{
    return randRange(20, 25, 2);
}

int main()
{
    printf("\n=== Arrays Of Structures ===\n\n");

    // Let's build a temperature logger: we need temperature and timestamp

    Sample samples[LEN];

    // Lets make some samples
    for (int i = 0; i < LEN; i++)
    {
        printf("Sample %d...\n", i);
        samples[i].timestamp = time(NULL);
        samples[i].temperature = getTemperature();
        sleep(1); // form unistd.h
    }
    
    // Print: timestamp, time offset from first sample, temperature
    printf("\ntimestamp, time offset, temp\n");

    for (int i = 0; i < LEN; i++)
    {
        printf("%ld, %ld, %5.2f\n", 
                samples[i].timestamp,
                samples[i].timestamp - samples[0].timestamp,
                samples[i].temperature);
    }
    

    printf("\n\n=== ByteGarage ===\n\n");
    return EXIT_SUCCESS;
}

