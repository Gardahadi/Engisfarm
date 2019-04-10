#include "list.h"
#include "CUnit/Basic.h"
#include <sstream>
#include <cstring>
#include <Product/Header/farmproduct.h>
#include <Product/Header/chickenmeat.h>
#include <Product/Header/platypusmilk.h>

using namespace std;

void listTest(){
    List<int> l;
    CU_ASSERT_EQUAL(l.getSize(), 256);
    CU_ASSERT_EQUAL(l.getNeff(), 0);
}

void listSizeTest(){
    List<int> l(5);
    CU_ASSERT_EQUAL(l.getSize(), 5);
    CU_ASSERT_EQUAL(l.getNeff(), 0);
}

void cctorTest(){
    List<int> l1(5);
    l1.add(3);
    List<int> l2 = l1;
    CU_ASSERT_EQUAL(l2.getSize(), 5);
    CU_ASSERT_EQUAL(l2.getNeff(), 1);
    CU_ASSERT_EQUAL(l2.getElmt(0), 3);
}

void assignmentTest(){
    List<int> l1(5);
    l1.add(3);
    List<int> l2;
    l2 = l1;
    CU_ASSERT_EQUAL(l2.getSize(), 5);
    CU_ASSERT_EQUAL(l2.getNeff(), 1);
    CU_ASSERT_EQUAL(l2.getElmt(0), 3);
}

void isEmptyTest(){
    List<int> l;
    CU_ASSERT_TRUE(l.isEmpty());
    l.add(2);
    CU_ASSERT_FALSE(l.isEmpty());
}

void isFullTest(){
    List<int> l(10);
    CU_ASSERT_FALSE(l.isFull());
    for(int i = 1; i<=10; i++){
        l.add(i);
    }
    CU_ASSERT_TRUE(l.isFull());
}

void addTest(){
    List<int> l;
    l.add(2);
    CU_ASSERT_EQUAL(l.getElmt(0), 2);
}

void removeTest(){
    List<int> l;
    l.add(2);
    l.add(3);
    int x;
    CU_ASSERT_EQUAL(l.getElmt(0), 3);
    CU_ASSERT_EQUAL(l.getNeff(), 1);
}

void removeAtTest(){
    List<int> l;
    l.add(2);
    l.add(3);
    l.add(4);
    l.removeAt(2);
    CU_ASSERT_EQUAL(l.getElmt(0), 2);
    CU_ASSERT_EQUAL(l.getElmt(1), 3);
    CU_ASSERT_EQUAL(l.getNeff(), 2);
}

void findTest(){
    List<int> l;
    l.add(2);
    l.add(3);
    CU_ASSERT_EQUAL(l.find(4), -1);
    CU_ASSERT_EQUAL(l.find(2), 0);
    CU_ASSERT_EQUAL(l.find(3), 1);
}

void getElmtTest(){
    List<int> l;
    l.add(2);
    l.add(3);
    CU_ASSERT_EQUAL(l.getElmt(0), 2);
    CU_ASSERT_EQUAL(l.getElmt(1), 3);
}

void getSizeTest(){
    List<int> l1(10);
    List<int> l2(30);
    CU_ASSERT_EQUAL(l1.getSize(), 10);
    CU_ASSERT_EQUAL(l2.getSize(), 30);
}

void getNeffTest(){
    List<int> l;
    CU_ASSERT_EQUAL(l.getNeff(), 0);
    l.add(2);
    l.add(3);
    CU_ASSERT_EQUAL(l.getNeff(), 2);
}

void getFirstIdxTest(){
    List<int> l;
    l.add(2);
    l.add(3);
    CU_ASSERT_EQUAL(l.getFirstIdx(), 0);
}

void getLastIdxTest(){
    List<int> l;
    l.add(2);
    l.add(3);
    CU_ASSERT_EQUAL(l.getLastIdx(), 1);
}

int main() {
    // Initialize the CUnit test registry
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    CU_basic_set_mode(CU_BRM_VERBOSE);

    CU_pSuite pSuite = NULL;

    // Add a suite to the registry
    pSuite = CU_add_suite("list.h", 0, 0);

    // Always check if add was successful
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Add the test to the suite
    if (NULL == CU_add_test(pSuite, "list", listTest)) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "listSize", listSizeTest)) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "cctor", cctorTest)) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "assignment", assignmentTest)) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "isEmpty", isEmptyTest)) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "isFull", isFullTest)) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "add", addTest)) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "remove", removeTest)) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "removeAt", removeAtTest)) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "find", findTest)) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "getElmt", getElmtTest)) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "getSize", getSizeTest)) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "getNeff", getNeffTest)) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "getFirstIdx", getFirstIdxTest)) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "getLastIdx", getLastIdxTest)) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    // Run the tests and show the run summary
    CU_basic_run_tests();
    return CU_get_error();
}