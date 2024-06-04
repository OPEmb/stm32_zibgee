#ifndef MACROS_H
#define MACROS_H
//stringification of the argument Arg
#define PP_STRINGIFY(Arg) PP_STRINGIFY_(Arg)
#define PP_STRINGIFY_(Arg) #Arg

//concatenation of the two arguments
#define PP_CAT2(_1, _2) PP_CAT_(_1, _2)
#define PP_CAT_(_1, _2) _1##_2

//enumerate the number of arguments (min:1, max: 8)
#define PP_VA_NUM_ARGS(...) PP_VA_NUM_ARGS_(__VA_ARGS__,8,7,6,5,4,3,2,1)
#define PP_VA_NUM_ARGS_(_1,_2,_3,_4,_5,_6,_7,_8,N,...) N

#define ARR_SIZE(x) sizeof((x))/sizeof((x)[0])

#endif /* MACROS_H */