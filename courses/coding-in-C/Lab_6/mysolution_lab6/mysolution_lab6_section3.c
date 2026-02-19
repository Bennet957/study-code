#include <stdio.h> 
#include <stdlib.h>

typedef struct {
    float time;
    double probability;
} SensorData;

typedef struct {
    int id;
    double threshold;
    SensorData *data;
    int object_detection;
} Sensor;

int main() {
    FILE *file1 = fopen("sensor1.txt", "r");
    if (file1 == NULL) {
        printf("Fehler beim Öffnen der ersten Datei.\n");
        return 1;
    }

    FILE *file2 = fopen("sensor2.txt", "r");
    if (file2 == NULL) {
        printf("Fehler beim Öffnen der zweiten Datei.\n");
        fclose(file1);
        return 1;
    }

    // Speicher anfordern
    Sensor *sensor1 = malloc(sizeof(Sensor));
    Sensor *sensor2 = malloc(sizeof(Sensor));
    if (!sensor1 || !sensor2) {
        printf("Speicher konnte nicht reserviert werden.\n");
        fclose(file1);
        fclose(file2);
        free(sensor1);
        free(sensor2);
        return 1;
    }

    sensor1->data = malloc(sizeof(SensorData));
    sensor2->data = malloc(sizeof(SensorData));
    if (!sensor1->data || !sensor2->data) {
        printf("Speicher für Sensordaten konnte nicht reserviert werden.\n");
        fclose(file1);
        fclose(file2);
        free(sensor1->data);
        free(sensor2->data);
        free(sensor1);
        free(sensor2);
        return 1;
    }

    sensor1->threshold = 0.8;
    sensor2->threshold = 0.7;

    /* --------- dein Teil: Sensor1 detections --------- */
    printf("Sensor1 detections");

    int prev1 = 0;
    float start1 = 0.0f;

    while (fscanf(file1, "%f %lf", &sensor1->data->time, &sensor1->data->probability) == 2) {
        int now1 = (sensor1->data->probability > sensor1->threshold);
        float t1 = sensor1->data->time;

        if (now1 && !prev1) {
            sensor1->object_detection = 1;
            start1 = t1;
            printf(" Start: %.2f", t1);
        } else if (!now1 && prev1) {
            sensor1->object_detection = 0;
            printf(" End: %.2f", t1);
        }

        prev1 = now1;
    }
    // falls Detection bis zum Dateiende aktiv bleibt
    if (prev1) {
        printf(" End: %.2f", sensor1->data->time);
    }

    /* --------- dein Teil: Sensor2 detections --------- */
    printf("\n\n\nSensor2 detections");

    int prev2 = 0;
    float start2 = 0.0f;

    while (fscanf(file2, "%f %lf", &sensor2->data->time, &sensor2->data->probability) == 2) {
        int now2 = (sensor2->data->probability > sensor2->threshold);
        float t2 = sensor2->data->time;

        if (now2 && !prev2) {
            sensor2->object_detection = 1;
            start2 = t2;
            printf(" Start: %.2f", t2);
        } else if (!now2 && prev2) {
            sensor2->object_detection = 0;
            printf(" End: %.2f", t2);
        }

        prev2 = now2;
    }
    // falls Detection bis zum Dateiende aktiv bleibt
    if (prev2) {
        printf(" End: %.2f", sensor2->data->time);
    }
    /* <<< WICHTIG: HIER war die fehlende KLAMMER im Original (Sensor2 while) >>> */

    rewind(file1);
    rewind(file2);

    int both_prev = 0;
    float both_start = 0.0f;

    printf("\n\nOverlaps (beide gleichzeitig):\n");

    while (fscanf(file1, "%f %lf", &sensor1->data->time, &sensor1->data->probability) == 2 &&
           fscanf(file2, "%f %lf", &sensor2->data->time, &sensor2->data->probability) == 2) {

        int s1 = (sensor1->data->probability > sensor1->threshold);
        int s2 = (sensor2->data->probability > sensor2->threshold);
        int both_now = (s1 && s2);

        // Annahme: gleiche Zeit pro Zeile -> wir nehmen Zeit von Sensor1
        float t = sensor1->data->time;

        if (both_now && !both_prev) {
            both_start = t; // Overlap beginnt
        } else if (!both_now && both_prev) {
            printf("Start %.2f  End %.2f\n", both_start, t); // Overlap endet
        }

        both_prev = both_now;
    }

    // falls Overlap bis zum Dateiende aktiv bleibt
    if (both_prev) {
        printf("Start %.2f  End %.2f\n", both_start, sensor1->data->time);
    }

    fclose(file1);
    fclose(file2);
    free(sensor1->data);
    free(sensor2->data);
    free(sensor1);
    free(sensor2);

    return 0;
}
