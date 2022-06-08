/*---------------------------------------------------------------------------
* @file: constants.h
* @authors: Braxton Goss & Elijah Shaw
* @brief: constants.h is used all over the library to define constants
* that are needed to set the size of arrays and indicate formatting rules.
--------------------------------------------------------------------------*/
#ifndef CONSTANTS_H
#define CONSTANTS_H
// Constants for output
const static int AVAIL_WIDTH = 7;
const static int TITLE_WIDTH = 35;
const static int MONTH_AUTHOR_WIDTH = 25;
const static int YEAR_WIDTH = 4;

// constants for hashing
const static int C_HASH_VALUE = 'C' - 'A';
const static int D_HASH_VALUE = 'D' - 'A';
const static int F_HASH_VALUE = 'F' - 'A';
const static int H_HASH_VALUE = 'H' - 'A';
const static int P_HASH_VALUE = 'P' - 'A';
const static int R_HASH_VALUE = 'R' - 'A';

// hashtable to contain patrons' size 
const int TABLE_SIZE = 100;

// used in item factory 
const static int MEDIA_TYPES = 50;

// used in transaction factory 
const static int TRANSACTION_TYPES = 50;


// 26 itemsbecause there are 26 possible letters
// each item occupies one letter of the alphabet 
// used in item factory 
const int ITEM_TYPES = 26; 



#endif