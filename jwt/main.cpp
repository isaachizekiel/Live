#include <iostream>
#include <fstream>
#include <chrono>
#include <jwt/jwt_all.h>
#include <jwt/rsavalidator.h>

using json = nlohmann::json;
using namespace std::chrono;

#define KEY_PATH "/home/izak/YoutubeLive/secret/secret.json"

int main() {
    // read a JSON file
    std::ifstream i(KEY_PATH);
    json j;
    j = json::parse(i);    

    // Setup a signer with empty pubkey
    RS256Validator signer("", j["private_key"]);

    milliseconds ms = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

    // Create the json payload
    json payload = {
      {"iss", j["client_email"]},
      {"scope", "https://www.googleapis.com/auth/youtube.force-ssl"},
      {"aud", "https://oauth2.googleapis.com/token"},
      {"exp", ms.count() + 3600},
      {"iat", ms.count()}      
    };


    // Let's encode the token to a string
    auto token = JWT::Encode(signer, payload);

    std::cout << token << std::endl;

}
