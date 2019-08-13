/*
**************************************
*************PROGRADO*****************
**************************************
Course implementation file
Authors: Ibrahim Suleiman, Yusuf Jimoh
Copyright 2019
***************************************
 */

#include"Course.h"
#include<iomanip>

Progrado::Course::Course():
m_courseDetails(5),
m_numCredits(4)
{
    m_courseDetails[courseName] = "Not set";
    m_courseDetails[courseId] = "Not set";
    m_courseDetails[semesterOffered] = "not set";
    m_courseDetails[courseType] = "Major";
    m_courseDetails[yearOffered] = "Freshman";   // defaults to freshman
}

Progrado::Course::Course(
                            std::string t_cname,
                            std::string t_cId,
                            std::string t_cType ,
                            std::string t_sem,
                            std::string t_yr,
                            int t_credits
                        ):
m_courseDetails(5),                        
m_numCredits(t_credits)

{
   // default constructor
    m_courseDetails[courseName] = t_cname;
    m_courseDetails[courseId] = t_cId;
    m_courseDetails[semesterOffered] = t_sem;
    m_courseDetails[courseType] = t_cType;
    m_courseDetails[yearOffered] = t_yr;
}

Progrado::Course::Course(std::vector<std::string> t_V, int t_credits):
m_courseDetails(t_V),
m_numCredits(t_credits)
{

}
std::string Progrado::Course::getCourseName() const { return m_courseDetails[courseName];}

std::string Progrado::Course::getSemesterOffered() const { return m_courseDetails[semesterOffered];}

std::string Progrado::Course::getCourseId() const { return m_courseDetails[courseId];}

std::string Progrado::Course::getCourseType() const { return m_courseDetails[courseType];}

int Progrado::Course::getNumCredits() const { return m_numCredits;} 

const std::string& Progrado::Course::operator [] (int idx)const { return m_courseDetails[idx];}

int Progrado::Course::getCountCourseDetails()const {return m_courseDetails.size();}

std::string Progrado::Course::getCourseBindParam(int idx)const {return m_CourseBindParams[idx];}


/// testing only
void Progrado::Course::displayCourse()const
{   int n = 0;
    for (int i = 0; i < m_courseDetails.size(); i++)
    {
       if(i == 0) n = 35;
       else n = 20;
        std::cout << std::left << std::setw(n)<< m_courseDetails[i];
    }
    
    std::cout << std::setw(2) << m_numCredits << std::endl;
}


Progrado::Course::~Course()
{
    
}