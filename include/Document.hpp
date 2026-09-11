#ifndef DOCUMENT_HPP
#define DOCUMENT_HPP

#include<cstddef>
#include<string>
#include"Vector.hpp"

class Document{
public:
    Document(std::size_t id,const std::string &text, 
            const Vector &doc_emb);

    std::size_t get_ID() const;

    const std::string& get_text() const;

    const Vector& get_emb() const;
private:
    std::size_t id;
    std::string text;
    Vector doc_emb;
};

#endif
