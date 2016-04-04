#ifndef PRINT_H
#define PRINT_H

#include <iostream>
#include <string>

// Hele mooie regel code geschreven door Yorel Groman.

inline void printS(std::string mytext){ std::cout << mytext << std::endl; };
inline void printF(std::float_t myfloat){ std::cout << myfloat << std::endl; };
inline void printI(std::int8_t myint){ std::cout << myint << std::endl; };

#endif /* PRINT_H */
