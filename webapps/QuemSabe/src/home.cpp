#include "home.h"

Home::Home(cppcms::service &srv, cppcms::json::value& cfg) : calassomys::WebApp(srv, cfg)
{
    dispatcher().assign("",&Home::inicio,this);
    mapper().assign("");
}

void Home::inicio()
{    
    calassomys::View index;
    index.setContent(config.get<string>("calassomys.webapp.web_content_path")+"simple.html");

    calassomys::View perguntaView;
    perguntaView.setContent(config.get<string>("calassomys.webapp.web_content_path")+"pergunta.html");
    auto perguntas = model.getUltimasPerguntas();
    for(Pergunta& pergunta: *perguntas) {
        vecItrNode vecNodes = perguntaView.getTagsByName("titulo");
        for(auto& node: vecNodes){
            perguntaView.setText(node, pergunta.getTitulo() );
            if(perguntaView.getDom().is_valid(node))
                node->setAttrute("href", "perguntar/mostrarPergunta?id="+to_string(pergunta.getId()) );
        }
        vecNodes = perguntaView.getTagsByName("descricao");
        for(auto& node: vecNodes)
            perguntaView.setText(node, pergunta.getDescricao());
        vecNodes = perguntaView.getTagsByName("data");
        for(auto& node: vecNodes)
            perguntaView.setText(node, pergunta.getData());

        index.insertContentId("content", perguntaView);
    }

    response().out() << index;
}
