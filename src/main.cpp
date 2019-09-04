
#include"Ui.h"

using namespace Progrado;
using namespace Progrado::UI;

int main(int argc, char **argv)

{
    try{

        std::unique_ptr<Ui> app(new Ui());

        app->setup();
        app->run();

    }
    catch(std::runtime_error t_err)
    {
        std::cout << t_err.what() << std::endl;
    }
    return 0;
}
