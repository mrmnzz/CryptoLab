//Develop a crypto system based on transposition cipher(with double
//permutation). The key length could be of any size.

#include<iostream>
#include<string>
using namespace std;


string encrypt(string s,int keylen,int key[]) //function for encryption
{
        int len=s.length(),x,y=keylen;


        if(len%keylen==0)     //calculating number of rows
                x=len/keylen;
        else
                x=(len/keylen)+1;

        if(x*y!=len)   //pushing garbage data to fill th matrix
        {
                for(int i=0;i<x*y-len;i++)
                        s.push_back('z');
        }



        char a[x+1][y+1];
        int k=0;
        for(int i=1;i<=x;i++)  //filling the matrix
        {
                for(int j=1;j<=y;j++)
                {
                        a[i][j]=s[k++];

                }

        }

        int key2[keylen+1];
        for(int i=1;i<=keylen;i++) //adjusting the key (e.g "4 1 3 2" => "2 4 3 1")
                key2[key[i]]=i;

        string result;

        for(int j=1;j<=y;j++)  //creating the final string
        {
                for(int i=1;i<=x;i++)
                        result.push_back(a[i][key2[j]]);
        }
        return result;
}


string decrypt(string s,int keylen,int key[]) //function for decryption
{
        int len=s.length(),x,y=keylen;
        x=len/keylen;       //calculating number of rows

        char a[x+1][y+1];

        int key2[keylen+1];
        for(int i=1;i<=keylen;i++)  //adjusting the key (e.g "4 1 3 2" => "2 4 3 1")
                key2[key[i]]=i;


        int k=0;

        for(int i=1;i<=y;i++)  //filling the matrix
        {
                for(int j=1;j<=x;j++)
                {
                        a[key2[i]][j]=s[k++];
                }
        }

        string result;

        for(int i=1;i<=x;i++)  //creating the final string
        {
                for(int j=1;j<=y;j++)
                        result.push_back(a[j][i]);
        }
        return result;
}


int main()
{
        int keylen;
        cout<<"Enter key length : ";
        cin>>keylen;
        int key[keylen+1];
        cout<<"\nEnter numeric key with spaces : ";
        for(int i=1;i<=keylen;i++)
        {
                cin>>key[i];
        }

        string s;
        cout<<"\nEnter string to be encrypted\n";
        cin>>s;
        string encrypted=encrypt(s,keylen,key);
        cout<<"\nFirst encrypted string : "<<encrypted;
        encrypted=encrypt(encrypted,keylen,key);
        cout<<"\nFinal encrypted string : "<<encrypted;

        string decrypted=decrypt(encrypted,keylen,key);

        decrypted=decrypt(decrypted,keylen,key);

        cout<<"\n\ndecrypted string : "<<decrypted<<endl;

        return 0;
}
