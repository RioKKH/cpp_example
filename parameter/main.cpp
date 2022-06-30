#include <iostream>
#include <memory>

#include "Parameters.hpp"
#include "Data.hpp"

int main(int argc, char *argv[])
{
	// // OK
	// Parameters prms;
	// prms.show();

	std::unique_ptr<Parameters> prms(new Parameters);
	prms->getEnv();
	prms->loadParams();
	prms->show();

	std::unique_ptr<Data> ref(new Data);
	ref->loadData();
	ref->show();

	return 0;
}
