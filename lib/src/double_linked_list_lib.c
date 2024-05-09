/*
 *  File Type:  C Source File
 *  
 *  Program:    C library for creating double linked lists (DL Lists) that can hold
 *              heterogeneous data types, achieved through void pointers.
 *
 *              (e.g.: you can store an int, a float and a string all in the same list !) 
 * 
 *  Made By:    Ransomware3301 (https://www.github.com/ransomware3301)
 *  Date:       09/05/2024
 */


/* 
 *    CHANGE THE HEADER FILE RELATIVE PATH IN RELATION TO YOUR FOLDER STRUCTURE 
 *    (a.k.a. where the header file is situated) 
 */
#include "double_linked_list_lib.h"


/* ==== Function Definitions ==== */


/* 
 *  Prints to terminal the double linked list
 */
void print_dl_list(dl_list_t *head)
{
    dl_list_t *ptr;


    if (head)
    {
        ptr = head;

        printf("\n[LIST CONTENTS]\n");

        while (ptr)
        {
            printf(" |\n");

            switch (ptr->data.type)
            {
                case SHORT_INT:     printf(strconcat(" |---> ", strconcat(ptr->data.format, "\n")), *(short int*)           (ptr->data.val));  break;
                case U_SHORT_INT:   printf(strconcat(" |---> ", strconcat(ptr->data.format, "\n")), *(unsigned short int*)  (ptr->data.val));  break;
                case INT:           printf(strconcat(" |---> ", strconcat(ptr->data.format, "\n")), *(int*)                 (ptr->data.val));  break;
                case U_INT:         printf(strconcat(" |---> ", strconcat(ptr->data.format, "\n")), *(unsigned int*)        (ptr->data.val));  break;
                case LONG_INT:      printf(strconcat(" |---> ", strconcat(ptr->data.format, "\n")), *(long int*)            (ptr->data.val));  break;
                case U_LONG_INT:    printf(strconcat(" |---> ", strconcat(ptr->data.format, "\n")), *(unsigned long int*)   (ptr->data.val));  break;
                case FLOAT:         printf(strconcat(" |---> ", strconcat(ptr->data.format, "\n")), *(float*)               (ptr->data.val));  break;
                case DOUBLE:        printf(strconcat(" |---> ", strconcat(ptr->data.format, "\n")), *(double*)              (ptr->data.val));  break;
                case CHAR:          printf(strconcat(" |---> ", strconcat(ptr->data.format, "\n")), *(char*)                (ptr->data.val));  break;
                case STRING:        printf(strconcat(" |---> ", strconcat(ptr->data.format, "\n")),  (char*)                (ptr->data.val));  break;

                default:            printf("[print_dl_list()] ERROR: Cannot convert and print value (missing format specifier)\n");            break;
            }

            ptr = ptr->next;
        }

        printf("\n\n");
    }
    else
    {
        printf("\t[EMPTY]\n");
    }
}


/* 
 *  Prints to terminal the double linked list
 */
void print_dl_list_v2(dl_list_t *head)
{
    dl_list_t *ptr;


    if (head)
    {
        ptr = head;

        printf("\n[LIST CONTENTS]\n\n  ");

        while (ptr)
        {
            switch (ptr->data.type)
            {
                case SHORT_INT:     printf(strconcat("[", strconcat(ptr->data.format, "]")), *(short int*)           (ptr->data.val));  break;
                case U_SHORT_INT:   printf(strconcat("[", strconcat(ptr->data.format, "]")), *(unsigned short int*)  (ptr->data.val));  break;
                case INT:           printf(strconcat("[", strconcat(ptr->data.format, "]")), *(int*)                 (ptr->data.val));  break;
                case U_INT:         printf(strconcat("[", strconcat(ptr->data.format, "]")), *(unsigned int*)        (ptr->data.val));  break;
                case LONG_INT:      printf(strconcat("[", strconcat(ptr->data.format, "]")), *(long int*)            (ptr->data.val));  break;
                case U_LONG_INT:    printf(strconcat("[", strconcat(ptr->data.format, "]")), *(unsigned long int*)   (ptr->data.val));  break;
                case FLOAT:         printf(strconcat("[", strconcat(ptr->data.format, "]")), *(float*)               (ptr->data.val));  break;
                case DOUBLE:        printf(strconcat("[", strconcat(ptr->data.format, "]")), *(double*)              (ptr->data.val));  break;
                case CHAR:          printf(strconcat("[", strconcat(ptr->data.format, "]")), *(char*)                (ptr->data.val));  break;
                case STRING:        printf(strconcat("[", strconcat(ptr->data.format, "]")),  (char*)                (ptr->data.val));  break;

                default:            printf("[print_dl_list()] ERROR: Cannot convert and print value (missing format specifier)\n");            break;
            }

            if (ptr->next != NULL)
            {
                if (ptr->next->prev != NULL)
                {
                    printf(" <--> ");
                }
                else
                {
                    printf(" ---> ");
                }
            }

            ptr = ptr->next;
        }

        printf("\n\n");
    }
    else
    {
        printf("\t[EMPTY]\n");
    }
}


