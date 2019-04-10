#include "../Header/land.h"
#include "../../FarmAnimal/Header/farmanimal.h"
#include "../../FarmAnimal/Header/cow.h"
#include "CUnit/Basic.h"

using namespace std;
void landTest(){
    FarmAnimal* f;
    f = new Cow[1]();
    Land l(true, f, grassLand);
    CU_ASSERT_EQUAL(l.isRumput(), true);
    CU_ASSERT_EQUAL(l.getAnimal() -> getId(), 5);
    CU_ASSERT_EQUAL(l.getType(), grassLand);
}

void renderTest(){
    FarmAnimal* f;
    f = new Cow[1]();
    Land l(true,f,grassLand);
    CU_ASSERT_EQUAL(l.render(), 5);
}

int main() {
    // Initialize the CUnit test registry
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    CU_basic_set_mode(CU_BRM_VERBOSE);

    CU_pSuite pSuite = NULL;

    // Add a suite to the registry
    pSuite = CU_add_suite("land.cpp", 0, 0);

    // Always check if add was successful
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Add the test to the suite
    if (NULL == CU_add_test(pSuite, "land", landTest)) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "render", renderTest)) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    // Run the tests and show the run summary
    CU_basic_run_tests();
    return CU_get_error();
}