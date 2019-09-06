

#ifndef COURSE_H
#define COURSE_H

#include<string>
#include<vector>
#include<iostream>
#include"Progrado.h"

namespace Progrado {
class Course; //
}


class Progrado::Course {
public:
    Course();
    ~Course();
    Course(std::vector<std::string>& t_V, int t_credits = 4);
    Course(std::string t_cname, std::string t_cId,
           std::string t_cType, std::string t_sem, std::string t_yr, int t_credits = 4);
    std::string getCourseName()const;
    std::string getSemesterOffered()const;
    std::string getCourseId()const;
    std::string getCourseType()const;
    int getNumCredits()const;
    int getCountCourseDetails()const;
    std::string getCourseBindParam(int idx) const;
    const std::string& operator [] (int idx)const;
    void displayCourse()const;

private:

    std::vector<std::string> m_courseDetails;
    const std::vector<std::string> m_CourseBindParams = {":courseName", ":courseId", ":semesterOffered", ":yearOffered",
                                                          ":courseType"
                                                        };  // DO NOT THE CHANGE ORDER!!!
    int m_numCredits;

};

#endif // endif