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
    myfile.open("mergesorted_temp.txt");
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
    ifstream file("tempm.txt");
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


//array info.celsius[]

void Merge(int a[],int l,int h,int mid){
    int i=l,j=mid+1,k=0;
    int z[h-l+1];
    
    
    while(i<=mid && j<=h){
        if(a[i]<a[j]){
            z[k]=a[i];
            k++;
            i++;}
        else
        {
            z[k]=a[j];
            k++;
            j++;
        }
    }
    while(i <= mid){
        z[k]=a[i];
        k++;
        i++;
    }
    while(j <=h){
        z[k]=a[j];
        k++;
        j++;
    }
    
    for(i=l; i<=h; i++) a[i]=z[i-l];
}

void MergeSort(int arr[],int l,int h){
    int mid;
    if(l<h){
        mid=(l+h)/2;          //xwrizoume sta duo to arr
        MergeSort(arr,l,mid);
        MergeSort(arr,mid+1,h);
        
        Merge(arr,l,h,mid);
    }
}



int main() {
    clock_t tStart=clock();
    vector<string> arr;
    vector<struct temp> info;
    arr=getinfo();
    info=setstruct(arr);
    int size=info.size();
    int temparr[size];
    for(int i=0; i<info.size(); i++) temparr[i]=info[i].celsius;
    MergeSort(temparr,0,size-1);

    writefile(info,temparr,size);
    
    cout<<endl<<"time taken "<<(double)(clock()-tStart)/CLOCKS_PER_SEC;

}
