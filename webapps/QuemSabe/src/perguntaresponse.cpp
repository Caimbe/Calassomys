#include "perguntaresponse.h"
#include <booster/log.h>

PerguntaResponse::PerguntaResponse(cppcms::service &srv, cppcms::json::value& cfg) : calassomys::WebApp(srv, cfg)
{
    dispatcher().assign("",&PerguntaResponse::fazerPergunta,this);
    dispatcher().assign("/novaPergunta",&PerguntaResponse::novaPergunta,this);
    dispatcher().assign("/mostrarPergunta",&PerguntaResponse::mostrarPergunta,this);
}

void PerguntaResponse::novaPergunta()
{
    if(request().request_method()!="POST")
        return;

    string titulo = request().post("titulo");
    string descricao = request().post("descricao");

    Pergunta pergunta(titulo, descricao);
    try{
        model.novaPergunta(pergunta);
    }
    catch(std::exception const &e) {
        BOOSTER_ERROR("quemsabe") << e.what()<<std::endl;
        BOOSTER_ERROR("quemsabe") << booster::trace(e);
    }
    catch(...) {
        BOOSTER_ERROR("quemsabe") << "Erro Desconhecido!";
    }

    response().set_redirect_header("/QuemSabe/home");
    return;
}

void PerguntaResponse::novaResposta()
{
    if(request().request_method()!="POST")
        return;

    string nome = request().post("nome");
    string resposta = request().post("resposta");
    string idPergunta = request().post("idPergunta");

    try{
        model.novaPergunta()
    }
    catch(std::exception const &e) {
        BOOSTER_ERROR("quemsabe") << e.what()<<std::endl;
        BOOSTER_ERROR("quemsabe") << booster::trace(e);
    }
    catch(...) {
        BOOSTER_ERROR("quemsabe") << "Erro Desconhecido!";
    }

    response().set_redirect_header("/QuemSabe/home");
    return;
}

void PerguntaResponse::mostrarPergunta()
{
    calassomys::View view;
    view.setContent(config.get<string>("calassomys.webapp.web_content_path")+"simple.html");
    view.setContentId("content", config.get<string>("calassomys.webapp.web_content_path") + "mostrarPergunta.html" );

    string id = request().get("id");

    const Pergunta& pergunta = model.getPergunta(id);
    if(pergunta.getId() != -1) {
        auto vecNodes = view.getTagsByName("titulo");
        for(auto node: vecNodes)
            view.setText(node, pergunta.getTitulo() );
        vecNodes = view.getTagsByName("descricao");
        for(auto node: vecNodes)
            view.setText(node, pergunta.getDescricao());
        vecNodes = view.getTagsByName("data");
        for(auto node: vecNodes)
            view.setText(node, pergunta.getData());
    }

    response().out() << view;
}

void PerguntaResponse::fazerPergunta()
{
    calassomys::View view;
    view.setContent(config.get<string>("calassomys.webapp.web_content_path")+"simple.html");
    view.setContentId("content", config.get<string>("calassomys.webapp.web_content_path") + "novaPergunta.html" );

    response().out() << view;
}
