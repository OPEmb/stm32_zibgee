#include "unity_fixture.h"

TEST_GROUP_RUNNER(MRF24J40MA){
    RUN_TEST_CASE(MRF24J40MA,SPI_IF_CALLED);
}

static void run_all_tests(void){
    RUN_TEST_GROUP(MRF24J40MA);
}

int main(int argc,const char* argv[]){
    return UnityMain(argc,argv,run_all_tests);
}