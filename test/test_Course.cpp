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
m_semesterOffered("unspecified"),
m_courseId("0"),
m_courseType("N/A"),
m_numCredits(4)
{

}

Progrado::Course::Course(
                            std::string t_cname,
                            std::string t_cId,
                            std::string t_cType ,
                            std::string t_sem,
                            int t_credits
                        ):
m_courseName(t_cname),
m_semesterOffered(t_sem),
m_courseId(t_cId),
m_courseType(t_cType),
m_numCredits(t_credits)
{
   // default constructor

}

  std::string Progrado::Course::getCourseName() const { return m_courseName;}

  std::string Progrado::Course::getSemesterOffered() const { return m_semesterOffered;}

  std::string Progrado::Course::getCourseId() const { return m_courseId;}

  std::string Progrado::Course::getCourseType() const { return m_courseType;}

  int Progrado::Course::getNumCredits() const { return m_numCredits;} 


Progrado::Course::~Course()
{
    
}