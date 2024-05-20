#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store course information
typedef struct
{
    char* courseCode;
    char* courseTitle;
    int credit;
    char* section;
    char* teacher;
} Course;

// Function to create a Course dynamically
Course createCourse(const char* courseCode, const char* courseTitle, int credit, const char* section, const char* teacher)
{
    Course course;
    course.courseCode = malloc(strlen(courseCode) + 1);
    course.courseTitle = malloc(strlen(courseTitle) + 1);
    course.section = malloc(strlen(section) + 1);
    course.teacher = malloc(strlen(teacher) + 1);

    if (course.courseCode) strcpy(course.courseCode, courseCode);
    if (course.courseTitle) strcpy(course.courseTitle, courseTitle);
    course.credit = credit;
    if (course.section) strcpy(course.section, section);
    if (course.teacher) strcpy(course.teacher, teacher);

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

// First semester output function
void firstSemester()
{
    // Number of courses
    int numCourses = 6;

    // Allocate memory for an array of Course structures
    Course* courses = malloc(numCourses * sizeof(Course));
    if (!courses)
    {
        perror("Failed to allocate memory");
        exit(1);
    }

    // Initialize the array of Course structures with the provided data
    courses[0] = createCourse("SE 111", "Computer Fundamentals", 3, "G", "Ms. Sazia Sharmin");
    courses[1] = createCourse("AOL 101", "Art of Living", 3, "G", "Ms. Nusrat Jahan");
    courses[2] = createCourse("ENG 101", "English I", 3, "G", "Ms. Sabina Sultana");
    courses[3] = createCourse("SE 112", "Computer Fundamentals Lab", 1, "G1", "Mr. Esraq Humayun");
    courses[4] = createCourse("SE 113", "Introduction to Software Engineering", 3, "G", "Mr. Debabrata Mallick");
    courses[5] = createCourse("MAT 101", "Mathematics I", 3, "G", "Mr. Md. Hasibur Rahaman Peash");

    // Print column headers with fixed widths
    printf("First Semester Courses:\n");
    printf("%-12s %-40s %-5s %-8s %-30s\n", "Course Code", "Course Title", "Credit", "Section", "Teacher");

    // Loop through the array and print each course's information with fixed widths
    for (int i = 0; i < numCourses; ++i)
    {
        printf("%-12s %-40s %-5d %-8s %-30s\n", courses[i].courseCode, courses[i].courseTitle, courses[i].credit, courses[i].section, courses[i].teacher);
    }

    // Free the memory allocated for each course
    for (int i = 0; i < numCourses; ++i)
    {
        freeCourse(courses[i]);
    }

    // Free the memory allocated for the array of Course structures
    free(courses);
}

// Define a structure to hold course information
struct CourseStruct
{
    char* code;
    char* title;
    int credit;
    char* section;
    char* teacher;
};

// Function to create a new Course structure and allocate memory for its members
struct CourseStruct* createCourseStruct(const char* code, const char* title, int credit, const char* section, const char* teacher)
{
    struct CourseStruct* course = (struct CourseStruct*)malloc(sizeof(struct CourseStruct));
    course->code = (char*)malloc(strlen(code) + 1);
    course->title = (char*)malloc(strlen(title) + 1);
    course->section = (char*)malloc(strlen(section) + 1);
    course->teacher = (char*)malloc(strlen(teacher) + 1);

    strcpy(course->code, code);
    strcpy(course->title, title);
    course->credit = credit;
    strcpy(course->section, section);
    strcpy(course->teacher, teacher);

    return course;
}

// Function to free the memory allocated for a Course structure
void freeCourseStruct(struct CourseStruct* course)
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
    // Array of pointers to store dynamically allocated Course structures
    struct CourseStruct* courses[] =
    {
        createCourseStruct("SE 122", "Structured Programming Lab", 1, "G1", "Ms. Maliha Bushra Hoque"),
        createCourseStruct("PHY 101", "Physics I", 3, "G", "Mr. Md. Suzauddulah"),
        createCourseStruct("MAT 102", "Mathematics II", 3, "G (40th Batch)", "Mr. Md Mozammelul Haque"),
        createCourseStruct("SE 123", "Discrete Mathematics", 3, "G", "Mr. Nuruzzaman Faruqui"),
        createCourseStruct("SE 212", "Software Requirement Specifications & Analysis", 3, "G", "Mr. Biraj Saha Aronya"),
        createCourseStruct("SE 213", "Digital Electronics & Logic Design", 3, "G (40th Batch)", "Ms. Nadira Islam Ruku"),
        createCourseStruct("SE 121", "Structured Programming", 3, "G", "Ms. Maliha Bushra Hoque")
    };

    // Calculate the total number of courses
    int numCourses = sizeof(courses) / sizeof(courses[0]);

    // Print column headers
    printf("Second Semester Courses:\n");
    printf("%-12s %-45s %-6s %-16s %s\n", "Course Code", "Course Title", "Credit", "Section", "Teacher");

    // Loop through the array of structures and print each course's information
    for (int i = 0; i < numCourses; ++i)
    {
        printf("%-12s %-45s %-6d %-16s %s\n", courses[i]->code, courses[i]->title, courses[i]->credit, courses[i]->section, courses[i]->teacher);
    }

    // Free the dynamically allocated memory
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
        "Ms. Ummey Fariha", "Mr. Ummay Fatema Urmi"
    };

    int numCourses = sizeof(courseCodes) / sizeof(courseCodes[0]);

    // Print column headers with fixed widths
    printf("Third Semester Courses:\n");
    printf("%-12s %-40s %-6s %-16s %s\n", "Course Code", "Course Title", "Credit", "Section", "Teacher");

    // Print each course's information with fixed widths
    for(int i = 0; i < numCourses; i++)
    {
        printf("%-12s %-40s %-6d %-16s %s\n", courseCodes[i], courseTitles[i], credits[i], sections[i], teachers[i]);
    }
}

// Main function to handle user input and call the corresponding output function
int main()
{
    while (1)
    {
        int choice;

        printf("Select an option:\n");
        printf("1. Show first semester courses\n");
        printf("2. Show second semester courses\n");
        printf("3. Show third semester courses\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

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
        default:
            printf("Invalid choice.\n");
            break;
        }

        // Add a prompt to allow user to continue or exit
        char continueChoice;
        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &continueChoice); // Space before %c to consume any newline character left by previous scanf
        if (continueChoice != 'y' && continueChoice != 'Y')
        {
            break;
        }
    }

    return 0;
}
