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

Progrado::Course::Course():
m_courseDetails(4),
m_numCredits(4)
{
    m_courseDetails[courseName] = "Not set";
    m_courseDetails[courseId] = "Not set";
    m_courseDetails[semesterOffered] = "not set";
    m_courseDetails[courseType] = "Major";
}

Progrado::Course::Course(
                            std::string t_cname,
                            std::string t_cId,
                            std::string t_cType ,
                            std::string t_sem,
                            int t_credits
                        ):
m_courseDetails(4),                        
m_numCredits(t_credits)

{
   // default constructor
    m_courseDetails[courseName] = t_cname;
    m_courseDetails[courseId] = t_cId;
    m_courseDetails[semesterOffered] = t_sem;
    m_courseDetails[courseType] = t_cType;
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

Progrado::Course::~Course()
{
    
}