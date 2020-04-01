#include <fstream>
#include <iostream>
#include "classes.h"

using namespace std;

void readCoordinates(ifstream &file, int n, item* item_list){
    int e; float r;
    for(int i=0; i<n; i++){
      file >> e >> r;
      item_list[i].setIntFloat(e,r);
    }
}

void showNodes(int n, item* item_list){
    for(int i=0; i<n; i++){
      cout<< item_list[i].getX()<< '\n';
    }
}


int main() {
    char filename[10];
    string line;
    mesh m;
    ifstream file;
    float k,Q;
    int nnodes,neltos,ndirich,nneu;
    
    do{
        cout << "Ingrese el nombre del archivo: ";
        cin >> filename;
        file.open(filename);
    }while(!file);
    
    file >> k >> Q;
    file >> nnodes >> neltos >> ndirich >> nneu;
    
    file >> line;

    m.setParameters(k, Q);
    m.setSizes(nnodes, neltos, ndirich, nneu);
    m.createData();

    readCoordinates(file,nnodes,m.getNodes());

    file.close();

    showNodes(nnodes,m.getNodes());

    return 0;
}
