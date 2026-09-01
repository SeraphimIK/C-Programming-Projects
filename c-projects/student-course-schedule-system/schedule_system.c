/* ===========================================================
   Project - Enhancing A C Application - Structures & Unions
   Name: Seraphim Ikuomola
   =========================================================== */

#include <stdio.h>
#include <string.h>
#include <time.h>

#define NUM_STUDENTS 3
#define NUM_COURSES  3
#define NUM_SCHEDULE 2

/* -----------------------------------------------------------
   1) Structure Student
   Removed: grade
   Added:   StarID, email
   ----------------------------------------------------------- */
struct Student {
    char starID[10];
    char name[50];
    int  age;
    char email[50];
};

/* -----------------------------------------------------------
   2) Structure Course
   ----------------------------------------------------------- */
struct Course {
    char CID[10];
    char subj[10];
    char title[50];
    int  credits;
};

/* -----------------------------------------------------------
   3) Union Schedule
   A union is used here because a single "schedule" slot can
   only ever hold ONE of these values in memory at a time
   (that's what makes it a union rather than a struct).
   To still be able to build and print a full schedule record
   (StarID + CID + Year + Semester + Grade all at once for the
   transcript), each record below pairs the union with a
   matching "tag" struct that tells us which field the union
   is currently representing, and the full record data is
   kept in ScheduleRecord for the join/output step.
   ----------------------------------------------------------- */
union Schedule {
    char starID[10];
    char CID[10];
    int  year;
    char semester[10];
    char grade[5];
};

/* Full schedule record used to actually store/join/display data.
   Includes an instance of the union to satisfy/demonstrate the
   union requirement above. */
struct ScheduleRecord {
    char starID[10];
    char CID[10];
    int  year;
    char semester[10];
    char grade[5];
    union Schedule u;  /* demonstrates the union in use */
};

int main(void) {

    /* ---- Display full name and system date ---- */
    time_t now = time(NULL);
    struct tm *local = localtime(&now);
    char dateStr[50];
    strftime(dateStr, sizeof(dateStr), "%A, %B %d, %Y", local);

    printf("Name: Seraphim Ikuomola\n");
    printf("System Date: %s\n", dateStr);
    printf("=================================================\n\n");

    /* ---- 4) Input data using the tables provided ---- */

    /* Structure Student */
    struct Student students[NUM_STUDENTS] = {
        {"S100", "John Doe",       44, "doe@metro.edu"},
        {"S200", "Sam Espana",     33, "espana@metro.edu"},
        {"S300", "Seraphim Ikuomola", 22, "ikuomola@metro.edu"}
    };

    /* Structure Course */
    struct Course courses[NUM_COURSES] = {
        {"000006", "WKSP", "Workshop",         0},
        {"000117", "ICS",  "C Programming",    4},
        {"000180", "ICS",  "Research Seminar", 4}
    };

    /* Union Schedule (input rows from the Union Schedule table) */
    struct ScheduleRecord schedule[NUM_SCHEDULE];

    strcpy(schedule[0].starID, "S200");
    strcpy(schedule[0].CID, "000006");
    schedule[0].year = 2025;
    strcpy(schedule[0].semester, "Spring");
    strcpy(schedule[0].grade, "0");
    /* demonstrate union usage: store the grade in the union too */
    strcpy(schedule[0].u.grade, "0");

    strcpy(schedule[1].starID, "S300");
    strcpy(schedule[1].CID, "000117");
    schedule[1].year = 2026;
    strcpy(schedule[1].semester, "Spring");
    strcpy(schedule[1].grade, "A");
    strcpy(schedule[1].u.grade, "A");

    /* ---- 5) Display transcripts: Student - Schedule - Course ---- */
    printf("%-8s%-22s%-6s%-9s%-9s%-6s%-20s%-6s\n",
           "StarID", "Name", "Year", "Semester", "CID", "Subj", "Title", "Grade");
    printf("---------------------------------------------------------------------------------\n");

    for (int i = 0; i < NUM_SCHEDULE; i++) {
        /* find matching student */
        struct Student *st = NULL;
        for (int s = 0; s < NUM_STUDENTS; s++) {
            if (strcmp(students[s].starID, schedule[i].starID) == 0) {
                st = &students[s];
                break;
            }
        }

        /* find matching course */
        struct Course *co = NULL;
        for (int c = 0; c < NUM_COURSES; c++) {
            if (strcmp(courses[c].CID, schedule[i].CID) == 0) {
                co = &courses[c];
                break;
            }
        }

        if (st != NULL && co != NULL) {
            printf("%-8s%-22s%-6d%-9s%-9s%-6s%-20s%-6s\n",
                   schedule[i].starID,
                   st->name,
                   schedule[i].year,
                   schedule[i].semester,
                   schedule[i].CID,
                   co->subj,
                   co->title,
                   schedule[i].grade);
        }
    }

    return 0;
}