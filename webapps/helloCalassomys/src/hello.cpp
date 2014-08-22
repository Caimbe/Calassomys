#include "hello.h"

Hello::Hello(cppcms::service& srv) : WebApp(srv)
{
    dispatcher().assign("/smile",&Hello::smile,this);
    dispatcher().assign("/",&Hello::homer,this);
}

void Hello::homer()
{
    response().out() << " 	  </br>"
"                        ___</br>"
"                      _//_\\\\</br>"
"                    ,"    //".</br>"
"                   /          \\</br>"
"                 _/           |</br>"
"                (.-,--.       |</br>"
"                /o/  o \\     /</br>"
"                \\_\\    /  /\\/\\</br>"
"                (__`--'   ._)</br>"
"                /  `-.     |</br>"
"               (     ,`-.  |</br>"
"                `-,--\\_  ) |-.</br>"
"                 _`.__.'  ,-' \\</br>"
"                |\\ )  _.-'    |</br>"
"                i-\\.'\\     ,--+.</br>"
"              .' .'   \\,-'/     \\</br>"
"             / /         /       \\</br>"
"             7_|         |       |</br>"
"             |/          \"i.___.j\"</br>"
"             /            |     |\\</br>"
"            /             |     | \\</br>"
"           /              |     |  |</br>"
"           |              |     |  |</br>"
"           |____          |     |-i'</br>"
"            |   """"----""|     | |</br>"
"            \\           ,-'     |/</br>"
"             `.         `-,     |</br>"
"              |`-._      / /| |\\ \\</br>"
"              |    `-.   `' | ||`-'</br>"
"              |      |      `-'|</br>"
"              |      |         |</br>"
"              |      |         |</br>"
"              |      |         |</br>"
"              |      |         |</br>"
"              |      |         |</br>"
"              |      |         |</br>"
"              )`-.___|         |</br>"
"            .'`-.____)`-.___.-'(</br>"
"          .'        .'-._____.-i</br>"
"         /        .'           |h</br>"
"         `-------/         .   |j</br>"
"                 `--------' '--'s";
}

void Hello::smile()
{
    response().out() << ":-) <br/>" << request().get("asdf");
    response().out() << "<a href='" << url("/") << "'>Go back</a>";
}
