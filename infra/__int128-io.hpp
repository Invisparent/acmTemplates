//
// Created by Invisparent on 1/22/2023.
//

#ifndef __INT128_IO_HPP
#define __INT128_IO_HPP

#include <iostream>

inline __int128 i128_read() {
    int sgn = 1;
    __int128 retVal = 0;
    char ch = std::getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            sgn = -1;
        ch = std::getchar();
    }
    while (ch >= '0' && ch <= '9') {
        /**
         *  WARNING:
         *  DO NOT USE (ch ^ 48) INSTEAD
         *  It can't pass my test
         */
        retVal = (retVal << 1) + (retVal << 3) + (ch - 48);
        ch = std::getchar();
    }
    return sgn * retVal;
}

inline void i128_print(__int128 dat) {
    if (dat < 0) {
        std::putchar('-');
        dat = -dat;
    }
    if (dat > 9)
        i128_print(dat / 10);
    std::putchar(dat % 10 + '0');
}


#endif // __INT128_IO_HPP
