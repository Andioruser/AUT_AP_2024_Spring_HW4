#include "server.h"

 // Getter functions
std::vector<User> Server::get_users() const {
    return users;
}

std::map<std::string, std::string> Server::get_public_keys() const {
    return public_keys;
}

std::vector<Message*> Server::get_messages() const {
    return messages;
}

// User and message management
User Server::create_user(std::string username) {
    auto it = find(users.begin(),users.end(),username);
    if(it != users.end()) {
        throw std::logic_error("username not exists");
    }
    std::string public_key{}, private_key{};
    crypto::generate_key(public_key, private_key);
    User user = User(username,private_key,this);
    users.push_back(user);
    public_keys.insert({username,public_key});
}

bool Server::create_message(Message* msg, std::string signature) {
    std::string username = msg->get_sender();
    if(!public_keys.count(username)) {
        return false;
    }
    std::string public_key = public_keys[username];
    bool authentic = crypto::verifySignature(public_key, "message", signature);
    if(authentic) {
        messages.push_back(msg);
    }
    return authentic;

}

 // Utility functions
 void sort_msgs(std::vector<Message*> msgs) {
    std::sort(msgs.begin(),msgs.end());
 }