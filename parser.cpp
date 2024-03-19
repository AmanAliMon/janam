void parse2cpp(std::vector<std::string> tokens, std::ofstream& outfile) {
    for (size_t i = 0; i < tokens.size(); i++) {
        std::string token = tokens[i];
        if (token == "let" || token == "var") {
            if (i + 3 < tokens.size() && tokens[i + 2] == ":") {
                outfile << (tokens[i + 3] + " " + tokens[i + 1]);
                i = i + 3;
            } else if (i + 4 < tokens.size() && tokens[i + 3] == "(" && tokens[i + 2] == "=") {
                int k = afterParams(tokens, i + 3);
                if (k != -1 && k + 3 < tokens.size() && tokens[k + 1] == "=" && tokens[k + 2] == ">") {
                    outfile << "auto " + tokens[i + 1] + " = [&](";
                    for (int q = i + 4; q <= k; q++) {
                        outfile << tokens[q];
                    }
                    i = k + 2;
                }
            }
        } else {
            outfile << token;
            // Add space between alphanumeric tokens
            if (i + 1 < tokens.size() && std::isalnum(token.back()) && std::isalnum(tokens[i + 1].front())) {
                outfile << " ";
            }
        }
    }
}