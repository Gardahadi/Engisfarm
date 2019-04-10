#include "../Header/bull.h"
#include "CUnit/Basic.h"
#include <cstring>

using namespace std;

void bullTest() {
//   Check if first param matches with second[2]
    Bull b;

    CU_ASSERT_EQUAL(b.isMilk(), false);
    CU_ASSERT_EQUAL(b.isEgg(), false);
    CU_ASSERT_EQUAL(b.isMeat(), true); 
    CU_ASSERT_EQUAL(b.isHungry(), true);
    CU_ASSERT_EQUAL(b.getLivingTime(), default_living_time);
}

void bersuaraTest() {
    Bull b;
    string s = b.bersuara();
    CU_ASSERT_EQUAL(s, "(Manly) Moooo...");
}

void getProductTest(){
    Bull b;
    FarmProduct f;
    bool e = false;
    try{
        f = b.getProduct(true);
        CU_ASSERT_EQUAL(f.getID(), 3);
    }catch (char const* err){
        if(strcmp(err,"Bull tidak memiliki susu") == 0){
            e = true;
        }
    }

    e = false;

    try{
        f = b.getProduct(false);
    }catch (char const* err){
        if(strcmp(err,"Bull tidak memiliki susu") == 0){
            e = true;
        }
    }
    
    CU_ASSERT_TRUE(e);
}

void getIdTest(){
    Bull b;
    b.setHungry(true);
    CU_ASSERT_EQUAL(b.getId(), 11);
    b.setHungry(false);
    CU_ASSERT_EQUAL(b.getId(), 12);
}

int main() {
    // Initialize the CUnit test registry
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    CU_basic_set_mode(CU_BRM_VERBOSE);

    CU_pSuite pSuite = NULL;

    // Add a suite to the registry
    pSuite = CU_add_suite("bull.cpp", 0, 0);

    // Always check if add was successful
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Add the test to the suite
    if (NULL == CU_add_test(pSuite, "bull", bullTest)) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "bersuara", bersuaraTest)) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "getProduct", getProductTest)) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "getId", getIdTest)) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    // Run the tests and show the run summary
    CU_basic_run_tests();
    return CU_get_error();
}