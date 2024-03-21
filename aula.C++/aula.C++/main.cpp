#include <iostream>
#include <stack>
using namespace std;

int main(){
    string geome;
    stack <string> formas;
    for(int i = 0; i < 4; i++){
        cout << "Entre com a " << i+1 << " " << "forma geometrica" << endl;
        cin >> geome;
        formas.push(geome);
    }
    cout << formas.size() << " " << endl;
    cout << formas.top() << " " << endl;
    
}
