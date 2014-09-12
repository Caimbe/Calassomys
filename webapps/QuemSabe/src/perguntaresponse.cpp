#include "perguntaresponse.h"
#include <booster/log.h>

PerguntaResponse::PerguntaResponse(cppcms::service &srv, cppcms::json::value& cfg) : calassomys::WebApp(srv, cfg)
{
    dispatcher().assign("/fazerPergunta",&PerguntaResponse::fazerPergunta,this);
    dispatcher().assign("/novaPergunta",&PerguntaResponse::novaPergunta,this);
    dispatcher().assign("/novaResposta",&PerguntaResponse::novaResposta,this);
    dispatcher().assign("/mostrarPergunta",&PerguntaResponse::mostrarPergunta,this);
}

void PerguntaResponse::novaPergunta()
{
    if(request().request_method()!="POST")
        return;

    string titulo = request().post("titulo");
    string descricao = request().post("descricao");
    if(titulo.empty()){
        response().set_redirect_header("/QuemSabe/perguntar/fazerPergunta");
        return;
    }

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
    if(resposta.empty()){
        response().set_redirect_header("/QuemSabe/perguntar/mostrarPergunta?id="+idPergunta);
        return;
    }

    Resposta resp;
    resp.setAutor(nome);
    resp.setResposta(resposta);
    resp.setIdPergunta(stol(idPergunta));

    try{
        model.novaResposta(idPergunta, resp);
    }
    catch(std::exception const &e) {
        BOOSTER_ERROR("quemsabe") << e.what()<<std::endl;
        BOOSTER_ERROR("quemsabe") << booster::trace(e);
    }
    catch(...) {
        BOOSTER_ERROR("quemsabe") << "Erro Desconhecido!";
    }

    response().set_redirect_header("/QuemSabe/perguntar/mostrarPergunta?id="+idPergunta);
    return;
}

void PerguntaResponse::mostrarPergunta()
{
    calassomys::View view;
    view.setContent(config.get<string>("calassomys.webapp.web_content_path")+"simple.html");
    view.setContentId("content", config.get<string>("calassomys.webapp.web_content_path") + "mostrarPergunta.html" );

    string id = request().get("id");

    Pergunta pergunta = model.getPergunta(id);
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
        vecNodes = view.getTagsByName("idPergunta");
        for(auto node: vecNodes)
            node->setAttrute("value", id );

        // respostas //
        View respostaView;
        respostaView.setContent(config.get<string>("calassomys.webapp.web_content_path")+"resposta.html");
        shared_ptr<vector<Resposta> > vecResposta = model.getRespostas(id);
        for(Resposta& resposta: *vecResposta)
        {
            tag item = respostaView.getTagById("autor");
            respostaView.setText(item, resposta.getAutor());
            item = respostaView.getTagById("resposta");
            respostaView.setText(item, resposta.getResposta());
            item = respostaView.getTagById("data");
            respostaView.setText(item, resposta.getData());

            view.insertContentId("respostas", respostaView);
        }
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
