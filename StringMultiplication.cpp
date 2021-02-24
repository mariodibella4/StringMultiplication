#include <iostream>
#include <vector>
#include <sstream>

using namespace std;
int firstDigit(int n) 
{ 
    while (n >= 10) {
        if(n/10==1){
            n=1;
            break;
        }
        n /= 10; 
    }
    return n; 
}
string attachZeros(int i){
    string zeros="";
    if(i==0)
        return "";
    while(i!=0){
        zeros.append("0");
        --i;
    }
    return zeros;
}
vector<string>  cleanUp(vector<string> finalRes){
    vector<string> cleanedUpRes;
    int initialLength=finalRes.size();
    int i=0;
    while(cleanedUpRes.size()!=initialLength){
        string temp=finalRes.at(0);
        string zerosToAttach=attachZeros(i);
        temp=temp+zerosToAttach;
        i++;
        finalRes.erase(finalRes.begin());
        cleanedUpRes.push_back(temp);
    }
    return cleanedUpRes;
} 
string addResults(vector<string> cleanedUpFinalRes){
    while(cleanedUpFinalRes.size()!=1){
        string first = cleanedUpFinalRes.at(0);
        string second = cleanedUpFinalRes.at(1);
        cleanedUpFinalRes.erase(cleanedUpFinalRes.begin()+1);
        int result;int remainder=0;
        vector<int>results;string fres="";int count=0;
        for(int i = first.length()-1,j = second.length()-1;j>=0;i--,j--){
            int firsti;int secondi;stringstream seconds;stringstream firsts;
           if(i<0){
               firsti=0;
           } else{
               firsts<<first.at(i);
                firsts>>firsti;
           }
           seconds<<second.at(j); 
           seconds>>secondi;
           result=firsti+secondi;
           
           results.push_back(result+remainder);
           string res=to_string(results.at(count));
           if(remainder!=0)
                remainder=0;
           if(res.length()>1){
              remainder=firstDigit(results.at(count)) ;
           }
           count++;
        }
        while(results.size()!=0){
            string re=to_string(results.at(0));
            if(results.size()==1){
                fres=re+fres;
                results.erase(results.begin());
                break;
            }
            
            if(re.length()>1)
                fres=re.at(1)+fres;
            else
            {
                fres=re+fres;
            }
            
            results.erase(results.begin());

        }
        cleanedUpFinalRes.at(0)=fres;
    }
    return cleanedUpFinalRes.at(0);
}
string mult(string first,string second){
    int result;int remainder;int k=0;vector<string>finalRes;
    for(int j = second.length()-1;j>=0;j--){
        vector<int>results;string fres="";int count=0;
        for(int i = first.length()-1;i>=0;i--){
            int firsti;int secondi;stringstream seconds;stringstream firsts;
           firsts<<first.at(i);
           seconds<<second.at(j); 
           firsts>>firsti;
           seconds>>secondi;
           result=firsti*secondi;
           results.push_back(result+remainder);
           string res=to_string(results.at(count));
           remainder=0;
           if(res.length()>1){
              remainder=firstDigit(results.at(count)) ;
           }
           count++;
        }
        remainder=0;
        while(results.size()!=0){
            string re=to_string(results.at(0));
            if(results.size()==1){
                fres=re+fres;
                results.erase(results.begin());
                break;
            }
            
            if(re.length()>1)
                fres=re.at(1)+fres;
            else
            {
                fres=re+fres;
            }
            
            results.erase(results.begin());

        }
        finalRes.push_back(fres);
    } 
    vector<string> cleanedUpFinalRes=cleanUp(finalRes);
    string solution= addResults(cleanedUpFinalRes);

    return solution;
}

int main()
{
  
    string first= "7997193456789456";
    string second="2589992345654389";
   string sol=mult(first,second);
    
    cout << sol << endl;
    

}