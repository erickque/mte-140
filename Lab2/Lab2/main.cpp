//
//  main.cpp
//  Lab2
//
//  Created by Eric Lin on 2018-02-27.
//  Copyright © 2018 Eric Lin. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

#include "Lab2Tests.hpp"

string get_status_str(bool status)
{
    return status ? "Pass" : "Fail";
}

int main()
{
    DynamicStackTest stack_test;
    CircularQueueTest queue_test;
    
    bool stack_test1_passed = stack_test.test1();
    bool stack_test2_passed = stack_test.test2();
    bool stack_test3_passed = stack_test.test3();
    bool stack_test4_passed = stack_test.test4();
    bool stack_test5_passed = stack_test.test5();
    bool stack_test6_passed = stack_test.test6();
    bool stack_test7_passed = stack_test.test7();
    bool stack_test8_passed = stack_test.test8();
    bool stack_test9_passed = stack_test.test9();
    bool stack_test10_passed = stack_test.test10();
    
    bool queue_test1_passed = queue_test.test1();
    bool queue_test2_passed = queue_test.test2();
    bool queue_test3_passed = queue_test.test3();
    bool queue_test4_passed = queue_test.test4();
    bool queue_test5_passed = queue_test.test5();
    bool queue_test6_passed = queue_test.test6();
    bool queue_test7_passed = queue_test.test7();
    bool queue_test8_passed = queue_test.test8();
    bool queue_test9_passed = queue_test.test9();
    bool queue_test10_passed = queue_test.test10();
    
    cout << "---Dynamic Stack Tests---" << endl;
    cout << "Test1: " << get_status_str(stack_test1_passed) << endl;
    cout << "Test2: " << get_status_str(stack_test2_passed) << endl;
    cout << "Test3: " << get_status_str(stack_test3_passed) << endl;
    cout << "Test4: " << get_status_str(stack_test4_passed) << endl;
    cout << "Test5: " << get_status_str(stack_test5_passed) << endl;
    cout << "Test6: " << get_status_str(stack_test6_passed) << endl;
    cout << "Test7: " << get_status_str(stack_test7_passed) << endl;
    cout << "Test8: " << get_status_str(stack_test8_passed) << endl;
    cout << "Test9: " << get_status_str(stack_test9_passed) << endl;
    cout << "Test10: " << get_status_str(stack_test10_passed) << endl;

    cout << endl;
    cout << "---Circular Queue Tests---" << endl;
    cout << "Test1: " << get_status_str(queue_test1_passed) << endl;
    cout << "Test2: " << get_status_str(queue_test2_passed) << endl;
    cout << "Test3: " << get_status_str(queue_test3_passed) << endl;
    cout << "Test4: " << get_status_str(queue_test4_passed) << endl;
    cout << "Test5: " << get_status_str(queue_test5_passed) << endl;
    cout << "Test6: " << get_status_str(queue_test6_passed) << endl;
    cout << "Test7: " << get_status_str(queue_test7_passed) << endl;
    cout << "Test8: " << get_status_str(queue_test8_passed) << endl;
    cout << "Test9: " << get_status_str(queue_test9_passed) << endl;
    cout << "Test10: " << get_status_str(queue_test10_passed) << endl;
    
    //system("pause");
}

