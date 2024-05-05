#include<stdio.h>
#include<ifstream>
#include<fstream>
using namespace std;

struct student{
 int roll;
 char name[50];
};

class database{
 struct student st;
 public :
   void insert();
   void read();
   void delete();
   void update();
   void search();
   void sort();

};

void database::sort(){
  ifstream file;   //to read
  ofstrewam out;   //to write
  int i=0,n,j;

 file.open("database.txt",ios::binary|ios::in);
 file.read((char*)&st[i],sizeOf(st[i]));

 while(!file.eof()){
  i++;
  file.read((char*)&st[i],sizeOf(st[i]));

}
file.close();


n=i;

for(i=0;i<=n;i++){
  for(j=i+1;j<=n;j++){
    if(st[i].roll > st[j].roll){
      temp=st[i];
      st[i]=st[j];
      st[j]=temp;
   }

}
}

out.open("database.txt",ios::binary|ios::trunc|ios::out);
for(i=0;i<=n;i++){
 out.write((char*)&st[i],sizeOf(struct student));
}

out.close();

}




void database::read(){

  struct student st;
  ifstream file;


  file.open("database.txt",ios::binary|ios::in);
  file.read((char*)&st,sizeOf(st));


  while(!file.eof()){
    cout<<"\n"<<st.roll<<"\t"<<st.name;
    file.read((char*)&st,sizeOf(st));
  }
  cout<<"\n";
  file.close();

}



void database::update(){

 struct student st;
 ifstream file;
 ofstream ofile;
  
 int roll_number,flag=0,flag=1;

 cout<<"Enter roll no. of the record you want to update";
 cin>>roll_number;

 file.open("database.txt",ios::binary|ios::in);
 ofile.open(db1.txt",ios::binary|ios::trunc|ios::out);


file.read((char*)&st,sizeOf(st));


while(!file.eof()){
  if(st.roll_number==st.roll){
    cout<<"Record found";
    cout<<"Enter new name of student";
    cin>>st.name;
    ofile.write(char*)&st,sizeOf(st));
    flag=1,flag1=1;
  
   }
  if(flag==0){
   ofile.write(char*)&st,sizeOf(st));    

  }
flag=0;

file.read((char*)&st,sizeOf(st));
 
} 

if(flag1==0){
   cout<<"record not found";
 }

 remove("database.txt");
 rename("db1.txt","database.txt");

 file.close();

}


void database::delete(){
 struct student st;
int roll_number,flag=0,flag1=0;
ifstream file;
ofstream ofile;

cout<<"Enter roll no in record to delete";
cin>>roll_number;	

file.open("database.txt",ios::binary|ios::in);
ofile.open("db1.txt",ios::binary|ios::out|ios::trunc);

file.read((char*)&st,sizeOf(st));
while(!file.eof()){
if(roll_number==st.roll){
 cout<<"Record found";
 flag=1,flag1=1;

}

flag=0;
file.read((char*)&st,sizeOf(st));
}

if(flag1==0){
  cout<<"\nRECORD NOT FOUND!!!\n";
}
remove("database.txt");
rename("db1.txt","database.txt");

file.close();

}
