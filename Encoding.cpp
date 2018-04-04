#include "HuffmanCoding.hpp"
using namespace std;
int total_char,total_sym,mxlen,total_written;
vector<string> codes(257);

void codewords(node *itr,string s);

void input(char *fname);

void write_freqability(char *fname);

void codewords(node *itr,string s)
{
    if(itr->left == NULL && itr->right==NULL)
    {
       // cout << itr->l << " " << s << endl;
        codes[itr->l]=s;
        if(s.size()>mxlen)
            mxlen=s.size();
        return;
    }
    codewords(itr->left,s+'0');
    codewords(itr->right,s+'1');
}

void input(char *fname)
{
    ifstream in(fname);
    char c;
    while(in.get(c))
    {
        //cout << int(c) << " " << char(c) << endl;
        total_char++;
        if(freq[int(byte(c))]==0)
            total_sym++;
        freq[int(byte(c))]++;
    }
   
    in.close();
}

void writeString(ofstream &out,const string &bitstring)
{
    for(size_t i=0;i<bitstring.size();i+=BITS_PER_BYTE)
    {
        byte b = bits_in_byte(bitstring.substr(i,BITS_PER_BYTE)).to_ulong();
        out << b;
    }
}

void write(const char *fname)
{
    string bitstring;
    ifstream in(fname);
    string wf(fname);wf+="_compressed";
    ofstream out(wf,ios::binary);
    char c;
    while(in.get(c))
    {
        total_written+=codes[int(byte(c))].size();
        bitstring+=codes[int(byte(c))];
        if(bitstring.size()%BITS_PER_BYTE==0)
        {
            writeString(out,bitstring);
            bitstring.clear();
        }
    }
    while(bitstring.size() % BITS_PER_BYTE)bitstring+='0';    
    writeString(out,bitstring);
    in.close();
    out.close();
}
void write_freqability(char *fname)
{
    string nname(fname);nname+="_freqability";
    ofstream out(nname);
    out << total_sym << " " << total_written << endl;
    for(int i=0;i<fqsz;i++)
        if(freq[i]!=0)
        out << i << " " << freq[i] << endl;
}

int main(int args,char **argc)
{
    if(args<2)
        return 0;

    input(argc[1]);
    
    node *root = configure();
    
    codewords(root,"");
    write(argc[1]);
    write_freqability(argc[1]);
    
    return 0;
}
