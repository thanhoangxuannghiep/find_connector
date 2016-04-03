#include <stdio.h>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>
#include <fstream>
#include <sstream>
#define MAX 100
using namespace std;
struct Node{
	int x;
	int y;
};
class Matrix{
private:
	int m;
	vector<vector<int>> _matrix;
	vector<vector<int>> _listConnector;
	//stack <Node> listNode;
public:
	void read_file(std::string file_name);
	void write_file(std::string file_name);
	int get_m(){return m;}
	void check_connector(string method); //kiem tra lien thong
	void DFS(int* label, int v, int SoThanhPhanLT);
	void BFS(int* label, int v, int SoThanhPhanLT);
	void arrange_top();
};