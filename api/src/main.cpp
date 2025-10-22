#include "crow_all.h"
#include <curl/curl.h>
#include <iostream>

void send_sms(const std::string& to, const std::string& msg) {
    CURL* curl = curl_easy_init();
    if(!curl) return;

    std::string sid = "YOUR_TWILIO_SID";
    std::string token = "YOUR_TWILIO_TOKEN";
    std::string from = "+1234567890";
    std::string data = "To: " + to + "From: " + from + "Body: " + msg;
    std::string url = "https://api.twilio.com/2010-04-01/Accounts/" + sid + "/Messages.json";

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());
    curl_easy_setopt(curl, CURLOPT_USERPWD, (sid + ":" + token).c_str());
    curl_easy_perform(curl);
    curl_easy_cleanup(curl);
}

int main() {
    crow::SimpleApp app;

    CROW_ROUTE(app, "/send_sms").methods("POST"_method)([](const crow::request& req){
        auto body = crow::json::load(req.body);
        if (!body)
            return crow::response(400, "Invalid JSON");

        std::string to = body["to"].s();
        std::string msg = body["msg"].s();

        send_sms(to, msg);
        return crow::response(200, "SMS sent successfully");
    });

    std::cout << "Server running on http://localhost:8080\n";
    app.port(8080).multithreaded().run();
}
