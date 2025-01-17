#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include "stdlib.h"
#include "ds18b20.h"

extern "C" {
int ds18b20_read_raw_temp (uint16_t *temp_ptr);
}

Model::Model() : modelListener(0)
{

}

void Model::tick()
{
    int max = 100, min = 5;
    uint16_t temp;

    if ((counter % 20) == 0)
    {
		int rd = rand() % (max - min + 1) + min;
		num = rd;
    }

    if ((counter % 30) == 0)
    {
    	if (ds18b20_read_raw_temp(&temp) == 1)
    	{
    		temperature = (float)temp / 16.0f;
    	}
    }
    modelListener->set_int(num);
    counter++;
}
