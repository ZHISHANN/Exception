#include "CException.h"
#include "unity.h"
#include "Exception.h"
#include <stdio.h>

#define ERR_OUT_OF_BOUND 3
#define ERR_UNKNOWN_COMPANY 4
#define ERR_UNKNOWN_PEOPLE 5

void setUp(void){}

void tearDown(void){}

//names is array 3 of pointer to char
char *names[] = {
	"Ali",
	"David",
	"Ah Beng",
	"Sally",
};

char *namesInCompanyl[] = {
	"Intel",
	"Nxp",
	"Micron",
	"Nestle",
};

char *namesInIntel[] = {
	"Getha",
	"Sammy",
	"Ah Cheng",
	"Molly",
};

char *namesInNxp[] = {
	"Gambor",
	"Muller",
	"Slokovac",
	"Bambi",
};

char *namesInMicron[] = {
	"Lily",
	"Happy",
	"May",
	"April",
};

char *namesInNestle[] = {
	"Baby",
	"Amy",
	"Newt",
};

char *getNameIntable(int index, char *names[], int maxSize){
	if (index >= maxSize || index <= 0)
	 Throw (ERR_OUT_OF_BOUND);
	return names[index];
}

char *getName(int index){
	if (index >= 4 || index <= 0)
	 Throw (ERR_OUT_OF_BOUND);
	return names[index];
}

char *getNamesInCompany(int companyIdx, int nameIdx){
	char *name;
	CEXCEPTION_T e;
	
	switch(companyIdx){
		case 0 :  //Intel
		Try {
		 name = getNameIntable(nameIdx,namesInIntel,4);
		} Catch(e){
			if(e == ERR_UNKNOWN_PEOPLE)
				printf("your are looking for unknown person at Intel. The index number you given are %d\n",nameIdx);
				Throw(e);
		}
		 break;
		case 1 :  //NXP
		 name = getNameIntable(nameIdx,namesInNxp,4);
		 printf("For NXP : You choose campany %d and people %d",companyIdx,nameIdx);
		 break;
		case 2 :  //Micron
		 name = getNameIntable(nameIdx,namesInMicron,4);
		 break;
		case 3 :   //Nestle
		 name = getNameIntable(nameIdx,namesInNestle,3);
		 break;
		default :
		 Throw (ERR_UNKNOWN_COMPANY);
	}
}

void test_getName_given_company_1_and_people_32_expect_(void)
{
	char *name;
	CEXCEPTION_T e;
	
	Try {
	  name = getNamesInCompany(1,32);
	  TEST_FAIL_MESSAGE("Expected ERR_OUT_OF_BOUND to be thrown, but none");
	} Catch(e){
		printf("Caught exception for NXP and ppl number 32"); 
	}
}

void test_getName_given_company_1_and_people_2_expect_Slokovac(void)
{
	char *name;
	CEXCEPTION_T e;
	
	Try {
	  name = getNamesInCompany(1,2);
	  TEST_ASSERT_EQUAL_STRING("Slokovac",name);
	} Catch(e){
		TEST_FAIL_MESSAGE("Expected ERR_UNKNOWN_COMPANY to be thrown, but none.");
	}
}

void test_getName_given_1_expect_David(void)
{
	char *name;
	CEXCEPTION_T e;
	
	Try {
	  name = getName(1);
	  TEST_ASSERT_EQUAL_STRING("David",name);
	  //printf("Name is %s\n",name);
	} Catch(e){
		TEST_FAIL_MESSAGE("Expected ERR_OUT_OF_BOUND to be thrown, but none.");
		//printf("erroe code: %d",e);
	}
    //TEST_ASSERT_EQUAL_STRING_LEN("David",name,5);
}

void test_getName_given_minus_1_expect_error_out_of_bound(void)
{
	char *name;
	CEXCEPTION_T e;
	
	Try {
	  name = getName(-1);
	  TEST_FAIL_MESSAGE("Expected ERR_OUT_OF_BOUND to be thrown, but none.");
	} Catch(e){
	}
}

void test_getName_given_4_expect_error_out_of_bound(void)
{
	char *name;
	CEXCEPTION_T e;
	
	Try {
	  name = getName(4);
	  TEST_FAIL_MESSAGE("Expected ERR_OUT_OF_BOUND to be thrown, but none.");
	} Catch(e){
	}
}
