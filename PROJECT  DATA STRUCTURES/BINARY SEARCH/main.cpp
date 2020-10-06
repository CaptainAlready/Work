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


vector<string> getinfo(string file1)
{
    string str;
    vector<char> temporary;
    vector<string> arr;                           //extract information apo to file kai apothikeuoume se vector me char
    ifstream file(file1);
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

void Swap_Data (long &number1, long &number2) {
    long temp;
    temp = number1; number1 = number2; number2 = temp;
}


void QuickSort(long list[], long left, long right,long list2[])
{
    long pivot, leftArrow, rightArrow; leftArrow = left;
    rightArrow = right;
    pivot = list[(left + right) / 2];
    
    do {
        while (list[rightArrow] > pivot)
            --rightArrow;
        while (list[leftArrow] < pivot)
            ++leftArrow;
        if (leftArrow <= rightArrow) {
            Swap_Data(list[leftArrow], list[rightArrow]);
            Swap_Data(list2[leftArrow], list2[rightArrow]); //alazw to index kai stis times tou int pinaka na antistoixoun me to index twn taksinomimenwn string
            ++leftArrow;
            --rightArrow;
        }
    } while (rightArrow >= leftArrow);
    if(left < rightArrow)
        QuickSort(list, left, rightArrow,list2);
    if (leftArrow < right)
        QuickSort(list, leftArrow, right,list2);
}

int binarySearch(long arr[], long l, long r, long x)
{
    if (r >= l) {
        long mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    
    return -1;
}

void removes(string sarr[],int size){
    for(int i=0; i<size; i++) {                       //afairoume apo ta string values ta perita chars
        string temporarys=sarr[i];
        string temporary2;
        int size2=temporarys.size();
        for(int j=0; j<temporarys.size(); j++){
            char c=temporarys[j];
            if(c!='-' && c!=':' && c!='T') temporary2.push_back(temporarys[j]);
        }
        sarr[i]=temporary2;
        temporary2.clear();
    }
}

void converdates(string sarr[],int size,long ints[]){
    for(int i=0; i<size; i++){           //bazoume hmeromhnies sto ints array
        long d;
        stringstream(sarr[i]) >> d;
        ints[i]=d;
    }
    
    }
    
long returnnum(string s){
    long d;
    string temporary;
        for(int j=0; j<s.size(); j++){
            char c=s[j];
            if(c!='-' && c!=':' && c!='T') temporary.push_back(s[j]);
        }
        s=temporary;
    for(int i=0; i<s.size(); i++){           //bazoume hmeromhnies sto ints array
        stringstream(s) >> d;
    }
    return d;
}



int main() {
    vector<string> arr;
    vector<struct temp> info;
    
    vector<struct temp> sortedinfo;
    arr=getinfo("hum.txt");
    info=setstruct(arr);
    int size=info.size();
    long ints[size];
    string sarr[size];
    long iarr[size];
    
    for(int i=0; i<size; i++){sarr[i]=info[i].date; iarr[i]=info[i].celsius;} //topothetoume tis times se pinakes
    
    removes(sarr,size);
    converdates(sarr, size, ints);
    QuickSort(ints,0,size-1,iarr);
    
    string a;
    cout<<"eisagete hmerominia ";
    cin>>a;
    clock_t tStart=clock();
    
    cout<<endl;
    long d=returnnum(a);
    
    int index=binarySearch(ints,0,size-1,d);
    cout<<a<<" is "<<iarr[index]<<endl;
    cout<<endl<<"time taken "<<(double)(clock()-tStart)/CLOCKS_PER_SEC;
    
}


