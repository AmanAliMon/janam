#include <cctype>

std::vector<std::string> tokenize(const std::string& input) {
    std::vector<std::string> tokens;
    std::string currentToken;
    char quoteChar = '\0'; // Tracks the type of quotation mark encountered

    for (char c : input) {
        if (quoteChar != '\0') { // Inside a quoted string
            currentToken += c;
            if (c == quoteChar) { // End of quoted string
                tokens.push_back(currentToken);
                currentToken.clear();
                quoteChar = '\0';
            }
        } else { // Outside quoted string
            if (std::isspace(c)) { // Whitespace
                if (!currentToken.empty()) { // Non-empty token
                    tokens.push_back(currentToken);
                    currentToken.clear();
                }
            } else if (std::isalnum(c) || c == '_') { // Alphanumeric or underscore
                currentToken += c;
            } else if (c == '"' || c == '`' || c == '\'') { // Quotation mark
                quoteChar = c;
                currentToken += c;
            } else { // Other characters
                if (!currentToken.empty()) { // Non-empty token
                    tokens.push_back(currentToken);
                    currentToken.clear();
                }
                tokens.push_back(std::string(1, c));
            }
        }
    }

    if (!currentToken.empty()) { // Add the last token
        tokens.push_back(currentToken);
    }

    return tokens;
}
// std::vector<std::string> tokenize(const std::string& input) {
//     std::vector<std::string> tokens;
//     std::string currentToken;

//     for (char c : input) {
//         if (std::isspace(c)) {
//             if (!currentToken.empty()) {
//                 tokens.push_back(currentToken);
//                 currentToken.clear();
//             }
//         } else if (std::isalnum(c) || c == '_') {
//             currentToken += c;
//         } else {
//             if (!currentToken.empty()) {
//                 tokens.push_back(currentToken);
//                 currentToken.clear();
//             }
//             tokens.push_back(std::string(1, c));
//         }
//     }

//    if (!currentToken.empty()) {
//         tokens.push_back(currentToken);
//     }

//     return tokens;
// }


