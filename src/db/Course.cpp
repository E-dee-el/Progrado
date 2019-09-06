
#include"Course.h"
#include<iomanip>
#include<fstream>
#include<iostream>

Progrado::Course::Course():
    m_courseDetails(5),
    m_numCredits(4)
{
    m_courseDetails[courseName] = "Not set";
    m_courseDetails[courseId] = "Not set";
    m_courseDetails[semesterOffered] = "not set";
    m_courseDetails[courseType] = "Major";
    m_courseDetails[yearOffered] = "Freshman";  // default to freshman
}

Progrado::Course::Course(
    std::string t_cname,
    std::string t_cId,
    std::string t_cType,
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

Progrado::Course::Course(std::vector<std::string>& t_V, int t_credits):
    m_courseDetails(t_V),
    m_numCredits(t_credits)
{

}
std::string Progrado::Course::getCourseName() const {
    return m_courseDetails[courseName];
}

std::string Progrado::Course::getSemesterOffered() const {
    return m_courseDetails[semesterOffered];
}

std::string Progrado::Course::getCourseId() const {
    return m_courseDetails[courseId];
}

std::string Progrado::Course::getCourseType() const {
    return m_courseDetails[courseType];
}

int Progrado::Course::getNumCredits() const {
    return m_numCredits;
}

const std::string& Progrado::Course::operator [] (int idx)const {
    return m_courseDetails[idx];
}

int Progrado::Course::getCountCourseDetails()const {
    return m_courseDetails.size();
}

std::string Progrado::Course::getCourseBindParam(int idx)const {
    return m_CourseBindParams[idx];
}

void Progrado::Course::printCourse()const
{
    for(auto i: m_courseDetails)
    {
        std::cout<<"*"<<std::setw(35)<<std::left<< i << "*\n";
    }
    std::cout <<"*"<<std::left<<"Credits: " << m_numCredits << "                         *\n";

}

void Progrado::Course::displayCourse()const
{
    std::ofstream outfile;
    outfile.open("result.csv", std::fstream::app);

    if(outfile.fail()) std:: cout << "error!\n";
    
    /*neat trick (?) to print header only once*/
    static int trk = 0;
    if(!trk--) 
        outfile << "Course Name, Course ID, Semester Taken, Year Taken, Course Type, Number of Credits\n";
    /**neat trick ends here*/

    for (int i = 0; i < m_courseDetails.size(); i++)
    {
        outfile << m_courseDetails[i] << ",";
    }
    outfile << m_numCredits << "\n";

    outfile.close();

}


Progrado::Course::~Course()
{

}