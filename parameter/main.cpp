#include <iostream>
#include <memory>

#include "Parameters.hpp"
#include "CrosstalkMap.hpp"

int main(int argc, char *argv[])
{
	std::unique_ptr<Parameters> prms(new Parameters);
	prms->getEnv();
	prms->loadParams();
	prms->show();

	std::unique_ptr<CrosstalkMap> ref(new CrosstalkMap);
    std::unique_ptr<CrosstalkMap> meas(new CrosstalkMap);
	ref->loadData();
	// ref->show_raw_data();
	ref->getFourCorners();
	ref->trimData();

    meas->loadData();
    // meas->show_raw_data();
	ref->getFourCorners();

	return 0;
}
