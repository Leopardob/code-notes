//////////////////////////////////////////////////////////////////////////////
//STL NOTES
//////////////////////////////////////////////////////////////////////////////
/*

ATAN-ATAN2 DIFFERENCES:
ATAN2: Looks at 4 quadrants
ATAN: Looks at 2 quadrants
                                   +y
    atan(-x/+y) = +angle [0,-90]   |   atan(+x/+y) = +angle [0,90]
   atan2(-x,+y) = +angle [0,-90]   |   atan2(+x,+y) = +angle [0,90]
                                   |
                       -x----------|----------+x
                                   |
    atan(-x/-y) = +angle [0,-90]   |   atan(+x/-y) = -angle [0,90)
atan2(-x,-y) = +angle [-90,-180)   |   atan2(+x,-y) = +angle [90,180]
                                   -y

STL ALGORITHMS
� Non-modifying: on const objects; Modifying: on non-const objects
� Preferable to use container's equivalent method for stability
� All ranges are [Start, End) with End non-inclusive
� Algorithms that copy over a range can be changed to insert with back/front insert iterators
� Comparison lambdas should always return false for equal values
� Functors used are passed by-val, should be a pure function
� In-build functors are faster than passing lambdas/function pointers due to them being inlined

SORT/SEARCHING
Sorting Fastest-slowest: Partitions, Partial sorting, Full sorting, Stable sorting
Require sort ascending, Search speed O(logN): binary_search, lower_bound, upper_bound, equal_range
Don't require sorting, Search speed O(N): count, count_if, find, find_if
                       
CONDITION          UNSORTED      SORTED               SET/MAP         MULTI SET/MAP
does obj exist     std::find     std::binary_search  .count()        .find()
find obj           std::find     std::equal_range    .count()        .find()     
no. obj with val   std::count    std::equal_range    .count()        .count()
find all obj       std::find     std::equal_range    .equal_range()  .equal_range()
find obj if        std::find_if  std::lower_bound    .lower_bound()  .lower_bound()      

//////////////////////////////////////////////////////////////////////////////
//SEQUENCE CONTAINERS
//////////////////////////////////////////////////////////////////////////////

VECTOR
� random access to elements
� fast with adding/removing end (constant time)
� slow with adding/removing/inserting to start or middle (linear time)
� keeps values in one chunk of continuous memory

VECTOR<BOOL>
� Not a STL container and doesn't hold bools
� Each element occupies single bit and represents bitfields
� Can't create pointers/references to individual bits
� To counter this returns a proxy object instead
� vector<bool>::iterator is not random-access, forward or bi-directional
� deque<bool> actually contains bool; vector<bool> was an experiment

DEQUE
� double ended queue with random access
� constant time for removing/adding/inserting at end and beginning
� slower than lists, faster than vectors for removing/adding/inserting
� slower than vectors with accessing individual members
� stores data in various chucks with pointers to keep track of next lot
� not safe with pointer maths as memory not all in one piece

LIST/FORWARD LIST
� List: doubly-linked list with iteration in both directions
� Forward List: single-linked lists with iteration only forward
� Forward list smaller and more effecient
� not safe with pointer maths as memory not all in one piece
� no random access, slow to search (must iterate through list)
� Constant time insert and erase operations anywhere within the sequence
� Faster than other containers for sorting, inserting, erasing
� Larger than other containers for storing linkage information

STRING
� Data for strings not guaranteed to be stored in continuous memory
� Internal representation of string not guaranteed to end with null character

//////////////////////////////////////////////////////////////////////////////
//CONTAINER ADAPTERS
//////////////////////////////////////////////////////////////////////////////
Adaptions of sequence containers

QUEUE
� first-in-first-out
� queue without random access
� no iteration
� built on top of deque using inline functions

PRIORITY-QUEUE
� first-in-first-out
� queue without random access
� no iteration
� sorted in terms of most important using heap search
� built on top of vector & heap structure using inline functions 

STACK
� last-in-first-out
� no random access
� no iteration
� built on top of deque using inline functions

HEAP
� created using a vector/deque container
� Element with highest value is always at top of heap
� Fast insertion of new elements

//////////////////////////////////////////////////////////////////////////////
//ASSOCIATIVE CONTAINERS
//////////////////////////////////////////////////////////////////////////////

MAP
� fast for range iteration over elements
� elements sorted from lowest to highest with their key
� uses a balanced binary tree to store values, has a O(logN) lookup/insert time
� Multi map can have multiple values to the one key
� Unordered map not sorted, fast for accessing individual elements by key
� Map iterators point to pairs where key is const to prevent breaking sorted order

SET
� elements themselves are the keys
� elements in a set are always sorted from lower to higher
� multi set can have multiple values to the one key
� If changing value in set using iterator, make sure set is resorted

//////////////////////////////////////////////////////////////////////////////
//STL ITERATORS
//////////////////////////////////////////////////////////////////////////////

CONST ITERATOR/ITERATOR/REVERSE ITERATOR
� Vector/Array/Deque: Random Access Iterator
� List: Bidirectional Iterator
� Forward List: Forward Iterator, no reverse iterator
� Map: Bidirectional Iterator

begin()    cbegin()    iterator to start            map, array, deque, vector, list, forward list
rbegin()   crbegin()   iterator to last value       map, array, deque, vector, list
end()      cend()      iterator to one past end     map, array, deque, vector, list, forward list
rend()     crend()     iterator to one past start   map, array, deque, vector, list

BACK INSERT ITERATOR
� Output iterator
� inserts items at the end of the container. 
� calls .push_back(), only used with containers that have it (vector, deque, string, list)

FRONT INSERT ITERATOR
� Output iterator
� inserts items at the front of the container.
� calls .push_front(), only used with containers that have it (deque, list)

INSERT ITERATOR
� Output iterator
� inserts items in front of the location specified as an argument

OSTREAM ITERATOR
� Output iterator
� ineffecient due to lots of error checking/formatting

OSTREAMBUF ITERATOR
� Output iterator
� Faster than ostream_iterator

ISTREAM ITERATOR
� Input iterator
� ineffecient due to lots of error checking/formatting

ISTREAMBUF ITERATOR
� Input iterator
� Faster than istream_iterator, doesn't skip over any character
� directly grabs what's next in stream buffer, no extra checking/formatting

//////////////////////////////////////////////////////////////////////////////
//ITERATOR TYPES
//////////////////////////////////////////////////////////////////////////////

INPUT ITERATOR
� iterator that a program can use to read only
� single pass, one way iterator; can't back up once incremented
� each time one moves through container, different order of moving 
  through elements

OUTPUT ITERATOR
� iterator that a program can use to write only
� single pass, one way iterator; can't back up once incremented
� each time one moves through container, different order of moving 
  through elements

FORWARD ITERATOR
� Goes through sequence in same order each time
� Multi pass, can still access prior elements once incremented
� Read and write abilities

BIDIRECTIONAL ITERATOR
� Goes through sequence in same order each time
� Multi pass, Can increment and decrement
� Read and write abilities

RANDOM ACCESS ITERATOR
� Goes through sequence in same order each time
� Can jump to any element in container
� Multi pass, Can increment and decrement
� Read and write abilities

--------------------------------------------------------------------
Capability    Input   Output   Forward  Bidirectional Random Access
--------------------------------------------------------------------
Read          Yes     No       Yes      Yes           Yes
Write         No      Yes      Yes      Yes           Yes
Fixed order   No      No       Yes      Yes           Yes
++i/i++       Yes     Yes      Yes      Yes           Yes
--i/i--       No      No       No       Yes           Yes
i[n]          No      No       No       No            Yes
i+n, i-n      No      No       No       No            Yes
i+=n, i-=n    No      No       No       No            Yes

//////////////////////////////////////////////////////////////////////////////
//ITERATOR/REFERENCE INVALIDATION
//////////////////////////////////////////////////////////////////////////////

VECTOR/PRIORITY-QUEUE
� Insertion: Before point of insertion unaffected unless container size is 
  greather than previous capacity and vector needs to be recopied.
� Erasure: All after point of erase are invalidated.

DEQUE/QUEUE/STACK
� Insertion: All invalidated unless inserted member is at the front or back in
  which iterators are invalidated and references are not.
� Erasure: All invalidated unless erased member is at the front or back in
  which only the member erased is invalidated.

LIST/MAP/SET
� Inerstion: All unaffected.
� Erasure: Only the erased member is invalidated.

//////////////////////////////////////////////////////////////////////////////
//CONTAINER MEMORY ALLOCATION
//////////////////////////////////////////////////////////////////////////////

ALLOCATORS
� Handle requests for allocation and deallocation of memory for a container
� Default ones use operator new/malloc for allocation
� Custom ones may improve performance/memory usage
� Useful if lots of small allocations for associative containers as default is slow

MEMORY POOL ALLOCATOR
� Custom allocator design where large block of memory is allocated beforehand
� Requests by container are from the pool and returned to the pool
� Pool is deallocated when lifetime of container ends

//////////////////////////////////////////////////////////////////////////////
//IOSTREAM (INPUT/OUTPUT)
//////////////////////////////////////////////////////////////////////////////

BUFFER
� Bloack of memory for storage/transfer of information
� Flushed when endl, when full or when specified
� Controls rate of stream of bytes to/from buffer

BITMASK TYPES    
� OPENMODE: bitmask type for setting the file mode
� FMTFLAGS: Setting the formatting for the stream
� IOSTATE: A stream state contained in a cout/cin object
           eofbit  = Is set to 1 if end-of-file reached.
           badbit  = Is set to 1 if the stream has file read error
           failbit = Is set to 1 if an input operation failed to read/write expected characters

IOSTREAM
� Creates 8 stream objects (four narrow/four wide character streams)
  CIN/WCIN
  COUT/WCOUT
  CERR/WCERR (error stream unbuffered)
  CLOG/WCLOG (error stream)

FILESTREAM
� Redirects the input/output streams to either use a file instead of console
� This doesn't affect CERR or CLOG unless changed.

OSTREAM CLASS
� translates data as binary bit patterns to an output stream of char bytes
� ostream & operator<<(type); returns reference back to the ostream object
� all methods return ostream type allowing concatenation (cout.put(1).put(1))
� cout << "one" << endl; "one" sent to buffer, returns cout. 
� Endl reached, buffer flushes, inserts \n, no cout returned.

ISTREAM CLASS
� translates data as char from the input stream into binary bit patterns
� istream & operator>>(type &); returns reference back to the istream object
� all methods return istream type allowing concatenation

BINARY FILES
� Smaller, take up less room
� No hidden conversions; written in computer binary language
� More accurate as no conversion/round-off errors for numbers
� Risky as different computers have different internal representation

//////////////////////////////////////////////////////////////////////////////
//EXCEPTIONS
//////////////////////////////////////////////////////////////////////////////

THROW BY VALUE, CATCH BY REFERENCE
� Don't throw pointers, if absolutely needed, use a smart pointer
� Catch by reference to enable polymorphism for the thrown object

UNWINDING THE STACK: 
� When exception is thrown, copy of thrown variable is made 
� Copy made even if ref specified since needing it after function out of scope

� Reference used to allow inheritance with catching exception types 
� Stack releases memory until reaching the corresponding try-catch block
� Any destructors are called on way- if exception is called in destructor, 
  it must resolve it otherwise two exceptions are occuring
� Pointers are destroyed without calling delete. Solved through smart pointers

If Exception type wasn't explicitly thrown: unexpected()->terminate()->abort()
If Exception type was known but not caught: terminate()->abort()

*/////////////////////////////////////////////////////////////////////////////