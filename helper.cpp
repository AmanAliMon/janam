
using namespace std;
int afterParams(const std::vector<std::string>& vec, int H) {
    int count = 1;
    for (size_t i = H + 1; i < vec.size(); ++i) {
        cout<<"count = "<<count;
            if (vec[i] == ")") {
                count -=1;
                if(count == 0){
                return i;
                }
            }else if(vec[i]=="("){
                count+=1;
        }
    }
    return -1; // If ')' is not found after the H-th string
}