/* 
 *  Prints to terminal the double linked list, but in REVERSE
 */
void print_dl_list_reverse(dl_list_t *head)
{
    dl_list_t *ptr;
    bool_t backlink_exists;


    if (head)
    {
        ptr = head;
        backlink_exists = true;

        printf("\n[LIST CONTENTS] [ORDER REVERSED]\n");

        while (ptr->next && backlink_exists)
        {
            ptr = ptr->next;
            backlink_exists = (ptr && ptr->prev != NULL);
        }

        if (backlink_exists)
        {
            while (ptr)
            {
                printf(" |\n");

                switch (ptr->data.type)
                {
                    case SHORT_INT:     printf(strconcat(" |---> ", strconcat(ptr->data.format, "\n")), *(short int*)           (ptr->data.val));  break;
                    case U_SHORT_INT:   printf(strconcat(" |---> ", strconcat(ptr->data.format, "\n")), *(unsigned short int*)  (ptr->data.val));  break;
                    case INT:           printf(strconcat(" |---> ", strconcat(ptr->data.format, "\n")), *(int*)                 (ptr->data.val));  break;
                    case U_INT:         printf(strconcat(" |---> ", strconcat(ptr->data.format, "\n")), *(unsigned int*)        (ptr->data.val));  break;
                    case LONG_INT:      printf(strconcat(" |---> ", strconcat(ptr->data.format, "\n")), *(long int*)            (ptr->data.val));  break;
                    case U_LONG_INT:    printf(strconcat(" |---> ", strconcat(ptr->data.format, "\n")), *(unsigned long int*)   (ptr->data.val));  break;
                    case FLOAT:         printf(strconcat(" |---> ", strconcat(ptr->data.format, "\n")), *(float*)               (ptr->data.val));  break;
                    case DOUBLE:        printf(strconcat(" |---> ", strconcat(ptr->data.format, "\n")), *(double*)              (ptr->data.val));  break;
                    case CHAR:          printf(strconcat(" |---> ", strconcat(ptr->data.format, "\n")), *(char*)                (ptr->data.val));  break;
                    case STRING:        printf(strconcat(" |---> ", strconcat(ptr->data.format, "\n")),  (char*)                (ptr->data.val));  break;

                    default:            printf("[print_dl_list()] ERROR: Cannot convert and print value (missing format specifier)\n");            break;
                }

                ptr = ptr->prev;
            }

            printf("\n\n");
        }
        else
        {
            printf("[print_dl_list_reverse()] ERROR: A backlink is missing in the chain (cannon print backwards)\n");
        }              
    }
    else
    {
        printf("\t[EMPTY]\n");
    }
}


/* 
 *  Prints to terminal the double linked list, but in REVERSE
 */
