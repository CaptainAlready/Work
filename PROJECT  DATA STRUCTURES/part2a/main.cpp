#include <iostream>
#include <fstream>
#include <string>
#include<vector>
#include<sstream>
#include<cmath>
#include<iomanip>
using namespace std;

struct days{
    string date;
    long numdate;
    float celsius;
};

class BST {
    
    struct node {
        string date;
        float celsius;
        long data;
        node* left;
        node* right;
    };
    
    node* root;
    
    node* insert(struct days day, node* t)
    {
        if(t == NULL)
        {
            t = new node;
            t->date=day.date;
            t->celsius=day.celsius;
            t->data = day.numdate;
            t->left = t->right = NULL;
        }
        else if(day.numdate < t->data)
            t->left = insert(day, t->left);
        else if(day.numdate > t->data)
            t->right = insert(day, t->right);
        return t;
    }
    
    node* findMin(node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->left == NULL)
            return t;
        else
            return findMin(t->left);
    }
    
    node* remove(struct days day, node* t) {
        node* temp;
        if(t == NULL)
            return NULL;
        else if(day.numdate < t->data)
            t->left = remove(day, t->left);
        else if(day.numdate > t->data)
            t->right = remove(day, t->right);
        else if(t->left && t->right)
        {
            temp = findMin(t->right);
            t->data = temp->data;
            t->right = remove(day, t->right); //che problema
        }
        else
        {
            temp = t;
            if(t->left == NULL)
                t = t->right;
            else if(t->right == NULL)
                t = t->left;
            delete temp;
        }
        
        return t;
    }
    
    void inorder(node* t) {
        if(t == NULL)
            return;
        inorder(t->left);
        cout <<"|"<<t->date<<": "<<setprecision(2)<<t->celsius<<"|";
        inorder(t->right);
    }
    
    node* find(node* t, struct days day) {
        if(t == NULL)
            return NULL;
        else if(day.numdate < t->data)
            return find(t->left, day);
        else if(day.numdate > t->data)
            return find(t->right, day);
        else
            return t;
    }
   
    
    
public:
    BST() {
        root = NULL;
    }
    
    void insert(struct days day) {
        root = insert(day, root);
    }
    
    void remove(struct days day) {
        root = remove(day, root);
    }
    
    void display() {
        inorder(root);
        cout << endl;
    }
    
    node* search(struct days day) {
        node* t;
        t = find(root, day);
        return t;
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



void menu(BST t, vector<struct days> days){
    bool flag=true;
   
    while(flag){
      BST p=t;
    cout<<"Επιλέξτε:"<<endl<<"1) Απεικόνιση του ΔΔΑ με ενδο-διατεταγμένη διάσχιση"<<endl<<"2) Αναζήτηση της ΜΕΣΗΣ ΘΕΡΜΟΚΡΑΣΙΑΣ βάσει ΗΜΕΡΑΣ που θα δίνεται από το χρήστη."<<endl<<"3) Τροποποίηση του πεδίου της ΜΕΣΗΣ ΘΕΡΜΟΚΡΑΣΙΑΣ που αντιστοιχεί σε συγκεκριμένη ΗΜΕΡΑ."<<endl<<"4) Διαγραφή μιας εγγραφής που αντιστοιχεί σε συγκεκριμένη ΗΜΕΡΑ."<<endl<<"5) Έξοδος από την εφαρμογή."<<endl;
    int ceid;
    cin>>ceid;
    switch(ceid){
      
        case 1:{t.display(); break;}
       
    case 2:{
            cout<<"Εισάγετε τη μέρα για να βρεθέι η  θερμοκρασία της:"<<endl;
            string  datenames;
            cin>>datenames;
        datenames={datenames[0],datenames[1],datenames[2],datenames[3],datenames[5],datenames[6],datenames[8],datenames[9]};
            long datenumname;
            stringstream(datenames) >> datenumname;
            struct days day;
            day.numdate=datenumname;
            cout<<"Η μέση θερμοκρασία είναι : "<<t.search(day)->celsius<<endl;
            break;
            }
       
    case 3:{
            cout<<"Εισάγετε τη μέρα για να βρεθέι η  θερμοκρασία της:"<<endl;
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
            t.search(day)->celsius=celsius;
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
        t.remove(day);
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
    BST t;
    for(int i=0; i<days.size(); i++) t.insert(days[i]);
    
    t.display();
 
    menu(t,days);
    
}




