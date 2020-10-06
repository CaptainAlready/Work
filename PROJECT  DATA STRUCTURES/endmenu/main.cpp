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

class BST2 {
    
    struct node {
        string date;
        float celsius;
        long data; //date
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
            t->data = day.celsius;
            t->left = t->right = NULL;
        }
        else if(day.celsius < t->data)
            t->left = insert(day, t->left);
        else if(day.celsius > t->data)
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
    
    node* findMax(node* t) {
        if(t == NULL)
            return NULL;
        else if(t->right == NULL)
            return t;
        else
            return findMax(t->right);
    }
    
    node* remove(struct days day, node* t) {
        node* temp;
        if(t == NULL)
            return NULL;
        else if(day.celsius< t->data)
            t->left = remove(day, t->left);
        else if(day.celsius > t->data)
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
        cout <<"|"<<t->celsius<<": "<<t->date<<"|";
        inorder(t->right);
    }
    
    node* find(node* t, struct days day) {
        if(t == NULL)
            return NULL;
        else if(day.celsius < t->data)
            return find(t->left, day);
        else if(day.celsius > t->data)
            return find(t->right, day);
        else
            return t;
    }
    
    
    
public:
    BST2() {
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
    void MIN(){
        cout<<findMin(root)->date<<endl;
    }
    void MAX(){
        cout<<findMax(root)->date<<endl;
    }
    
};

class BST1{
    
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
    BST1() {
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


void menu(BST1 t, vector<struct days> days){
    bool flag=true;
    
    while(flag){
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

void menu2(BST2 t, vector<struct days> days){
    bool flag=true;
    
    while(flag){
        cout<<"Επιλέξτε:"<<endl<<"1) Απεικόνιση του ΔΔΑ με ενδο-διατεταγμένη διάσχιση."<<endl<<"2)Εύρεση ΗΜΕΡΑΣ/ΗΜΕΡΏΝ με την ΕΛΑΧΙΣΤΗ ΜΕΣΗ ΘΕΡΜΟΚΡΑΣΙΑ."<<endl<<"3)Εύρεση ΗΜΕΡΑΣ/ΗΜΕΡΩΝ με τη ΜΕΓΙΣΤΗ ΜΕΣΗ ΘΕΡΜΟΚΡΑΣΙΑ."<<endl<<"4) Έξοδος από την εφαρμογή."<<endl;
        int ceid;
        cin>>ceid;
        switch(ceid){
                
            case 1:{t.display(); break;}
                
            case 2:{
                cout<<"H μέρα/μέρες με την ελάχιστη θερμοκρασία είναι: ";
                t.MIN();
                cout<<endl;
                break;
            }
                
            case 3:{
                cout<<"H μέρα/μέρες με την μέγιστη θερμοκρασία είναι: ";
                t.MAX();
                cout<<endl;
                break;
            }
            case 4: {flag=false; break;}
        }
        
    }
}

void menu3(Hash(h), vector<struct days> days){
    bool flag=true;
    
    while(flag){
        
        cout<<"Επιλέξτε:"<<endl<<"1) Απεικόνιση του HASH-table."<<endl<<"2) Αναζήτηση της ΜΕΣΗΣ ΘΕΡΜΟΚΡΑΣΙΑΣ βάσει ΗΜΕΡΑΣ που θα δίνεται από το χρήστη."<<endl<<"3) Τροποποίηση του πεδίου της ΜΕΣΗΣ ΘΕΡΜΟΚΡΑΣΙΑΣ που αντιστοιχεί σε συγκεκριμένη ΗΜΕΡΑ."<<endl<<"4) Διαγραφή μιας εγγραφής που αντιστοιχεί σε συγκεκριμένη ΗΜΕΡΑ."<<endl<<"5) Έξοδος από την εφαρμογή."<<endl;
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
    cout<<"Eπιλέξτε (1) φόρτωση του αρχείου σε ένα ΔΔΑ ή (2) σε μία δομή Hashing με αλυσίδες."<<endl;
    bool flag=true;
    int a;
    cin>>a;
    vector<string> arr;
    vector<struct days> days;
    arr=getinfo("tempm.txt");
    days=infotodays(arr);
    switch(a){
            
        case 1:{//case 1
            int a2;
            while(flag){//while
            cout<<"Επιλέξτε η φόρτωση στο ΔΔΑ να γίνει: (1) με βάση την ΗΜΕΡΑ ή (2) τη ΜΕΣΗ ΘΕΡΜΟΚΡΑΣΙΑ ανά ημέρα."<<endl;
            cin>>a2;
            if(a2==1){
            flag=false;
                BST1 t;
                for(int i=0; i<days.size(); i++) t.insert(days[i]);
                menu(t,days);
                break;
            }
            else if(a2==2){
            flag=false;
                BST2 t;
                for(int i=0; i<days.size(); i++) t.insert(days[i]);
                menu2(t,days);
                break;
            }else cout<<"Επιλέξτε σωστή τιμή σας παρακαλώ πολύ γιατί κουράζεται η μνήμη"<<endl;
            }//while
            break;
        }//case 1
        case 2:{//case 2
            Hash(h);
            for(int i=0; i<days.size(); i++) h.insertItem(days[i]);
            //h.displayHash();
            menu3(h,days);
            break;
        }//case 2
            break;
  } //end of switch
 
}



