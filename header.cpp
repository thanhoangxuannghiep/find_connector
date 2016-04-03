#include "header.h"
void Matrix::read_file(std::string file_name){
	ifstream file;
    file.open (file_name);
    if (!file.is_open()) return;
    string line, word;
	file >> m;
	for(int i = 0; i<m;i++){
		int value;
		vector<int> arrValue;
		for(int j=0;j<m;j++){
			file >> value;
			arrValue.push_back(value);
		}
		this->_matrix.push_back(arrValue);
	}
}
void Matrix::check_connector(string method){
	int *arrLabel = new int[_matrix.size()]();
	int count_TPLT;
	count_TPLT=1;
	for(int v=0;v<Matrix::_matrix.size();v++){
		if(arrLabel[v]==0){
			if(method == "d"){
				DFS(arrLabel,v,count_TPLT);
			}
			else if(method=="b"){
				BFS(arrLabel,v,count_TPLT);
			}
			vector<int> array_temp;
			for(int k=0; k < (signed)_matrix.size();k++){
				if(arrLabel[k]==count_TPLT){
					array_temp.push_back(k);
				}
			}
			Matrix::_listConnector.push_back(array_temp);
			count_TPLT=count_TPLT+1;
		}	
	}
}
void Matrix::arrange_top(){
	for (int i = 0; i < Matrix::_listConnector.size(); i++){
		for (int j = i + 1; j < Matrix::_listConnector.size(); j++){
			if (Matrix::_listConnector[i].size() > Matrix::_listConnector[j].size()){
				vector<int> temp=Matrix::_listConnector[i];
				Matrix::_listConnector[i]=Matrix::_listConnector[j];
				Matrix::_listConnector[j]=temp;
			}
		}
	}
}
void Matrix::DFS(int* label,int top,int count){
	label[top]= count;// bat len 1
	for(int j = 0; j <(signed)_matrix.size();j++){
		//cac dinh ke va chua vieng tham
		if(Matrix::_matrix[top][j]==1 && label[j]==0){
			Matrix::DFS(label,j,count);
		}
	}
}
void Matrix::BFS(int* label,int top,int soTPLT){
	queue <int> Q;
	Q.push(top);//them dih vao hang doi
	label[top]=soTPLT;//bat len 1
	while(!Q.empty()){
		int x= Q.front();
		Q.pop();
		for(int i=0; (signed)_matrix.size(); i++){
			//cac dinh ke va chua vieng tham
			if(_matrix[x][i]==1 && label[i]==0)
			{
				//bat len 1
				label[i]=soTPLT;
				//them i vao hang doi queue
				Q.push(i);
			}
		}

	}
}

void Matrix::write_file(std::string file_name){
	cout << endl;
	ofstream file(file_name);
	if(file.is_open())
	{
		file.clear();
		file << Matrix::_listConnector.size() << endl;
		for(int i=0;i<Matrix::_listConnector.size();i++)
		{
			for(int j=0; j<Matrix::_listConnector[i].size();j++)
			{
					file << Matrix::_listConnector[i][j] << " ";
			}
			file << endl;
		}
		file.close();
		cout<<"success";
	}

}