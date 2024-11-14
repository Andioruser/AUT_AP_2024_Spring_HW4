#ifndef TEXT_MESSAGE_H
#define TEXT_MESSAGE_H

#include "message.h"  // Include the base class header

class TextMessage : public Message {
public:
    // Constructor
    TextMessage(std::string text, std::string sender, std::string receiver);

    // Member function for printing
    void print(std::ostream &os) const;

    // Getter function for the text content
    std::string get_text() const;

private:
    std::string text;  // The text content of the message
};

#endif // TEXT_MESSAGE_H