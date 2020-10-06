#include <iostream>
#include <fstream>
#include <string>
#include<vector>
#include<sstream>
#include<ctime>
using namespace std;

struct temp {
    string date;
    int celsius;
};

void writefile(vector<temp> info,int temparr[],int size){
    ofstream myfile;
    myfile.open("quicksorted_temp.txt");
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


void Swap_Data (int &number1, int &number2) {
    int temp;
    temp = number1; number1 = number2; number2 = temp;
}









void QuickSort(int list[], int left, int right)
{
    int pivot, leftArrow, rightArrow; leftArrow = left;
    rightArrow = right;
    pivot = list[(left + right) / 2];
    
    do {
    while (list[rightArrow] > pivot)
        --rightArrow;
    while (list[leftArrow] < pivot)
        ++leftArrow;
   if (leftArrow <= rightArrow) {
        Swap_Data(list[leftArrow], list[rightArrow]);
        ++leftArrow;
        --rightArrow;
     }
    } while (rightArrow >= leftArrow);
      if(left < rightArrow)
          QuickSort(list, left, rightArrow);
      if (leftArrow < right)
          QuickSort(list, leftArrow, right);
}

int main() {
    clock_t tStart=clock();
    vector<string> arr;
    vector<struct temp> info;
    arr=getinfo();
    info=setstruct(arr);
    int size=info.size();
    int temparr[size];
    
    for(int i=0; i<size; i++) temparr[i]=info[i].celsius; //fortonoume tis times ston temparr
    QuickSort(temparr,0,size-1);
    writefile(info,temparr,size);
    cout<<endl<<"time taken "<<(double)(clock()-tStart)/CLOCKS_PER_SEC;

}

