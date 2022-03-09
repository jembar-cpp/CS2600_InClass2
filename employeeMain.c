/**
 * EmployeeMain.c
 * File included from lecture notes.
 * Modified from original to include searching for phone number and salary.
 */

#include <string.h> 
#include <stdlib.h> 
#include "employee.h" 

int main(void){ 
    //defined in employeeSearchOne.c 
    PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind); 
    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char * nameToFind); 
    PtrToEmployee searchEmployeeByPhone(const Employee table[], int sizeTable, char * pNum);

    //defined in employeeTable.c 
    extern Employee EmployeeTable[];     
    extern const int EmployeeTableEntries;      

    PtrToEmployee matchPtr;  //Declaration 
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045); 

    //Example not found 
    if (matchPtr != NULL) 
        printf("Employee ID 1045 is in record %d\n", matchPtr - EmployeeTable); 
    else 
        printf("Employee ID is NOT found in the record\n"); 

    //Example found 
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat"); 
    if (matchPtr != NULL) 
        printf("Employee Tony Bobcat is in record %d\n", matchPtr - EmployeeTable); 
    else 
        printf("Employee Tony Bobcat is NOT found in the record\n");

    // Search by phone number
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "213-555-1212"); // will be found
    if (matchPtr != NULL) 
        printf("Employee with phone number 213-555-1212 is in record %d\n", matchPtr - EmployeeTable); 
    else 
        printf("Employee with phone number 213-555-1212 is NOT found in the record\n");

    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "981-417-2441"); // will not be found
    if (matchPtr != NULL) 
        printf("Employee with phone number 981-417-2441 is in record %d\n", matchPtr - EmployeeTable); 
    else 
        printf("Employee with phone number 981-417-2441 is NOT found in the record\n");

    return EXIT_SUCCESS;
} 