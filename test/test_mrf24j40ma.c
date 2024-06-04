#include "mrf24j40ma_dev.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(MRF24J40MA);

TEST_SETUP(MRF24J40MA){

}

TEST_TEAR_DOWN(MRF24J40MA){

}

TEST(MRF24J40MA,SPI_IF_CALLED){
    TEST_ASSERT_EQUAL(0,1);
}