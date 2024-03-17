void parse2cpp(vector<string> tokens,ofstream& outfile){
for(size_t i = 0; i < tokens.size(); i++)
{
    string token  = tokens[i];
        if(token == "let" || token == "var"){
            if(tokens[i+2] == ":"){
                outfile<<( tokens[i+3] + " " + tokens[i+1]);
                i = i+3;
             }
            else if(tokens[i+3] == "(" && tokens[i+2]=="="){
                int k = afterParams(tokens,i+3);
                cout << tokens[k] << k;
                if(tokens[k+1] == "=" && tokens[k+2] == ">" ){
                    outfile<<"auto " + tokens[i+1] + " = [&](";
                    for(int q = i+4; q <= k; q++)
                    {
                        cout<<"\nadded # param\n";
                        outfile<<tokens[q];
                    }
                    cout<<endl<<tokens[k+3];
                    i = k+2;
                    cout<<endl<<i<< " @ k : "<<k ;
                    //    auto stringReturningLambda = []() -> std::string {
                }
            }
        }
        //Last else
        else{
            outfile<<token;
        }
    }
}