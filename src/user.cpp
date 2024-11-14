#include "user.h"

// Constructor
User::User(std::string username, std::string private_key, Server* server)
    :username(username),private_key(private_key),server(server){
}

// Getter for username
std::string User::get_username() const {
    return username;
}

// Functions to send messages
bool User::send_text_message(std::string text, std::string receiver) {
    std::string signature = crypto::signMessage(private_key, text);
    TextMessage * textmsg =  new TextMessage(text, username, receiver);
    server->create_message(textmsg,signature);
}
    
bool User::send_voice_message(std::string receiver) {
    std::string signature = crypto::signMessage(private_key, "voice");
    VoiceMessage * voicemsg =  new VoiceMessage(username, receiver);
    server->create_message(voicemsg,signature);
}