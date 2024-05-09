# heterogeneous_double_linked_list_library
C (ANSI 89) double linked list library that can hold heterogeneous data, achieved through the extensive use of void pointers.

- - -

# Brief Introduction:
This library implements double linked lists in C (ANSI 89), which are an "extension" of simply linked list due to 
the fact that the former have bidirectional links and the latter only have unidirectional links.

Another feature of this library is the ability to store heterogeneous data types in a single list, thus behaving 
similarly to heterogeneous elements lists in other higher-level programming languages (e.g. Python, Kotlin, etc...)

The heterogeneous characteristic is achieved through the use of <code>void</code> pointers.

In particular, the supported data types are:
- <code>string</code>
- All C basic types, which are:
  - <code>short int</code>
  - <code>unsigned short int</code>
  - <code>int</code>
  - <code>unsigned int</code>
  - <code>long int</code>
  - <code>unsigned long int</code>
  - <code>float</code>
  - <code>double</code>
  - <code>char</code>

- - -

# Data Packets
To make the library capable of working with and creating lists that hold heterogeneous data types, each list item
contains a <code>struct</code> data type defined as:

```C
/* Heterogeneous Data Packet Definition */
typedef struct hetdata
{
    void *val;
    type_t type;
    char *format;
}
hetdata_t;
```

This particular object, which I like to call "_data packet_", contains 3 fields: _val_, _type_ and _format_:
- _val_ is a <code>void</code> pointer (<code>void*</code>) that points to a memory cell that contains some data
- _type_ is an integer (from 0 to 9, extremes included) that enumerates all the data types supported by the library, and it's used to describe the data pointed by _val_
- _format_ is a <code>string</code> containing the formatting characters required for the correct input/output of that particular data type

And it's thanks to this <code>struct</code> that the library can hold heterogeneous data in a single list.

- - -
