#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store course information
typedef struct
{
    char *courseCode;
    char *courseTitle;
    int credit;
    char *section;
    char *teacher;
} Course;

// Function to create a Course dynamically
Course createCourse(const char *courseCode, const char *courseTitle, int credit, const char *section, const char *teacher)
{
    Course course;
    course.courseCode = (char *)malloc(strlen(courseCode) + 1);
    course.courseTitle = (char *)malloc(strlen(courseTitle) + 1);
    course.section = (char *)malloc(strlen(section) + 1);
    course.teacher = (char *)malloc(strlen(teacher) + 1);

    if (!course.courseCode || !course.courseTitle || !course.section || !course.teacher)
    {
        perror("Failed to allocate memory");
        exit(1);
    }

    strcpy(course.courseCode, courseCode);
    strcpy(course.courseTitle, courseTitle);
    course.credit = credit;
    strcpy(course.section, section);
    strcpy(course.teacher, teacher);

    return course;
}

// Function to free the memory allocated for a Course
void freeCourse(Course course)
{
    free(course.courseCode);
    free(course.courseTitle);
    free(course.section);
    free(course.teacher);
}

// Function to print course information
void printSemester(Course *courses, int numCourses)
{
    printf("%-12s %-40s %-5s %-8s %-30s\n", "Course Code", "Course Title", "Credit", "Section", "Teacher");
    for (int i = 0; i < numCourses; ++i)
    {
        printf("%-12s %-40s %-5d %-8s %-30s\n", courses[i].courseCode, courses[i].courseTitle, courses[i].credit, courses[i].section, courses[i].teacher);
    }
}

// Function to view courses
void viewCourses(Course *courses, int numCourses)
{
    printf("Courses:\n");
    for (int i = 0; i < numCourses; ++i)
    {
        printf("%s - %s\n", courses[i].courseCode, courses[i].courseTitle);
    }
}

// Function to view course schedule
void viewCourseSchedule(Course *courses, int numCourses)
{
    printf("Course Schedule:\n");
    for (int i = 0; i < numCourses; ++i)
    {
        printf("%s - %s\n", courses[i].courseTitle, courses[i].teacher);
    }
}

