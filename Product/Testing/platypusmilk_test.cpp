#include "../Header/platypusmilk.h"
#include "CUnit/Basic.h"
#include <sstream>
#include <cstring>

using namespace std;

void platypusMilkTest(){
    PlatypusMilk c;
    CU_ASSERT_EQUAL(c.getHarga(),25000);
    CU_ASSERT_EQUAL(c.getID(), 6);
}

int main(){
    // Initialize the CUnit test registry
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    CU_basic_set_mode(CU_BRM_VERBOSE);

    CU_pSuite pSuite = NULL;

    // Add a suite to the registry
    pSuite = CU_add_suite("platypusmilk.cpp", 0, 0);

    // Always check if add was successful
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Add the test to the suite
    if (NULL == CU_add_test(pSuite, "platypusmilk", platypusMilkTest)) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Run the tests and show the run summary
    CU_basic_run_tests();
    return CU_get_error();
}