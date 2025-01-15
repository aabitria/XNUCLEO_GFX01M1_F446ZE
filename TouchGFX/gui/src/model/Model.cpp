#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include "stdlib.h"

Model::Model() : modelListener(0)
{

}

void Model::tick()
{
    int max = 100, min = 5;

    if ((counter % 20) == 0)
    {
		int rd = rand() % (max - min + 1) + min;
		num = rd;
    }

    modelListener->set_int(num);
    counter++;
}
