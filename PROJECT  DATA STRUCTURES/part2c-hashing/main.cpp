#include <iostream>
#include <fstream>
#include <string>
#include<vector>
#include<sstream>
#include<cmath>
#include<iomanip>
#include<list>

using namespace std;

struct days{
    string date;
    long numdate;
    float celsius;
};

class Hash{
    int m;
    list <struct days>*table;
public:
  Hash (){
        this->m = 11;
        table = new list < struct days >[m];
    }
   
    long hashFunction (long x){
        return (x % m);
    }
  void  insertItem (struct days day){
        long index = hashFunction (day.numdate);
        table[index].push_back (day);
    }
   
   void deleteItem (struct days  day){
        long index = hashFunction (day.numdate);
        list <struct days>::iterator i;
        for (i = table[index].begin (); i != table[index].end (); i++){
            if (i->numdate == day.numdate)
                break;
        }
        if (i != table[index].end ())
            table[index].erase (i);
    }
  void  displayHash (){
        for (int i = 0; i < m; i++){
            cout << i;
            for (auto x:table[i])
                cout << " --> " <<"|"<<x.date<<": "<<x.celsius<<"|";
            cout << endl;
        }
    void displayHash ();
 }
    
    
    struct days search(struct days day){
        struct days null=null;
        long j = hashFunction (day.numdate);
        list <struct days>::iterator i;
        for (i = table[j].begin (); i != table[j].end (); i++){
            if(i->numdate==day.numdate){
                return *i;
                break;
        }
      }
        return null;
    }
    
    void replace(float celsius,struct days day){
    struct days null=null;
    long j = hashFunction (day.numdate);
    list <struct days>::iterator i;
    for (i = table[j].begin (); i != table[j].end (); i++){
        if(i->numdate==day.numdate){
            i->celsius=celsius;
            break;
      }
     }
    }
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
        if(c!='"' && c!='{' && c!=',')
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



void menu(Hash(h), vector<struct days> days){
    bool flag=true;
    
    while(flag){
    
        cout<<"Επιλέξτε:"<<endl<<"1) Απεικόνιση του ΔΔΑ με ενδο-διατεταγμένη διάσχιση"<<endl<<"2) Αναζήτηση της ΜΕΣΗΣ ΘΕΡΜΟΚΡΑΣΙΑΣ βάσει ΗΜΕΡΑΣ που θα δίνεται από το χρήστη."<<endl<<"3) Τροποποίηση του πεδίου της ΜΕΣΗΣ ΘΕΡΜΟΚΡΑΣΙΑΣ που αντιστοιχεί σε συγκεκριμένη ΗΜΕΡΑ."<<endl<<"4) Διαγραφή μιας εγγραφής που αντιστοιχεί σε συγκεκριμένη ΗΜΕΡΑ."<<endl<<"5) Έξοδος από την εφαρμογή."<<endl;
        int ceid;
        cin>>ceid;
        switch(ceid){
                
            case 1:{h.displayHash(); break;}
                
            case 2:{
                cout<<"Εισάγετε τη μέρα για να βρεθέι η  θερμοκρασία της:"<<endl;
                string  datenames;
                cin>>datenames;
                datenames={datenames[0],datenames[1],datenames[2],datenames[3],datenames[5],datenames[6],datenames[8],datenames[9]};
                long datenumname;
                stringstream(datenames) >> datenumname;
                struct days day;
                day.numdate=datenumname;
                cout<<"Η μέση θερμοκρασία είναι : "<< h.search(day).celsius<<endl;
                break;
            }
                
            case 3:{
                cout<<"Εισάγετε τη μέρα για να τροποποιηθεί η  θερμοκρασία της:"<<endl;
                string  datenames;
                cin>>datenames;
                datenames={datenames[0],datenames[1],datenames[2],datenames[3],datenames[5],datenames[6],datenames[8],datenames[9]};
                long datenumname;
                stringstream(datenames) >> datenumname;
                struct days day;
                day.numdate=datenumname;
                float celsius;
                cout<<"Εισάγετε τη νέα θερμοκρασία:"<<endl;
                cin>>celsius;
                h.replace(celsius,day);
                break;
            }
            case 4:{
                cout<<"Εισάγετε τη μέρα για να διαγραφεί:"<<endl;
                string  datenames;
                cin>>datenames;
                datenames={datenames[0],datenames[1],datenames[2],datenames[3],datenames[5],datenames[6],datenames[8],datenames[9]};
                long datenumname;
                stringstream(datenames) >> datenumname;
                struct days day;
                day.numdate=datenumname;
                h.deleteItem(day);
                break;
            }
            case 5: {flag=false; break;}
        }
        
    }
}





vector<struct days> infotodays(vector<string> arr){
    vector<days> days;
    struct days  temp;
    int count=0;
    int tempmo=0;
    float index;
    for(int i=0; i<arr.size()-1; i+=2){
        string str=arr[i+1];
        temp.date=arr[i];
        // cout<<temp.date<<endl;
        float d;
        stringstream(arr[i+1]) >> d;
        //cout<<d<<endl;
        tempmo+=d;
        index+=1;
        for(int j=0; j<str.size(); j++)
            if(str[j]=='}'){
                temp.date={temp.date[0],temp.date[1],temp.date[2],temp.date[3],temp.date[4],temp.date[5],temp.date[6],temp.date[7],
                    temp.date[8],temp.date[9]};
                long x;
                string fotis;
                for(int a=0; a<temp.date.size(); a++)
                    if(temp.date[a]!='-')
                        fotis.push_back(temp.date[a]);
                
                stringstream(fotis) >> x;
                temp.numdate=x;
                temp.celsius=float(tempmo/index);
                index=0;
                //cout<<temp.celsius<<endl;
                days.push_back(temp);
                tempmo=0;
            }
    }
    return days;
}




int main() {
    vector<string> arr;
    vector<struct days> days;
    arr=getinfo("tempm.txt");
    days=infotodays(arr);
    //for(int i=0; i<days.size(); i++) cout<<days[i].date<<" "<<days[i].numdate<<" "<<days[i].celsius<<endl;
  
    Hash(h);
    for(int i=0; i<days.size(); i++) h.insertItem(days[i]);
    //h.displayHash();
    menu(h,days);
}