void print_dl_list_v2_reverse(dl_list_t *head)
{
    dl_list_t *ptr;
    bool_t backlink_exists;


    if (head)
    {
        ptr = head;
        backlink_exists = true;

        printf("\n[LIST CONTENTS] [ORDER REVERSED]\n  ");

        while (ptr->next && backlink_exists)
        {
            ptr = ptr->next;
            backlink_exists = (ptr && ptr->prev != NULL);
        }

        if (backlink_exists)
        {
            while (ptr)
            {
                if (ptr->next != NULL)
                {
                    if (ptr->next->prev != NULL)
                    {
                        printf(" <--> ");
                    }
                    else
                    {
                        printf(" ---> ");
                    }
                }

                switch (ptr->data.type)
                {
                    case SHORT_INT:     printf(strconcat("[", strconcat(ptr->data.format, "]")), *(short int*)           (ptr->data.val));  break;
                    case U_SHORT_INT:   printf(strconcat("[", strconcat(ptr->data.format, "]")), *(unsigned short int*)  (ptr->data.val));  break;
                    case INT:           printf(strconcat("[", strconcat(ptr->data.format, "]")), *(int*)                 (ptr->data.val));  break;
                    case U_INT:         printf(strconcat("[", strconcat(ptr->data.format, "]")), *(unsigned int*)        (ptr->data.val));  break;
                    case LONG_INT:      printf(strconcat("[", strconcat(ptr->data.format, "]")), *(long int*)            (ptr->data.val));  break;
                    case U_LONG_INT:    printf(strconcat("[", strconcat(ptr->data.format, "]")), *(unsigned long int*)   (ptr->data.val));  break;
                    case FLOAT:         printf(strconcat("[", strconcat(ptr->data.format, "]")), *(float*)               (ptr->data.val));  break;
                    case DOUBLE:        printf(strconcat("[", strconcat(ptr->data.format, "]")), *(double*)              (ptr->data.val));  break;
                    case CHAR:          printf(strconcat("[", strconcat(ptr->data.format, "]")), *(char*)                (ptr->data.val));  break;
                    case STRING:        printf(strconcat("[", strconcat(ptr->data.format, "]")),  (char*)                (ptr->data.val));  break;

                    default:            printf("[print_dl_list()] ERROR: Cannot convert and print value (missing format specifier)\n");            break;
                }

                ptr = ptr->prev;
            }

            printf("\n\n");
        }
        else
        {
            printf("[print_dl_list_v2_reverse()] ERROR: A backlink is missing in the chain (cannon print backwards)\n");
        }        
    }
    else
    {
        printf("\t[EMPTY]\n");
    }
}


/*
 *  Prints to terminal all the C data types  
 */
void show_data_types(void)
{
    printf("\nAvailable data types:\n");
    printf(" (0) - SHORT_INT\n");
    printf(" (1) - U_SHORT_INT\n");
    printf(" (2) - INT\n");
    printf(" (3) - U_INT\n");
    printf(" (4) - LONG_INT\n");
    printf(" (5) - U_LONG_INT\n");
    printf(" (6) - FLOAT\n");
    printf(" (7) - DOUBLE\n");
    printf(" (8) - CHAR\n");
    printf(" (9) - STRING\n");
}


/* 
 *  Creates a list from user input
 */
dl_list_t * input_dl_list(void)
{
    dl_list_t *head;
    hetdata_t data;
    type_t type;
    int i, dim;


    head = NULL;
    i = 0;

    do
    {
        dim = *((int*)safe_input(INT, STRING_BUFFER_SIZE, "Insert list size: "));
    } 
    while (dim < 1);

    while (i < dim)
    {
        printf("\n[DATA BLOCK #%d]", i + 1);
        show_data_types();
        printf("\n");

        do
        {
            type = *((type_t*)safe_input(U_INT, STRING_BUFFER_SIZE, "Choose data type to insert: "));
        } 
        while ( !is_data_type(type) );


        data.val = safe_input(type, STRING_BUFFER_SIZE, "Insert value: ");
        data.type = type;

        switch (type)
        {
            case SHORT_INT:     data.format = "%hd";    break;
            case U_SHORT_INT:   data.format = "%hu";    break;
            case INT:           data.format = "%d";     break;
            case U_INT:         data.format = "%u";     break;
            case LONG_INT:      data.format = "%ld";    break;
            case U_LONG_INT:    data.format = "%lu";    break;
            case FLOAT:         data.format = "%f";     break;
            case DOUBLE:        data.format = "%lf";    break;
            case CHAR:          data.format = "%c";     break;
            case STRING:        data.format = "%s";     break;

            default:            data.format = STRING_EMPTY_PLACEHOLDER; 
                                break;
        }

        head = push_back(head, data);
        i++;
    }
    

    return head;
}


