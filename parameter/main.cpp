#include <iostream>
#include <memory>

#include "Parameters.hpp"
#include "Data.hpp"

int main(int argc, char *argv[])
{
	std::unique_ptr<Parameters> prms(new Parameters);
	prms->getEnv();
	prms->loadParams();
	prms->show();

	std::unique_ptr<Data> ref(new Data);
    std::unique_ptr<Data> meas(new Data);
	ref->loadData();
	ref->show();
    meas->loadData();
    meas->show();
    // ref->showX();
    // ref->showY();

	return 0;
}
