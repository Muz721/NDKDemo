//
// Created by Administrator on 2018/11/9.
//

#ifndef NDKDEMO_MD5UTILS_H
#define NDKDEMO_MD5UTILS_H

#include <string>

using namespace std;

#define F(x, y, z)((x&y)|(~x&z))
#define G(x, y, z)((x&z)|(y&~z))
#define H(x, y, z) (x^y^z)
#define I(x, y, z) (y ^ (x | ~z))
#define ROTATE_LEFT(x, n) ((x << n) | (x >> (32-n)))

#define FF(a, b, c, d, x, s, ac) { \
a += F(b, c, d) + x + ac; \
a = ROTATE_LEFT(a, s); \
a += b; \
}

#define GG(a, b, c, d, x, s, ac) { \
    a += G(b, c, d) + x + ac; \
    a = ROTATE_LEFT(a, s); \
    a += b; \
}

#define HH(a, b, c, d, x, s, ac) { \
    a += H(b, c, d) + x + ac; \
    a = ROTATE_LEFT(a, s); \
    a += b; \
}
#define II(a, b, c, d, x, s, ac) { \
    a += I(b, c, d) + x + ac; \
    a = ROTATE_LEFT(a, s); \
    a += b; \
}


class Md5Utils {
private:

    unsigned int count[2];
    unsigned int state[4];
    unsigned char buffer[64];


    void MD5Update(unsigned char *input, unsigned int inputlen);

    void MD5Final(unsigned char digest[16]);

    void MD5Transform(unsigned int state[4], unsigned char block[64]);

    void MD5Encode(unsigned char *output, unsigned int *input, unsigned int len);

    void MD5Decode(unsigned int *output, unsigned char *input, unsigned int len);

    static const char HEX_NUMBERS[16];
public:
    string encryption16(char *decrypt);

    string encryption32(char *decrypt);

    Md5Utils();

    ~Md5Utils();

};


#endif //NDKDEMO_MD5UTILS_H