/* 
 *  Creates a heterogeneous data struct from user input
 */
hetdata_t input_data(void)
{
    hetdata_t data;


    printf("\n[DATA BLOCK INPUT]");
    show_data_types();
    printf("\n");

    do
    {
        data.type = *((type_t*)safe_input(U_INT, STRING_BUFFER_SIZE, "Choose data type to insert: "));
    } 
    while ( !is_data_type(data.type) );
    

    switch (data.type)
    {
        case SHORT_INT:     data.format = "%hd";    break;
        case U_SHORT_INT:   data.format = "%hu";    break;
        case INT:           data.format = "%d";     break;
        case U_INT:         data.format = "%u";     break;
        case LONG_INT:      data.format = "%ld";    break;
        case U_LONG_INT:    data.format = "%lu";    break;
        case FLOAT:         data.format = "%f";     break;
        case DOUBLE:        data.format = "%lf";    break;
        case CHAR:          data.format = "%c";     break;
        case STRING:        data.format = "%s";     break;

        default:            data.format = STRING_EMPTY_PLACEHOLDER; 
                            break;
    }

    data.val = safe_input(data.type, STRING_BUFFER_SIZE, "Insert value: ");
    
    return data;
}


/*
 *  Safe input method that can get an user input in different 
 *  data types (see the "enum type" for the complete list) by
 *  first acquiring user input in a buffer and then formatting it
 *  as specified by the function parameters. Then the function
 *  returns a void pointer that needs to be formatted afterwards
 *  into the correct type
 */
void * safe_input(const type_t type_selector, const unsigned long int bufsize, char *message)
{
    void *result;
    char *buf, *format, *filtered_buf;
    bool_t acquired_input;


    if (bufsize > 0)
    {
        switch (type_selector)
        {
            case SHORT_INT:     format = "%hd";
                                result = (short*)malloc(sizeof(short int));
                                break;
            
            case U_SHORT_INT:   format = "%hu";
                                result = (unsigned short int*)malloc(sizeof(unsigned short int));
                                break;

            case INT:           format = "%d";
                                result = (int*)malloc(sizeof(int));
                                break;
            
            case U_INT:         format = "%u";
                                result = (unsigned int*)malloc(sizeof(unsigned int));
                                break;

            case LONG_INT:      format = "%ld";
                                result = (long int*)malloc(sizeof(long int));
                                break;
            
            case U_LONG_INT:    format = "%lu";
                                result = (unsigned long int*)malloc(sizeof(unsigned long int));
                                break;

            case FLOAT:         format = "%f";
                                result = (float*)malloc(sizeof(float));
                                break;

            case DOUBLE:        format = "%lf";
                                result = (double*)malloc(sizeof(double));
                                break;

            case CHAR:          format = "%c";
                                result = (char*)malloc(sizeof(char));
                                break;

            case STRING:        format = "%s";
                                result = (char*)malloc(sizeof(char) * (bufsize + 1));
                                break;

            default:            format = STRING_EMPTY_PLACEHOLDER;
                                result = NULL;
        }

        if (result)
        {
            if (( buf = (char*)malloc(sizeof(char) * (bufsize + 1)) ))
            {
                acquired_input = false;
                fflush(stdin);

                do
                {
                    if (message)
                    {
                        printf("%s", message);
                    }

                    /* 
                     *  NOTE: 
                     *  -   fgets() puts an END_OF_STRING ('\0') character at the 
                     *      end of the buffer if no errors occur during input
                     */
                    if (fgets(buf, bufsize + 1, stdin))
                    {
                        if (type_selector != STRING)
                        {
                            if (1 == sscanf(buf, format, result))
                            {
                                acquired_input = true;
                            }
                        }
                        else
                        {
                            filtered_buf = filter(buf, NEWLINE_CHAR);
                            memcpy(result, filtered_buf, strlen(filtered_buf));

                            acquired_input = true;
                        }
                    }
                }
                while ( !acquired_input );

                free(buf);
            }
            else
            {
                printf("[safe_input()] ERROR: Memory allocation was unsuccessful\n");
            }
        }
        else
        {
            if (strcmp(format, STRING_EMPTY_PLACEHOLDER) == 0)
            {
                printf("[safe_input()] ERROR: Memory allocation was unsuccessful\n");
            }
            else
            {
                printf("[safe_input()] ERROR: The selected type does not exist in the list of specified ones\n");
            }
        }
    }
    else
    {
        result = NULL;
        printf("[safe_input()] ERROR: The give buffer size can only be greater than zero\n");
    }

    return result;
}


