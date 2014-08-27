#ifndef HELLO_H
#define HELLO_H

#include <webapp.h>

class Hello : public calassomys::WebApp
{
public:
    Hello(cppcms::service& srv);
    void homer();
    void smile();
};

#endif // HELLO_H
