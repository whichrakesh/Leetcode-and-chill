#include <iostream>
#include <vector>
using namespace std;

template<typename T>
std::vector<T> slice(std::vector<T> const &v, int m, int size)
{
    auto first = v.cbegin() + m;
    auto last = v.cbegin() + m + size;

    std::vector<T> vec(first, last);
    return vec;
}

bool areSame(vector<int> pre, vector<int> post, vector<int> in){
	if(pre.size() != post.size() || pre.size() != in.size()){
		return false;
	}
	if(pre.size() == 0){
		return true;
	}
	int root = pre[0];
	if(root != post[post.size() - 1]){
		return false;
	}
	vector<int> left, right;
	int i = 0;
	for(i = 0; i<in.size(); i++){
		if(in[i] == root){
			break;
		} else {
			left.push_back(in[i]);
		}
	}
	if(i >= in.size()){
		return false;
	}
	for( i = i+1 ;i<in.size(); i++){
		right.push_back(in[i]);
	}
	vector<int> preLeft = slice(pre, 1, left.size());
	vector<int> preRight = slice(pre, 1 + left.size(), right.size());
	vector<int> postLeft = slice(post, 0, left.size());
	vector<int> postRight = slice(post, left.size(), right.size());
	return areSame(preLeft, postLeft, left) && areSame(preRight, postRight, right);	
}

int main() {
	
	// your code here
	int N, num;
	cin >> N;
	vector<int> pre, post, in;
	for(int i = 0; i < N; i++){
		cin >> num;
		pre.push_back(num);
	}
	for(int i = 0; i < N; i++){
		cin >> num;
		post.push_back(num);
	}
	for(int i = 0; i < N; i++){
		cin >> num;
		in.push_back(num);
	}
	
	bool same = areSame(pre, post, in);
	if(same){
		cout << "yes";
	} else {
		cout << "no";
	}
	
	return 0;
}