/*
 *  Allocates an empty instance of an heterogeneous data block
 */
hetdata_t * create_data_block(void *val, type_t type, char *format)
{
    hetdata_t *data;


    if (( data = (hetdata_t*)malloc(sizeof(hetdata_t)) ))
    {
        data->val = val;
        data->format = format;
        data->type = type;
    }
    else
    {
        printf("[create_empty_data_block()] ERROR: Memory allocation was unsuccessful\n");
    }

    return data;
}


/*
 *  Filters out all the given 'remove' characters found in str
 */
char * filter(char *str, char remove)
{
    char *filtered;
    int i, j, len;
   

    filtered = NULL;

    if (str)
    {
        len = strlen(str);
        i = 0;

        while ((str + i) && *(str + i) != END_OF_STRING)
        {   
            if ( *(str + i) == remove)
            {
                len--;
            }
            i++;
        }

        if (( filtered = (char*)malloc(sizeof(char) * (len + 1)) ))
        {
            i = 0;
            j = 0;

            while ((str + i) && *(str + i) != END_OF_STRING)
            {
                if (*(str + i) != remove)
                {
                    *(filtered + j) = *(str + i);
                    j++;
                }
                i++;
            }

            *(filtered + len) = END_OF_STRING;
        }
        else
        {
            printf("[filter()] ERROR: Memory allocation was unsuccessful\n");
        }
    }

    return filtered;
}


/*
 *  Given two source strings src1 and src2, it returns the concatenation 
 *  of the beginning of src2 to the end of src1
 */
char * strconcat(char *src1, char *src2)
{
    char *str;
    int len1, len2, len;
    int i;


    str = NULL;

    if (src1 && src2)
    {
        len1 = strlen(src1);
        len2 = strlen(src2);
        len = len1 + len2;

        if (( str = (char*)malloc(sizeof(char) * (len + 1)) ))
        {
            i = 0;

            while (i < len1)
            {
                *(str + i) = *(src1 + i);
                i++;
            }

            i = 0;

            while (i < len2)
            {
                *(str + len1 + i) = *(src2 + i);
                i++;
            }

            *(str + len) = END_OF_STRING;
        }
        else
        {
            printf("[strconcat()] ERROR: Memory allocation was unsuccessful\n");
        }
    }

    return str;
}


/* 
 *  Returns true (1) if the given type is a C type, false (0) otherwise
 */
bool_t is_data_type(type_t type)
{
    return (type >= 0 && type <= 9);
}


/* 
 *  Pushes a new list element to the top of the list
 */
dl_list_t * push_front(dl_list_t *head, hetdata_t data)
{
    dl_list_t *new_elem;


    if (( new_elem = (dl_list_t*)malloc(sizeof(dl_list_t)) ))
    {
        new_elem->data.val = data.val;
        new_elem->data.format = data.format;
        new_elem->data.type = data.type;

        new_elem->prev = NULL;
        new_elem->next = head;
        
        if (head)
        {
            head->prev = new_elem;
        }
        
        head = new_elem;
    }
    else
    {
        printf("[push_front()] ERROR: Memory allocation was unsuccessful\n");
    }

    return head;
}


/* 
 *  Pushes a new list element to the end of the list
 */
dl_list_t * push_back(dl_list_t *head, hetdata_t data)
{
    dl_list_t *new_elem, *ptr;


    if (( new_elem = (dl_list_t*)malloc(sizeof(dl_list_t)) ))
    {
        new_elem->data.val = data.val;
        new_elem->data.format = data.format;
        new_elem->data.type = data.type;

        if (head)
        {
            ptr = head;

            while (ptr->next)
            {
                ptr = ptr->next;
            }

            ptr->next = new_elem;
            new_elem->prev = ptr;
            new_elem->next = NULL;
        }
        else
        {
            head = new_elem;
            new_elem->prev = NULL;
            new_elem->next = NULL;
        }
    }
    else
    {
        printf("[push_back()] ERROR: Memory allocation was unsuccessful\n");
    }

    return head;
}


