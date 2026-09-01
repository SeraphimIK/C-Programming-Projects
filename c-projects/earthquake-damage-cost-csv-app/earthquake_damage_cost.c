/*
 * Project 5 - Earthquake Damage Cost App (File Handling / CSV)
 * Student: Seraphim Ikuomola
 * System Date: (printed at runtime)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(void) {
    char buffer[2048];
    char *data;
    int count = 0;
    float magnitude;
    float sum   = 0.0f;
    float minMag = 0.0f;
    float maxMag = 0.0f;
    int   first  = 1;
    double totalCost = 0.0;
    int    choice;
    char   filename[64];
    int    i, skip;

    /* --- System date --- */
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    char dateStr[32];
    strftime(dateStr, sizeof(dateStr), "%B %d, %Y", tm_info);

    printf("\n==============================================\n");
    printf("  Earthquake Damage Cost App\n");
    printf("  Student: Seraphim Ikuomola\n");
    printf("  Date: %s\n", dateStr);
    printf("==============================================\n\n");

    /* --- EXTRA POINTS: user selects dataset --- */
    printf("Select Earthquake Dataset:\n");
    printf("  1. All Earthquakes   (all_month.csv)\n");
    printf("  2. Significant Only  (significant_month.csv)\n");
    printf("Enter 1 or 2: ");
    scanf("%d", &choice);

    if (choice == 2)
        strcpy(filename, "significant_month.csv");
    else
        strcpy(filename, "all_month.csv");

    FILE *USGSfile = fopen(filename, "r");
    if (USGSfile == NULL) {
        printf("Error: Could not open '%s'\n", filename);
        exit(-1);
    }
    printf("\nOpened file: %s\n", filename);

    /* --- Skip header row --- */
    if (!fgets(buffer, sizeof(buffer), USGSfile)) {
        printf("File is empty.\n");
        fclose(USGSfile);
        return 0;
    }

    printf("\nPlace\n\n");

    /* -------------------------------------------------------
     * USGS CSV column layout (0-indexed):
     *  0=time  1=lat  2=lon  3=depth  4=mag  5=magType
     *  6=nst   7=gap  8=dmin 9=rms   10=net 11=id
     * 12=updated  13=place  14=type ...
     * ------------------------------------------------------- */
    while (fgets(buffer, sizeof(buffer), USGSfile)) {
        skip = 0;

        /* col 0 - time */
        data = strtok(buffer, ",");
        if (data == NULL) continue;
        char time_str[64];
        strncpy(time_str, data, sizeof(time_str) - 1);
        time_str[sizeof(time_str) - 1] = '\0';

        /* skip cols 1-3 (lat, lon, depth) */
        for (i = 0; i < 3; i++) {
            data = strtok(NULL, ",");
            if (data == NULL) { skip = 1; break; }
        }
        if (skip) continue;

        /* col 4 - mag */
        data = strtok(NULL, ",");
        if (data == NULL || data[0] == '\0') continue;
        magnitude = (float)atof(data);
        if (magnitude <= 0.0f) continue;

        /* skip cols 5-12 (magType, nst, gap, dmin, rms, net, id, updated) */
        for (i = 0; i < 8; i++) {
            data = strtok(NULL, ",");
            if (data == NULL) { skip = 1; break; }
        }
        if (skip) continue;

        /* col 13 - place */
        data = strtok(NULL, ",");
        if (data == NULL) continue;
        char place[256];
        strncpy(place, data, sizeof(place) - 1);
        place[sizeof(place) - 1] = '\0';

        /* Handle quoted place names that contain commas */
        if (place[0] == '"') {
            size_t plen = strlen(place);
            if (plen == 0 || place[plen - 1] != '"') {
                char *extra = strtok(NULL, ",");
                if (extra != NULL) {
                    strncat(place, ",", sizeof(place) - strlen(place) - 1);
                    strncat(place, extra, sizeof(place) - strlen(place) - 1);
                }
            }
        }
        place[strcspn(place, "\r\n")] = '\0';
        /* Strip surrounding quotes */
        size_t plen = strlen(place);
        if (plen >= 2 && place[0] == '"' && place[plen - 1] == '"') {
            memmove(place, place + 1, plen - 2);
            place[plen - 2] = '\0';
        }

        /* --- FIXED cost formula: pow(magnitude,3) x 1000000 --- */
        double cost = pow((double)magnitude, 3.0) * 1000000.0;

        printf("Time: %s, Magnitude: %.2f, Cost:$%.2f, Place: %s\n",
               time_str, magnitude, cost, place);

        /* --- Statistics accumulators --- */
        count++;
        sum += magnitude;
        totalCost += cost;
        if (first || magnitude < minMag) minMag = magnitude;
        if (first || magnitude > maxMag) maxMag = magnitude;
        first = 0;
    }

    fclose(USGSfile);

    printf("\n==============================================\n");
    if (count > 0) {
        float  avgMag  = sum / (float)count;
        double avgCost = totalCost / (double)count;
        double minCost = pow((double)minMag, 3.0) * 1000000.0;
        double maxCost = pow((double)maxMag, 3.0) * 1000000.0;

        printf("Magnitude Statistics => Sum = %.2f, Count = %d, Average magnitude = %.2f\n",
               sum, count, avgMag);
        printf("                        Min = %.2f, Max = %.2f\n", minMag, maxMag);
        printf("Average Earthquake cost = $%.2f\n", avgCost);
        printf("Min Earthquake cost     = $%.2f\n", minCost);
        printf("Max Earthquake cost     = $%.2f\n", maxCost);
    } else {
        printf("No positive magnitude records found.\n");
    }
    printf("==============================================\n");

    return 0;
}
