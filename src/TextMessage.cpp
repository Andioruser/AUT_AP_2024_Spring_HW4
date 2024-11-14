#include "TextMessage.h"


  // Constructor
TextMessage::TextMessage(std::string text, std::string sender, std::string receiver)
      :text(text),Message("text",sender,receiver){

}


// Member function for printing
void TextMessage::print(std::ostream &os) const {
    os<<"*************************\n";
    os<<*(static_cast<const Message*>(this));
    os<<"text: "<<get_text()<<std::endl;
    os<<"*************************\n";
}

// Getter function for the text content
std::string TextMessage::get_text() const {
    return text;
}