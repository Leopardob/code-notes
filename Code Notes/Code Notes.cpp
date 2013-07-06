//////////////////////////////////////////////////////////////////////////////
//VARIABLES
//////////////////////////////////////////////////////////////////////////////
/*

MINIMUM STANDARDS     BYTES   BITS    SUFFIX    RANGE
short (short int)     2       16                –32768 to 32767
unsigned short        2       16       U        0 to 65535
int                   2/4     16/32             Depends on machine, minimum size of short
unsigned int          2/4     16/32    U        Depends on machine, minimum size of short
long (long int)       4       32       L        –2147483648 to 2147483647                  
unsigned long         4       32       UL       0 to 4294967295
long long             8       64       LL       –9223372036854775808 to 9223372036854775807
unsigned long long    8       64       ULL      0 to 18446744073709551615
char                  1       8        ''       Signage Dependent on compiler
signed char           1       8        ''       0 to 255
unsigned char         1       8        ''       –128 to 127                
bool                  1       8                 0 to 1
float                 4       32       F        3.4E +/- 38 (7 digits)   
double                8       64                1.7E +/- 308 (15 digits)             
long double           8       64       L        1.7E +/- 308 (15 digits)
pointer/reference     4/8     32/64             Depends on whether 32/64 bit machine

BYTE: 8 bits (256 values; 2⁸)
WORD: 2 bytes
DOUBLE WORD: 2 words
QUAD WORD: 2 double words

HEXADECIMAL: 
1-F (1-15 where A = 10)
Two hex values = one byte
0xff = 0xffffffff = 255 = 11111111

LOCAL SCOPE: Variable defined in a block
GLOBAL SCOPE: Variable defined outside a block, can be in a namespace
CLASS SCOPE: Member Variables in a class
FUNCTION PROTOTYPE SCOPE: Variables in function prototype

PUBLIC/EXTERNAL LINKAGE: Can be accessed accross files
PRIVATE/INTERNAL LINKAGE: Can only be accessed by file declared in

DECLARING VARIABLES:
 • Determines how much memory is needed for a data object
 • Determines how the bits in memory are interpreted 
  (bool and char use same amount of memory but shown differently)
 • Determines what methods can be performed using the data object.

NAMING CONVENTION
 • Characters usable: alphabet, numbers, underscore character
 • The first character in a name cannot be a numeric digit.
 • Uppercase characters are considered distinct from lowercase characters.
 • You can’t use a C++ keyword for a name.
 • C++ places no limits on the length of a name
 • Names beginning with __ or _ are reserved for use by the compiler

===========================================================================
VARIABLES TYPES
===========================================================================

VALUE TYPES: have automatic storage, stored on stack/register
REFERENCE TYPES: have dynamic storage, stored on heap 
STATIC TYPES: have static storage, stored in fixed seperate memory/data segment

STATIC VARIABLES
• Static typed variables: class members, local or global variables
• Class members initialised to 0 or given value from class .cpp before main called
• Global/Local initialised to 0 until first use then re-initialised to given value when used
• Global variables: don't require static keyword to be static typed (keyword determines linkage)
• Static const variables: if type is known may be replaced throughout program as macro

TEMPORARY VARIABLES
• Value-typed variables auto created on the stack during:
    - reference initialization
    - expression evaluation
    - automatic type conversion
    - function passing/returning
• Move semantics reduces creation of temp variables

CONST VARIABLES
• If type is known and only used as a literal variable, replaced as a macro at compile time
• If type unknown or is refered to, may be stored in fixed seperate memory/data segment
• Variable const-casted remains in same location but cannot change values
• Pros: Using const allows both const and non-const objects to use a method
• Pros: Using const protects you against accidently editing data
• Cons: Usage must be maintained otherwise useless
• Cons: Hard to tell if variable is const stored in seperate memory or just const casted

===========================================================================
CONVERSION
===========================================================================
TYPE-SAFETY: How much language allows type errors/conversion (ie. int as float)
TYPECASTING: Forcing conversion explicitly
AUTOMATIC TYPE CONVERSION: Automatically converted by compilier
  • INTEGRAL CONVERSION: Short, char and bool converted to int by compilier before usage
  • STANDARD CONVERSION: Conversion between types without loss of data (int to char)
  • PROMOTION: Lower types down the list are converted up to a larger type
    Long Double
     ↑ Double
       ↑ Float
         ↑ Unsinged Long Int
           ↑ Long Int
             ↑ Unsigned Int
               ↑ Int
                 ↑ Unsigned Short
                   ↑ Short

//////////////////////////////////////////////////////////////////////////////
//CHARACTERS AND OPERATORS
//////////////////////////////////////////////////////////////////////////////

%  Remainder whole number after how many x is in y
:: Scope resolution operator

CHARACTER CODES
Newline = \n 
Horizontal tab = \t
Backspace = \b
Backslash  = \\
Single quote = \’
Double quote = \”
Return = \r
Null character = \0
int('A') = 65 for ASCII

SEQUENCE POINTS
;  [ int x = 0; ]
,  [ f(x,y) ]
|| [ x || y ]
&& [ x && y }
?: [ x ? y : 0 ]
• After a function's returned object has been copied back to the caller
• After evaluation of all a function's parameters when the function is called
• After the initialization of each base and member for an object

PRECENDENCE
if equal precedence then first one 
is done first in expression
()
!
* and / 
+ and - 
%
==
< and > 
&&
||
bitwise operators

//////////////////////////////////////////////////////////////////////////////
//MOVE SEMANTICS
//////////////////////////////////////////////////////////////////////////////

• Allows resources to transfer between objects rather than copying
• Automatically done when passing variables by-val for stl/conatiner/values
• STL containers no longer copy values when expanding; moves values via pointers
• Required for unique pointer (which can't be copied) usage in STL containers

                                EXPRESSION
                                /        \
                            GLVALUE    RVALUE
                            /     \    /    \
                        LVALUE    XVALUE   PRVALUE

GLVALUE: L-value or X-value
LVALUE: Persisting; appears on left side of assignment expression
RVALUE: Temporary; appears on right side of assignment expression
XVALUE: Value that will expire soon (Rvalue reference function return)
PRVALUE: Rvalue that isn't an xvalue (Non-reference function return)

//////////////////////////////////////////////////////////////////////////////
//POINTERS
//////////////////////////////////////////////////////////////////////////////

DEEP COPY: Underlying memory the reference/pointer points to is copied
SHALLOW COPY: Reference/pointer is copied and points to original data

VARIABLES/OBJECTS: &name gives address of object
C-STYLE ARRAY: name gives address of first element
CSTRING/STRING LITERAL: name gives string, &name gives address of first character

===========================================================================
POINTERS/REFERENCES DIFFERENCES
===========================================================================
• Pointers hold a memory address; reference is another name for variable.
• Pointer must be dereferenced, reference just uses name
• References can't change once initialised. Pointers can change what they point to.s
• References can't easily be nullptr or void, pointers can
• Multiple levels of Pointers, one level of reference
• Pointers use -> for classes/structures while references use .

===========================================================================
SMART POINTERS
===========================================================================

SHARED POINTER
• uses reference counting; when goes to 0, object is deleted
• supports copying/assigning/usage in STL containers
• can't detect cyclic dependencies

WEAK POINTER
• non-owning observers of an object owned by shared_ptr.
• does not use reference counting
• when object is deleted, all pointers are marked as invalid
• useful when having cyclic dependencies and in place of raw pointers

UNIQUE/SCOPED POINTER
• neither transferable nor sharable
• can't be copied, only moved, can be used in stl containers
• when pointer goes out of scope, object deleted
• std::unique_ptr requires default destructor to be declared if using forward dec

INTRUSIVE POINTER
• Shared pointer where reference counting is not done by the pointer object
• Helper function is used which is defined by the object that is pointed to

AUTO POINTER
• has sole ownership of the object which is passed if the pointer is copied
• if copied the original is set to nullptr; passing by-ref is okay
• can't point to arrays due to it using delete, not delete []
• can't point to memory on the stack
• can't be used in STL containers due to it's transfer ownership property

ARRAY POINTERS
• boost scoped_array; Simple sole ownership of arrays. Noncopyable.
• boost shared_array; Array ownership shared among multiple pointers.

===========================================================================
SMART POINTER REQUIREMENTS
===========================================================================

                            unique_ptr       shared_ptr
+------------------------+---------------+---------------+
|          P()           |      I        |      I        |
|  default constructor   |               |               |
+------------------------+---------------+---------------+
|      P(const P&)       |     N/A       |      I        |
|    copy constructor    |               |               |
+------------------------+---------------+---------------+
|         P(P&&)         |      I        |      I        |
|    move constructor    |               |               |
+------------------------+---------------+---------------+
|         ~P()           |      C        |      I        |
|       destructor       |               |               |
+------------------------+---------------+---------------+
|         P(A*)          |      I        |      C        |
+------------------------+---------------+---------------+
|  operator=(const P&)   |     N/A       |      I        |
|    copy assignment     |               |               |
+------------------------+---------------+---------------+
|    operator=(P&&)      |      C        |      I        |
|    move assignment     |               |               |
+------------------------+---------------+---------------+
|        reset()         |      C        |      I        |
+------------------------+---------------+---------------+
|       reset(A*)        |      C        |      C        |
+------------------------+---------------+---------------+

===========================================================================
NEW AND DELETE
===========================================================================
• Don’t use delete to free memory that new didn’t allocate.
• Don’t use delete to free the same block of memory twice in succession.
• Use delete [] if you used new [] to allocate an array.
• Use delete (no brackets) if you used new to allocate a single entity.
• It’s safe to apply delete to the null pointer (nothing happens).

PLACEMENT NEW:
• creates section of memory in stack
• can't use delete since its on the stack; deleted when goes out of scope
• FOR CLASS: destructor must be explicitly called before it goes out of scope

//////////////////////////////////////////////////////////////////////////////
//PROGRAM EXECUTION
//////////////////////////////////////////////////////////////////////////////

1) PREPROCESSOR
• Accepts Source code, Outputs Source code
• Removes comments and # directives

2) COMPILER
• Accepts Source code, Outputs machine/assembly/object code

3) LINKER
• Accepts machine code, Outputs machine code in form of executable
• Links together your code with any external libraries

STACK:
• Contains all local variables/parameters of functions below top
• Copies contents of all registers that were in use in each function below top
• Contains memory address of next instruction to execute for the function
  after the function it calls returns

STACK FRAME: Area of the stack that contains the local vars/parameters for a function
REGISTER: Fragments of memory that are the working area on the CPU
OPCODE: single executable machine language instruction
MNEMONICS: set to equal an opcode or a series of them/operands
OPERANDS: arguments given after the opcode
SEGMENTS: Program is organised into different sections

ESP: STACK POINTER REGISTER: Always points to the top of the stack
EBP: STACK BASE POINTER REGISTER: Pointer to data on the stack. 
EAX: ACCUMULATOR REGISTER: Primarly used for mathematical operations
EBX: BASE REGISTER: Pointer to data in a segment register
ECX: COUNTER REGISTER: Counter for string and loop operations
EDX: DATA REGISTER: Used in arithmetic operations and I/O operations
ESI: SOURCE REGISTER: Used as a pointer to a source in stream operations
EDI: DESTINATION REGISTER: Used as a pointer to a destination in stream operations
FLAGS REGISTER: Reports on the status of the program being executed
IP (INTRUCTION POINTER) REGISTER: Contains a pointer to the next intruction to be executed

DATA SEGMENT: Contains Initialized data segment and Uninitialized data segment(BSS)
INITIALIZED DATA SEGMENT: Contains global/static/constant data
UNINITIALIZED DATA SEGMENT(BSS): Contains uninitialised data

CDECL: Arugments passed via stack. Calling function cleans the stack; allows variadic functions
STDCALL: Arugments passed via stack. Called function cleans the stack; doesn't allow variadic functions
THISCALL: Arugments passed via stack. 'this' pointer passed in ecx register
FASTCALL: First 2-3 small arguments are passed in registers; Additional/large arguments passed via stack
          Calling function cleans the stack

BIG-O NOTATION:
Used to describe the performance of algorithm based on item amount
O(1) = doesn't depend on number of items
O(N) = depends on nummber of items using a power-of curve
O(logN) = depends on the number of items using a log curve

COMPILE TIME: action performed during compilation; uses no execution time.
CONSTANT TIME: time taken doesn't increase with number of elements
LINEAR TIME: time taken increases with number of elements

//////////////////////////////////////////////////////////////////////////////
//MEMORY REPRESENTATION
//////////////////////////////////////////////////////////////////////////////

FLOATING POINT PRECISION: Binary cannot express some floating point values (0.1) exactly
ENDIAN-NESS: Ordering of bytes in memory of a data object

LITTLE ENDIAN (BACKWARDS)
• multi-byte values are written least significant byte first
• used by x86 architecture
• 0x12345678 is written in memory as 78 56 34 12    

BIG ENDIAN (FORWARDS)
• multi-byte values are written most significant byte first
• 0x12345678 is written in memory as 12 34 56 78

TWOS COMPLEMENT
• Standard way of representing negative integers in binary
• + sign is changed by inverting all of the bits and adding one

    Start:    0001  (decimal 1)
    Invert:   1110
    Add One:  1111  (decimal -1)

//////////////////////////////////////////////////////////////////////////////
//MULTITHREADING
//////////////////////////////////////////////////////////////////////////////

• Threads within a program share same data space/information with main thread
• Thread has a beginning, execution sequence and conclusion
• Thread has instruction pointer- keeps track of where its currently running
• Threads can be interrupted and put to sleep while other threads are running

*//////////////////////////////////////////////////////////////////////////////