// First semester output function
void firstSemester()
{
    int numCourses = 6;
    Course *courses = (Course *)malloc(numCourses * sizeof(Course));
    if (!courses)
    {
        perror("Failed to allocate memory");
        exit(1);
    }

    courses[0] = createCourse("SE 111", "Computer Fundamentals", 3, "G", "Ms. Sazia Sharmin");
    courses[1] = createCourse("AOL 101", "Art of Living", 3, "G", "Ms. Nusrat Jahan");
    courses[2] = createCourse("ENG 101", "English I", 3, "G", "Ms. Sabina Sultana");
    courses[3] = createCourse("SE 112", "Computer Fundamentals Lab", 1, "G1", "Mr. Esraq Humayun");
    courses[4] = createCourse("SE 113", "Introduction to Software Engineering", 3, "G", "Mr. Debabrata Mallick");
    courses[5] = createCourse("MAT 101", "Mathematics I", 3, "G", "Mr. Md. Hasibur Rahaman Peash");

    int choice;
    while (1)
    {
        printf("\nFirst Semester Options:\n");
        printf("1. View Courses\n");
        printf("2. View Course Schedule\n");
        printf("3. View All Information\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1)
        {
            while (getchar() != '\n');  // Clear the invalid input
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        switch (choice)
        {
        case 1:
            viewCourses(courses, numCourses);
            break;
        case 2:
            viewCourseSchedule(courses, numCourses);
            break;
        case 3:
            printf("\nFirst Semester Courses:\n");
            printSemester(courses, numCourses);
            break;
        default:
            printf("Invalid choice.\n");
            break;
        }

        char continueChoice;
        printf("Do you want to continue with first semester options? (y/n): ");
        scanf(" %c", &continueChoice);
        if (continueChoice != 'y' && continueChoice != 'Y')
        {
            break;
        }
    }

    for (int i = 0; i < numCourses; ++i)
    {
        freeCourse(courses[i]);
    }
    free(courses);
}

// Define a structure to hold course information
struct CourseStruct
{
    char *code;
    char *title;
    int credit;
    char *section;
    char *teacher;
};

// Function to create a new Course structure and allocate memory for its members
struct CourseStruct *createCourseStruct(const char *code, const char *title, int credit, const char *section, const char *teacher)
{
    struct CourseStruct *course = (struct CourseStruct *)malloc(sizeof(struct CourseStruct));
    if (!course)
    {
        perror("Failed to allocate memory");
        exit(1);
    }
    course->code = (char *)malloc(strlen(code) + 1);
    course->title = (char *)malloc(strlen(title) + 1);
    course->section = (char *)malloc(strlen(section) + 1);
    course->teacher = (char *)malloc(strlen(teacher) + 1);

    if (!course->code || !course->title || !course->section || !course->teacher)
    {
        perror("Failed to allocate memory");
        exit(1);
    }

    strcpy(course->code, code);
    strcpy(course->title, title);
    course->credit = credit;
    strcpy(course->section, section);
    strcpy(course->teacher, teacher);

    return course;
}

// Function to free the memory allocated for a Course structure
void freeCourseStruct(struct CourseStruct *course)
{
    free(course->code);
    free(course->title);
    free(course->section);
    free(course->teacher);
    free(course);
}

// Second semester output function
void secondSemester()
{
    struct CourseStruct *courses[] =
    {
        createCourseStruct("SE 122", "Structured Programming Lab", 1, "G1", "Ms. Maliha Bushra Hoque"),
        createCourseStruct("PHY 101", "Physics I", 3, "G", "Mr. Md. Suzauddulah"),

        createCourseStruct("MAT 102", "Mathematics II", 3, "G (40th Batch)", "Mr. Md Mozammelul Haque"),
        createCourseStruct("SE 123", "Discrete Mathematics", 3, "G", "Mr. Nuruzzaman Faruqui"),
        createCourseStruct("SE 212", "Software Requirement Specifications & Analysis", 3, "G", "Mr. Biraj Saha Aronya"),
        createCourseStruct("SE 213", "Digital Electronics & Logic Design", 3, "G (40th Batch)", "Ms. Nadira Islam Ruku"),
        createCourseStruct("SE 121", "Structured Programming", 3, "G", "Ms. Maliha Bushra Hoque")
    };

    int numCourses = sizeof(courses) / sizeof(courses[0]);

    int choice;
    while (1)
    {
        printf("\nSecond Semester Options:\n");
        printf("1. View Courses\n");
        printf("2. View Course Schedule\n");
        printf("3. View All Information\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1)
        {
            while (getchar() != '\n');  // Clear the invalid input
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        switch (choice)
        {
        case 1:
            printf("Courses:\n");
            for (int i = 0; i < numCourses; ++i)
            {
                printf("%s - %s\n", courses[i]->code, courses[i]->title);
            }
            break;
        case 2:
            printf("Course Schedule:\n");
            for (int i = 0; i < numCourses; ++i)
            {
                printf("%s - %s\n", courses[i]->title, courses[i]->teacher);
            }
            break;
        case 3:
            printf("\nSecond Semester Courses:\n");
            printf("%-12s %-45s %-6s %-16s %s\n", "Course Code", "Course Title", "Credit", "Section", "Teacher");
            printf("\n");
            for (int i = 0; i < numCourses; ++i)
            {
                printf("%-12s %-45s %-6d %-16s %s\n", courses[i]->code, courses[i]->title, courses[i]->credit, courses[i]->section, courses[i]->teacher);
            }
            break;
        default:
            printf("Invalid choice.\n");
            break;
        }


        char continueChoice;
        printf("Do you want to continue with second semester options? (y/n): ");
        scanf(" %c", &continueChoice);
        if (continueChoice != 'y' && continueChoice != 'Y')
        {
            break;
        }
    }

    for (int i = 0; i < numCourses; ++i)
    {
        freeCourseStruct(courses[i]);
    }
}

// Third semester output function
void thirdSemester()
{
    char *courseCodes[] =
    {
        "SE 222", "SE 211", "SE 132", "SE 133", "SE 131", "BNS 101", "STA 101"
    };

    char *courseTitles[] =
    {
        "Computer Architecture", "Object Oriented Concepts", "Data Structure Lab",
        "Software Development Capstone Project", "Data Structure",
        "Bangladesh Studies", "Statistics I"
    };

    int credits[] = {3, 3, 1, 3, 3, 3, 3};

    char *sections[] =
    {
        "G", "G", "G1", "G1", "G", "G (40th Batch)", "G"
    };

    char *teachers[] =
    {
        "Ms. Sazia Sharmin", "Mr. Sanjoy Dev", "Mr. Biraj Saha Aronya",
        "Mr. Fazla Rabby Raihan", "Mr. K. M. Shahriar Islam",
        "Ms. Ummey Fariha", "Ms. Ummay Fatema Urmi"
    };

    int numCourses = sizeof(courseCodes) / sizeof(courseCodes[0]);

    int choice;
    while (1)
    {
        printf("\nThird Semester Options:\n");
        printf("1. View Courses\n");
        printf("2. View Course Schedule\n");
        printf("3. View All Information\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1)
        {
            while (getchar() != '\n');  // Clear the invalid input
            printf("Invalid input. Please enter a number.\n");
            continue;
        }
        switch (choice)
        {
        case 1:
            printf("Courses:\n");
            for (int i = 0; i < numCourses; i++)
            {
                printf("%s - %s\n", courseCodes[i], courseTitles[i]);
            }
            break;
        case 2:
            printf("Course Schedule:\n");
            for (int i = 0; i < numCourses; i++)
            {
                printf("%s - %s\n", courseTitles[i], teachers[i]);
            }
            break;
        case 3:
            printf("\nThird Semester Courses:\n");
            printf("%-12s %-40s %-6s %-16s %s\n", "Course Code", "Course Title", "Credit", "Section", "Teacher");
            for(int i = 0; i < numCourses; i++)
            {
                printf("%-12s %-40s %-6d %-16s %s\n", courseCodes[i], courseTitles[i], credits[i], sections[i], teachers[i]);
            }
            break;
        default:
            printf("Invalid choice.\n");
            break;
        }

        char continueChoice;
        printf("Do you want to continue with third semester options? (y/n): ");
        scanf(" %c", &continueChoice);
        if (continueChoice != 'y' && continueChoice != 'Y')
        {
            break;
        }
    }
}

void comingSoon()
{
    printf("Coming Soon...\n");
}

// Function to find the day of the week for a given date
int dayOfWeek(int y, int m, int d)
{
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    y -= m < 3;
    return (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}

// Function to print the calendar
void printCalendar(int year, int month)
{
    int daysInMonth, i, day;
    int currentDay = 1;

    // Array to store the number of days in each month
    int daysOfMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Check for leap year
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        daysOfMonth[1] = 29;

    // Find the day of the week for the 1st day of the month
    day = dayOfWeek(year, month, 1);

    // Print the header
    printf("   --------------%d %d--------------\n", month, year);
    printf("   Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    // Print leading spaces
    for (i = 0; i < day; i++)
    {
        printf("     ");
    }

    // Print the days
    daysInMonth = daysOfMonth[month - 1];
    while (currentDay <= daysInMonth)
    {
        printf("%5d", currentDay);

        // Move to the next line after Saturday
        if (++day % 7 == 0)
        {
            printf("\n");
        }
        currentDay++;
    }

    // Print a new line at the end
    printf("\n");
}

int main()
{
    printf("\n\n");
    printf("                                |---------------------|                                     \n");
    printf("------------------------------- |Academic Information |-------------------------------------\n");
    printf("                                |---------------------|                                     \n\n");

    char departmentChoice;

    printf("Are you from Department of Software Engineering? (y/n): ");
    scanf(" %c", &departmentChoice);
    if (departmentChoice != 'y' && departmentChoice != 'Y')
    {
        printf("You are in the wrong destination\n");
        return 0;
    }

    char viewCalendar;
    printf("Do you want to see the calendar? (y/n): ");
    scanf(" %c", &viewCalendar);
    if (viewCalendar == 'y' || viewCalendar == 'Y')
    {
        int year, month;

        // Input year and month from user
        printf("Enter year: ");
        scanf("%d", &year);
        printf("Enter month (1-12): ");
        scanf("%d", &month);

        // Check if the input month and year are valid
        if (month < 1 || month > 12)
        {
            printf("Invalid month!\n");
            return 1;
        }

        // Call the printCalendar function
        printCalendar(year, month);
    }

    while (1)
    {
        int choice;

        printf("\nSelect an option:\n");
        printf("1. Show first semester courses\n");
        printf("2. Show second semester courses\n");
        printf("3. Show third semester courses\n");
        printf("4. Show fourth semester courses\n");
        printf("5. Show fifth semester courses\n");
        printf("6. Show sixth semester courses\n");
        printf("7. Show seventh semester courses\n");
        printf("8. Show eighth semester courses\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1)
        {
            while (getchar() != '\n');  // Clear the invalid input
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        switch (choice)
        {
        case 1:
            firstSemester();
            break;
        case 2:
            secondSemester();
            break;
        case 3:
            thirdSemester();
            break;
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
            comingSoon();
            break;
        default:
            printf("You are done with study.\n");
            break;
        }

        char continueChoice;
        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &continueChoice);
        if (continueChoice != 'y' && continueChoice != 'Y')
        {
            break;
        }
    }

    return 0;
}
