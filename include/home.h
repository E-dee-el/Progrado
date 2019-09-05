
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
#include"search_course.h"
#include"screen.h"
#include<memory>
#include<iostream>


/*namespace Progrado contains all progrado-specific classes*/
namespace Progrado{

    class home{
        public:
            home();
            ~home();
            void initialize_screen(const UI::screen& t_scrn)const; /*call from execute: initialize app. scrn*/
            void execute();
            void display_home_options(); 



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