/* 
 *  Pops the first element, found on head, from the list
 */
dl_list_t * pop_front(dl_list_t *head, hetdata_t *data)
{
    dl_list_t *del;

    if (head && data != NULL)
    {
        data->val = head->data.val;
        data->format = head->data.format;
        data->type = head->data.type;

        del = head;
        head = head->next;
        free(del);

        if (head)
        {
            head->prev = NULL;
        }
    }
    else
    {
        printf("[pop_front()] ERROR: The given data buffer is not initialized\n");
    }

    return head;
}


/* 
 *  Pops the last element from the list
 */
dl_list_t * pop_back(dl_list_t *head, hetdata_t *data)
{
    dl_list_t *ptr, *prev;


    if (head && data != NULL)
    {
        ptr = head;
        prev = NULL;

        while (ptr->next)
        {
            prev = ptr;
            ptr = ptr->next;
        }

        data->val = ptr->data.val;
        data->format = ptr->data.format;
        data->type = ptr->data.type;

        free(ptr);

        if (prev)
        {
            prev->next = NULL;
        }
    }
    else
    {
        printf("[pop_back()] ERROR: The given data buffer is not initialized\n");
    }

    return head;
}


/*
 *  Deletes the first instance of val found in the list
 */
dl_list_t * delete_instance(dl_list_t *head, hetdata_t *data)
{
    dl_list_t *ptr, *prev, *del;
    bool_t found;

    
    if (head)
    {
        ptr = head;
        prev = NULL;
        found = false;

        while (ptr && !found)
        {
            if (ptr && ptr->data.type == data->type)
            {                
                switch (ptr->data.type)
                {
                    case SHORT_INT:     found = (*((short int*) ptr->data.val) == *((short int*) data->val));                       break;
                    case U_SHORT_INT:   found = (*((unsigned short int*) ptr->data.val) == *((unsigned short int*) data->val));     break;
                    case INT:           found = (*((int*) ptr->data.val) == *((int*) data->val));                                   break;
                    case U_INT:         found = (*((unsigned int*) ptr->data.val) == *((unsigned int*) data->val));                 break;
                    case LONG_INT:      found = (*((long int*) ptr->data.val) == *((long int*) data->val));                         break;
                    case U_LONG_INT:    found = (*((unsigned long int*) ptr->data.val) == *((unsigned long int*) data->val));       break;
                    case FLOAT:         found = (*((float*) ptr->data.val) == *((float*) data->val));                               break;
                    case DOUBLE:        found = (*((double*) ptr->data.val) == *((double*) data->val));                             break;
                    case CHAR:          found = (*((char*) ptr->data.val) == *((char*) data->val));                                 break;
                    case STRING:        found = (strcmp(((char*) ptr->data.val), ((char*) data->val)) == 0);                        break;

                    default:            printf("[delete_all_instances()] ERROR: The given type is not a default C type\n");         break;
                }
            }

            if (found)
            {
                if (ptr == head)
                {
                    del = head;
                    head = head->next;

                    if (head)
                    {
                        head->prev = NULL;
                    }
                    
                    free(del);
                    ptr = head;
                }
                else
                {
                    del = ptr;
                    ptr = ptr->next;
                    prev->next = ptr;

                    if (ptr)
                    {
                        ptr->prev = prev;
                    }

                    free(del);
                }   
            }
            else
            {
                prev = ptr;
                ptr = ptr->next;
            }
        }
    }

    return head; 
}


/*
 *  Deletes ALL instances of val found in the list
 */
