#include "VoiceMessage.h"

VoiceMessage::VoiceMessage(std::string sender, std::string receiver)
    :Message("voice",sender,receiver){
    /*  *****这里初始化vector的实现需要再想想***** */
    std::srand(std::time(0));  // 用当前时间作为种子，确保每次运行随机
    voice.resize(5);
    for (int i = 0; i < 5; ++i) {
        voice[i] = rand() % 256;  // 生成0到255之间的随机字节
    }
}

// Member function for printing
void VoiceMessage::print(std::ostream &os) const {
    os<<"*************************\n";
    os<<*(static_cast<const Message*>(this));
    os<<"voice: ";
    for(auto voice : get_voice()) {
        os<<voice;
    }
    os<<std::endl;
    os<<"*************************\n";
}

// Getter function for the voice data
std::vector<unsigned char> VoiceMessage::get_voice() const {
    return voice;
}