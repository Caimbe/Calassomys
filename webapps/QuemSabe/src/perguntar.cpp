#include "perguntar.h"

Perguntar::Perguntar(cppcms::service &srv, cppcms::json::value& cfg) : calassomys::WebApp(srv, cfg)
{
    dispatcher().assign("",&Perguntar::fazerPergunta,this);
    dispatcher().assign("/novaPergunta",&Perguntar::novaPergunta,this);
}

void Perguntar::novaPergunta()
{
    if(request().request_method()!="POST")
        return;

    string titulo = request().post("titulo");
    string descricao = request().post("descricao");

    Pergunta pergunta(titulo, descricao);
    model.novaPergunta(pergunta);
}

void Perguntar::fazerPergunta()
{
    calassomys::View view;
    view.setContent(config.get<string>("calassomys.webapp.web_content_path")+"simple.html");
    view.setContentId("content", config.get<string>("calassomys.webapp.web_content_path") + "perguntar.html" );

    response().out() << view;
}
