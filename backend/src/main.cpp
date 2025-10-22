#include <iostream>
#include <curl/curl.h>

int main() {
    CURL* curl = curl_easy_init();
    if(!curl) {
        std::cerr << "Curl init failed\n";
        return 1;
    }

    // Example using Twilio API
    std::string sid = "YOUR_TWILIO_SID";
    std::string token = "YOUR_TWILIO_TOKEN";
    std::string from = "+1234567890"; // your Twilio number
    std::string to = "+919999999999"; // recipient number
    std::string msg = "Hello from C++ SMS sender!";

    std::string data = "To=" + to + "&From=" + from + "&Body=" + msg;
    std::string url = "https://api.twilio.com/2010-04-01/Accounts/" + sid + "/Messages.json";

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());
    curl_easy_setopt(curl, CURLOPT_USERPWD, (sid + ":" + token).c_str());

    CURLcode res = curl_easy_perform(curl);
    if(res != CURLE_OK)
        std::cerr << "Curl failed: " << curl_easy_strerror(res) << "\n";
    else
        std::cout << "SMS sent successfully!\n";

    curl_easy_cleanup(curl);
    return 0;
}
