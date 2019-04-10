#include "../Header/truck.h"
#include "CUnit/Basic.h"
#include <cstring>

void truckTest(){
    Truck t;
    CU_ASSERT_EQUAL(t.isAvailable(), true);
}

void renderTest(){
    Truck t;
    CU_ASSERT_EQUAL(t.render(),21);
}

void updateCellTest(){
    Truck t;
    t.setNotReady();
    for(int i=0; i<MAXREADY; i++)
        t.updateCell(readyTruck);
    CU_ASSERT_EQUAL(t.isAvailable(),true);
}
int main() {
    // Initialize the CUnit test registry
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    CU_basic_set_mode(CU_BRM_VERBOSE);

    CU_pSuite pSuite = NULL;

    // Add a suite to the registry
    pSuite = CU_add_suite("truck.cpp", 0, 0);

    // Always check if add was successful
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Add the test to the suite
    if (NULL == CU_add_test(pSuite, "truck", truckTest)) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "render", renderTest)) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "updateCell", updateCellTest)) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    // Run the tests and show the run summary
    CU_basic_run_tests();
    return CU_get_error();
}