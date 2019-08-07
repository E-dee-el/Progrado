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
m_courseName("Not set"),
m_courseId("0"),
m_courseType("N/A"),
m_numCredits(4)
{

}

Progrado::Course::Course(int t_credits = 4,
                            std::string t_cname,
                            std::string t_cId,
                            std::string t_cType ,
                            std::string t_sem
                        ):
m_courseName(t_cname),
m_courseId(t_cId),
m_courseType(t_cType),
m_numCredits(t_credits)
{

}

inline std::string Progrado::Course::getCourseName() const { return m_courseName;}

inline std::string Progrado::Course::getSemesterOffered() const { return m_semesterOffered;}

inline std::string Progrado::Course::getCourseId() const { return m_courseId;}

inline std::string Progrado::Course::getCourseType() const { return m_courseType;}

inline int Progrado::Course::getNumCredits() const { return m_numCredits;} 


Progrado::Course::~Course()
{
    
}