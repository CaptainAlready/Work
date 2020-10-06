#include <iostream>
#include <fstream>
#include <string>
#include<vector>
#include<sstream>
using namespace std;

struct temp {
    string date;
    int celsius;
};

void writefile(vector<temp> info,int temparr[],int size){
    ofstream myfile;
    myfile.open("countingsorted_temp.txt");
    for(int i=0; i<size; i++){
        for(int j=0; j<info.size(); j++)                                      //pername ta sorted apotelesmata se file
            if(info[j].celsius==temparr[i])  {
                myfile<<info[j].date<< " "<<temparr[i]<<endl;
                info.erase(info.begin()+j);
            }
    }
    cout<<"SORTED";
    myfile.close();
}


vector<string> getinfo()
{
    string str;
    vector<char> temporary;
    vector<string> arr;                           //extract information apo to file kai apothikeuoume se vector me char
    ifstream file("hum.txt");
    char c;
    while(!file.eof()){
        file.get(c);
        if(c!='"' && c!='{' && c!='}' && c!=',')
            temporary.push_back(c);}
    
    for(int i=0; i<temporary.size(); i++)
        if(temporary[i]==' ') temporary[i]='\n';   //diaxeirish char-vector kai apthikeysh timestapm kai timhs se diadoxikes
    //theseis string pinaka
    for(int i=0; i<temporary.size(); i++){
        if(temporary[i]=='\n') {
            arr.push_back(str);
            str.clear();}
        else
            str.push_back(temporary[i]);}
    return arr;} //exoume perasei se diadoxikes theseis tou arr tis plhrofories



vector<struct temp> setstruct(vector<string> arr) {       //pername tis plhrofories se vector apo structs/kathe struct simbolizei mia hm/nia
    vector<temp> info;
    struct temp pros;
    for(int i=0; i<arr.size()-1; i+=2){
        pros.date=arr[i];
        int d;
        stringstream(arr[i+1]) >> d;
        pros.celsius=d;
        info.push_back(pros);
    }
    return info;
    
}


int maxstoixeio(int arr[],int size){
    int max=arr[1];
    for(int i=2; i<=size; i++)
        if(arr[i]>max) max=arr[i];
    return max;
}




void countingsort(int arr[],int size,vector<temp> info){
    int b[size+1]; //o taksinomimenos pinakas
    int max=maxstoixeio(arr,size);
    int c[max+1];  //pinakas c boithitikos
    
    for(int i=0; i<=max; i++) c[i]=0; //arxikopoioume c me mhdenika
    
    for(int i=1; i<=size; i++) c[arr[i]]++; //arithmoume to plithos twn stoixeiwn tou a
    
    for(int i=1; i<=max; i++) c[i]=c[i]+c[i-1]; //sarwnoume kai thetoume c[i]=c[i]+c[i-1]
    
    for(int i=size; i>=1; i--){
        b[c[arr[i]]]=arr[i];
        c[arr[i]]=c[arr[i]]-1; //meionoume to index gia kathe thesh tou c
    }
    
    writefile(info,b,size+1);
   }








int main() {
    clock_t tStart=clock();
    
    vector<string> arr;
    vector<struct temp> info;
    arr=getinfo();
    info=setstruct(arr);
    int size=info.size();
    int temparr[size+1];
    for(int i=1; i<=size; i++) temparr[i]=info[i].celsius; //fortonoume tis times ston temparr
    countingsort(temparr,size,info);
    cout<<endl<<"time taken "<<(double)(clock()-tStart)/CLOCKS_PER_SEC;
}

