
#ifndef HOME_H
#define HOME_H

#include"add_course.h"
#include"remove_course.h"
#include"modify_course.h"
#include"modify_user_details.h"
#include"delete_acct.h"
#include"retrieve_user_details.h"
#include"view_course.h"
#include"view_user_details.h"
#include"search.h"
#include<memory>
#include<iostream>


/*namespace Progrado contains all progrado-specific classes*/
namespace Progrado{

    class home{
        public:
            home();
            ~home();
            void intialize_screen(const int); /*initialize a screen by passing an enum type from the enum below*/



        private:

        /*pass as arguments to the initialize_screen method*/
                enum  
                {
                    add_course_screen,
                    remove_course_screen,
                    modify_course_screen,
                    delete_acct_screen,
                    view_course_screen,
                    search_course_screen,
                    view_user_details_screen,
                    modify_user_screen,
                    retrieve_user_details_screen
                };

                

    }; // class home
} // namespace progrado
#endif