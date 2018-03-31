#include "HuffmanCoding.hpp"

int needed_to_read;

void Decode(node *root,char *fname)
{
    string s;
    for(int i=0;fname[i]!='_';i++)
        s+=fname[i];
    ifstream in(fname);
    ofstream out(s+"_uncompressed");
    node *itr = root;
    string bitstring;
    char c;
    while(in.get(c))
    {
        bitstring += bits_in_byte( byte(c) ).to_string() ; // append as string of '0' '1'
    }
    //ofstream tout("binary_receive");
    //tout << bitstring << endl;
    for(int i=0;i<needed_to_read;i++)
    {
        if(bitstring[i]=='1')
        {
            if(itr->right==NULL)
            {
                out << char(itr->l);
                itr=root;
            }
                itr=itr->right;
        }
        else
        {
            if(itr->left==NULL)
            {
                out << char(itr->l);
                itr=root;
            }
                itr=itr->left;
        }
    }
    if(itr->left==NULL && itr->right==NULL)
        out << char(itr->l);
    else
        cout << "error" << endl;
    out.close();
    in.close();
}

void codewords(node *itr,string s)
{
    if(itr->left == NULL && itr->right==NULL)
    {
       cout << (itr->l) << " " << s << endl;
        return;
    }
    codewords(itr->left,s+'0');
    codewords(itr->right,s+'1');
}
int main(int args,char **argc)
{
    if(args<3)
        return 0;
    ifstream in(argc[1]);
    priority_queue<node *,vector<node *>,comp> pq;
    int n;in >> n >> needed_to_read;
    ford(i,0,n)
    {
        int l,f;
        in >> l >> f;
        freq[l]=f;
    }
    in.close(); 
   
    node *root = configure();
    //codewords(root,""); 
    Decode(root,argc[2]);
    return 0;
}

