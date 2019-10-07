#include<iostream>
#include<string>
#include<map>

using namespace std;

int main(){
    string patt = "test";
    string intext = "this is a test";

    // bad match table -- letter, val pair

    map<char, int> bmatch;
    for (int i=0; i<patt.size(); i++){
        bmatch[patt[i]] = max(1, (int)(patt.size()-i-1));
    }
    bmatch['*'] = patt.size();

    for (auto i:bmatch) cout<<"bmatch["<<i.first<<"] = "<<i.second<<endl;


    // search
    bool match = false;
    int match_index = -1;
    for (int i=patt.size()-1, j=patt.size()-1; i<intext.size(); ){
        for (int k=i;j>=0;k--, j--){
            if (patt[j] != intext[k]){
                //  if badmatch table contains the text character
                if (bmatch.count(intext[k])){
                    i+=bmatch[intext[k]];
                } else {
                    i+=bmatch['*'];
                }
                j=patt.size()-1;
                break;
            }
        }
        if (j<0){
            match=true;
            match_index=i-patt.size()+1;
            break;
        }
    }

    if (match)  cout<<"Substring match at index "<<match_index<<endl;
    else    cout<<"Substring match not found"<<endl;


}
