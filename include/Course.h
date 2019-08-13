
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
#include<vector>
#include<iostream>

namespace Progrado{
    class Course;
}


class Progrado::Course{
    public:
        Course();
        ~Course();
        Course(std::vector<std::string>, int);
        Course(std::string, std::string,
                std::string, std::string, std::string, int t_credits = 4);
          std::string getCourseName()const;
          std::string getSemesterOffered()const; 
          std::string getCourseId()const; 
          std::string getCourseType()const;
          int getNumCredits()const;
          int getCountCourseDetails()const;
          std::string getCourseBindParam(int) const;
          const std::string& operator [] (int)const;
          void displayCourse()const;

    private:
        enum{courseName, semesterOffered, yearOffered, courseId, courseType};
        std::vector<std::string> m_courseDetails;
        const std::vector<std::string> m_CourseBindParams = {":courseName", ":semesterOffered", ":yearOffered",
        ":courseId", ":courseType"};  // DO NOT THE CHANGE ORDER!!!
        int m_numCredits;
           
};

#endif // endif