dl_list_t * delete_all_instances(dl_list_t *head, hetdata_t *data)
{
    dl_list_t *ptr, *prev, *del;
    bool_t found;

    
    if (head)
    {
        ptr = head;

        while (ptr)
        {
            found = false;

            if (ptr->data.type == data->type)
            {
                switch (ptr->data.type)
                {
                    case SHORT_INT:     found = (*((short int*) ptr->data.val) == *((short int*) data->val));                       break;
                    case U_SHORT_INT:   found = (*((unsigned short int*) ptr->data.val) == *((unsigned short int*) data->val));     break;
                    case INT:           found = (*((int*) ptr->data.val) == *((int*) data->val));                                   break;
                    case U_INT:         found = (*((unsigned int*) ptr->data.val) == *((unsigned int*) data->val));                 break;
                    case LONG_INT:      found = (*((long int*) ptr->data.val) == *((long int*) data->val));                         break;
                    case U_LONG_INT:    found = (*((unsigned long int*) ptr->data.val) == *((unsigned long int*) data->val));       break;
                    case FLOAT:         found = (*((float*) ptr->data.val) == *((float*) data->val));                               break;
                    case DOUBLE:        found = (*((double*) ptr->data.val) == *((double*) data->val));                             break;
                    case CHAR:          found = (*((char*) ptr->data.val) == *((char*) data->val));                                 break;
                    case STRING:        found = (strcmp(((char*) ptr->data.val), ((char*) data->val)) == 0);                        break;

                    default:            printf("[delete_all_instances()] ERROR: The given type is not a default C type\n");         break;
                }
            }
            
            if (found)
            {
                if (ptr == head)
                {
                    del = head;
                    head = head->next;

                    if (head)
                    {
                        head->prev = NULL;
                    }
                    
                    free(del);
                    ptr = head;
                }
                else
                {
                    del = ptr;
                    ptr = ptr->next; 
                    prev->next = ptr;

                    if (ptr)
                    {
                        ptr->prev = prev;
                    }

                    free(del);
                }
            }
            else
            {
                prev = ptr;
                ptr = ptr->next;
            }
        }
    }

    return head; 
}


/* 
 *  Deletes ALL ITEMS in the list
 */
dl_list_t * delete_dl_list(dl_list_t *head)
{
    dl_list_t *del;


    while (head)
    {
        del = head;
        head = head->next;
        free(del);
    }

    return head;
}


/*
 *  Searches the list for the given value, returns a pointer to it if
 *  it's been found, NULL otherwise
 */
dl_list_t * find(dl_list_t *head, hetdata_t *data)
{
    dl_list_t *ptr;
    bool_t found;


    ptr = NULL;

    if (head)
    {
        ptr = head;
        found = false;

        while (ptr && !found)
        {
            if (ptr->data.type == data->type)
            {                
                switch (ptr->data.type)
                {
                    case SHORT_INT:     found = (*((short int*) ptr->data.val) == *((short int*) data->val));                       break;
                    case U_SHORT_INT:   found = (*((unsigned short int*) ptr->data.val) == *((unsigned short int*) data->val));     break;
                    case INT:           found = (*((int*) ptr->data.val) == *((int*) data->val));                                   break;
                    case U_INT:         found = (*((unsigned int*) ptr->data.val) == *((unsigned int*) data->val));                 break;
                    case LONG_INT:      found = (*((long int*) ptr->data.val) == *((long int*) data->val));                         break;
                    case U_LONG_INT:    found = (*((unsigned long int*) ptr->data.val) == *((unsigned long int*) data->val));       break;
                    case FLOAT:         found = (*((float*) ptr->data.val) == *((float*) data->val));                               break;
                    case DOUBLE:        found = (*((double*) ptr->data.val) == *((double*) data->val));                             break;
                    case CHAR:          found = (*((char*) ptr->data.val) == *((char*) data->val));                                 break;
                    case STRING:        found = (strcmp(((char*) ptr->data.val), ((char*) data->val)) == 0);                        break;

                    default:            printf("[delete_all_instances()] ERROR: The given type is not a default C type\n");         break;
                }
            }
            
            if ( !found )
            {
                ptr = ptr->next;
            }
        }
    }

    return ptr;
}


/*
 *  Creates and returns an exact copy of the given list
 */
dl_list_t * copy_dl_list(dl_list_t *head)
{
    dl_list_t *copy;
    hetdata_t data;


    copy = NULL;

    while (head)
    {
        data.val = head->data.val;
        data.format = head->data.format;
        data.type = head->data.type;

        copy = push_back(copy, data);

        head = head->next;
    }

    return copy;
}
