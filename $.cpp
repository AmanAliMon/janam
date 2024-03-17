#include"dependencies.cpp"
#include"helper.cpp"
#include"tokenizer.cpp"
#include"parser.cpp"

int main(int argc, const char * argv[]) {

const char * inputFile = "example.ts";
const char * outputFile ="tests/output";

if(argc != 1 && string(argv[1]) == "compile"){
const char * inputFile = argv[2];
const char * outputFile = argv[3];
}
  std::ifstream infile(inputFile);
stringstream input;
ofstream outfile("tests/presite.cpp");
    if (infile.is_open()) {
        input << infile.rdbuf();
 
        infile.close(); // Close the file stream
    } else {
        std::cerr << "Unable to open file for reading." << std::endl;
        return 1;
    }
    // std::string input = "let Name : string = \"Aman\"; console.log(Name);";

if(outfile.is_open()){
outfile << "#include\"../binder.con\"\nint main(){" << std::endl;
}else{
    cerr<<"File not found";
}
    parse2cpp(tokenize(input.str()),outfile);


outfile << "}" << std::endl;
outfile.close();
    system((string("g++ tests/presite.cpp -o ") + outputFile + " && " + outputFile).c_str());
    return 0;
}