#include"Document.hpp"
#include<cstddef>
#include<string>

Document::Document(std::size_t id,const std::string &text,
                  const Vector &doc_emb) :
                  id{id},text{text},doc_emb{doc_emb}{};

std::size_t Document::get_ID() const{
    return id;
}

const std::string& Document::get_text() const{
    return text;
}

const Vector& Document::get_emb() const{
    return doc_emb;
} 
