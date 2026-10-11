
/*B. Did Not Go to Print
time limit per test2 seconds
memory limit per test256 megabytes
Recently, K1o0n bought himself a new expensive printer, which is distinguished by its memory, 
that is, it may not print immediately. Yesterday, while he was away from his new purchase, his friends used the printer.

There are n
 documents numbered from 1
 to n
. Initially, the printer memory is empty. The friends sequentially performed n
 commands on the printer, where the i
-th command can be one of:

'1'  — scanning. Document i
 is sent to the device memory and is placed on top of everything already there.
'2'  — printing from memory. If the memory is not empty, the device prints the topmost  
document in memory and removes it from there. Otherwise, the device prints document i
.
'3'  — quick print. The device prints document i
.
Today, the friends came to K1o0n with a complaint — not all documents were printed. Help K1o0n find the indices of all documents 
that were not printed.*/


#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void resolverCaso(){
    int n;
    cout << "Ingrese el numero de documentos (n): " << endl;
    cin >> n;

    string s;
    cout << "Ingrese la secuencia de comandos (s): " << endl;
    cin >> s;

    vector<bool> impreso(n + 1, false);
    vector<int> memoria;

for(int i = 1; i <= n; ++i){
    char comando =  s[i - 1];

    if(comando == '1'){
        memoria.push_back(i);

    }else if(comando == '2'){
        if(!memoria.empty()){
            int ultimo_doc = memoria.back();
            impreso[ultimo_doc] = true;
            memoria.pop_back();
            
        }else{
            impreso[i] = true;

        }
    }else if(comando == '3'){
        impreso[i] = true;

    }
}

vector<int> no_impresos;

for(int i = 1; i <= n; ++i){
    if(!impreso[i]){
        no_impresos.push_back(i);
    }
}

cout<<no_impresos.size() << "\n";

for(int i = 0; i < no_impresos.size(); ++i){
    cout << no_impresos[i];
    if(i + 1 < no_impresos.size()){
        cout << " ";
    }
}
cout << "\n";
};

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t;
    cout<<"Ingrese numero n: "<<endl;
    if(cin >> t){
        while(t > 0){
            resolverCaso();
            t--;
        }
    }
    return 0;
}