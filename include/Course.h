
/*
**************************************
*************PROGRADO*****************
**************************************
Course header file
Authors: Ibrahim Suleiman, Yusuf Jimoh
Copyright 2019
***************************************
 */

#ifndef COURSE_H
#define COURSE_H

#include<string>

namespace Progrado{
    class Course;
}


class Progrado::Course{
    public:
        Course();
        ~Course();
        Course(int, std::string, std::string,
                std::string, std::string);
        inline std::string getCourseName()const;
        inline std::string getSemesterOffered()const; 
        inline std::string getCourseId()const; 
        inline std::string getCourseType()const;
        inline int getNumCredits()const;

    private:
        std::string m_courseName;
        std::string m_semesterOffered;
        std::string m_courseId; 
        std::string m_courseType; // major/minor/gen elective, etc
        int m_numCredits;
           
};

#endif // endif