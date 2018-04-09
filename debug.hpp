#ifndef debug_hpp
#define debug_hpp

#include <stdio.h>

#ifdef DEBUG
#define log(x) std::cout << x << std::endl;
#else
#define log(x)
#endif

#endif /* debug_hpp */
