#ifndef HELLO_H
#define HELLO_H

#include <webapp.h>

class Hello : public WebApp
{
public:
    Hello();
};
_WebApp("/hello",Hello)

#endif // HELLO_H
