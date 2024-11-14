#ifndef VOICE_MESSAGE_H
#define VOICE_MESSAGE_H

#include "message.h"  // Include the base class header

class VoiceMessage : public Message {
public:
    // Constructor
    VoiceMessage(std::string sender, std::string receiver);

    // Member function for printing
    void print(std::ostream &os) const;

    // Getter function for the voice data
    std::vector<unsigned char> get_voice() const;

private:
    std::vector<unsigned char> voice; // Array of bytes to store the voice data
};

#endif // VOICE_MESSAGE_H