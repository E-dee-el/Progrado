
// Progrado "global" constants, functions declared here
#ifndef PROGRADO
#define PROGRADO

namespace Progrado
{
    const char* PROGRADO_DB_LOCATION = "data/progrado.db"; 
    const char* PROGRADO_NEW_USER_TABLE = 
    "CREATE TABLE IF NOT EXISTS user(lastName TEXT,"
                               "firstName TEXT,"
                               "yearInCollege TEXT,"
                               "userName TEXT PRIMARY KEY,"
                               "password TEXT,"
                               "major TEXT,"
                               "minor TEXT)";
    const char* PROGRADO_INSERT_NEW_USER = 
    "INSERT INTO user (lastName, firstName, yearInCollege, userName, password, major, minor)"
    "VALUES(:lastName, :firstName, :yearInCollege, :userName, :password, :major, :minor)";                           
                                                                        
}

#endif