#include "message.h"

Message::Message(std::string type, std::string sender, std::string receiver)
    :type(type),sender(sender),receiver(receiver),time(getTimestamp()) {
}

Message::Message()
    :type("text"),sender("unknown"),receiver("unknown"),time(getTimestamp()){
}

// Getter functions
std::string Message::get_type() const {
    return type;
}

std::string Message::get_sender() const {
    return sender;
}
    
std::string Message::get_receiver() const {
    return receiver;
}
    
std::string Message::get_time() const {
    return time;
}

// Print function for use in operator<< overloading
void Message::print(std::ostream &os) const {
    os<<"*************************\n";
    os<<*this;
    os<<"*************************\n";
}

// Overload operator<< to work with Message objects
std::ostream& operator<<(std::ostream &os, const Message &msg) {
    os << msg.sender << " -> " << msg.receiver << std::endl;
    std::cout << "message type: " << msg.type << std::endl;
    std::cout << "message time: " << msg.time << std::endl;
    return os;
}