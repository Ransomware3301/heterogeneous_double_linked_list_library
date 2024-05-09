/*
 *  File Type:  C Header File
 *  
 *  Program:    C library for creating double linked lists (DL Lists) that can hold
 *              heterogeneous data types, achieved through void pointers.
 *
 *              (e.g.: you can store an int, a float and a string all in the same list !) 
 * 
 *  Made By:    Ransomware3301 (https://www.github.com/ransomware3301)
 *  Date:       09/05/2024
 */


#ifndef __DOUBLE_LINKED_LIST_H_
#define __DOUBLE_LINKED_LIST_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


#define STRING_BUFFER_SIZE 256
#define STRING_EMPTY_PLACEHOLDER " "
#define END_OF_STRING '\0'
#define NEWLINE_CHAR '\n'
#define ZERO_CHAR '0'


/* ==== Type Definitions ==== */


/* Boolean Type Definition */
typedef enum bool
{
    false,
    true
}
bool_t;


/* 
 *  ALL types that can be read from user input 
 *  with the "safe_input()" function 
 */
typedef enum type 
{
    SHORT_INT,
    U_SHORT_INT,
    INT,
    U_INT,
    LONG_INT,
    U_LONG_INT,
    FLOAT,
    DOUBLE,
    CHAR,
    STRING
}
type_t;


/* Heterogeneous Data Packet Definition */
typedef struct hetdata
{
    void *val;
    type_t type;
    char *format;
}
hetdata_t;


/* Double Linked List Definition */
typedef struct dl_list 
{
    hetdata_t data;
    struct dl_list *prev;
    struct dl_list *next;
}
dl_list_t;


/* ==== Function Declarations ==== */


/* I/O */
void        print_dl_list(dl_list_t*);
void        print_dl_list_v2(dl_list_t*);
void        print_dl_list_reverse(dl_list_t*);
void        print_dl_list_v2_reverse(dl_list_t*);
void        show_data_types(void);
dl_list_t * input_dl_list(void);
hetdata_t   input_data(void);
void *      safe_input(const type_t, const unsigned long int, char*);


/* Actions */
hetdata_t * create_data_block(void*, type_t, char*);


/* Miscellaneous */
char * filter(char*, char);
char * strconcat(char*, char*);
bool_t is_data_type(type_t);


/* Double Linked List Operations */
dl_list_t * push_front(dl_list_t*, hetdata_t);
dl_list_t * push_back(dl_list_t*, hetdata_t);
dl_list_t * pop_front(dl_list_t*, hetdata_t*);
dl_list_t * pop_back(dl_list_t*, hetdata_t*);
dl_list_t * delete_instance(dl_list_t*, hetdata_t*);
dl_list_t * delete_all_instances(dl_list_t*, hetdata_t*);
dl_list_t * delete_dl_list(dl_list_t*);
dl_list_t * find(dl_list_t*, hetdata_t*);
dl_list_t * copy_dl_list(dl_list_t*);


#endif
